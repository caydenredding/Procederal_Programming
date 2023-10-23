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

int str_len(char* input){
    int i = 0;
    for (; input[i] != '\0'; i++){
        continue;
    }
    return (i);
}

int is_prime(int x)
{
    float temp_ansf = 0.0;
    int temp_ansi = 0;
    for (int i = 2; (i*i) <= x; i++){
        
        temp_ansi = (x / i);
        float x_f = (float) x;
        temp_ansf = (x_f/i);
        if ((temp_ansf) == (temp_ansi)) {
            return 0;
        }
    }
    if (x==1){ return 0; }
    return 1;
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

    char test [] = "Hello World!!!";
    printf("%s is %d letters\n", test, str_len(test));

    int test_primes [] = {5, 6, 10, 11, 1, 2, 101};
    for (int i = 0; i < 7; i++){
        printf("%d:\t%d\n", test_primes[i], is_prime(test_primes[i]));
    }

}

