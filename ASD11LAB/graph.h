#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

void inputGraph(Graph* graph, FILE* stream);
Node* createNode(int vertex);
Graph* createGraph(int numVertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);

#endif