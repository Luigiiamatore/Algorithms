#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_SIZE 2

void scambia (int *a, int i, int j);
void stampa (int *a, int lung);
void selection_sort (int *a, int n);
void merge_sort (int *a, int sx, int dx, int *x);
void merge (int *a, int sx, int m, int dx, int *x);

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
    /*int *x = malloc(lung * sizeof(int));
    merge_sort(a, 0, lung, x);*/

    stampa(a, lung);
    return 0;
}

void scambia (int *a, int i, int j) {
    int tmp = *(a + i);
    *(a + i) = *(a + j);
    *(a + j) = tmp;
}

void stampa (int *a, int lung) {
    printf("\nArray: ");
    for (int i = 0; i < lung; i++)
        printf("%d ", *(a + i));
    printf("\n");
}

void selection_sort (int *a, int n) {
    while(n > 1) {
        int max_index = 0, max = *a;
        for (int i = 1; i < n; i++) {
            if (*(a + i) > max) {
                max = *(a + i);
                max_index = i;
            }
        }
        scambia(a, max_index, n-1);
        selection_sort(a, --n);
    }
}

void merge_sort (int *a, int sx, int dx, int *x) {
    if (abs(dx - sx) > 1) {
        int m = (dx + sx)/2;
        merge_sort(a, sx, m, x);
        merge_sort(a, m, dx, x);
        merge(a, sx, m, dx, x);
    }
}

void merge (int *a, int sx, int m, int dx, int *x) {
    int i = 0, s = sx, d = m;
    while (s < m && d < dx) {
        if (*(a + s) <= *(a + d)) {
            *(x + i) = *(a + s);
            s++;
            i++;
        }
        else {
            *(x + i) = *(a + d);
            d++;
            i++;
        }
    }
    if (s < m)
        while (s < m) {
            *(x + i) = *(a + s);
            i++;
            s++;
        }
    else
        while(d < dx) {
            *(x + i) = *(a + d);
            i++;
            d++;
        }

    for (i = 0; i < dx - sx; i++)
        *(a + sx + i) = *(x + i);
}