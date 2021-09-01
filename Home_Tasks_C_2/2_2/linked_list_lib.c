#include "linked_list_lib.h"

/*
 * This the function creates 1 list item
 * 
 * @param the address of a pointer of type Node, and the value itself that we want to write (value of type int)
 */
void list_add( Node **head, int data ){
    // check null pointer ( to create the first item in the list )
    if((*head) == NULL){
			// allocate memory of the size of Node, and assign the pointer to the area of ​​allocated memory
            *head = (Node*)malloc(sizeof(Node));
			// check if memory has been allocated or not
            if((*head) == NULL) {
                exit(-1);
            }
            (*head)->value = data;
            (*head)->next = NULL;  
    }
	// if we create not the first element then
    else {
            Node *node = *head;
            while(node->next != NULL) {
                    node = node->next;
            }
			// allocate memory of the size of Node, and assign the pointer to the area of ​​allocated memory
            node->next = (Node*)malloc(sizeof(Node));
            if(node->next == NULL) {
                    exit(-1);
            }
            node->next->next = NULL;
            node->next->value = data;
    }
}

/*
 * This function shows whether the list contains the specified value
 * 
 * @param the list address of type Node, and the value itself that we want to write (value of type int)
 * @return if the specified value is present in the list, then we return 1, else 0
 */
int list_contains( Node *head, int data){
    if(head == NULL) {
       exit(-1);
    }
    do {
		// if the specified value is present in the list, then we return 1
        if(head->value == data) {
            return 1;
        }
        head = head->next;
    } while(head->next != NULL);
    // if the specified value is not in the list then return 0
    return 0;
}

/*
 * This function removes the last element of the list
 * 
 * @param the address of a pointer of type Node
 */
void list_remove( Node **head ){
    Node* prev = NULL;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
}

/*
 * This function prints all the values ​​stored in the list
 * 
 * @param the list address of type Node
 */
void list_print_all(Node *head)
{
        while(head != NULL) {
            printf("value = %d \r\n", head->value);
            head = head->next;
        }
}