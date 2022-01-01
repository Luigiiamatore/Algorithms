#ifndef BINARY_SEARCH_TREE_H

#define BINARY_SEARCH_TREE_H

#include "item.h"

struct bist_node {
    Item info;
    struct bist_node *l, *r;
};

typedef struct bist_node *Bist_node;

// Crea un nuovo albero binario a ricerca
Bist_node bist_new(Item item);

// De-alloca la memoria di un albero binario a ricerca
void bist_delete(Bist_node *t);

// Visita in profondità secondo la strategia "in-order"
void bist_inorder(Bist_node t);

// Visita in profondità con ordine inverso
void bist_revorder(Bist_node t);

// Inserisce un item nell'albero
Bist_node bist_insert(Bist_node t, Item item);

// Rimuove un nodo dell'albero
Bist_node bist_remove(Bist_node t, Item item);

// Ricerca 'item' nell'albero e se lo trova
// restituisce il nodo a cui appartiene, NULL altrimenti
Bist_node bist_find(Bist_node t, Item item);

// Restituisce la chiave minima dell'albero
Item bist_min(Bist_node t);

// Restituisce la chiave massima dell'albero
Item bist_max(Bist_node t);

// Trasforma un array in un albero binario a ricerca
Bist_node bist_arr2tree(Item a[], int size);

#endif