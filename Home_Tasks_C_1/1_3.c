#include <stdio.h>
#include <stdint.h>

/*
 * This function converts from RGB888 to RGB565 format
 * 
 * @param value RGB colors in 8 bit format
 * @return result converts RGB565 format
 */
uint16_t Convert_RGB888_to_RGB565( uint8_t red, uint8_t green, uint8_t blue )
{
    return (uint16_t)((red & 0xf8) << 8) | (uint16_t)((green & 0xfc) << 3) | (uint16_t)(blue >> 3);
}

int main()
{
    uint8_t R = 255;
    uint8_t G = 50;
    uint8_t B = 125;
    uint16_t RGB565 = Convert_RGB888_to_RGB565( R, G, B );
    
    printf("RGB565 = 0x%04X", RGB565);

    return 0;
}
