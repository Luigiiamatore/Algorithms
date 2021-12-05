#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define L0 5

// deve leggere una riga terminata dal carattere c
char *read_line(char c) {
    char *line;
    char read;
    int i = 0, size = L0;
    
    line = malloc(size + 1);
    if (line == NULL) {
        printf("Memoria esaurita!");
        exit(EXIT_FAILURE);
    }

    while(1) {
        scanf("%c", &read);

        if (read == c)
            return line;
        if (i >= size) {
            size *= 2;
            line = realloc(line, size + 1);
        }
        
        line[i++] = read;
    }
}

// deve leggere una parola di caratteri alfanumerici
// (la lettura deve interrompersi al primo carattere
// non alfanumerico; se il primo carattere letto non 
// è alfanumerico, la stringa restituita sarà la stringa vuota)
char *read_word(void) {
    char *word;
    char read;
    int i = 0, size = L0;

    word = malloc(size + 1);
    if (word == NULL) {
        printf("Memoria esaurita!");
        exit(EXIT_FAILURE);
    }

    while(1) {
        scanf("%c", &read);

        if (!isalnum(read))
            return word;
        if (i >= size) {
            size *= 2;
            word = realloc(word, size + 1);
        }

        word[i++] = read;
    }
}

