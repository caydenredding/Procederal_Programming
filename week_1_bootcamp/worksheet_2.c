#include <stdio.h>

int main()
{

    int task_3() {
        int array [] = {21,-304,1,-56,0};

        int max = array[0];

        for (int i=0; i<5; i++){
            if(max<array[i]){
                max = array[i];
            }

        }

        printf("%d\n", max);

    }

    int task_2() {
        int forward_array [] = {21,-304,1,-56,0};
        int reversed_array [5];

        printf("Before:\n\n");

        for (int i=0; i<5; i++){
            printf("Element %d: %d\n", i, forward_array[i]);
        }

        for(int i=0; i<5; i++){
            reversed_array[i] = forward_array[4-i];
        }

        printf("\nAfter:\n\n");

        for (int i=0; i<5; i++){
            printf("Element %d: %d\n", i, reversed_array[i]);
        }

        return 0;
    }


    int task_1() {
        int user_input [5];
        int total = 0;

        for (int i = 0; i<5; i++){
            printf("Enter number:\t");
            scanf("%d", &user_input[i]);
            total += user_input[i];
            printf("\n");
        }

        printf("The sum of these 5 numbers is %d\n", total);
        return 0;
    }

    //task_2();
    task_3();

}