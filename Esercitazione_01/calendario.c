#include <stdio.h>

int main(void) {
    int mese, giorno;
    printf("Inserisci il numero del mese (1 = gennaio, ..., 12 = dicembre): ");
    scanf("%d", &mese);
    printf("Inserisci il giorno di inizio mese (1 = lunedì, ..., 7 = domenica): ");
    scanf("%d", &giorno);

    giorno--;
    int ultimoGiorno;

    switch(mese) {
        case 2:
            ultimoGiorno = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            ultimoGiorno = 30;
            break;
        default:
            ultimoGiorno = 31;
    }

    int cal[5][7];
    int contatore = 1;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 7; j++) {
            if(i == 0 && j < giorno)
                cal[i][j] = 0;
            else if(contatore <= ultimoGiorno){
                cal[i][j] = contatore;
                contatore++;
            }
            else
                cal[i][j] = 0;
        }
    }

    printf(" L   M   M   G   V   S   D\n ");
    for(int i = 0; i < 5; i ++) {
        for(int j = 0; j < 7; j++) {
            if(cal[i][j] == 0)
                printf(" ");
            else
                printf("%d", cal[i][j]);
            
            if(cal[i][j] >= 10){
                printf("  ");
            } else {
                printf("   ");
            }
        }
        printf("\n ");
    }
    return 0;
}