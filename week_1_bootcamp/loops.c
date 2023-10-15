#include <stdio.h>

int main () 
{

    
int getSquares()
{
    int a = -20, n;

    while (a <= 40){
        n= a*a;
        printf("n = %d\t", n);
        printf("a = %d\n", a);
        a++;
    }
    printf("After the loop n is %d\n", n);
    return 0;
}

int getOdds()
{
    int a;
    for(int n = 0; n<10; n++) {
        a = (n*2) + 1;
        printf("%d\n", a);
    }
    return 0;
}

int reversedNums() {
    for (int a=20; a>=0; a-=2){
        printf("%d\n", a);
    }
    return 0;
}


    //getOdds();
    reversedNums();
    //getSquares();



}



