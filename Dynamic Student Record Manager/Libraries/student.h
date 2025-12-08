#ifndef STUDENT_H
#define STUDENT_H

struct Student{
    char firstName[50];
    char lastName[50];
    int studentID;
    int grades[5];//array to safe the grades
    // position of classes in the grades array: 1. english 2. spanish 3. math, 4. social studies, 5. religion.
};
struct StudentNode {
    struct Student student;
    struct StudentNode* next;
};
#endif
