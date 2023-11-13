#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

void printOpitons();

int validate_file(const char *filename, FITNESS_DATA *data) {
    FILE *file = fopen(filename, "r");

	// file not found
    if (file == NULL) {
        printf("Error: could not open file");
        return 1;
    }

	int buffer_size = 100;
	char line_buffer[buffer_size];

	int i = 0;
	char temp_steps [6];

	// putting data from file into suitable array (causes segmentation fault)

	while (fgets(line_buffer, buffer_size, file) != NULL) {
        tokeniseRecord(line_buffer, ",", data[i].date, data[i].time, temp_steps);
		i++;
		data[i].steps = atoi(temp_steps);
    }

	return 0;

}

int num_records();

int min_steps();

int max_steps();

int avg_steps();

int max_stretch(int stretch_size);

#endif // FITNESS_DATA_STRUCT_H