#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "bfs.h"

int main() {
    system("chcp 1251 & cls");
    int numVertices;
    printf("Введіть кількість вершин графа: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    int choice;
    printf("Виберіть спосіб введення графа:\n");
    printf("1. Ввести з клавіатури\n");
    printf("2. Ввести з файлу\n");
    printf("Ваш вибір: ");
    scanf("%d", &choice);
    rewind(stdin);

    FILE* file = NULL;

    if (choice == 1) {
        inputGraph(graph, stdin);
    }
    else if (choice == 2) {
        char filename[100];
        printf("Введіть назву файлу: ");
        scanf("%s", filename);

        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Помилка відкриття файлу.\n");
            return 1;
        }

        inputGraph(graph, file);
    }
    else {
        printf("Невірний вибір.\n");
        return 1;
    }

    printf("Граф:\n");
    printGraph(graph);

    int startVertex, endVertex;
    printf("Введіть початкову та кінцеву вершини для пошуку найкоротшого шляху: ");
    scanf("%d %d", &startVertex, &endVertex);

    bfs(graph, startVertex, endVertex);

    if (file != NULL) {
        fclose(file);
    }

    return 0;
}