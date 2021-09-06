#include <stdio.h>
#include <stdlib.h>

/*
 * This the function copies the passed string to a new one and returns the address of the new string
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


int main()
{
    char* str = "Golinskiy Konstantin";
    
    char* copy_string = str_cpy( str );
    
    printf("%s \r\n", str );
    printf("%s \r\n", copy_string );
	
    free( copy_string );
	
    return 0;
}
