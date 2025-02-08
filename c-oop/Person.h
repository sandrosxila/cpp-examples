#ifndef PERSON_H
#define PERSON_H

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

// Constructor for Person
Person *create_person(char *name, int age, char *gender);

// Method for introducing the person
void introduce_person(Person *self);

// Method for clean up
void destroy_person(Person *self);

#endif
