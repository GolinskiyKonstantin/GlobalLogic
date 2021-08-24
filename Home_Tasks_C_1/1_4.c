#include <stdio.h>
#include <stdint.h>

float meters_to_inches( float meters )
{
    return meters / 0.0254f;
}

float get_perimeter(float w, float h)
{   
    if( w > 0.0f && h > 0.0f ){
        return meters_to_inches((w + h) * 2);
    }
    else {
        return -1;
    }
}

float get_area(float w, float h)
{   
    if( w > 0.0f && h > 0.0f ){
        return meters_to_inches(w * h);
    }
    else {
        return -1;
    }
}


int main()
{
    float width, height;
    
    do{
        printf("%s", "Enter width ( in meters ): \r\n");
        scanf("%f", &width);
    }while(!(width > 0.0f));
    
    do{
        printf("%s", "Enter height ( in meters ): \r\n");
        scanf("%f", &height);
    }while(!(height > 0.0f));
    
    printf("get_perimeter of rectangle: %.2f inch \r\n", get_perimeter(width, height));
    printf("area of rectangle: %.2f inch \r\n", get_area(width, height));
    return 0;
}
