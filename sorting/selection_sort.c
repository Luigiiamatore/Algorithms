#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 2

void scambia (int *a, int i, int j);
void selection_sort (int *a, int lung);

int main() {
    int *a, i = 0, size = DEFAULT_SIZE;
    a = malloc(size * sizeof(int));
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

    selection_sort(a, lung);

    for (i = 0; i < lung; i++)
        printf("%d ", a[i]);
        
    return 0;
}

void scambia (int a[], int i, int j) {
    int tmp = *(a + i);
    *(a + i) = *(a + j);
    *(a + j) = tmp;
}

void selection_sort (int *a, int lung) {
    int min_index;
    for (int i = 0; i < lung - 1; i++) {
        min_index = i;

        for (int j = i + 1; j < lung; j++)
            if (*(a + j) < *(a + min_index))
                min_index = j;

        scambia(a, i, min_index);
    }
}