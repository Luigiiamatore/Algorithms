#include "binarytree.h"

// Crea un nuovo nodo il cui valore è e
Bit_node new_node (int e) {
    Bit_node new = malloc(sizeof(struct bit_node));
    new -> item = e;
    new -> l = NULL;
    new -> r = NULL;
    return new;
}

// Stampa il valore relativo al nodo p
void bit_printnode (Bit_node p) {
    printf("%d ", p -> item);
}

// Stampa un albero binario puntato da p secondo la metodologia
// "inorder"
void bit_inorder (Bit_node p) {
    if (p) {
        bit_inorder(p -> l);
        bit_printnode(p);
        bit_inorder(p -> r);
    }
}

// Stampa un albero binario puntato da p secondo la metodologia
// "preorder"
void bit_preorder (Bit_node p) {
    if (p) {
        bit_printnode(p);
        bit_preorder(p -> l);
        bit_preorder(p -> r);
    }
}

// Stampa un albero binario puntato da p secondo la metodologia
// "postorder"
void bit_postorder (Bit_node p) {
    if (p) {
        bit_postorder(p -> l);
        bit_postorder(p -> r);
        bit_printnode(p);
    }
}

// Stampa un albero binario puntato da root nella rappresentazione
// usata nei sommari dei libri
void bit_printsummary (Bit_node root, int tabs) {
    if (root) {
        for (int i = 0; i < tabs; i++)
            printf("\t");
        printf("* ");
        bit_printnode(root);
        printf("\n");
        bit_printsummary(root -> l, tabs + 1);
        bit_printsummary(root -> r, tabs + 1);
    }
}

// Dato un array a di dimensione size, ritorna il sottoalbero 
// binario (completo) con queste proprietà:
//      - radice a[j]
//      - figlio sx a[2*j + 1] e figlio dx a[2*j+2] (se < size)
Bit_node bit_arr2tree (int a[], int size, int j) {
    if (j == 0) {
        Bit_node root = new_node(a[j]);
        if (j + 1 < size) {
            root -> l = bit_arr2tree(a, size, j+1);
            if (j + 2 < size)
                root -> r = bit_arr2tree(a, size, j+2);
        }
        return root;
    }
    Bit_node p = new_node(a[j]);
    if (2 * j + 1 < size)
        p -> l = bit_arr2tree(a, size, 2 * j + 1);
    else
        p -> l = NULL;
    if (2 * j + 2 < size)
        p -> r = bit_arr2tree(a, size, 2 * j + 2);
    else
        p -> r = NULL;
    return p;
}