#include "library.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char gradeLetter(int grade){
    if(grade >= 90) return 'A';
    if(grade >=80) return 'B';
    if(grade >= 70) return 'C';
    if(grade >=60) return 'D';
    if(grade >= 0) return 'F';
    return '?';//Invalid grade
}

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
        printf("Student ID: %lld\n", current->student.studentID);
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
            long long newID;
            printf("What will the new student ID be:\n>> ");
            scanf("%lld", &newID);
            
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

void removeStudent(struct StudentNode **head, int position) {

    if (*head == NULL) {
        printf("Empty list, no students to remove.\n");
        return;
    }
    
    struct StudentNode *temp = *head;
    
    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("Student removed.\n");
        return;
    }
    
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position, choose a valid student.\n");
        return;
    }
    
    struct StudentNode *nodeToDelete = temp->next;
    
    temp->next = nodeToDelete->next;
    
    free(nodeToDelete);
    
    printf("Student removed.\n");
}

void printSingleStudent(struct Student *student) {
    
    printf("Name: %s %s\n", student->lastName, student->firstName);
    printf("Student ID: %lld\n", student->studentID);
    printf("English: %3d %c\n", student->grades[0], gradeLetter(student->grades[0]));
    printf("Spanish: %3d %c\n", student->grades[1], gradeLetter(student->grades[1]));
    printf("Math: %3d %c\n", student->grades[2], gradeLetter(student->grades[2]));
    printf("Social Studies: %3d %c\n", student->grades[3], gradeLetter(student->grades[3]));
    printf("Religion: %3d %c\n", student->grades[4], gradeLetter(student->grades[4]));
    printStudentStatistics(student);
}

void freeAllStudents(struct StudentNode **head) {

    struct StudentNode *current = *head;
    struct StudentNode *next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
    printf("Student record cleared from memory.\n");
}

struct StudentNode* searchByID(struct StudentNode *head, long long id) {

    struct StudentNode *current = head;
    
