#ifndef TEACHER_HPP
#define TEACHER_HPP

#include <iostream>

#include "Person.cpp"

class Teacher : public Person
{
private:
  std::string subject;
  int years_of_experience;

public:
  // Constructor for Teacher
  Teacher(std::string name, int age, std::string gender, std::string subject, int years_of_experience)
      : Person(name, age, gender), subject(subject), years_of_experience(years_of_experience) {}

  // Method for introducing the teacher
  void introduce() const override {
    Person::introduce(); // Call base class's introduce method
    std::cout << "I teach " << subject << " and have " << years_of_experience << " years of experience." << std::endl;
  }

  // Method for grading papers
  void gradePapers() const {
    std::cout << name << " is grading papers for " << subject << "." << std::endl;
  }
};

#endif