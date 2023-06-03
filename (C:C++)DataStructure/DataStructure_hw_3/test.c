#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct Graph {
    int numVertices;
    int numEdges;
    Edge* edges;
} Graph;

Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = (Edge*)malloc(numEdges * sizeof(Edge));

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Edge newEdge;
    newEdge.src = src;
    newEdge.dest = dest;
    newEdge.weight = weight;
    graph->edges[graph->numEdges] = newEdge;
    graph->numEdges++;
}

void removeEdge(Graph* graph, int index) {
    if (index >= 0 && index < graph->numEdges) {
        for (int i = index; i < graph->numEdges - 1; i++) {
            graph->edges[i] = graph->edges[i + 1];
        }
        graph->numEdges--;
    }
}

Graph* createMST(Graph* graph) {
    for (int i = 0; i < graph->numEdges - 1; i++) {
        for (int j = 0; j < graph->numEdges - i - 1; j++) {
            if (graph->edges[j].weight > graph->edges[j + 1].weight) {
                Edge temp = graph->edges[j];
                graph->edges[j] = graph->edges[j + 1];
                graph->edges[j + 1] = temp;
            }
        }
    }

    Graph* mstGraph = createGraph(graph->numVertices, 0);
    int* parent = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        parent[i] = i;
    }

    int edgeCount = 0;
    int i = 0;
    while (edgeCount < graph->numVertices - 1) {
        Edge currEdge = graph->edges[i];

        int srcParent = parent[currEdge.src];
        int destParent = parent[currEdge.dest];

        if (srcParent != destParent) {
            addEdge(mstGraph, currEdge.src, currEdge.dest, currEdge.weight);
            parent[destParent] = srcParent;
            edgeCount++;
        }

        i++;
    }

    free(parent);

    return mstGraph;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numEdges; i++) {
        Edge currEdge = graph->edges[i];
        printf("간선 %d: (%d - %d), 가중치: %d\n", i, currEdge.src, currEdge.dest, currEdge.weight);
    }
}

int main() {
    int numVertices = 5;
    int numEdges = 7;
    Graph* graph = createGraph(numVertices, numEdges);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 0, 3, 4);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 3, 4, 3);

    printf("초기 그래프:\n");
    printGraph(graph);

    Graph* mstGraph = createMST(graph);

    printf("\nMST 그래프:\n");
    printGraph(mstGraph);

    removeEdge(mstGraph, 1);

    printf("\n간선 삭제 후 그래프:\n");
    printGraph(mstGraph);

    free(graph->edges);
    free(graph);
    free(mstGraph->edges);
    free(mstGraph);

    return 0;
}
