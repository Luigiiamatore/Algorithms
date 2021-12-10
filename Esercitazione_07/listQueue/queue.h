#ifndef QUEUE_H

#define QUEUE_H

#include "list_tail.c"

typedef List_with_tail Queue;

Queue *new_queue();

void enqueue (Queue *, int);

int dequeue (Queue *);

int front_value (Queue *);

int is_empty_queue (Queue *);

void print_queue(Queue *);

#endif