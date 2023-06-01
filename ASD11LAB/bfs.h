#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include "queue.h"

void printPath(int* parents, int vertex);
void bfs(Graph* graph, int startVertex, int endVertex);

#endif