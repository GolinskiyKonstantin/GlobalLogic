#include <stdio.h>

int mass[] = {-5, 10, 507, 45, -75, 90};

int max_value_mass(int* p_mass, const unsigned int mass_size){
  
  int buff = p_mass[0];
   
  for( unsigned int i = 1; i < mass_size; i++ ){
      if( buff < p_mass[i] ){
          buff = p_mass[i];
      }
  }
  return buff;
}

int main()
{
    printf("Max mass value: %d", max_value_mass( mass, sizeof(mass)/sizeof(int)) );
    return 0;
}
