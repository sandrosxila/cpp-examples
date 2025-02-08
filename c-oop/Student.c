#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

typedef struct Student {
  Person *base;  // Inherit from Person
  int grade_level;
  float GPA;
} Student;

// Constructor for Student
Student *create_student(char *name, int age, char *gender, int grade_level, float GPA) {
    Student *new_student = (Student *)malloc(sizeof(Student));
    new_student->base = create_person(name, age, gender);  // Inherit from Person
    new_student->grade_level = grade_level;
    new_student->GPA = GPA;
    return new_student;
}

// Method for introducing the student
void introduce_student(Student *self) {
    introduce_person(self->base);  // Call base class's introduce method
    printf("I am in grade %d with a GPA of %.2f.\n", self->grade_level, self->GPA);
}

// Method for studying
void study(Student *self) {
    printf("%s is studying for the upcoming exams.\n", self->base->name);
}

// Method for clean-up
void destroy_student(Student *self){
  destroy_person(self->base);
  free(self);

  self = NULL;
}
