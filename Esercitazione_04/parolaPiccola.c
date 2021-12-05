#include <stdio.h>
#include <string.h>
#define MAX 100

typedef char * String;

int smallest_word_index(String s[], int n) {
    char min[MAX];
    int pos = 0;
    strcpy(min, *s);

    for(String *i = s + 1; i < s + n; i++) {
        if (strcmp(*i, min) < 0) {
            strcpy(min, *i);
            pos = i - s;
        }
    }

    return pos;
}

int main() {
    String dict[] = {"ciao", "b", "a", "funziona", "bene", "il", "programma"};
    int lun = 7, pos;
    pos = smallest_word_index(dict, lun);
    printf("pos = %d", pos);
    return 0;
}

/*int smallest_word_index (char *s[], int n) {
    char min[strlen(*s)];
    int pos = 0;
    strcpy(min, *s);

    for (char **i = s + 1; i < s + n; i++) {
        if (strcmp(*i, min) < 0) {
            strcpy(min, *i);
            pos = i - s;
        }
    }

    return pos;
}

int main() {
    char *dict[] = {"ciao", "mondo", "come", "funziona", "bene", "il", "programma"};
    int lun = 7, pos;
    pos = smallest_word_index(dict, lun);
    printf("pos = %d", pos);
    return 0;
}*/