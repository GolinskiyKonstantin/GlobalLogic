#include "linked_list_lib.h"


void list_add( Node **head, int data ){
    
    if((*head) == NULL){
            *head = (Node*)malloc(sizeof(Node));
            if((*head) == NULL) {
                exit(-1);
            }
            (*head)->value = data;
            (*head)->next = NULL;  
    }
    else {
            Node *node = *head;
            while(node->next != NULL) {
                    node = node->next;
            }
            node->next = (Node*)malloc(sizeof(Node));
            if(node->next == NULL) {
                    exit(-1);
            }
            node->next->next = NULL;
            node->next->value = data;
    }
}

int list_contains( Node *head, int data){
    if(head == NULL) {
       exit(-1);
    }
    do {
        if(head->value == data) {
            return 1;
        }
        head = head->next;
    } while(head->next != NULL);
   
    return 0;
}

void list_remove( Node **head ){
    Node* prev = NULL;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
}

void list_print_all(Node *head)
{
        while(head != NULL) {
            printf("value = %d \r\n", head->value);
            head = head->next;
        }
}