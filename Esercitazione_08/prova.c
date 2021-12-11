#include <stdio.h>
#include <stdlib.h>

struct bit_node {
    int item;
    struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

Bit_node new_node (int e) {
    Bit_node new = malloc(sizeof(struct bit_node));
    new -> item = e;
    new -> l = NULL;
    new -> r = NULL;
    return new;
}

void bit_printnode (Bit_node p) {
    printf("%d", p -> item);
}

void print_tree (Bit_node root, int j) {
    if (root) {
        for (int i = 0; i < j; i++)
            printf("\t");
        bit_printnode(root);
        print_tree(root -> l, j + 1);
        print_tree(root -> r, j + 1);
    }
}

void bit_preorder (Bit_node p) {
    if (p) {
        bit_printnode(p);
        bit_preorder(p -> l);
        bit_preorder(p -> r);
    }
}

Bit_node bit_arr2tree (int a[], int size, int j) {
    if (j == 0) {
        Bit_node root = new_node(a[j]);
        root -> l = bit_arr2tree(a, size, j+1);
        root -> r = bit_arr2tree(a, size, j+2);
        return root;
    }
    Bit_node p = new_node(a[j]);
    if (2 * j + 1 < size)
        p -> l = bit_arr2tree(a, size, 2 * j + 1);
    if (2 * j + 2 < size)
        p -> r = bit_arr2tree(a, size, 2 * j + 2);
    return p;
}

int main() {
    int a[] = {69, 89, 28, 39, 66, 44, 12, 2, 71};
    int len = 9;
    Bit_node tree = bit_arr2tree(a, len, 0);
    print_tree(tree, 0);
    return 0;
}