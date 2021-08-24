#include <stdlib.h>
#include <stdio.h>
#include "linked_list_lib.h"

int main()
{
    Node *head = NULL;
    
    for( int i = 2; i < 10; i++ ){
        list_add( &head, i );
    }

    list_print_all( head );
    
    for( int j = 0; j < 11; j++ ){
        printf("list %d \r\n", list_contains( head, j ) );
    }
    
    return 0;
}