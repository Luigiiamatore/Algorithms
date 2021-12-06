#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node *Node;

Node list_insert_1 (int n, Node l) {
    Node new = malloc(sizeof(struct node));
    new -> info = n;
    new -> next = l;
    return new;
}

void list_insert_2 (int n, struct node **l) {
    struct node *new = malloc(sizeof(struct node));
    new -> info = n;
    new -> next = *l;
    *l = new;
}

struct node *list_search (int n, struct node *l) {
    for (; l != NULL && l -> info != n; l = l -> next);
    return l;
}

void list_delete (int n, struct node *l) {
    struct node *curr, *prev;
    for (curr = l, prev = NULL; curr != NULL; prev = curr, curr = curr -> next) {
        if (curr -> info == n) break;
    }
    if (curr == NULL)           // non trovato nella lista
        return;
    if (prev == NULL)           // lista vuota
        l = l -> next;
    else                        // trovato
        prev -> next = curr -> next;
    free(curr);
}

void print_list(struct node *l) {
    printf("\n");
    while (l != NULL) {
        printf("info: %d\n", l -> info);
        l = l -> next;
    }
}

void print_listInv(Node l) {
    if (l != NULL) {
        print_listInv(l->next);
        printf("info: %d\n", l->info);
    }
}

int *list_to_array(Node l) {
    int size = sizeof(int);
    int *arr = malloc(size);
    int i = 0;
    while(l != NULL) {
        arr = realloc(arr, ++size);
        *(arr + i++) = l->info;
        l = l->next;
    }
    return arr;
}

void list_destroy(Node l) {
    while(l != NULL) {
        Node next = l->next;
        free(l);
        l = next;
    }
}

int number_of_elements(Node l) {
    int num = 0;
    while(l != NULL) {
        num++;
        l = l->next;
    }
    return num;
}