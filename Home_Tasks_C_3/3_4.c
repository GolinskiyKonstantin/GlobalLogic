#include <stdio.h>
#include <stdlib.h>


int* map(int* arr, unsigned int arr_size, void (*p_fun)(int* value) ){
    for( unsigned int i = 0; i < arr_size; i++){
        p_fun( arr + i );
    }
    
    int* array_new = (int*)malloc( arr_size * 2 * sizeof(int) );
    if( array_new == NULL ){ exit(1); }
    
    for( unsigned int i = 0; i < arr_size*2; i++){
        array_new[i] = arr[i];
    }
    
    return array_new;
}

void fun_user_one( int* value ){
    *value = 1;
}

void fun_user_two( int* value ){
    *value = 2;
}

int main()
{
    int* array = (int*)malloc( 10 * sizeof(int) );
    if( array == NULL ){ exit(1); }
    
    int* new_arr = map( array, 10, fun_user_one );
    
    for( unsigned int i = 0; i < 10; i++){
       printf("%d \r\n", array[i]);
    }
    
    map( new_arr, 20, fun_user_two );
    
    for( unsigned int i = 0; i < 20; i++){
       printf("%d \r\n", new_arr[i]);
    }
    
    free(new_arr);
    
    return 0;
}
