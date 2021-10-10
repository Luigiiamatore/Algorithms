#include <stdio.h>

int main(void){
    char ch;
    int parentesi_aperte = 0, parentesi_chiuse = 0;
    int char_letti = 0;
    for(;;){
        ch = getchar();

        if(ch == '.')
            break;
        
        char_letti++;
        if(ch == '(')
            parentesi_aperte++;
        else if(ch == ')')
            parentesi_chiuse++;
        
        if(parentesi_aperte < parentesi_chiuse) {
            printf("La stringa non è un'espressione ben parentesizzata.");
            printf("\nCarattere %d: troppe parentesi chiuse!", char_letti);
            return 0;
        }
    }
    if(parentesi_aperte > parentesi_chiuse){
        printf("La stringa non è un'espressione ben parentesizzata.");
        printf("\nCarattere %d: mancano parentesi chiuse alla fine!", char_letti);
        return 0;
    }
    
    printf("La stringa è un'espressione ben parentesizzata.");
    printf("%d\n%d", parentesi_aperte, parentesi_chiuse);
    return 0;
}