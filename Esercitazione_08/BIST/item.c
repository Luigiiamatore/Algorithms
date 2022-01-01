#include <stdio.h>
#include <stdlib.h>
#include "item.h"

// Stampa un item
void print_item(Item item) {
    printf("%s --> %d\n", item.word, item.occ);
}