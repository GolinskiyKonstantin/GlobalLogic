#include <stdio.h>
#include <stdlib.h>

char* str_cpy(char* st){
    if( st != NULL){
        
        unsigned int str_len = 0;
        while(st[str_len]){ str_len++; }
        
        char* new_str = (char*)malloc(str_len+1);
        if(new_str == NULL) {
            return NULL;
        }
        
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

    return 0;
}