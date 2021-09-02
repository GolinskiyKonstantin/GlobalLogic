#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*
 * This function copies the passed string to a new one and returns the address of the new string
 * 
 * @param string address
 * @return returns the address of the new string ( or NULL if no memory for the new line has been allocated )
 */
char* str_cpy(char* st){
	// check if the given pointer contains an address
    if( st != NULL){
        
		// count the length of the transmitted string
        unsigned int str_len = 0;
        while(st[str_len]){ str_len++; }
        
		// allocate memory for a new string
        char* new_str = (char*)malloc(str_len+1);
        if(new_str == NULL) {
            return NULL;
        }
        // copy
        for( unsigned int i = 0; i < str_len+1; i++){
            new_str[i] = st[i];
        }
        return new_str;
    }
    else{
        return NULL;
    }
}
//===========================================================================================

/*
 * This function checks the equality of strings, whether the source string is equal to the copy string
 * 
 * @param first parameter string source second parameter string copy third parameter expected result
*/
void U_Test_string_equality(const char* str_origin, const char* str_copy, bool result){
    uint32_t len_str_origin = 0;
    uint32_t len_str_copy = 0;
    
    while(str_origin[len_str_origin] != '\0'){ len_str_origin++; }
    while(str_copy[len_str_copy] != '\0'){ len_str_copy++; }
    
    if( (len_str_origin == len_str_copy) && ( result ) ){
        printf("%s \r\n", "Test \"U_Test_string_equality\" successfully completed !!!" );
    }
    else{
        printf("%s \r\n", "Test \"U_Test_string_equality\" failed !!!" );
        printf("expected result: %d, actual result %d \r\n", result, !result  );
    }
}
//===========================================================================================

/*
 * This function compares the addresses of two pointers, the original string and the copy, 
 * whether they point to the same memory address or not
 * 
 * @param first parameter string source second parameter string copy third parameter expected result
 * (1 - memory address is the same, 0 - different memory address)
*/
void U_Test_compare_pointers(const char* str_origin, const char* str_copy, bool result){
    if( (str_origin != str_copy) && ( !result ) ){
        printf("%s \r\n", "Test \"U_Test_compare_pointers\" successfully completed !!!" );
    }
    else{
        printf("%s \r\n", "Test \"U_Test_compare_pointers\" failed !!!" );
        printf("expected result: %d, actual result %d \r\n", result, !result  );
    }
}
//===========================================================================================
/*
 * This function checks the "character by character" content of the copied string with the original string
 * 
 * @param first parameter string source second parameter string copy third parameter expected result
*/
void U_Test_character_by_character_comparison(const char* str_origin, const char* str_copy, bool result){
    uint32_t counter = 0;
    while( str_copy[counter] != '\0'){
        counter++;
        if((str_copy[counter] == str_origin[counter]) && result){
            continue;
        }
        else{
            printf("%s \r\n", "Test \"U_Test_character_by_character_comparison\" failed !!!" );
            printf("expected result: %d, actual result %d \r\n", result, !result  );
            break;
        }
    }
    if( (str_copy[counter] == '\0') && (str_origin[counter] == '\0') ){
        printf("%s \r\n", "Test \"U_Test_character_by_character_comparison\" successfully completed !!!" );
    }
}
//===========================================================================================
/*
 * This the function checks if the pointer of the copied string points to NULL
 * 
 * @param first parameter string source second parameter string copy third parameter expected result
*/
void U_Test_checking_for_empty_string( const char* str_copy, bool result){
    if((str_copy == NULL) && result){
        printf("%s \r\n", "Test \"U_Test_checking_for_empty_string\" failed !!!" );
        printf("expected result: %d, actual result %d \r\n", result, !result  );
    }
    else{
        printf("%s \r\n", "Test \"U_Test_checking_for_empty_string\" successfully completed !!!" );
    }
}
//===========================================================================================


int main()
{
    char* str = "Golinskiy Konstantin";
    
    char* copy_string = str_cpy( str );
    
    printf("%s \r\n", str );
    printf("%s \r\n", copy_string );
    
    U_Test_string_equality( str, copy_string, true );
    U_Test_compare_pointers( str, copy_string, false );
    U_Test_character_by_character_comparison( str, copy_string, true );
    U_Test_checking_for_empty_string( copy_string, false );
    
    
    return 0;
}