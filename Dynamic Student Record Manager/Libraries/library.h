#ifndef LIBRARY_H
#define LIBRARY_H
#include "student.h"

char gradeLetter(int grade);
void printAllStudentsInfo(struct Student *students, int studentTotal);
void updateStudent(int userSelection, int userStudentSelec, struct Student *students);

#endif
