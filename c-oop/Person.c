#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

// Constructor for Person
Person *create_person(char *name, int age, char *gender) {
    Person *new_person = (Person *)malloc(sizeof(Person));
    new_person->name = strdup(name);
    new_person->age = age;
    new_person->gender = strdup(gender);
    return new_person;
}

// Method for introducing the person
void introduce_person(Person *self) {
    printf("Hello, my name is %s. I am %d years old and %s.\n", self->name, self->age, self->gender);
}

// Method for free up space
void destroy_person(Person *self){
  free(self->name);
  free(self->gender);
  free(self);

  self = NULL;
}