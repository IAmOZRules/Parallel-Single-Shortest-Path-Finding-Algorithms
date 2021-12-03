void omp_dijkstra(int **G, int nodes, int startnode, int endnode, int num_threads, int verbose)
{
    #pragma omp parallel num_threads(num_threads) default(none) private(count, i, j, my_mindist, my_nextnode)
    shared(G, startnode, nodes, mindistance, visited, distance, nextnode, cost, pred, num_threads)
    {
        // Using single thread to set initial values
        #pragma omp single {
            distance[startnode] = 0;
            visited[startnode] = 1;
        }

        // Dijkstra's algorithm in parallel
        for (count = 1; count < nodes - 1; count++) {
            // Using single thread to set mindistance
            #pragma omp single
            { mindistance = INF; }

            my_mindist = INF;
            my_nextnode = -1;

            // Each thread finds and sets its own mindistance and nextnode
            #pragma omp for schedule(guided, 16)
            for (i = 0; i < nodes; i++) {
                if (distance[i] < my_mindist && !visited[i]) {
                    my_mindist = distance[i];
                    my_nextnode = i;
                }
            }

            // Using single thread to get the minimum distance and nextnode
            #pragma omp critical {
                if (my_mindist < mindistance) {
                    mindistance = my_mindist;
                    nextnode = my_nextnode;
                }
            }

            // Waiting until all threads have set mindistance and nextnode
            #pragma omp barrier

            // If nextnode is not set, then there is no path
            #pragma omp single
            { visited[nextnode] = 1; }

            // Update distance and pred arrays
            #pragma omp for schedule(guided, 16)
            for (i = 0; i < nodes; i++)
                if (!visited[i])
                    if (mindistance + cost[nextnode][i] < distance[i]) {
                        distance[i] = mindistance + cost[nextnode][i];
                        pred[i] = nextnode;
                    }
        }
    }


    // print the result
    if (verbose)
        print_distance(startnode, endnode, distance, pred);

    free(visited); free(distance);
    free(cost); free(pred);
}