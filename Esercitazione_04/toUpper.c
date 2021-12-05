#include <stdio.h>
#include <ctype.h>

char *maiuscolo(char *stringa) {
    for (char *inizio = stringa; *inizio != 0; inizio++)
        *inizio = toupper(*inizio);
    return stringa;
}

int main() {
    char stringa[BUFSIZ];
    char read;
    int i = 0;
    while ( ( read = getchar() ) != '\n') {
        stringa[i] = read;
        i++;
    }
    stringa[i] = '\0';

    printf("%s\n", maiuscolo(stringa));
    return 0;
}