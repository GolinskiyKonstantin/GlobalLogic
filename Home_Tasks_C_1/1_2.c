

uint16_t swap16( uint16_t value )
{
   return value = (value >> 8) | (value << 8);
}


uint32_t swap32( uint32_t value )
{
   return value = (value >> 24) | ((value & 0x00ff0000U ) >> 8) |
                  ((value & 0x0000ff00U ) << 8) | (value << 24);
}


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
