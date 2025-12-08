#ifndef LIBRARY_H
#define LIBRARY_H
#include "student.h"

char gradeLetter(int grade);
struct StudentNode* createStudentNode(struct Student s);
void insertStudent(struct StudentNode **head, struct Student s);
void printAllStudents(struct StudentNode *head);
int countStudents(struct StudentNode *head);
struct StudentNode* getStudentAtPosition(struct StudentNode *head, int position);
void updateStudentInNode(int userSelection, struct Student *student);

#endif
