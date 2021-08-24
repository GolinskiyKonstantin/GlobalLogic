#include <stdlib.h>
#include <stdio.h>
#include "my_arr.h"


int main()
{
    int* my_arr;

    my_arr = ar_push( my_arr, 2 );
    my_arr = ar_push( my_arr, 5 );
    my_arr = ar_push( my_arr, 6 );
    
    ar_print_all( my_arr );
    
    printf("%d \r\n", ar_find_first(my_arr, 8 ) );
    
    my_arr = ar_remove(my_arr, 1);
    
    ar_print_all( my_arr );
    
    return 0;
}
