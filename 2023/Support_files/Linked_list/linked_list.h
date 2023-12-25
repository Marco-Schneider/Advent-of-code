#ifndef _linked_list_h_
#define _linked_list_h_

#include <stdio.h>
#include <stdlib.h>

#define ERROR -INT_MAX
#define TRUE 1
#define FALSE 0

typedef struct node { 
    char data;
    struct node *next;
} Node, List;

List* create();
void print_list(List *l);
void destroy(List *l);
List* insert_back(List *l, char k);
List* removek(List *l, char k);

#endif