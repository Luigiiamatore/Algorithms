#include <stdlib.h>
#include <stdio.h>

void *my_malloc (size_t n) {
    void *p;
    p = malloc(n);
    if (p == NULL) {
        printf("Spazio nell'heap terminato...\n");
        exit(EXIT_FAILURE);
    }

    return p;
}