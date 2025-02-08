#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>

class Person {
  protected:
    std::string name;
    int age;
    std::string gender;
  public:
    Person(std::string name, int age, std::string gender) : name(name), age(age), gender(gender) {}

    virtual void introduce() const {
      std::cout << "Hello, my name is " << name << ". I am " << age << " years old and " << gender << "." << std::endl;
    }
};

#endif