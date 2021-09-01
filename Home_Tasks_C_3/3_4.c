#include <stdio.h>
#include <stdlib.h>

/*
 * This function that receives an array of elements, its size and a function that will be applied individually to each element of the array, can also change the existing array or return a new one.
 * 
 * @param address for an array of elements, its size and address for a function that will be applied individually to each element of the array
 * @return returns an existing array or a new one.
 */
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

// the function assigns the value to the passed parameter 1
void fun_user_one( int* value ){
    *value = 1;
}

// the function assigns the value to the passed parameter 2
void fun_user_two( int* value ){
    *value = 2;
}

int main()
{
	// create an array of 10 int type elements
    int* array = (int*)malloc( 10 * sizeof(int) );
    if( array == NULL ){ exit(1); }
    
	// call the map function, pass the previously created array, its size and the address of the 
	// function that will change the value of the passed array, the function will return the address to the new array
    int* new_arr = map( array, 10, fun_user_one );
    
	// we print data from an array
    for( unsigned int i = 0; i < 10; i++){
       printf("%d \r\n", array[i]);
    }
    
	// we repeat the same actions only with other parameters
    map( new_arr, 20, fun_user_two );
    
    for( unsigned int i = 0; i < 20; i++){
       printf("%d \r\n", new_arr[i]);
    }
    
    free(new_arr);
    
    return 0;
}
