#include "queue_fifo.h"

int arr[50];
unsigned int arr_current_cursor = 0;

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

