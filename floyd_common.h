#include <stdio.h>
#include <stdlib.h>

void printPath(int **path, int startnode, int endnode)
{
    if (path[startnode][endnode] == startnode)
    {
        return;
    }
    printPath(path, startnode, path[startnode][endnode]);
    printf("%d <- ", path[startnode][endnode]);
}

void printSolution(int **cost, int **path, int startnode, int endnode)
{
    printf("Path is: %d <- ", startnode);
    printPath(path, startnode, endnode);
    printf("%d\n", endnode);
}