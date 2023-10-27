#include <stdio.h>

int main()
{
    char filename [] = "squares.dat";
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("");
        return 1;
    }

    unsigned long long int n;
    printf("Enter number of squares to output:\t");
    scanf("%llu", &n);

    for (unsigned long long int i = 1; i <= n; i++){
        fprintf(file, "%llu\n", (i*i));
    }

    fclose(file);
    return 0;
}