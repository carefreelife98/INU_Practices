for (int i = 0; i < NUM_GRAPHS; i++) {
        graphs[i] = malloc(sizeof(Graph));
        graphs[i]->numVertices = 0;
        for (int j = 0; j < NUM_VERTICES; j++) {
            graphs[i]->vertices[j] = 0;
        }
    }
    printf("ok2");