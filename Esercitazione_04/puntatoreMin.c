#include <stdio.h>

int *smallest(int a[], int n) {
    int *min = a;
    for (int i = 1; i < n; i++)
        if (a[i] < *min)
            min = a + i;
    
    return min;
}

int main() {
    int a[100];
    int n;
    printf("quanti elementi vuoi inserire? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    printf("Il minimo è %d", *smallest(a,n));
    return 0;
}