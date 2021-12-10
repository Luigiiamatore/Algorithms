#include <stdio.h>
#include <stdlib.h>
#include "item_int.c"
#include "stack.h"

struct node {
    Item info;
    struct node *next;
};

typedef struct node * Node;

Node stack = NULL;

void make_empty() {
    while (stack != NULL) {
        Node p = stack -> next;
        free(stack);
        stack = p;
    }
}

int is_empty() {
    if (stack == NULL)
        return 1;
    return 0;
}

Item top() {
    if (stack != NULL)
        return stack -> info;
    printf("non posso eseguire top(): pila vuota!\n");
    exit(EXIT_FAILURE);
}

Item pop() {
    if (stack != NULL) {
        Item n = stack -> info;
        stack = stack -> next;
        return n;
    }
    printf("non posso eseguire pop(): pila vuota!\n");
    exit(EXIT_FAILURE);
}

void push(Item item) {
    Node new;
    new = malloc(sizeof(struct node));
    new -> info = item;
    if (is_empty())
        new -> next = NULL;
    else
        new -> next = stack;
    stack = new;
}

void print_stack() {
    Node p = stack;
    printf("Pila: ");
    while (p != NULL) {
        print_item(p->info);
        printf(" ");
        p = p->next;
    }
    printf("\n");
}