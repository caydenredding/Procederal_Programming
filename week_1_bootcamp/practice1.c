#include <stdio.h>

int main()
{
    float base, height, area;
    printf("Enter base:\t");
    scanf("%f", &base);
    printf("Enter height:\t");
    scanf("%f", &height);
    area = base*height;
    printf("The area is %f\n", area);
}