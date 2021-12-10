#ifndef QUEUE_H

#define QUEUE_H
#include "item.h"

typedef struct {
    int front;
    int rear;
    int number_elements;
    int len;
    Item *array;
} Queue;

// Crea una nuova coda vuota
Queue *new_queue (int n);

// De-alloca la memoria relativa alla coda
void delete_queue (Queue **q);

// Aggiunge un elemento in coda
void enqueue (Queue *q, Item item);

// Rimuove e ritorna l'elemento in testa
Item dequeue (Queue *q);

// Ritorna l'elemento in testa
Item front_value (Queue *q);

// Ritorna 1 se la coda è vuota, 0 altrimenti
int is_empty_queue (Queue *q);

// Stampa il contenuto della coda
void print_queue (Queue *q);

#endif