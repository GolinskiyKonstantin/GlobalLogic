
#ifndef _LINKED_LIST_LIB_H
#define _LINKED_LIST_LIB_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;


void list_add( Node **head, int data );
int list_contains( Node *head, int data);
void list_remove( Node **head );
void list_print_all(Node *head);

#ifdef __cplusplus
}
#endif

#endif	/*	_LINKED_LIST_LIB_H */