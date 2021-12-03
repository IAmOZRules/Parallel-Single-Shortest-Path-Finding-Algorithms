#include <stdio.h>
#include <stdlib.h>

void serial_floyd(int **graph, int n, int startnode, int endnode, int verbose)
{
    int i, j, k;
    int **cost, **path;

    cost = (int **)malloc(n * sizeof(int *));
    path = (int **)malloc(n * sizeof(int *));

    // Initialize cost and path matrices
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
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                // If there is a shorter path from i to j via then update the cost and path
                if (cost[i][k] != INF && cost[k][j] != INF && cost[i][k] + cost[k][j] < cost[i][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    path[i][j] = path[k][j];
                }

    // Print the path
    if (verbose) {
        printf("\nDistance of Node %d from Node %d is: %d kms.\n", endnode, startnode, cost[startnode][endnode]);
        printSolution(cost, path, startnode, endnode);
    }
}