#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "item.c"

// Crea una nuova coda vuota
Queue *new_queue (int n) {
    Queue *new;
    new = malloc(sizeof(Queue));
    new -> front = -1;
    new -> rear = -1;
    new -> number_elements = 0;
    new -> len = n;
    new -> array = malloc(n * sizeof(Item));
    return new;
}

// De-alloca la memoria relativa alla coda
void delete_queue (Queue **q) {
    free((*q) -> array);
    free(*q);
    *q = NULL;
}

// Aggiunge un elemento in coda
void enqueue (Queue *q, Item item) {
    if (q -> number_elements == q -> len)
        return;
    q -> array[++(q -> rear) % q -> len] = item;
    q -> number_elements++;
    if (q -> number_elements == 1)
        q -> front = q -> rear;
}

// Rimuove e ritorna l'elemento in testa
Item dequeue (Queue *q) {
    Item item = q -> array[q -> front];
    q -> front = (q -> front + 1) % q -> len;
    q -> number_elements--;
    return item;
}

// Ritorna l'elemento in testa
Item front_value (Queue *q) {
    return q -> array[q -> front];
}

// Ritorna 1 se la coda è vuota, 0 altrimenti
int is_empty_queue (Queue *q) {
    return q == NULL || q -> number_elements == 0;
}

// Stampa il contenuto della coda
void print_queue (Queue *q) {
    if (q == NULL || q -> number_elements == 0) {
        printf("Coda vuota.\n");
        return;
    }
    printf("Coda: ");
    if (q -> front > q -> rear) {
        for (int i = q -> front; i < q -> front + q -> number_elements; i++)
            print_item(q -> array[i % q -> len]);
    } else {
        for (int i = q -> front; i <= q -> rear; i++)
            print_item(q -> array[i]);
    }
    printf("\n");
}