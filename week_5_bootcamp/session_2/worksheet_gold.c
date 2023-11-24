#include "worksheet_utils.h"
#include <stdio.h>

int num_readings;
reading struct_array[500];
float sorted_readings[5][150];


int main() {

    FILE *file = open_file("data.txt", "r");
    read_file(file, struct_array, &num_readings);
    
}
