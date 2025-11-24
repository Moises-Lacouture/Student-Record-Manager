#include "library.h"
#include "student.h"
#include <stdio.h>

char gradeLetter(int grade){ //Function return grade in letter with grade in int
    if(grade >= 90) return 'A';
    if(grade >=80) return 'B';
    if(grade >= 70) return 'C';
    if(grade >=60) return 'D';
    if(grade >= 0) return 'F';
    return '?';//Invalid grade
}

//implement add, remove, update, search, compute statistics and display modular functions.

void printAllStudentsInfo(struct Student students[], int studentTotal){//This Function will print ALL the information of ALL the students.
    
    for (int i = 0; i < studentTotal; i++) {
        printf("%d. Name: %s %s.\n",i + 1,students[i].lastName, students[i].firstName);
        printf("Student ID#: %d\n", students[i].studentID);
        printf("Grade for English class: %d %c \n", students[i].grades[0], gradeLetter(students[i].grades[0]));
        printf("Grade for English class: %d %c \n", students[i].grades[1], gradeLetter(students[i].grades[1]));
        printf("Grade for English class: %d %c \n", students[i].grades[2], gradeLetter(students[i].grades[2]));
        printf("Grade for English class: %d %c \n", students[i].grades[3], gradeLetter(students[i].grades[3]));
        printf("Grade for English class: %d %c \n", students[i].grades[4], gradeLetter(students[i].grades[4]));
        printf("===============================\n");

    }
}
