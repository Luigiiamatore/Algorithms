#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Bool;

int main() {
    srand(time(NULL));
    char matrix[10][10];
    Bool used[10][10];
    int x, y;
    int dir;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            matrix[i][j] = '.';
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            used[i][j] = 0;
        }
    }

    for(;;){
        if(used[0][0] == 0) {
            matrix[0][0] = 'A';
            used[0][0] = 1;
            x = 0; y = 0;
        } else {
            dir = rand() % 4;
            switch (dir) {
                case 0:
                    
                    break;
            
                default:
                    break;
            }
        }
    }


    return 0;
}