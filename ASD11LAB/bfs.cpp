#include "bfs.h"
#include "graph.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void printPath(int* parents, int vertex) {
    if (vertex == -1) {
        return;
    }

    printPath(parents, parents[vertex]);
    printf("%d ", vertex);
}

void bfs(Graph* graph, int startVertex, int endVertex) {
    int* parents = (int*)malloc(graph->numVertices * sizeof(int));
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++) {
        parents[i] = -1;
        visited[i] = false;
    }

    Queue* queue = createQueue();
    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                parents[adjVertex] = currentVertex;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }

    if (parents[endVertex] == -1) {
        printf("Немає шляху між вершинами %d та %d\n", startVertex, endVertex);
    }
    else {
        printf("Найкоротший шлях між вершинами %d та %d: ", startVertex, endVertex);
        printPath(parents, endVertex);
        printf("\n");
    }

    free(parents);
    free(visited);
    free(queue);
}