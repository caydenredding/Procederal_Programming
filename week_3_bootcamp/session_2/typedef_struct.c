#include <stdio.h>

typedef struct {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
} student;

int print_students(student* students, int n){
    for (int i = 0; i < n; i++) {
        printf("-------------\n");
        printf("Student name: %s\n", students[i].name);
        printf("Student ID: %s\n", students[i].student_id);
        printf("Final mark: %u\n", students[i].mark);
    }
    printf("-------------\n");
    return 0;
}

int update_scores(student* students, int n){
    for (int i = 0; i < n; i++){
        int old_mark = students[i].mark;
        students[i].mark = 35 + (13 + (i*17)) % 65; // mark
        printf("Student %d\nOld Score: %d\n", i, old_mark);

        if (old_mark < students[i].mark){
            printf("\033[0;32m");
            // printf("New Score: %d", students[i].mark)
        } else if (old_mark > students[i].mark){
            printf("\033[0;31m");
        } else {
            printf("\033[0;33m");
        }
        printf("New Score: %d\n", students[i].mark);
        printf("\033[0m");
        printf("--------------\n");
    }
    return 0;
}

int main () {
    // Data generated using ChatGPT.
    int number_of_students = 10, i;
    student students [] = {
        {"Alice Smith",    "64827593", 67},
        {"Bob Johnson",    "19374650", 89},
        {"Charlie Brown",  "82056914", 76},
        {"David Davis",    "45790182", 44},
        {"Eve Wilson",     "36102478", 91},
        {"Frank Anderson", "93571826", 53},
        {"Grace Lee",      "50249867", 78},
        {"Hannah Clark",   "74820591", 62},
        {"Isaac Harris",   "61093745", 89},
        {"Jack White",     "92847501", 72},
    };

    update_scores(students, number_of_students);

    return 0;
    
}