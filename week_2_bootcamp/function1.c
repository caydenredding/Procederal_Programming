#include <stdio.h>

int sum (int a, int b, int *p)
{
    int answer;
    answer = a + b;

    (*p)++;

    return answer;
}

int main () 
{

    int a = 5;
    int *p = &a;

    int y = 2;
    int z = sum(5, y, p); // calling our new function

    printf ("The sum of 5 and %d is %d\nAnd a now equals %d\n", y, z, a);
}