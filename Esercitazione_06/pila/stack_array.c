#include <stdio.h>
#include <stdlib.h>
#include "item_int.c"
#include "stack.h"
#define MAX 100

Item stack[MAX];
int top_index = -1;

void make_empty() {
    top_index  = -1;
}

int is_empty() {
    if (top_index == -1)
        return 1;
    return 0;
}

Item top() {
    if (!is_empty())
        return stack[top_index];
    printf("non posso eseguire top(): pila vuota!\n");
    exit(EXIT_FAILURE);
}

Item pop() {
    if (!is_empty())
        return stack[top_index--];
    printf("non posso eseguire pop(): pila vuota!\n");
    exit(EXIT_FAILURE);
}

void push(Item item) {
    if(top_index < MAX)
        stack[++top_index] = item;
    else 
        exit(EXIT_FAILURE);
}

void print_stack() {
    printf("Pila: ");
    for (int i = top_index; i >= 0; i--) {
        print_item(stack[i]);
        printf(" ");
    }
    printf("\n");
}