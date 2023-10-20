#include <stdio.h>

void reverseArray (int* input_array, int length)
{
    int temp;
    for (int i = 0; i < ((length)/2); i++){
        temp = input_array[i];
        input_array[i] = input_array[length-i-1];
        input_array[length-i-1] = temp;
    }
}

int str_len(char input){
    char* first = &input;
    char* current;
    int i;
    for (i = 0; current* != '\0'; i++){
        current = (first+i);
    }
    return (i-1);
}

int main()
{
    int n = 10;
    int fwd_array [n];
    for (int i = 0; i < n; i++){
        fwd_array[i] = i+1;
    }

    reverseArray(fwd_array, n);

    for (int i = 0; i < n; i++){
        printf("%d\n", fwd_array[i]);
    }

    char test [] = "hello";
    printf("Hello is %d letters", str_len(test));

}

