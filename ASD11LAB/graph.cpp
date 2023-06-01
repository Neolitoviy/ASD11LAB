#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100

void inputGraph(Graph* graph, FILE* stream) {
    int src, dest;
    char input[MAX_INPUT_SIZE];

    printf("¬вед≥ть ребра графа (зак≥нч≥ть введенн€, вв≥вши -1 -1):\n");
    while (fgets(input, MAX_INPUT_SIZE, stream) != NULL && sscanf(input, "%d %d", &src, &dest) == 2) {
        if (src == -1 && dest == -1) {
            break;
        }
        addEdge(graph, src, dest);
    }
}

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (Node**)malloc(numVertices * sizeof(Node*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("—ум≥жн≥ вершини вершини %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}