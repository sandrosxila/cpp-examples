#include <stdio.h>
#include <stdlib.h>
#include "Teacher.h"
#include "Student.h"

int main() {
    // Create Teacher and Student objects
    Teacher *teacher = create_teacher("Mrs. Smith", 40, "Female", "Mathematics", 15);
    Student *student = create_student("John Doe", 16, "Male", 10, 3.8);

    // Call methods for Teacher
    introduce_teacher(teacher);
    grade_papers(teacher);

    printf("\n");

    // Call methods for Student
    introduce_student(student);
    study(student);

    // Free allocated memory
    free(teacher);
    free(student);
    
    return 0;
}

// Run:
// gcc c-oop/main.c c-oop/Person.c c-oop/Teacher.c c-oop/Student.c -o output/school_system && output/school_system