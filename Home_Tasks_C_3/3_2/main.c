#include <stdlib.h>
#include <stdio.h>
#include "stack_lib.h"

int main()
{
    
    push(1);
    push(2);
    push(5);
    push(7);
    
    int val_1, val_2, val_3;
    
    if( pop(&val_1) ){
       printf("pop = %d\r\n", val_1 ); 
    }
    
    if( pop(&val_2) ){
       printf("pop = %d\r\n", val_2 ); 
    }
    
    if( pop(&val_3) ){
       printf("pop = %d\r\n", val_3 ); 
    }
    
    return 0;
}