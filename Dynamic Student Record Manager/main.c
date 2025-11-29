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
    int userOption = 0,// User response variable
    studentTotal = 0; // Amount of students(Size of the array/linked list)
    
    struct Student students[100];// array for students

    do {
        printf("\t-------- Student Record Manager --------\n");
        
        printf("1. Add Student.\n");
        printf("2. Remove Student.\n");
        printf("3. Search student.\n");
        printf("4. Update student.\n");
        printf("9. Save list.\n");
        
        
        printf("Please choose your option\n>> ");//temporal printf, need to create menu and show options
        scanf("%d",&userOption);//variable for menu option, user
        
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

                students[studentTotal] = student;//array of students
                studentTotal += 1;//increase the size of the array each time a student is entered
                break;
            }
            case 2:{ // Remove student option
                int userRemoveStudent;//variable for student removal, user
                printf("Choose the student you want to remove:\n>> ");
                printAllStudentsInfo(students, studentTotal);
                printf(">> ");
                scanf("%d", &userRemoveStudent);//user enters the student they want removed
                //Create function for student removal(This uses pointer)
                
                break;
            }
            case 3:{ // Search students
                printf("Choose the student:\n>> ");
                //Show all the students
                //once the student is chosen, show all the information of the student
                break;
            }
            case 4:{ // Update students
                int userStudentSelection,
                userUpdateSelect;
                printf("Choose the student you want to update:\n>> ");
                printAllStudentsInfo(students, studentTotal);// Show all students
                scanf("%d", &userStudentSelection);
                printf("What do you want to change from the student?\n");
                printf("1. The name.\n");
                printf("2. Student ID.\n");
                printf("3. Grade for English class.\n");
                printf("4. Grade for Spanish class.\n");
                printf("5. Grade for Math class.\n");
                printf("6. Grade for Social Studies class.\n");
                printf("7. Grade for Religion class.\n");
                scanf("%d", &userUpdateSelect);
                
                updateStudent(userUpdateSelect, userStudentSelection, students);
                
                break;
            }
            
            default:
                printf("Input option is not valid.\n>> ");
                break;
        }
    } while (userOption != 5);
    return 0;
}
