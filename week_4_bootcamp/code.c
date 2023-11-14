#include "utilities.h"

int main()
{
    // array of daily readings
    reading daily_readings[100];
    int num_readings;

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    FILE *file = open_file(filename, "r");
    read_file(file, daily_readings, &num_readings);
    fclose(file);

    char month [4];
    char choice;
    float mean = 0;
    float max = 0;
    float min = 0;

    while (1)
    {
        

        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your lowest blood iron level\n");                     // SILVER
        printf("D: View your highest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            printf("\n\n");
            for (int i = 0; i < num_readings; i++)
            {
                printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            }
            printf("\n\n");
            break;

        case 'B':
        case 'b':
            mean = find_mean(daily_readings, num_readings);
            printf("\nThe mean of the readings is: %.2f\n\n\n", mean);
            break;

        case 'C':
        case 'c':
            max = find_highest(daily_readings, num_readings);
            printf("\nThe highest value of the readings is: %.1f\n\n\n", max);
            break;

        case 'D':
        case 'd':
            min = find_lowest(daily_readings, num_readings);
            printf("\nThe lowest value of the readings is: %.1f\n\n\n", min);
            break;

        case 'E':
        case 'e':
            printf("\nEnter the first 3 letters of the month in capitals: ");
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", month);
            printf("\n");
            monthly_iron(daily_readings, num_readings, month);
            break;

        case 'F':
        case 'f':
            return 0;
            break;

        case 'G':
        case 'g':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}