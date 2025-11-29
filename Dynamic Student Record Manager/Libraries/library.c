#include "library.h"
#include "student.h"
#include <stdio.h>
#include <string.h>

char gradeLetter(int grade){ //Function return grade in letter with grade in int
    if(grade >= 90) return 'A';
    if(grade >=80) return 'B';
    if(grade >= 70) return 'C';
    if(grade >=60) return 'D';
    if(grade >= 0) return 'F';
    return '?';//Invalid grade
}

//implement add, remove, update, search, compute statistics and display modular functions.

void printAllStudentsInfo(struct Student *students, int studentTotal){//This Function will print ALL the information of ALL the students.
    
    for (int i = 0; i < studentTotal; i++) {
        
        
        printf("%d. Name: %s %s.\n",i + 1,(students + i)->lastName, (students + i) -> firstName);
        printf("Student ID#: %d\n", (students + i)-> studentID);
        printf("Grade for English class: %d %c \n", (students + i)->grades[0], gradeLetter((students+ i)->grades[0]));
        printf("Grade for Spanish class: %d %c \n", (students + i)->grades[1], gradeLetter((students+ i)->grades[1]));
        printf("Grade for Math class: %d %c \n", (students + i)->grades[1], gradeLetter((students+ i)->grades[2]));
        printf("Grade for Social Studies class: %d %c \n", (students + i)->grades[1], gradeLetter((students+ i)->grades[3]));
        printf("Grade for Religion class: %d %c \n", (students + i)->grades[1], gradeLetter((students+ i)->grades[4]));
        printf("===============================\n");

    }
}

void updateStudent(int userSelection, int userStudentSelec, struct Student *students){
    int index = userStudentSelec - 1;
    switch (userSelection) {
        case 1:{
            char firstName[50],
            lastName[50];
            
            printf("What will the last name be:\n>> ");
            scanf("%49s", lastName);
            
            printf("What will the first name be:\n>> ");
            scanf("%49s",firstName);
            
            strcpy(students[index].lastName, lastName);
            strcpy(students[index].firstName, firstName);

            printf("Updated student name succesfully\n");
            
            break;
        }
            
        case 2:{
            int newID;
            printf("What will the new student ID be:\n>> ");
            scanf("%d", &newID);
            
            students[index].studentID = newID;
            
            printf("Updated student ID succesfully\n");
            
            break;
        }
            
        case 3:{
            int newGrade;
            
            printf("What will the new English class grade be:\n>> ");
            scanf("%d", &newGrade);
            
            students[index].grades[0] = newGrade;
            
            printf("Updated english class grade succesfully\n");
            
            break;
        }
        case 4:{
            int newGrade;
            
            printf("What will the new spanish class grade be:\n>> ");
            scanf("%d", &newGrade);
            
            students[index].grades[1] = newGrade;
            
            printf("Updated spanish class grade succesfully\n");
            
            break;
        }
            
        case 5:{
            int newGrade;
            
            printf("What will the new math class grade be:\n>> ");
            scanf("%d", &newGrade);
            
            students[index].grades[2] = newGrade;
            
            printf("Updated math class grade succesfully\n");
            
            break;
        }
            
        case 6:{
            int newGrade;
            
            printf("What will the new social studies class grade be:\n>> ");
            scanf("%d", &newGrade);
            
            students[index].grades[3] = newGrade;
            
            printf("Updated social studies class grade succesfully\n");
            
            break;
        }
            
        case 7:{
            int newGrade;
            
            printf("What will the new religion class grade be:\n>> ");
            scanf("%d", &newGrade);
            
            students[index].grades[4] = newGrade;
            
            printf("Updated religion class grade succesfully\n");
            
            break;
        }
            
        default:
            break;
    }
}
// invalid input function
//Create function for student removal(This uses pointer to modify the array/linked list/variable that has the number of students)
//Update the element in an array
