#include "my_arr.h"

//variable that stores the current size of the array
static unsigned int size_arr;

/*
 * This function adds a value to the end of the array
 * 
 * @param the address of the array and the value to be written (value of type int)
 * @return returns the address of the new array to which the data was added
 */
int* ar_push(int* p_arr, int value){
	// check the pointer to NULL
	// if it is NULL then create an array
    if(p_arr == NULL){
        size_arr = 1;
        p_arr = (int*)malloc( sizeof(int) );
        p_arr[0] = value;
        return p_arr;
    }
	// if the pointer is not NULL means we allocate
	// new memory for 1 element more, copy the data from the transferred array there and add the transferred value to the end
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

/*
 * This function prints all elements of the array
 * 
 * @param the address of the array
 */
void ar_print_all(const int* p_arr){
	
	// if array empty
    if(!size_arr){
       printf("%s \r\n", "array empty!!!"); 
    }
    else{
        for( int i = 0; i < size_arr; i++){
            printf("%d \r\n", p_arr[i]);
        }
    }
}

/*
 * This function to find a value in an array
 * 
 * @param array address and value to find (integer value)
 * @return returns -2 if the pointer is NULL, -1 if the specified value is not in the array or the index of the element that stores the desired value.
 */
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

/*
 * This function to remove the specified array element
 * 
 * @param array address and the index of the array to be deleted (integer value)
 * @return returns the address of the new array with the element removed
 */
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