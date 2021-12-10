#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 2

void print_array(int *a, int lung);
void insertion_sort(int *a, int lung);

int main() {
    int size = DEFAULT_SIZE;
    int *a = malloc(size * sizeof(int));
    int i = 0;
    printf("Inserisci una sequenza di interi: ");
    while(1) {
        char c;
        if (i > size) {
            size *= 2;
            a = realloc(a, size * sizeof(int));
        }
        int n;
        scanf("%d", &n);
        *(a + i++) = n;
        if (c = getchar() == '\n')
            break;
    }
    int lung = i;
    insertion_sort(a, lung);
    print_array(a, lung);
    return 0;
}

void insertion_sort(int *a, int lung) {
    for (int k = 1; k < lung; k++) {
        int x = *(a + k);
        int j = k - 1;
        while (j >= 0 && *(a + j) > x) {
            *(a + j + 1) = *(a + j);
            j--;
        }
        *(a + j + 1) = x;
    }
}

void print_array(int *a, int lung) {
    for (int i = 0; i < lung; i++)
        printf("%d ", *(a + i));
}