#include "binarytree.c"

#define DEFAULT_SIZE 2

int main() {
    int size = DEFAULT_SIZE;
    int *a = malloc(sizeof(int) * size);
    int n, i = -1;
    char c;
    while(1) {
        scanf("%d", &n);
        c = getchar();
        if (++i > size) {
            size *= 2;
            a = realloc(a, size);
        }
        a[i] = n;
        if (c == '\n')
            break;
    }
    Bit_node tree = bit_arr2tree(a, i + 1, 0);
    bit_printsummary(tree, 0);
    return 0;
}