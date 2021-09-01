#include "queue_fifo.h"

int arr[50];
unsigned int arr_current_cursor = 0;

/*
 * This function enqueues the value
 * 
 * @param the value we queue
 * @return returns 1 if the value was queued or 0 if the queue is full
 */
int enqueue(int value){
    if( arr_current_cursor < (sizeof(arr)/sizeof(int)) ){
        arr[arr_current_cursor] = value;
        arr_current_cursor++;
        return 1;
    }
    else{
        return 0;
    }
}

/*
 * This function that retrieves a value from a queue
 * 
 * @param the address of the variable where the value will be retrieved
 * @return returns 1 if the value was popped from the queue, or 0 if the queue is empty
 */
int dequeue(int* value){
    if( arr_current_cursor > 0 ){
        *value = arr[0];
        
        for( int i = 0; i < (arr_current_cursor-1); i++ ){
            arr[i] = arr[i+1];
        }
        
        arr_current_cursor--;
        return 1;
    }
    else{
        return 0;
    }
}

