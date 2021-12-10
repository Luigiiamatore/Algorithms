#include "queue.h"

Queue *new_queue() {
    return new_list();
}

void enqueue (Queue *q, int e) {
    add_at_end(q, e);
}

int dequeue (Queue *q) {
    return remove_from_head(q);
}

int front_value (Queue *q) {
    return head_value(q);
}

int is_empty_queue (Queue *q) {
    return is_empty_list(q);
}

void print_queue(Queue *q) {
    if (q -> tail == NULL) {
        printf("Coda vuota.\n");
        return;
    }
    printf("Coda: ");
    for (Node i = q -> head; i != NULL; i = i -> next)
        printf("%d ", i -> info);
    printf("\n");
}