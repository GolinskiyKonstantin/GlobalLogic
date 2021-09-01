#include "stack_lib.h"

// create a pointer to a list of type Node
Node *head = NULL;

// stack size
unsigned int size_stack = 0;

/*
 * This function adds a value to the stack
 * 
 * @param value to add
 */
void push(int value){
    list_add(&head, value);
    size_stack++;
}

/*
 * This function gets a value from the stack
 * 
 * @param the address of the variable where the value will fit
 * @return will return 1 if the data was received, or 0 if the stack is empty
 */
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

