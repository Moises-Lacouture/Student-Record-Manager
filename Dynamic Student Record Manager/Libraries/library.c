#include "library.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
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

struct StudentNode* createStudentNode(struct Student s){// Create a new student node
    struct StudentNode *newNode = (struct StudentNode*)malloc(sizeof(struct StudentNode));
    
    if(newNode == NULL){
        printf("Error: memory allocation failed.\n");
        return NULL;
    }
    
    newNode->student = s;
    newNode->next = NULL;
    
    return newNode;
}

void insertStudent(struct StudentNode **head, struct Student s) {// Insert student in the beginning
    struct StudentNode *newNode = createStudentNode(s);
    
    if (newNode == NULL)
        return;
    
    newNode->next = *head;
    
    *head = newNode;
}

void printAllStudents(struct StudentNode *head) {// Print all students
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }
    
    struct StudentNode *current = head;
    int count = 1;
    
    while (current != NULL) {
        printf("%d. Name: %s %s\n", count++,
               current->student.lastName,
               current->student.firstName);
        printf("Student ID: %ld\n", current->student.studentID);
        printf("English: %d %c\n", current->student.grades[0],
               gradeLetter(current->student.grades[0]));
        printf("Spanish: %d %c\n", current->student.grades[1],
               gradeLetter(current->student.grades[1]));
        printf("Math: %d %c\n", current->student.grades[2],
               gradeLetter(current->student.grades[2]));
        printf("Social Studies: %d %c\n", current->student.grades[3],
               gradeLetter(current->student.grades[3]));
        printf("Religion: %d %c\n", current->student.grades[4],
               gradeLetter(current->student.grades[4]));
        
        current = current->next;
    }
}

int StudentTotal(struct StudentNode *head) {// Amount of students in the list
    int count = 0;
    struct StudentNode *current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

struct StudentNode* getStudentAtPosition(struct StudentNode *head, int position) { // Change poistion in the list of the student
    struct StudentNode *current = head;
    int count = 1;
    
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }
    
    return current;
}

void updateStudentInNode(int userSelection, struct Student *student) { //Change the information of the student in the selected position
    switch (userSelection) {
        case 1: {
            char firstName[50], lastName[50];
            
            printf("What will the last name be:\n>> ");
            scanf("%49s", lastName);
            
            printf("What will the first name be:\n>> ");
            scanf("%49s", firstName);
            
            strcpy(student->lastName, lastName);
            strcpy(student->firstName, firstName);
            
            break;
        }
        
        case 2: {
            int newID;
            printf("What will the new student ID be:\n>> ");
            scanf("%d", &newID);
            
            student->studentID = newID;
            break;
        }
        
        case 3: {
            int newGrade;
            printf("What will the new English class grade be:\n>> ");
            scanf("%d", &newGrade);
            student->grades[0] = newGrade;
            break;
        }
        
        case 4: {
            int newGrade;
            printf("What will the new Spanish class grade be:\n>> ");
            scanf("%d", &newGrade);
            student->grades[1] = newGrade;
            break;
        }
        
        case 5: {
            int newGrade;
            printf("What will the new Math class grade be:\n>> ");
            scanf("%d", &newGrade);
            student->grades[2] = newGrade;
            break;
        }
        
        case 6: {
            int newGrade;
            printf("What will the new Social Studies class grade be:\n>> ");
            scanf("%d", &newGrade);
            student->grades[3] = newGrade;
            break;
        }
        
        case 7: {
            int newGrade;
            printf("What will the new Religion class grade be:\n>> ");
            scanf("%d", &newGrade);
            student->grades[4] = newGrade;
            break;
        }
        
        default:
            printf("Invalid option chosen.\n");
            break;
    }
}
