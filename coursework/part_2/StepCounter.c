#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

char menu_choice;
int quit = 0, num_records;
FITNESS_DATA step_count [500];
char filename [30];


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

    void printOptions() {
            printf("Menu Options:\n");
            printf("A: Specify the filename to be imported\n");
            printf("B: Display the total number of records in the file\n");
            printf("C: Find the date and time of the timeslot with the fewest steps\n");
            printf("D: Find the date and time of the timeslot with the largest number of steps\n");
            printf("E: Find the mean step count of all the records in the file\n");
            printf("F: Find the longest continuous period where the step count is above 500 steps\n");
            printf("Q: Quit\n");
            printf("Enter choice: ");


    }


// Complete the main function
int main() {
    while (quit == 0)
    {
        printOptions();
        scanf("%c", &menu_choice);
        printf("\n");
        
        switch (menu_choice)
        {
            // Import file
            case 'a':
            case 'A':
                printf("Input filename: ");
                scanf("%s", filename);
                validate_file(filename, step_count, *num_records);

                break;
            case 'b':
            case 'B':
                printf("%d",num_records);
                break;
            // case 'c':
            // case 'C':
            //     printf("%d",min_steps());
            //     break;
            // case 'd':
            // case 'D':
            //     printf("%d",max_steps());
            //     break;
            // case 'e':
            // case 'E':
            //     printf("%d",avg_steps());
            //     break;
            // case 'f':
            // case 'F':
            //     printf("%d", max_stretch(500));
            //     break;
            // quit
            case 'q':
            case 'Q':
                quit = 1;
                break;
            // Invalid Selection
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }   
}
