// Add students and the subjects they study ✅
// Add teachers and the subject they teach
// Assign Grades to students per subject in school
// Find which students are enrolled in a specified subject ✅
// Find the grades a specified student has achieved in a specified subject 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int studentId;
    char name[50];
    int *subjectId;
    float *grades;
} Student;

typedef struct {
    int teacherId;
    char name[50];
    int subjectId;
} Teacher;

typedef struct {
    int subjectId;
    char name[50];
} Subject;

// Adding a student
Student * createStudent() 
{
    Student *newStudent = (Student*)malloc(sizeof(Student));
    printf("Enter new Student ID: ");
    scanf("%u", &(newStudent->studentId));
    // prompt all other important details from the user

    return newStudent;
}
