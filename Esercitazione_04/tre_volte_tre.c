#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 100

void treVolte (char *a[], int n) {
    char **p, *q;
    int conta = 0;
    int conta_e;

    for (p = a; p < a + n; p++) {
        char *c;
        conta_e = 0;
        c = *p;
        while (*c) {
            if (*c == 'e') {
                //printf("ciucciacazzi");
                conta_e++;
            }
            if (conta_e == 3) {
                conta++;
                break;
            }
            c++;
        }
        //printf("%d", conta);
        if (conta == 3) {
            strcpy (q, *p);                             // strcpy(q, p) non va bene, *p è una stringa, p è un puntatore a stringa
            strcpy (*p, a[0]);                          // come sopra
            strcpy (a[0], q);
            return;
        }
    }
}

int main ( int argc , char ** argv ) {
    treVolte (argv + 1, argc - 1);

    for (char** p = argv + 1; p < argv + argc; p++)     //p partiva da argv, ma argv punta al nome dell'eseguibile
        printf ("%s ", *p);
    printf ("\n");
    return 0;
}
