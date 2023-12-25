#include "linked_list.h"

/*
    Creates a empty linked list
*/
List* create() {
    return NULL;
}

/*
    Inserts a given k key into a linked list l
*/
List* insert_back(List *l, char k) {
    if (l == NULL) {
        l = (Node*)malloc(sizeof(Node));
        l->data = k;
        l->next = NULL;
    }
    else {
        l->next = insert_back (l->next, k);
    }
    return l;
}

/* 
    Removes a given k key from a linked list
*/
List* removek(List *l, char k) {
    if(l == NULL) {
        return NULL;
    }
    else if(l->data == k) {
        List *temp = l;
        l = l->next;
        free(temp);
    }
    else {
        l->next = removek(l->next, k);
    }
    return l;
}

/* 
    Receives the pointer to the head of a linked list
    and prints its content to the user
*/
void print_list(List* l) {
    if (l != NULL) {
        printf("%d ", l->data);
        print_list(l->next);      
    }
}

/* 
    Destroys the created list, 
    returning the memory that was allocated
*/
void destroy(List *l) {
    if(l != NULL) {
        destroy(l->next);
        free(l);
    }	
}