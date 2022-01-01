#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_search_tree.h"
#include "item.h"

// Crea un nuovo albero binario a ricerca
Bist_node bist_new(Item item) {
    Bist_node new = malloc(sizeof(struct bist_node));
    new -> l = NULL;
    new -> r = NULL;
    new -> info = item;
    return new;
}

// De-alloca la memoria di un albero binario a ricerca
void bist_delete(Bist_node *t) {
    if (*t == NULL)
        return;
    Bist_node *root = t;
    bist_delete(&((*t) -> l));
    bist_delete(&((*t) -> r));
    free((*t) -> info.word);
    free(*t);
    //*t = NULL;
}

// Visita in profondità secondo la strategia "in-order"
void bist_inorder(Bist_node t) {
    if (t != NULL) {
        bist_inorder(t -> l);
        print_item(t -> info);
        bist_inorder(t -> r); 
    }
}

// Visita in profondità con ordine inverso
void bist_revorder(Bist_node t) {
    if (t != NULL) {
        bist_revorder(t -> r);
        print_item(t -> info);
        bist_revorder(t -> l); 
    }
}

// Inserisce un item nell'albero
Bist_node bist_insert(Bist_node t, Item item) {
    if (t == NULL)
        return bist_new(item);
    Bist_node root = t;
    if (strcmp(item.word, t->info.word) < 0)
        t -> l = bist_insert(t -> l, item);
    else
        t -> r = bist_insert(t -> r, item);
    return root;
}

// Rimuove un nodo dell'albero
Bist_node bist_remove(Bist_node t, Item item) {
    Bist_node curr = t, prev = NULL;
    while (curr != NULL && strcmp(item.word, curr->info.word) != 0) {
        prev = curr;
        if (strcmp(item.word, curr->info.word) < 0)
            curr = curr->l;
        else
            curr = curr->r;
    }
    if (curr == NULL)
        return t;
    
    if (curr -> l == NULL) {
        if (prev != NULL) {
            if (strcmp(item.word, prev->info.word) < 0)
                prev -> l = curr -> r;
            else
                prev -> r = curr -> r;
        } else
            t = curr -> r;
        free(curr->info.word);
        free(curr);
    } else if (curr -> r == NULL) {
        if (prev != NULL) {
            if (strcmp(item.word, prev->info.word) < 0)
                prev -> l = curr -> l;
            else
                prev -> r = curr -> l;
        } else
            t = curr -> l;
        free(curr->info.word);
        free(curr);
    } else {
        Bist_node prev_2 = curr, max = curr -> l;
        while (max -> r != NULL) {
            prev_2 = max;
            max = max -> r;
        }
        curr -> info = max -> info;
        if (curr == prev_2)
            curr -> l = max -> l;
        else
            prev_2 -> r = max -> l;
        free(max -> info.word);
        free(max);
    }
    return t;
}

// Ricerca 'item' nell'albero e se lo trova
// restituisce il nodo a cui appartiene, NULL altrimenti
Bist_node bist_find(Bist_node t, Item item) {
    Bist_node curr = t;
    while (curr != NULL && strcmp(curr->info.word, item.word) != 0) {
        if (strcmp(item.word, curr->info.word) < 0)
            curr = curr -> l;
        else
            curr = curr -> r;
    }
    return curr;
}

// Restituisce la chiave minima dell'albero
Item bist_min(Bist_node t) {
    Bist_node curr = t, prev = NULL;
    while (curr != NULL) {
        prev = curr;
        curr = curr -> l;
    }
    return prev -> info;
}

// Restituisce la chiave massima dell'albero
Item bist_max(Bist_node t) {
    Bist_node curr = t, prev = NULL;
    while (curr != NULL) {
        prev = curr;
        curr = curr -> r;
    }
    return prev -> info;
}

// Trasforma un array in un albero binario a ricerca
Bist_node bist_arr2tree(Item a[], int size) {
    Bist_node root = bist_new(a[0]);

    for (int i = 1; i < size; i++) 
        root = bist_insert(root, a[i]);

    return root;
}