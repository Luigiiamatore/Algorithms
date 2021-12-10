#include <stdio.h>
#include <stdlib.h>
#include "pila/stack_array.c"

int main() {
    char token[10], new_line;
    make_empty();
    while(1) {
        scanf("%s", token);
        new_line = getchar();
        switch (token[0]) {
        Item n, x, y;
        case '+':
            y = pop();
            x = pop();
            push(x + y);
            break;
        case '-':
            y = pop();
            x = pop();
            push(x - y);
            break;
        case '*':
            y = pop();
            x = pop();
            push(x * y);
            break;
        case '/':
            y = pop();
            x = pop();
            push(x / y);
            break;
        default:
            n = atoi(token);
            push(n);
        break;
        }
        if (new_line == '\n')
            break;
    }
    printf("Risultato: ");
    print_item(top());
    printf("\n");

    make_empty();

    return 0;
}