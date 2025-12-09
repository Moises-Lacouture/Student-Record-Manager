/*
 Dynamic Student Record Manager
 By Moises Lacouture
 Student ID#4000461273
 
 Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include "Libraries/library.h"
#include "Libraries/student.h"
#define STUDENT_DATA "students_list.csv"

int main(void){
    int userOption = 0;// User response variable
    struct StudentNode *head = NULL; //Student node
    
    loadFromFile(&head, STUDENT_DATA);//Check if there is already a file for the student record

    do {
        printf("\t-------- Student Record Manager --------\n");
        
        printf("1. Add Student.\n");
        printf("2. Remove Student.\n");
        printf("3. Search student.\n");
        printf("4. Update student.\n");
        printf("5. Print students.\n");
        printf("6. Save List.\n");
        printf("7. Re-load list.\n");
        printf("8. Sort / Top Students.\n");
        
        printf("9. Exit.\n");
        
        
        printf("Please choose your option\n>> ");
        scanf("%d",&userOption);//variable for menu option, user
        
        switch (userOption) {
            case 1:{ // Add students option
                
                struct Student student;
                
                printf("Please enter the First Name of the student>\n>> ");
                scanf("%49s", student.firstName);
                
                printf("Please enter the last name of the student\n>> ");
                scanf("%49s", student.lastName);
                
                printf("Please enter the ID of the student\n>> ");
                scanf("%lld", &student.studentID);
                
                if (searchByID(head, student.studentID) != NULL) {//Checking if ID is duplicate
                    printf("Error: A student with ID %lld already exists.\n", student.studentID);
                    break;
                }
                
                 student.grades[0] = getValidGrade("Please enter the final grade for English class:\n>> ");
                 printf("Credits for English:\n>> ");
                 scanf("%d", &student.credits[0]);
                 
                 student.grades[1] = getValidGrade("Please enter the final grade for Spanish class:\n>> ");
                 printf("Credits for Spanish:\n>> ");
                 scanf("%d", &student.credits[1]);
                 
                 student.grades[2] = getValidGrade("Please enter the final grade for Math class:\n>> ");
                 printf("Credits for Math:\n>> ");
                 scanf("%d", &student.credits[2]);
                 
                 student.grades[3] = getValidGrade("Please enter the final grade for Social Studies class:\n>> ");
                 printf("Credits for Social Studies:\n>> ");
                 scanf("%d", &student.credits[3]);
                 
                 student.grades[4] = getValidGrade("Please enter the final grade for Religion class:\n>> ");
                 printf("Credits for Religion:\n>> ");
                 scanf("%d", &student.credits[4]);

                insertStudent(&head, student);
                break;
            }
            case 2:{ // Remove student option
                if (head == NULL) {
                    printf("No students in the list.\n");
                    break;
                }
                
                int userRemoveStudent;
                printAllStudents(head);
                printf("Choose the student you want to remove (0 to cancel):\n>> ");
                scanf("%d", &userRemoveStudent);
                
                if (userRemoveStudent == 0) {
                    printf("Cancelled.\n");
                    break;
                }
                
                removeStudent(&head, userRemoveStudent);
                break;
            }
            case 3:{ // Search students
                searchMenu(head);
                
                break;
            }
            case 4:{
                if (head == NULL) {
                    printf("There are no students in the list.\n");
                    break;
                }
                
                int userStudentSelection, userUpdateSelect;
                
                printAllStudents(head);
                printf("Choose the student you want to update:\n>> ");
                scanf("%d", &userStudentSelection);
                
                struct StudentNode *node = getStudentAtPosition(head, userStudentSelection);
                
                if (node == NULL) {
                    printf("Invalid student selection.\n");
                    break;
                }
                
                printf("What do you want to change from the student?\n");
                printf("1. The name.\n");
                printf("2. Student ID.\n");
                printf("3. Grade for English class.\n");
                printf("4. Grade for Spanish class.\n");
                printf("5. Grade for Math class.\n");
                printf("6. Grade for Social Studies class.\n");
                printf("7. Grade for Religion class.\n");
                scanf("%d", &userUpdateSelect);
                
                updateStudentInNode(userUpdateSelect, &(node->student));
                
                break;
            }
            case 5:{
                printAllStudents(head);
                break;
            }
            case 6:{
                saveToFile(head, STUDENT_DATA);
                break;
            }
            case 7:{
                freeAllStudents(&head);
                loadFromFile(&head, STUDENT_DATA);
                break;
            }
            case 8: {
                if (head == NULL) {
                    printf("No students in the list.\n");
                    break;
                }
                
                int sortOption;
                printf("\n1. Sort by GPA, highest first.\n");
                printf("2. Sort by Last Name (A-Z)\n");
                printf("3. Show Top Students\n");
                printf(">> ");
                scanf("%d", &sortOption);
                
                if (sortOption == 1) {
                    sortByGPA(&head);
                    printAllStudents(head);
                } else if (sortOption == 2) {
                    sortByLastName(&head);
                    printAllStudents(head);
                } else if (sortOption == 3) {
                    int n;
                    printf("How many top students to show?\n>> ");
                    scanf("%d", &n);
                    printTopStudents(head, n);
                } else {
                    printf("Invalid option.\n");
                }
                break;
            }
            case 9: {
                printf("Save before exiting?\n1 for Yes\n0 for No:\n>> ");
                int saveChoice;
                scanf("%d", &saveChoice);
                
                if (saveChoice == 1) {
                    saveToFile(head, STUDENT_DATA);
                }
                
                freeAllStudents(&head);
                break;
            }
            default:
                printf("Input option is not valid.\n>> ");
                break;
        }
    } while (userOption != 9);
    return 0;
}
