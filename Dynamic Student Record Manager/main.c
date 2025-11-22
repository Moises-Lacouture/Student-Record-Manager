/*
 Dynamic Student Record Manager
 By Moises Lacouture
 Student ID#4000461273
 
 Description:
 */


//search: How to save a string in c, it is with an array but search the best way to do it.
//search: How to create your library, for the functions, and how to connect it.
//search: How to do a function, the diferent types of functions too.

//Do a function that depending on the grade in int will return a grade in letter(always use capital letter for the grade).
//Do a function that takes the input string and returns the string with the first letter capitalize and the rest in lowercase.
#include <stdio.h>

int main(void){
    int userOption = 0; // User response variable
    do {
        switch (userOption) {
            case 1: // Add students option
                printf("Please enter the First Name of the student>\n>> ");
                
                printf("Please enter the last name of the student\n>> ");
                
                printf("Please enter the final grade for the English class:\n>> ");
                
                printf("Please enter the final grade for the Spanish class:\n>> ");

                printf("Please enter the final grade for the Math class:\n>> ");

                printf("Please enter the final grade for the Social Studies class:\n>> ");

                printf("Please enter the final grade for the Religion class:\n>> ");

                break;
            case 2: // Remove studetns option
                printf("Choose the student you want to remove:\n>> ");
                //Find a way to take the struct students from the array and display their names.(Show all the students)
                //Once the student is chose, display all the information of that student(This code is repeated, create a function for it)

                break;
            case 3: // Search students
                printf("Choose the student:\n>> ");
                //Show all the students
                //once the student is chosen, show all the information of the student
                break;
            case 4: // Update students
                printf("Choose the student you want to update:\n>> ");
                //Show all the students
                //Once the student is chose, display all the information of that student in options
                //Once the option is chosen and the updated value is entered make a confirmation showing the current value and the new value entered.
                printf("");
                break;
            
            default:
                printf("Input option is not valid.\n>> ");
                break;
        }
    } while (userOption != 5);
    return 0;
}
