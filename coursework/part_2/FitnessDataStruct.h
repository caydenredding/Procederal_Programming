#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H
#define buffer_size 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

void printOpitons();

int import_file(const char *filename, FITNESS_DATA *data, int *num_readings) {
    FILE *input = fopen(filename, "r");
    	if (!input)
    	{
        	printf("Error: File could not be opened\n");
        	return 1;
    	}

	char line[buffer_size];
    int counter = 0;
	char steps [6];

    while (fgets(line, buffer_size, input))
            {
                tokeniseRecord(line, ",", data[counter].date, data[counter].time, steps);
				data[counter].steps = atoi(steps);
                counter++;
            }

    *num_readings = counter;

	return 0;
}

int min_steps(FITNESS_DATA *data, int num_readings, char *date, char *time)
{
	int min = 1000000;
	for (int i = 0; i < num_readings; i++)
	{
		if (data[i].steps < min)
		{
			min = data[i].steps;
			strcpy(date, data[i].date);
			strcpy(time, data[i].time);
		}
	}
	return 0;
}

int max_steps();

int avg_steps();

int max_stretch(int stretch_size);

#endif // FITNESS_DATA_STRUCT_H