#include <stdio.h>
#include <stdint.h>

/*
 * This function converts meters to inches
 * 
 * @param meters ( value meters )
 * @return value in inches
 */
float meters_to_inches( float meters )
{
    return meters / 0.0254f;
}

/*
 * This function to get the perimeter in inches
 * 
 * @param parameters width and height are specified in meters
 * @return returns the perimeter in inches (returns -1 if incorrect parameters are passed to the function)
 */
float get_perimeter(float w, float h)
{   
    if( w > 0.0f && h > 0.0f ){
        return meters_to_inches((w + h) * 2);
    }
    else {
        return -1;
    }
}

/*
 * This function to get the area in inches
 * 
 * @param parameters width and height are specified in meters
 * @return returns the area in inches (returns -1 if incorrect parameters are passed to the function)
 */
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
    
    // Enter width
    do{
        printf("%s", "Enter width ( from 0 to 99, in meters  ): \r\n");
        scanf("%f", &width);
		// checking for correct input value
        while(getchar()!='\n');
        if(!(width > 0.0f && width < 100.0f)){
           printf("%s", "You entered an incorrect value!!!\r\n"); 
        }
        else{
            break;
        }
    }while(1);
    
    // Enter height
    do{
        printf("%s", "Enter height ( from 0 to 99, in meters ): \r\n");
        scanf("%f", &height);
		// checking for correct input value
        while(getchar()!='\n');
        if(!(height > 0.0f && height < 100.0f)){
           printf("%s", "You entered an incorrect value!!!\r\n"); 
        }
        else{
            break;
        }
    }while(1);
    
    // print result
    printf("get_perimeter of rectangle: %.2f inch \r\n", get_perimeter(width, height));
    printf("area of rectangle: %.2f inch \r\n", get_area(width, height));
    
    return 0;
}