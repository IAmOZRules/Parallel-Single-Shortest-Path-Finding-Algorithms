#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "generate_graph.h"
#include "dijkstra_common.h"
#include "dijkstra_serial.h"
#include "dijkstra_parallel.h"

int main()
{
    int **graph, i, j, nodes, edges, start_node, end_node, num_threads;

    scanf("%d %d %d %d %d", &num_threads, &nodes, &edges, &start_node, &end_node);
    graph = generate_graph(nodes, edges, 0);

    double start = omp_get_wtime();
    serial_dijkstra(graph, nodes, start_node, end_node, 0);
    double end = omp_get_wtime();
    double ser_time = end - start;

    start = omp_get_wtime();
    omp_dijkstra(graph, nodes, start_node, end_node, num_threads, 0);
    end = omp_get_wtime();
    double par_time = end - start;

    ser_time = ser_time * 1000000;
    par_time = par_time * 1000000;

    float speedup = ser_time / par_time;
    float efficiency = (speedup / num_threads) * 100;

    FILE *fp;
    fp = fopen("./results/bench_dijkstra.csv", "a+");
    fprintf(fp, "%d,%d,%.0f,%.0f,%.3f,%.2f\n", num_threads, nodes, ser_time, par_time, speedup, efficiency);

    fclose(fp);

    return 0;
}