#ifndef STACK_H
#define STACK_H
#include "item.h"

// svuota la pila 
void make_empty();

// restituisce 1 se la pila è vuota, 0 altrimenti
int is_empty();

/* se la pila non è vuota restituisce il top della pila;
altrimenti esce con messaggio di errore */
Item top();

/* se la pila non è vuota, estrae il top dalla pila;
altrimenti esce con messaggio di errore */
Item pop();

/* se c'è spazio, aggiunge n alla pila;
altrimenti esce con messaggio di errore */
void push(Item item);

// stampa il contenuto della pila, partendo dal top
void print_stack();

#endif