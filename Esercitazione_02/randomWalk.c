#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

typedef int Bool;

void initGrid(char grid[DIM][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            grid[i][j] = '.';
        }
    }
}

void resetUsed(Bool used[DIM + 2][DIM + 2]) {
    for (int i = 0; i < DIM + 2; i++) {
        for (int j = 0; j < DIM + 2; j++) {
            if (i == 0 || j == 0 || i == DIM + 1 || j == DIM + 1)
                used[i][j] = 1;
            else
                used[i][j] = 0;
        }
    }
}

void printGrid(char grid[DIM][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char grid[DIM][DIM];
    Bool used[DIM + 2][DIM + 2];
    int x, y;
    int move;
    char letter;

    initGrid(grid);
    resetUsed(used);

    letter = 'A';
    x = 0;
    y = 0;
    grid[x][y] = letter;
    used[x + 1][y + 1] = 1;

    for (;;) {
        if (letter == 'Z')
            break;
        move = rand() % 4;

        if (x == 0 && move == 0)                 // Sono nella riga più in alto
            continue;
        else if (x == DIM - 1 && move == 2)      // Sono nella riga più in basso
            continue;
        else if (y == 0 && move == 3)            // Sono nella colonna più a sinistra
            continue;
        else if (y == DIM - 1 && move == 1)      // Sono nella colonna più a destra
            continue;
        else {
            if (used[x][y + 1] == 1 && used[x + 1][y + 2] == 1 && used[x + 2][y + 1] == 1 && used[x + 1][y] == 1)
                break;

            letter++;

            switch(move) {
                case 0:
                    x--;
                    break;
                case 1:
                    y++;
                    break;
                case 2:
                    x++;
                    break;
                case 3:
                    y--;
            }
            if (used[x + 1][y + 1] == 1) {
                switch(move) {
                    case 0:
                        x++;
                        break;
                    case 1:
                        y--;
                        break;
                    case 2:
                        x--;
                        break;
                    case 3:
                        y++;
                }
                letter--;
                continue;
            }
            grid[x][y] = letter;
            used[x + 1][y + 1] = 1;
        }
    }
    printGrid(grid);
    return 0;
}