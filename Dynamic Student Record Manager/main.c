/*
 Dynamic Student Record Manager
 By Moises Lacouture
 Student ID#4000461273
 
 Description:
 */

//Do a function that takes the input string and returns the string with the first letter capitalize and the rest in lowercase.(This is for the name and lastname)

#include <stdio.h>
#include "Libraries/library.h"
#include "Libraries/student.h"

int main(void){
    int userOption = 0; // User response variable
    do {
        switch (userOption) {
            case 1:{ // Add students option
                char firstName[50];
                char lastName[50];
                
                int englishGrade,
                spanishGrade,
                mathGrade,
                socialsGrade,
                religionGrade;
                
                printf("Please enter the First Name of the student>\n>> ");
                scanf("%49s", firstName);
                
                printf("Please enter the last name of the student\n>> ");
                scanf("%49s", lastName);
                
                printf("Please enter the final grade for the English class:\n>> ");
                scanf("%d", &englishGrade);
                
                printf("Please enter the final grade for the Spanish class:\n>> ");
                scanf("%d", &spanishGrade);
                
                printf("Please enter the final grade for the Math class:\n>> ");
                scanf("%d", &mathGrade);

                printf("Please enter the final grade for the Social Studies class:\n>> ");
                scanf("%d", &socialsGrade);

                printf("Please enter the final grade for the Religion class:\n>> ");
                scanf("%d", &religionGrade);

                break;
            }
            case 2:{ // Remove studetns option
                printf("Choose the student you want to remove:\n>> ");
                //Find a way to take the struct students from the array and display their names.(Show all the students)
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
