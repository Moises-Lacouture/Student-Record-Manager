#ifndef LIBRARY_H
#define LIBRARY_H
#include "student.h"

//Show Grade Letter Function
char gradeLetter(int grade);

//Student Node
struct StudentNode* createStudentNode(struct Student s);

//Add Student function
void insertStudent(struct StudentNode **head, struct Student s);

//Total students Function
int countStudents(struct StudentNode *head);

//Manipulate Student/Linked List
struct StudentNode* getStudentAtPosition(struct StudentNode *head, int position);
void updateStudentInNode(int userSelection, struct Student *student);

//Delete/Remove functions
void freeAllStudents(struct StudentNode **head);
void removeStudent(struct StudentNode **head, int position);

//Print Functions
void printSingleStudent(struct Student *student);
void printAllStudents(struct StudentNode *head);

//Search Functions
void searchMenu(struct StudentNode *head);
struct StudentNode* searchByID(struct StudentNode *head, long long id);
struct StudentNode* searchByLastName(struct StudentNode *head, char *lastName);
int findMinGrade(struct Student *student);
int findMaxGrade(struct Student *student);

//Student Stats
float calculateStudentAverage(struct Student *student);
void printStudentStatistics(struct Student *student);// Average GPA, Best Grade, Lowet Grade

//Validating Input
int getValidGrade(const char *prompt);

//Save and Load File Function
void saveToFile(struct StudentNode *head, const char *filename);
void loadFromFile(struct StudentNode **head, const char *filename);

#endif
