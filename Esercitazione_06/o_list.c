#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node * Node;

Node olist_insert (int n, Node l) {
    Node curr = l, prev = NULL;
    for (; curr != NULL && n > curr->info;prev = curr, curr = curr -> next);
    Node new;
    new = malloc(sizeof(struct node));
    new -> info = n;
    new -> next = curr;
    if (prev == NULL) 
        l = new;
    else
        prev -> next = new;
    return l;
}

Node olist_search (int n, Node l) {
    while(l != NULL && l->info < n)
        l = l->next;
    if (l != NULL && l->info == n)
        return l;
    else
        return NULL;
}

void print_list(struct node *l) {
    printf("\n");
    while (l != NULL) {
        printf("info: %d\n", l -> info);
        l = l -> next;
    }
}

void list_destroy(Node l) {
    while(l != NULL) {
        Node next = l->next;
        free(l);
        l = next;
    }
}