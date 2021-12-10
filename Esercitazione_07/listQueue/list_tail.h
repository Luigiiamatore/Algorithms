#ifndef LIST_TAIL_H

#define LIST_TAIL_H

struct node {
    int info;
    struct node *next;
};

typedef struct node *Node;

typedef struct {
    Node head;
    Node tail;
} List_with_tail;

// Alloca la memoria per una nuova lista
List_with_tail *new_list ();

// Crea un nuovo nodo della lista
Node new_node (int);

// Aggiunge alla coda un nodo
void add_at_end(List_with_tail *l, int e);

// Rimuove l'elemento in testa e lo ritorna
int remove_from_head (List_with_tail *l);

// Ritorna l'elemento in testa
int head_value (List_with_tail *l);

// Ritorna 1 se la lista è vuota, 0 altrimenti
int is_empty_list (List_with_tail *l);

// Stampa il contenuto di una lista
void print_list (List_with_tail *l);

#endif