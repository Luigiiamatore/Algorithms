#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BIST/item.h"
#include "BIST/binary_search_tree.h"

#define WORD 20

int main() {
    Bist_node root = NULL;

    while(1) {
        int i = 0, counter = 0;
        char *word , ch;
        word = malloc((WORD + 1) * sizeof(char));

        ch = getchar();
        while(ch != ' ' && ch != '\n') {
            if (counter >= WORD) {
                printf("Inserita una parola troppo lunga\n");
                exit(EXIT_FAILURE);
            }
            if(!ispunct(ch))
                word[i++] = tolower(ch);
            counter++;
            ch = getchar();
        }
        word[i++] = '\0';

        if(strcmp(word, "stop") == 0) break;

        Item item = {word, 1};
        Bist_node find = bist_find(root, item);
        if (find == NULL)
            root = bist_insert(root, item);
        else
            find->info.occ++;
    }
    printf("OCCORRENZE DI PAROLE NEL TESTO IN ORDINE ALFABETICO\n***************************************************\n");
    bist_inorder(root);
    printf("\nOCCORRENZE DI PAROLE NEL TESTO IN ORDINE INVERSO\n************************************************\n");
    bist_revorder(root);
    bist_delete(&root);
    return 0;
}