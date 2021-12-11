#ifndef BINARYTREE_H

#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

struct bit_node {
    int item;
    struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

// Crea un nuovo nodo il cui valore è e
Bit_node new_node (int e);

// Stampa il valore relativo al nodo p
void bit_printnode (Bit_node p);

// Stampa un albero binario puntato da p secondo la metodologia
// "inorder"
void bit_inorder (Bit_node p);

// Stampa un albero binario puntato da p secondo la metodologia
// "preorder"
void bit_preorder (Bit_node p);

// Stampa un albero binario puntato da p secondo la metodologia
// "postorder"
void bit_postorder (Bit_node p);

// Stampa un albero binario puntato da root nella rappresentazione
// usata nei sommari dei libri
void bit_printsummary (Bit_node root, int tabs);

// Dato un array a di dimensione size, ritorna il sottoalbero 
// binario (completo) con queste proprietà:
//      - radice a[j]
//      - figlio sx a[2*j + 1] e figlio dx a[2*j+2] (se < size)
Bit_node bit_arr2tree (int a[], int size, int j);

#endif