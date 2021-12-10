#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node * Node;

Node olist_insert (int n, Node l) {
    Node curr = l, prev = NULL;
    for (; curr != NULL && n > curr->info;prev = curr, curr = curr -> next);
    Node new;
    new = malloc(sizeof(struct node));
    new -> info = n;
    new -> next = curr;
    if (prev == NULL) 
        l = new;
    else
        prev -> next = new;
    return l;
}

Node olist_search (int n, Node l) {
    while(l != NULL && l->info < n)
        l = l->next;
    if (l != NULL && l->info == n)
        return l;
    else
        return NULL;
}

void list_delete (int n, struct node **l) {
    struct node *curr = *l, *prev = NULL;
    for (; curr != NULL && curr -> info != n;) {
        prev = curr;
        curr = curr -> next;
    }
    if (curr == NULL)           // non trovato nella lista
        return;
    if (prev == NULL)           // lista vuota
        *l = curr -> next;
    else                        // trovato
        prev -> next = curr -> next;
    free(curr);
}

void print_list(struct node *l) {
    printf("\n");
    while (l != NULL) {
        printf("info: %d\n", l -> info);
        l = l -> next;
    }
}

void list_destroy(Node l) {
    while(l != NULL) {
        Node next = l->next;
        free(l);
        l = next;
    }
}

int number_of_elements(Node l) {
    int num = 0;
    while(l != NULL) {
        num++;
        l = l->next;
    }
    return num;
}

int main() {
    Node N = NULL;
    char c;
    while((c = getchar()) != 'f') {
        int n;
        switch(c) {
            case '+':
                scanf("%d", &n);
                if (olist_search(n, N) == NULL)
                    N = olist_insert(n, N);
                break;
            case '-':
                scanf("%d", &n);
                list_delete(n, &N);
                break;
            case '?':
                scanf("%d", &n);
                if (olist_search(n, N) != NULL)
                    printf("Il numero %d appartiene all'insieme.\n", n);
                else
                    printf("Il numero %d non appartiene all'insieme.\n", n);
                break;
            case 'c':
                printf("La cardinalità dell'insieme è: %d\n", number_of_elements(N));
                break;
            case 'p':
                print_list(N);
                break;
            case 'd':
                list_destroy(N);
                N = NULL;
                break;
            default:
        }
    }
    return 0;
}