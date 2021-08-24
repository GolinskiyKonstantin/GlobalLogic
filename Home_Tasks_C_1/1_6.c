#include <stdio.h>
#include <stdint.h>

unsigned long long get_factorial(unsigned long long f)
{
    if( f ){
        unsigned long long factorial = 1;
        for( unsigned long long i = 1; i <= f; i++ ){
            factorial *= i; 
        }
        return factorial;
    }
    else{
        return 0;
    }
}



int main()
{
    
    printf("factorial 10 =  %lld \r\n", get_factorial( 10 ) );

    return 0;
}
