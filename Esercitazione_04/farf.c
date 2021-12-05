#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define true 1
#define false 0

bool isVowel(char letter) {
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
        return true;
    else return false;
}

void farf(char *word, int n) {
    for (int i = 0; i < n; i++) {
        if (isVowel(word[i]))
            printf("%cf%c", word[i], word[i]);
        else
            printf("%c", word[i]);
    }
    return;
}

int main(int argc, char *argv[]) {
    farf(*(argv + 1), strlen(*(argv + 1)));
    return 0;
}