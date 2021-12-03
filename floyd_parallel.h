#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void omp_floyd(int** graph, int n, int threads, int startnode, int endnode, int verbose)
{
	int i, j, k;
    int **cost, **path;

	int *rowK = (int*)malloc(sizeof(int)*n);
    int *matrix = (int*)malloc(sizeof(int)*n*n);

    cost = (int **)malloc(n * sizeof(int *));
    path = (int **)malloc(n * sizeof(int *));

    // Flatten the graph to a 1D array for easier access
    #pragma omp parallel for num_threads(threads) shared(graph, n, matrix, rowK) private(i, j, k)
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            matrix[i*n+j] = graph[i][j];

    // Initialize cost and path matrices
    #pragma omp for schedule(static)
    for (i = 0; i < n; i++)
    {
        cost[i] = (int *)malloc(n * sizeof(int));
        path[i] = (int *)malloc(n * sizeof(int));

        for (j = 0; j < n; j++)
        {
            cost[i][j] = graph[i][j];

            if (i == j)
                path[i][j] = i;
            else if (graph[i][j] == INF)
                path[i][j] = -1;
            else
                path[i][j] = i;
        }
    }

    // Floyd-Warshall algorithm
    #pragma omp parallel num_threads(threads) private(k) shared(matrix, rowK)
    for (k = 0; k < n; k++) 
    {   
        // Using master thread to copy the rowK array
    	#pragma omp master
    	memcpy(rowK, matrix + (k * n), sizeof(int)*n);
        
        #pragma omp for private(i, j) schedule(static)
        for (i = 0; i < n; i++) 
            for (j = 0; j < n; j++) 
            {
                // If the calculated cost is less than the current cost
                // update the cost and path
                int newPath = matrix[i * n + k] + rowK[j];
                if (matrix[i * n + j] > newPath)
                {
                    matrix[i * n + j] = newPath;
                    cost[i][j] = cost[i][k] + cost[k][j];
                    path[i][j] = path[k][j];
                }
            }
    }

    // Print the results
    if (verbose) {
        printf("Distance of Node %d from Node %d is: %d kms.\n", endnode, startnode, matrix[startnode * n + endnode]);
        printSolution(cost, path, startnode, endnode);
    }
}