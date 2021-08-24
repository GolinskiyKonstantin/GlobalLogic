
uint16_t Convert_RGB888_to_RGB565( uint8_t red, uint8_t green, uint8_t blue )
{
    return (uint16_t)((red & 0xf8) << 8) | (uint16_t)((green & 0xfc) << 3) | (uint16_t)(blue >> 3);
}