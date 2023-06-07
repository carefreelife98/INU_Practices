#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode{
    int vertex;
    struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
    int n;
    GraphNode *adj_list[MAX_VERTICES];
}GraphType;

