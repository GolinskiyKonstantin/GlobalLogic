#include <stdlib.h>
#include <stdio.h>
#include "linked_list_lib.h"

int main()
{
	// create a pointer to our list
    Node *head = NULL;
    
	// in a loop fill our list with values ​​from 2 to 9 inclusive
    for( int i = 2; i < 10; i++ ){
        list_add( &head, i );
    }
	
	// print the entire list
    list_print_all( head );
    
	// check if the list contains a value between 0 and 10 inclusive
    for( int j = 0; j < 11; j++ ){
        printf("list %d \r\n", list_contains( head, j ) );
    }
    
    return 0;
}