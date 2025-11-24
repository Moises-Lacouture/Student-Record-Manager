/*
 Dynamic Student Record Manager
 By Moises Lacouture
 Student ID#4000461273
 
 Description:
 */

//Do a function that takes the input string and returns the string with the first letter capitalize and the rest in lowercase.(This is for the name and lastname)

//Add a feature to save the data, this is done via creating, reading and modifing text files.

#include <stdio.h>
#include "Libraries/library.h"
#include "Libraries/student.h"

int main(void){
    int userOption = 0,
    studentTotal = 0; // User response variable
    
    struct Student students[100];


    do {
        printf("Please choose your option\n>> ");//temporal printf, need to create menu and show options
        scanf("%d",&userOption);
        
        switch (userOption) {
            case 1:{ // Add students option
                
                struct Student student;
                
                printf("Please enter the First Name of the student>\n>> ");
                scanf("%49s", student.firstName);
                
                printf("Please enter the last name of the student\n>> ");
                scanf("%49s", student.lastName);
                
                printf("Please enter the ID of the student\n>> ");
                scanf("%d", &student.studentID);
                
                printf("Please enter the final grade for the English class:\n>> ");
                scanf("%d", &student.grades[0]);
                
                printf("Please enter the final grade for the Spanish class:\n>> ");
                scanf("%d", &student.grades[1]);
                
                printf("Please enter the final grade for the Math class:\n>> ");
                scanf("%d", &student.grades[2]);

                printf("Please enter the final grade for the Social Studies class:\n>> ");
                scanf("%d", &student.grades[3]);

                printf("Please enter the final grade for the Religion class:\n>> ");
                scanf("%d", &student.grades[4]);

                students[studentTotal] = student;
                studentTotal += 1;
                break;
            }
            case 2:{ // Remove studetns option
                printf("Choose the student you want to remove:\n>> ");
                printAllStudentsInfo(students, studentTotal);
                //Once the student is chose, display all the information of that student(This code is repeated, create a function for it)
                
                break;
            }
            case 3:{ // Search students
                printf("Choose the student:\n>> ");
                //Show all the students
                //once the student is chosen, show all the information of the student
                break;
            }
            case 4:{ // Update students
                printf("Choose the student you want to update:\n>> ");
                //Show all the students
                //Once the student is chose, display all the information of that student in options
                //Once the option is chosen and the updated value is entered make a confirmation showing the current value and the new value entered.
                printf("");
                break;
            }
            
            default:
                printf("Input option is not valid.\n>> ");
                break;
        }
    } while (userOption != 5);
    return 0;
}
