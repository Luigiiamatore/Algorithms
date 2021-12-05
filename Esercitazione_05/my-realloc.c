#include <stdlib.h>
#include <stdio.h>

void *my_realloc(void *p, size_t t) {
    p = realloc(p, t);
    if (p == NULL) {
        printf("Memory finished!");
        exit(EXIT_FAILURE);
    }

    return p;
}