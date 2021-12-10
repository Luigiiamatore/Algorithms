#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 2

void print_array (int *a, int lung);
void merge_sort (int *a, int sx, int dx, int *x);
void merge (int *a, int sx, int m, int dx, int *x);

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
        printf("size: %d\n", size);
        int n;
        scanf("%d", &n);
        *(a + i++) = n;
        if (c = getchar() == '\n')
            break;
    }
    int lung = i;
    int *x = malloc(lung * sizeof(int));
    merge_sort(a, 0, lung, x);
    print_array(a, lung);
    return 0;
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

void print_array(int *a, int lung) {
    for (int i = 0; i < lung; i++)
        printf("%d ", *(a + i));
}