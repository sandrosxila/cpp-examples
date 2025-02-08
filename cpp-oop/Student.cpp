#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include "Person.cpp"

class Student : public Person
{
private:
  int grade_level;
  float GPA;

public:
  // Constructor for Student
  Student(std::string name, int age, std::string gender, int grade_level, float GPA)
      : Person(name, age, gender), grade_level(grade_level), GPA(GPA) {}

  // Method for introducing the student
  void introduce() const override {
    Person::introduce(); // Call base class's introduce method
    std::cout << "I am in grade " << grade_level << " with a GPA of " << GPA << "." << std::endl;
  }

  // Method for studying
  void study() const {
    std::cout << name << " is studying for the upcoming exams." << std::endl;
  }
};

#endif