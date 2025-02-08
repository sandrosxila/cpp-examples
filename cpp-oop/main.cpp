#include <iostream>
#include "Teacher.cpp"
#include "Student.cpp"

int main() {
    // Create Teacher and Student objects
    Teacher teacher("Mrs. Smith", 40, "Female", "Mathematics", 15);
    Student student("John Doe", 16, "Male", 10, 3.8);

    // Call methods for Teacher
    teacher.introduce();
    teacher.gradePapers();

    std::cout << std::endl;

    // Call methods for Student
    student.introduce();
    student.study();

    return 0;
}

// run
// g++ cpp-oop/main.cpp cpp-oop/Person.cpp cpp-oop/Teacher.cpp cpp-oop/Student.cpp -o output/school_system && output/school_system