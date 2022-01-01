#ifndef GRAFI_H

#define GRAFI_H

struct graph {
    int n, m;               // n = num vertici, m = num lati
    int **A;                // matrice di adiacenza
};

typedef struct graph *Graph;

/* crea un grafo con n nodi */
Graph graph_new (int n);

/* distrugge il grafo g */
void graph_destroy (Graph g);

/* inserisce l'arco (v,w) nel grafo g */
void graph_edgeinsert (Graph g, int v, int w);

/* legge da standard input un grafo (specificare il formato!!) */
Graph graph_read (void);

/* stampa su standard output un grafo (specificare il formato!!) */
void graph_print (Graph g);

#endif