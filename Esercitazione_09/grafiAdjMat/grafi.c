#include "grafi.h"
#include <stdio.h>
#include <stdlib.h>

/* crea un grafo con n nodi */
Graph graph_new (int n) {
    Graph g;
    g = malloc(n * sizeof(struct listnode*));
    return g;
}

/* distrugge il grafo g */
void graph_destroy (Graph g) {
    for (int i = 0; i < g->n; i++)
        free(g->A[i]);
    free(g->A);
    free(g);
}

/* inserisce l'arco (v,w) nel grafo g */
void graph_edgeinsert (Graph g, int v, int w) {
    g -> A[v][w] = 1;
}

/* legge da standard input un grafo (specificare il formato!!) */
Graph graph_read () {
    int n, edge;
    printf("Numero nodi del grafo: ");
    scanf("%d", &n);
    Graph g = graph_new(n);
    printf("Inserire la matrice di adiacenza:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &edge);
            if (edge)
                g -> A[i][j] = 1;
        }
    }
    return g;
}

/* stampa su standard output un grafo (specificare il formato!!) */
void graph_print (Graph g) {
    printf("Matrice di adiacenza:\n");
    for (int i = 0; i < g -> n; i++) {
        for (int j = 0; j < g -> n; j++)
            printf("%d ", g->A[i][j]);
        printf("\n");
    }
}