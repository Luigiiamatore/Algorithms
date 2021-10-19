#include <stdio.h>

int main() {
    int r, c;
    char ch;

    printf("r: ");
    scanf("%d", &r);
    getchar();  
    printf("c: ");
    scanf("%d", &c);
    getchar();

    char grid[r][c];

    for (int i = 0; i < r; i++) {
        while (ch = getchar() != '\n') {
            
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            /*if (grid[i][j] != '*') {
                
            }*/
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}