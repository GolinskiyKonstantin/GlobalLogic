#include <stdio.h>
#include <stdint.h>


int main()
{
    int user_num = 0;
    
    do{
        printf("%s", "Enter num 1...500 \r\n");
        scanf("%d", &user_num);
    }while( !((user_num > 0) && (user_num <= 500)) );
    
    printf("%s", "============= \r\n");
    
    for(int i = 1; i <= 500; i++ ){
        if( !(i%user_num) ){
            printf("%d \r\n", i );
        }
    }
    
    return 0;
}
