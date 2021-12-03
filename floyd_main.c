#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generate_graph.h"
#include "floyd_common.h"
#include "floyd_serial.h"
#include "floyd_parallel.h"

int main()
{
    int **graph, i, j, nodes, edges, start_node, end_node;

    int num_threads;
    printf("\nEnter number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter no. of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    graph = generate_graph(nodes, edges, 1);

    printf("\nEnter the starting node: ");
    scanf("%d", &start_node);

    printf("Enter the ending node: ");
    scanf("%d", &end_node);

    printf("\n<--- SERIAL FLOYD-WARSHALL --->\n");
    double start = omp_get_wtime();
    serial_floyd(graph, nodes, start_node, end_node, 1);
    double end = omp_get_wtime();
    double ser_time = end - start;

    printf("\n<--- PARALLEL FLOYD-WARSHALL --->\n\n");
    start = omp_get_wtime();
    omp_floyd(graph, nodes, num_threads, start_node, end_node, 1);
    end = omp_get_wtime();
    double par_time = end - start;

    printf("\n<--- TIME RESULTS --->\n");
    printf("\nSerial execution time: %.0f µs", ser_time * 1000000);
    printf("\nParallel execution time: %.0f µs", par_time * 1000000);

    printf("\n\n<--- PERFORMANCE METRICS --->\n");
    float speedup = ser_time / par_time;
    printf("\nSpeedup Factor: %.3f", speedup);
    float efficiency = (speedup / num_threads) * 100;
    printf("\nEfficiency: %.2f %%\n", efficiency);

    return 0;
}