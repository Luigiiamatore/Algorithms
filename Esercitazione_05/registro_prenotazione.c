#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Errore nella fase di allocazione.");
        exit(1);
    }
    return ptr;
}

void ***newBook(char ***book, int n) {
    *book = my_malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
        (*book)[i] = NULL;
}

void book_f(char **book, int k, char *name) {
    char **ptr = book + k;
    if (*ptr != NULL) {
        printf("Posto già occupato!\n");
        return;
    }
    *ptr = my_malloc((strlen(name)) * sizeof(char));
    strcpy(*ptr, name);
    return;
}

void cancel(char **book, int k) {
    if (book[k] != NULL)
        book[k] = NULL;
    return;
}

void move(char **book, int from, int to) {
    if (*(book + to) != NULL) {
        printf("Posto già prenotato!\n");
        return;
    }
    if (*(book + from) != NULL) {
        book[to] = book[from];
        book[from] = NULL;
    } else {
        printf("move(%d,%d): errore.\n", from + 1, to + 1);
    }
    return;
}

//Stampa il contenuto del registro (posti prenotati)
void printBook(char **book, int n) {
    printf("\nREGISTER[1..%d]:\n", n);
    for (int i = 0; i < n; i++) {
        if ((*(book + i)) != NULL)
            printf("%d --> %s\n", i + 1, *(book + i));
    }
    printf("\n");
    return;
}

int main() {
    char **book;
    char c;
    int n, k;
    int from, to;
    
    while((c = getchar()) != 'f') {
        switch(c) {
            case 'b': // b n --> newBook(n)
                scanf("%d", &n);
                if (n < 0)
                    printf("Numero inserito non valido.\n");
                else
                    newBook(&book, n);
                break;
            case '+': // + k name --> book(k, name)
                char *name;
                scanf("%d %s", &k, name);
                if (k > 0 && k <= n)
                    book_f(book, k - 1, name);
                else
                    printf("Inserire un numero compreso tre 1 e %d.\n", n);
                break;
            case '-': // - k --> cancel(k)
                scanf("%d", &k);
                if (k > 0 && k <= n)
                    cancel(book, k - 1);
                else
                    printf("Inserire un numero compreso tre 1 e %d.\n", n);
                break;
            case 'm': // m from to ---> move from to
                scanf("%d %d", &from, &to);
                if (from <= 0 || from > n)
                    printf("Registro sorgente non valido.\n");
                else if (to <= 0 || to > n)
                    printf("Registro destinazione non valido.\n");
                else
                    move(book, from - 1, to - 1);
                break;
            case 'p': // p ---> printBook()
                printBook(book, n);
                break;
        }
    }

    return 0;
}