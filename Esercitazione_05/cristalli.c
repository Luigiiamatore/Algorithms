#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// restituisce il lato di un cristallo dato il tempo t
int latoCristallo (int t) {
    return pow(2, t+1) - 1;
}

// crea la matrice di char n x n
char **creaMatrice (int n) {
    char **m;

    // alloco il puntatore alle stringhe
    m = malloc(n * sizeof(char *));
    if (m == NULL) {
        printf("Errore nella fase di allocazione.");
        exit(1);
    }

    //alloco le varie stringhe
    for(int i = 0; i < n; i++) {
        *(m + i) = malloc(n * sizeof(int));
        if (*(m + i) == NULL) {
            printf("Errore nella fase di allocazione.");
        exit(1);
        }
    }

    // setto la matrice son soli '.'
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            *(*(m + i) + j) = '.';
        }
    return m;
}

// funzione ricorsiva che imposta la sotto matrice data la lunghezza di essa e gli indici di riga e colonna riferiti alla matrice cristallo
void crist (char **m, int r0, int c0, int l) {
    // caso base
    if (l == 1)
        *(*(m + r0) + c0) = '*';
    else {
        // setto il centro
        *(*(m + l/2 + r0) + (l/2) + c0) = '*';
        // creo le quattro sottomatrici ai vertici del quadrato centrale
        crist(m, r0, c0, l/2);
        crist(m, r0, c0 + (l/2) + 1, l/2);
        crist(m, r0 + (l/2) + 1, c0, l/2);
        crist(m, r0 + (l/2) + 1, c0 + (l/2) + 1, l/2);
    }
    return;
}

// funzione che con l'ausilio di crist(...) crea un cristallo di lato l
void cristallo(char **m, int l) {
    crist(m, 0, 0, l);
    return;
}

// stampa di una matrice n x n
void stampaMatrice (char **m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c ", *(*(m + i) + j));
        printf("\n");
    }
    return;
}

void free_m(char **m, int l) {
    for (int i = 0; i < l; i++)
        free(*(m + i));
    free(m);
}

int main() {
    char **matrix;
    int t, lato;
    printf("Inserisci t = ");
    scanf("%d", &t);
    if (t >= 0) {
        lato = latoCristallo(t);
        matrix = creaMatrice(lato);
        cristallo(matrix, lato);
        printf("\n");
        stampaMatrice(matrix, lato);
    }
    free_m(matrix, lato);
    return 0;
}