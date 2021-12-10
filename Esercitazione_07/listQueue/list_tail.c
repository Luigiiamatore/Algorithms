#include <stdio.h>
#include <stdlib.h>
#include "list_tail.h"

List_with_tail *new_list () {
    List_with_tail *l = malloc(sizeof(List_with_tail *));
    l -> head = NULL;
    l -> tail = NULL;
}

Node new_node (int e) {
    Node new = malloc(sizeof(struct node));
    new -> info = e;
    new -> next = NULL;
    return new;
}

void add_at_end(List_with_tail *l, int e) {
    if (l -> tail == NULL) {
        l -> tail = new_node(e);
        l -> head = l -> tail;
    } else {
        l -> tail -> next = new_node(e);
        l -> tail = l -> tail -> next;
    }   
}

int remove_from_head (List_with_tail *l) {
    int x = l -> head -> info;
    l -> head = l -> head -> next;
    return x;
}

int head_value (List_with_tail *l) {
    return l -> head -> info;
}

int is_empty_list (List_with_tail *l) {
    return l -> tail == NULL;
}

void print_list (List_with_tail *l) {
    if (l -> tail == NULL) {
        printf("Lista vuota.");
        return;
    }
    printf("Lista: ");
    for (Node i = l -> head; i != NULL; i = i -> next)
        printf("%d ", i -> info);
    printf("\n");
}