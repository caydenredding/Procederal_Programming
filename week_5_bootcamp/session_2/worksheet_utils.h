#include <stdio.h>

typedef struct {
    char date[13];
    float blood_iron;
} reading;

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, float *bloodIron)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        // turns the blood iron into a float - similar to atoi().
        // we have to tell C that bloodIron is a pointer so it stores it.
        *bloodIron = atof(token);
    }

    // Free the duplicated string
    free(inputCopy);
}

FILE *open_file(char *filename, char *mode)
{
    FILE *input = fopen(filename, mode);
        if (!input)
        {
            printf("Error: File could not be opened\n");
            return NULL;
        }
    return input;
}

int read_file(FILE *inputFile, reading *dataArray, int *num_readings)
{
    char line[buffer_size];
    int counter = 0;

    while (fgets(line, buffer_size, inputFile))
            {
                // split up the line and store it in the right place
                // using the & operator to pass in a pointer to the bloodIron so it stores it
                tokeniseRecord(line, ",", dataArray[counter].date, &dataArray[counter].bloodIron);
                counter++;
            }
    *num_readings = counter;

    return 0;
}

int sort_struct(reading *dataArray, float outputArray[5][150], const int num_readings)
{
    for (int i = 0; i<num_readings; i++)
    {
        switch(itoa(((int)dataArray[i].blood_iron)-10))
        {
            case '1':
                break;
            case '2': 
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break:

        }
    }
}