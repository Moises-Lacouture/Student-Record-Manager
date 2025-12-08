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

int main(void){
    int userOption = 0;// User response variable
    struct StudentNode *head = NULL;
    
    do {
        printf("\t-------- Student Record Manager --------\n");
        
        printf("1. Add Student.\n");
        printf("2. Remove Student.\n");
        printf("3. Search student.\n");
        printf("4. Update student.\n");
        printf("9. Save list.\n");
        
        
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

                insertStudent(&head, student);
                break;
            }
            case 2:{ // Remove student option
                int userRemoveStudent;//variable for student removal, user
                printAllStudents(head);
                printf("Choose the student you want to remove:\n>> ");
                scanf("%d", &userRemoveStudent);//user enters the student they want removed
                //Create the function for removing specific student in the linked list with their memory address(This uses pointer/linked list)
                printf("Remove feature coming soon.");
                
                break;
            }
            case 3:{ // Search students
                int userSearchSelection;
                scanf("%d", &userSearchSelection);
                //printf that shows the options of search of the student. By passing grades(GPA), by passing or failing grade in an specific class.
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
            
            default:
                printf("Input option is not valid.\n>> ");
                break;
        }
    } while (userOption != 5);
    return 0;
}
