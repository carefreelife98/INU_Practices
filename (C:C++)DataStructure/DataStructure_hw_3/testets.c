#include <stdio.h>

#define FILE_LEN 100

typedef struct Edge {
    int start, end;
    float weight;
} Edge;

typedef struct GraphType_ {
    int n;
    Edge edges[FILE_LEN];
} GraphType;

typedef struct vertices {
    int v[20];
    int n;
} Vertices;

void extractEdgesInRange(const GraphType* graph, const Vertices* range) {
    printf("Edges within the range:\n");
    for (int i = 0; i < graph->n; i++) {
        int start = graph->edges[i].start;
        int end = graph->edges[i].end;

        int startInRange = 0;
        int endInRange = 0;

        for (int j = 0; j < range->n; j++) {
            if (start == range->v[j]) {
                startInRange = 1;
            }
            if (end == range->v[j]) {
                endInRange = 1;
            }
        }

        if (startInRange && endInRange) {
            printf("Edge: %d-%d, Weight: %.2f\n", start, end, graph->edges[i].weight);
        }
    }
}

int main() {
    GraphType graph = {
        5,
        {
            {1, 2, 0.5},
            {2, 3, 0.8},
            {3, 4, 0.7},
            {4, 5, 0.4},
            {5, 6, 0.2}
        }
    };

    Vertices range = {
        {2, 3, 4},
        3
    };

    extractEdgesInRange(&graph, &range);

    return 0;
}
