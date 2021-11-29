#include <stdio.h>

/*void hanoi(int n, int from, int temp, int to) {
    if (n == 1)
        printf("%d -> %d\n", from, to);
    else if (n > 1) {
        hanoi(n-1, from, to, temp);
        printf("%d -> %d\n", from, to);
        hanoi(n-1, temp, from, to);
    }
}*/

int hanoi(int n, int from, int temp, int to, int moves) {
    if (n == 1)
        moves++;
    else if (n > 1) {
        moves = hanoi(n-1, from, to, temp, moves);
        moves++;
        moves = hanoi(n-1, temp, from, to, moves);
    }
    return moves;
}

int main() {
    int n, moves = 0;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    moves = hanoi(n, 0, 1, 2, moves);
    printf("Mosse = %d", moves);
    return 0;
}