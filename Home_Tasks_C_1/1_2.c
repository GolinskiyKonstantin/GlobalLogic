#include <stdio.h>
#include <stdint.h>

/*
 * This function will swap the bytes ( 2 bytes)
 * 
 * @param value is the value to be swapped
 * @return swapped result
 */
uint16_t swap16( uint16_t value )
{
   return value = (value >> 8) | (value << 8);
}

/*
 * This function will swap the bytes ( 4 bytes)
 * 
 * @param value is the value to be swapped
 * @return swapped result
 */
uint32_t swap32( uint32_t value )
{
   return value = (value >> 24) | ((value & 0x00ff0000U ) >> 8) |
                  ((value & 0x0000ff00U ) << 8) | (value << 24);
}

/*
 * This function will swap the bytes ( 8 bytes)
 * 
 * @param value is the value to be swapped
 * @return swapped result
 */
uint64_t swap64( uint64_t value )
{
   return value = (value >> 56) | ((value & 0x00ff000000000000ULL ) >> 40) |
                  ((value & 0x0000ff0000000000ULL ) >> 24) |  
                  ((value & 0x000000ff00000000ULL ) >> 8) |
                  ((value & 0x00000000ff000000ULL ) << 8) |
                  ((value & 0x0000000000ff0000ULL ) << 24) |
                  ((value & 0x000000000000ff00ULL ) << 40) |
                  (value << 56) ; 
}

int main()
{
    uint16_t A = 0x2211U;
    A = swap16( A );
    printf("A = 0x%04X \r\n", A);
    
    uint32_t B = 0x44332211UL;
    B = swap32( B );
    printf("B = 0x%08X \r\n", B);
    
    uint64_t C = 0x8877665544332211ULL;
    C = swap64( C );
    printf("C = 0x%016lX \r\n", C);
    return 0;
}