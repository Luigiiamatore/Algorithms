#include <stdio.h>

typedef struct{
    int giorno, mese, anno;
}Data;

int main() {
    Data dates[100];
    Data max;
    int g, m, a;
    int len;
    char flush;

    printf("Inserite un massimo di 100 date nel formato dd/mm/yyyy:\n");
    for(len = 0; len < 100; len++) {
        scanf("%d/%d/%d", &g, &m, &a);
        if(g == 0 && m == 0 && a == 0) {
            len--;
            break;
        }
        dates[len].giorno = g;
        dates[len].mese = m;
        dates[len].anno = a;
        //scanf("%c", &flush);
    }

    printf("Inserire data limite: ");
    scanf("%d/%d/%d", &max.giorno, &max.mese, &max.anno);

    printf("\nDate precedenti a %02d/%02d/%04d:\n", max.giorno, max.mese, max.anno);
    for(int i = 0; i <= len; i++) {
        if(dates[i].anno < max.anno || (dates[i].anno == max.anno && dates[i].mese < max.mese) || (dates[i].anno == max.anno && dates[i].mese == max.mese && dates[i].giorno < max.giorno)) {
            printf("%02d/%02d/%04d\n", dates[i].giorno, dates[i].mese, dates[i].anno);
        }  
    }
}