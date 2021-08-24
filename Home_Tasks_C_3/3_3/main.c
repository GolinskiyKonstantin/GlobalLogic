#include <stdio.h>
#include "queue_fifo.h"


int main()
{
    // ====== SAVE ================================= //
    if( enqueue( 5 ) ){
        printf("Save OK \r\n");
    }
    else{
        printf("Save Error \r\n");
    }
    
    if( enqueue( 8 ) ){
        printf("Save OK \r\n");
    }
    else{
        printf("Save Error \r\n");
    }
    
    if( enqueue( 10 ) ){
        printf("Save OK \r\n");
    }
    else{
        printf("Save Error \r\n");
    }
    
    // ====== READ ================================= //
    int val_1;
    if( dequeue( &val_1 ) ){
        printf("Read OK, val = %d \r\n", val_1);
    }
    else{
        printf("Read Error \r\n");
    }
    
    int val_2;
    if( dequeue( &val_2 ) ){
        printf("Read OK, val = %d \r\n", val_2);
    }
    else{
        printf("Read Error \r\n");
    }
    
    int val_3;
    if( dequeue( &val_3 ) ){
        printf("Read OK, val = %d \r\n", val_3);
    }
    else{
        printf("Read Error \r\n");
    }
    
    return 0;
}
