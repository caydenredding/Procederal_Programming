#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename [] = "squares.dat";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    int buffer_size = 100;
    int num, i;
    unsigned long long int all_nums [10000];
    char line_buffer[buffer_size];
    for (i = 0; fgets(line_buffer, buffer_size, file) != NULL; i++) {
        num = atoi(line_buffer);
        all_nums[i] = num;
    }

    fclose(file);

    int num_lines = i;
    int total = 0;

    for (i-=1; i >= 0; i--){
        total += all_nums[i];
    }

    float ans = (1.0*total/num_lines);

    printf("The average of all of these squares is:\t%f\n", (ans));

}