#include <stdio.h>
#include <string.h>
#define true 1
#define false 0
#include <stdbool.h>

bool isPalindrome(char *s) {
    char *sx = s, *dx = s + strlen(s) - 1;

    while(sx++ < dx--)
        if (*sx != *dx)
            return false;
    
    return true;
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if(isPalindrome(argv[i]))
            printf("La parola %s è palindroma\n", argv[i]);
        else
            printf("La parola %s non è palindroma\n", argv[i]);
    }
    return 0;
}
