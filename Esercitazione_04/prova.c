#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s[] = argv[1];
    char c = s[0];
    for (int i = 0; c != '\0'; i++){
        c = s[i];
        printf("%c", c);
    }
    return 0;
}