    while (current != NULL) {
        if (current->student.studentID == id) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

struct StudentNode* searchByLastName(struct StudentNode *head, char *lastName) {

    struct StudentNode *current = head;
    
    while (current != NULL) {
        if (strcmp(current->student.lastName, lastName) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

void searchMenu(struct StudentNode *head) {

    if (head == NULL) {
        printf("No students in the list to search.\n");
        return;
    }
    
    int searchOption;
    
    printf("\nSearch Options: \n");
    printf("1. Search by ID\n");
    printf("2. Search by Last Name\n");
    printf("3. List students with passing GPA (>= 70)\n");
    printf("4. List students with failing GPA (< 70)\n");
    printf(">> ");
    scanf("%d", &searchOption);
    
    switch (searchOption) {
        case 1: {
            long long searchID;
            printf("Enter Student ID:\n>> ");
            scanf("%lld", &searchID);
            
            struct StudentNode *found = searchByID(head, searchID);
            if (found != NULL) {
                printf("\n");
                printSingleStudent(&(found->student));
            } else {
                printf("No student found with that ID.\n");
            }
            break;
        }
        
        case 2: {
            char searchName[50];
            printf("Enter Last Name to search:\n>> ");
            scanf("%49s", searchName);
            
            struct StudentNode *found = searchByLastName(head, searchName);
            if (found != NULL) {
                printf("\n");
                printSingleStudent(&(found->student));
            } else {
                printf("No student found with that last name.\n");
            }
            break;
        }
        
        case 3: {
            printf("\nStudents with Passing GPA:\n");
            struct StudentNode *current = head;
            int count = 0;
            
            while (current != NULL) {
                float avg = calculateStudentAverage(&(current->student));
                if (avg >= 70.0) {
                    count++;
                    printf("\n%d. %s %s - GPA: %.2f\n", count,
                           current->student.lastName,
                           current->student.firstName,
                           avg);
                }
                current = current->next;
            }
            
            if (count == 0) {
                printf("No students with passing GPA found.\n");
            } else {
                printf("\nTotal passing students: %d\n", count);
            }
            break;
        }
        
        case 4: {
            printf("\nStudents with Failing GPA:\n");
            struct StudentNode *current = head;
            int count = 0;
            
            while (current != NULL) {
                float avg = calculateStudentAverage(&(current->student));
                if (avg < 70.0) {
                    count++;
                    printf("\n%d. %s %s - GPA: %.2f\n", count,
                           current->student.lastName,
                           current->student.firstName,
                           avg);
                }
                current = current->next;
            }
            
            if (count == 0) {
                printf("No students with failing GPA found.\n");
            } else {
                printf("\nTotal failing students: %d\n", count);
            }
            break;
        }
        
        default:
            printf("Invalid search option.\n");
            break;
    }
}

float calculateStudentAverage(struct Student *student) {

    int sum = 0;
    
    for (int i = 0; i < 5; i++) {
        sum += student->grades[i];
    }
    
    return sum / 5.0;
}

int findMinGrade(struct Student *student) {

    int min = student->grades[0];
    
    for (int i = 1; i < 5; i++) {
        if (student->grades[i] < min) {
            min = student->grades[i];
        }
    }
    
    return min;
}

int findMaxGrade(struct Student *student) {

    int max = student->grades[0];
    
    for (int i = 1; i < 5; i++) {
        if (student->grades[i] > max) {
            max = student->grades[i];
        }
    }
    
    return max;
}

void printStudentStatistics(struct Student *student) {

    printf("--- Statistics ---\n");
    printf("Average GPA: %.2f\n", calculateStudentAverage(student));
    printf("Highest Grade: %d %c\n", findMaxGrade(student), gradeLetter(findMaxGrade(student)));
    printf("Lowest Grade:  %d %c\n", findMinGrade(student), gradeLetter(findMinGrade(student)));
}

int getValidGrade(const char *prompt) {
    // Gets a valid grade between 0 and 100 from user
    int grade;
    do {
        printf("%s", prompt);
        scanf("%d", &grade);
        if (grade < 0 || grade > 100) {
            printf("Invalid grade. Please enter a value between 0-100.\n");
        }
    } while (grade < 0 || grade > 100);
    return grade;
}

// ============== File I/O ==============

void saveToFile(struct StudentNode *head, const char *filename) {
    // Save all students to a CSV file
    if (head == NULL) {
        printf("No students to save.\n");
        return;
    }
    
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    
    // Write header line
    fprintf(file, "FirstName,LastName,StudentID,English,Spanish,Math,SocialStudies,Religion\n");
    
    struct StudentNode *current = head;
    int count = 0;
    
    while (current != NULL) {
        fprintf(file, "%s,%s,%lld,%d,%d,%d,%d,%d\n",
                current->student.firstName,
                current->student.lastName,
                current->student.studentID,
                current->student.grades[0],
                current->student.grades[1],
                current->student.grades[2],
                current->student.grades[3],
                current->student.grades[4]);
        count++;
        current = current->next;
    }
    
    fclose(file);
    printf("Successfully saved %d student(s) to '%s'.\n", count, filename);
}

void loadFromFile(struct StudentNode **head, const char *filename) {
    // Load students from a CSV file
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("No existing data file found. Starting with empty list.\n");
        return;
    }
    
    // Skip header line
    char header[256];
    if (fgets(header, sizeof(header), file) == NULL) {
        printf("Error reading file header.\n");
        fclose(file);
        return;
    }
    
    struct Student student;
    int count = 0;
    
    while (fscanf(file, "%49[^,],%49[^,],%lld,%d,%d,%d,%d,%d\n",
                  student.firstName,
                  student.lastName,
                  &student.studentID,
                  &student.grades[0],
                  &student.grades[1],
                  &student.grades[2],
                  &student.grades[3],
                  &student.grades[4]) == 8) {
        
        // Create node directly to avoid the "added successfully" message for each
        struct StudentNode *newNode = createStudentNode(student);
        if (newNode != NULL) {
            newNode->next = *head;
            *head = newNode;
            count++;
        }
    }
    
    fclose(file);
    printf("Successfully loaded %d student(s) from '%s'.\n", count, filename);
}
