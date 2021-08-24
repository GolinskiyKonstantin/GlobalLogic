#include "my_arr.h"

static unsigned int size_arr;

int* ar_push(int* p_arr, int value){
    if(p_arr == NULL){
        size_arr = 1;
        p_arr = (int*)malloc( sizeof(int) );
        p_arr[0] = value;
        return p_arr;
    }
    else{
        int* p_arr_new = (int*)malloc( (size_arr + 1) * sizeof(int) );
        if(p_arr_new == NULL) {
            exit(-1);
        }
        else{
            int i;
            for( i = 0; i < size_arr; i++){
                p_arr_new[i]=p_arr[i];
            }
            p_arr_new[i]=value;
            size_arr++;
            free(p_arr);
            return p_arr_new;
        }
    }
}


void ar_print_all(const int* p_arr){
    if(!size_arr){
       printf("%s \r\n", "array empty!!!"); 
    }
    else{
        for( int i = 0; i < size_arr; i++){
            printf("%d \r\n", p_arr[i]);
        }
    }
}


int ar_find_first(const int* p_arr, int value){
    if(p_arr == NULL){
        return -2;
    }
    else{
        for( int i = 0; i < size_arr; i++){
            if(p_arr[i] == value){
                return i;
            } 
        } 
        return -1;
    }
    
}

int* ar_remove(int* p_arr, int index){
    if( p_arr == NULL ){
        printf("%s \r\n", "Error pointer!!!" );
    }
    else if( index > ( size_arr-1) ){
        printf("%s \r\n", "Error index!!!" );
    }
    else{
       int* p_arr_new = (int*)malloc( (size_arr - 1) * sizeof(int) );
        if(p_arr_new == NULL) {
            exit(-1);
        }
        else{ 
            for( int i = 0; i < size_arr; i++){
                if( i < index){
                    p_arr_new[i]=p_arr[i];
                }
                else{
                    p_arr_new[i]=p_arr[i+1];
                }
            }
            size_arr--;
            free(p_arr);
            return p_arr_new;
        }
    }
}