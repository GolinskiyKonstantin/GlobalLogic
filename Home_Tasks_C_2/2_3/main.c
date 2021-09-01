#include <stdlib.h>
#include <stdio.h>
#include "my_arr.h"


int main()
{	
	// create a pointer for array
    int* my_arr;
	
	// fill the array with values
    my_arr = ar_push( my_arr, 2 );
    my_arr = ar_push( my_arr, 5 );
    my_arr = ar_push( my_arr, 6 );
    
	// print all the values ​​of the array
    ar_print_all( my_arr );
    
	// looking for the number 8 in the array
    printf("%d \r\n", ar_find_first(my_arr, 8 ) );
    
	// remove the value with index 1 from the array
    my_arr = ar_remove(my_arr, 1);
    
	// print all the values ​​of the array
    ar_print_all( my_arr );
    
    return 0;
}
