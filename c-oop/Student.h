#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    int grade_level;
    float GPA;
} Student;

// Constructor for Student
Student *create_student(char *name, int age, char *gender, int grade_level, float GPA);

// Method for introducing the student
void introduce_student(Student *self);

// Method for studying
void study(Student *self);

// Method for clean-up
void destroy_student(Student *self);

#endif
