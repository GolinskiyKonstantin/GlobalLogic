#include <stdio.h>
#include <stdint.h>

const double PI = 3.141592653589793;

double get_circumference(float r)
{
    if(r > 0.0f){
        return (double)(2 * PI * r);
    }
    else{
        return -1.0;
    }
}

double get_area_circle(float r)
{
    if(r > 0.0f){
        return (double)(PI * r * r);
    }
    else{
        return -1.0;
    }
}


int main()
{ 
    printf("circumference: %lf \r\n", get_circumference( 6.0f ) );
    printf("area circle: %lf \r\n", get_area_circle( 6.0f ) );
    return 0;
}
