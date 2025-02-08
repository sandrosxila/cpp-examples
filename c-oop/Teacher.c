#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

typedef struct Teacher {
  Person *base;  // Inherit from Person
  char *subject;
  int years_of_experience;
} Teacher;

// Constructor for Teacher
Teacher *create_teacher(char *name, int age, char *gender, char *subject, int years_of_experience) {
    Teacher *new_teacher = (Teacher *)malloc(sizeof(Teacher));
    new_teacher->base = create_person(name, age, gender);  // Inherit from Person
    new_teacher->subject = strdup(subject);
    new_teacher->years_of_experience = years_of_experience;

    return new_teacher;
}

// Method for introducing the teacher
void introduce_teacher(Teacher *self) {
    introduce_person(self->base);  // Call base class's introduce method
    printf("I teach %s and have %d years of experience.\n", self->subject, self->years_of_experience);
}

// Method for grading papers
void grade_papers(Teacher *self) {
    printf("%s is grading papers for %s.\n", self->base->name, self->subject);
}

// Method for clean-up
void destroy_teacher(Teacher *self){
  destroy_person(self->base);

  free(self->subject);
  free(self);

  self = NULL;
}