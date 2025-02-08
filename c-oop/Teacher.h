#ifndef TEACHER_H
#define TEACHER_H

typedef struct Teacher {
    char *subject;
    int years_of_experience;
} Teacher;

// Constructor for Teacher
Teacher *create_teacher(char *name, int age, char *gender, char *subject, int years_of_experience);

// Method for introducing the teacher
void introduce_teacher(Teacher *self);

// Method for grading papers
void grade_papers(Teacher *self);

// Method fot clean-up
void destroy_teacher(Teacher *self);

#endif
