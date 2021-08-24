#include "stack_lib.h"


Node *head = NULL;

unsigned int size_stack = 0;

void push(int value){
    list_add(&head, value);
    size_stack++;
}

int pop(int* value){
    
    Node *head_pop = head;
    
    if(size_stack != 0){
        int num_el = size_stack-1;
        while( num_el-- ){
                head_pop = head_pop->next;
        }
        size_stack--;
        *value = head_pop->value;
        list_remove(&head_pop);
        return 1;
    }
    else{
        return 0;
    }
}

