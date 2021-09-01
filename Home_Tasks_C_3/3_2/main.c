#include <stdlib.h>
#include <stdio.h>
#include "stack_lib.h"

int main()
{
    // fill the stack with values
    push(1);
    push(2);
    push(5);
    push(7);
    
    int val_1, val_2, val_3;
    
	// get the values ​​from the stack and check (got the value or the stack is empty)
    if( pop(&val_1) ){
       printf("pop = %d\r\n", val_1 ); 
    }
    
	// get the values ​​from the stack and check (got the value or the stack is empty)
    if( pop(&val_2) ){
       printf("pop = %d\r\n", val_2 ); 
    }
    
	// get the values ​​from the stack and check (got the value or the stack is empty)
    if( pop(&val_3) ){
       printf("pop = %d\r\n", val_3 ); 
    }
    
    return 0;
}