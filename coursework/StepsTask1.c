#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {

    // Open File

    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    FITNESS_DATA step_count [500];

    // Read in the data and store in array.
    int buffer_size = 100, i;
    char temp_date [11];
    char temp_time [6], temp_steps [8];
    char line_buffer[buffer_size];
    for (i = 0; fgets(line_buffer, buffer_size, file) != NULL; i++) {
        tokeniseRecord(line_buffer, ",", temp_date, temp_time, temp_steps);

        strcpy(step_count[i].date, temp_date);
        strcpy(step_count[i].time, temp_time);
        step_count[i].steps = atoi(temp_steps);
    }

    fclose(file);

    // Output data

    printf("Number of records in file: %d\n", i);
    
    for (int n = 0; n<3; n++){
        printf("%s/%s/%d\n", step_count[n].date, step_count[n].time, step_count[n].steps);
    }

    return 0;

}