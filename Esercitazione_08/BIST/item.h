#ifndef ITEM_H

#define ITEM_H

typedef struct item {
    char *word;
    int occ;
}Item;

// Stampa un item
void print_item(Item item);

#endif