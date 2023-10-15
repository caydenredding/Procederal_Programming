#include <stdio.h>

int main()
{
    // int a [10];
    // int count = 0;

    // for (int value = 0; value < 10; value++){
    //     a[value] = count;
    //     count = count + 11;
    // }

    // for (int value = 0; value < 10; value++){
    //     printf("%d\n", a[value]);
    // }

    char name [5] = "hello";
    
    for(int i=4; i>=0; i--){
        printf("%c", name[i]);
    }

    return 0;


}