#include <stdio.h>
#define DIM 100

void printGrid(char grid[DIM][DIM], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void schiacciatina(char grid[DIM][DIM], int r, int c) {
    for  (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != '*') {
                for (int k = i + 1; k < r; k++) {
                    if (grid[k][j] == '*') {
                        int tmp = grid[i][j];
                        grid[i][j] = grid[k][j];
                        if (k == i + 1) {
                            grid[k][j] = tmp;
                        } else {
                            for (int m = i + 1; m <= k; m++) {
                                if (m == k)
                                    grid[m][j] = tmp;
                                else {
                                    int tmp2 = grid[m][j];
                                    grid[m][j] = tmp;
                                    tmp = tmp2;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    int r, c;
    char grid[DIM][DIM];

    printf("r: ");
    scanf("%d", &r);
    printf("c: ");
    scanf("%d", &c);
    getchar();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%c", &grid[i][j]);
            getchar();
        }
    }
    printf("\n");
    schiacciatina(grid, r, c);
    printGrid(grid, r, c);
    return 0;
}