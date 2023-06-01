#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "bfs.h"

int main() {
    system("chcp 1251 & cls");
    int numVertices;
    printf("������ ������� ������ �����: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    int choice;
    printf("������� ����� �������� �����:\n");
    printf("1. ������ � ���������\n");
    printf("2. ������ � �����\n");
    printf("��� ����: ");
    scanf("%d", &choice);
    rewind(stdin);

    FILE* file = NULL;

    if (choice == 1) {
        inputGraph(graph, stdin);
    }
    else if (choice == 2) {
        char filename[100];
        printf("������ ����� �����: ");
        scanf("%s", filename);

        file = fopen(filename, "r");
        if (file == NULL) {
            printf("������� �������� �����.\n");
            return 1;
        }

        inputGraph(graph, file);
    }
    else {
        printf("������� ����.\n");
        return 1;
    }

    printf("����:\n");
    printGraph(graph);

    int startVertex, endVertex;
    printf("������ ��������� �� ������ ������� ��� ������ ������������ �����: ");
    scanf("%d %d", &startVertex, &endVertex);

    bfs(graph, startVertex, endVertex);

    if (file != NULL) {
        fclose(file);
    }

    return 0;
}