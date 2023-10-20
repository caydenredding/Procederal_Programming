#include <stdio.h>

float sum (float a, float b)
{
    float answer;
    answer = a + b;
    return answer;
}

int main () 
{
    float y = 2.11345;
    float z = sum(5.6542, y); // calling our new function

    printf ("The sum of 5 and %f is %.3f\n", y, z);
}