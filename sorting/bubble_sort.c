#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 2

void print_array (int *a, int lung);
void scambia (int *a, int i, int j);
void bubble_sort (int *a, int lung);

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
    bubble_sort(a, lung);
    print_array(a, lung);
    return 0;
}

void scambia (int *a, int i, int j) {
    int tmp = *(a + i);
    *(a + i) = *(a + j);
    *(a + j) = tmp;
}

void bubble_sort(int *a, int lung) {
    int scambiato;
    do {
        scambiato = 0;
        for (int i = 1; i < lung; i++)
            if (*(a + i) < *(a + i - 1)) {
                scambia(a, i, i - 1);
                scambiato = 1;
            }
    } while (scambiato);
}

void print_array(int *a, int lung) {
    for (int i = 0; i < lung; i++)
        printf("%d ", *(a + i));
}