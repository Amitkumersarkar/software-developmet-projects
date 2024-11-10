/*
Student Record Management system project
using c program created by A.S ID-22235103283 Int-51..!
*/
// here we define important libraries to include..
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// here we define data structure and constant..
#define MAX 100
// here we define structure and name..
struct Student
{
    int id;
    char name[100];
    int age;
    float gpa;
    char semester[100];
    char department[100];
    int phone;
};

// here we declared functions..

void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count, int id);
void modifyStudent(struct Student students[], int count, int id);
void deleteStudent(struct Student students[], int *count, int id);

// here we declared main functions..

int main()
{
    struct Student students[MAX];
    int count = 0;
    int choice, id;
    while (1)
    {
        printf("\n------STUDENTS RECORD MANAGEMENT SYSTEM PROJECTS------\n");
        printf("1. ADD STUDENT\n");
        printf("2. DISPLAY STUDENTS\n");
        printf("3. SEARCH STUDENT\n");
        printf("4. MODIFY STUDENT\n");
        printf("5. DELETE STUDENT\n");
        printf("6. EXIT\n");
        printf(" ENTER YOUR CHOICE :");
        printf(" %d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(students, &count);
            break;
        case 2:
            displayStudents(students, &count);
            break;
        case 3:
            printf("Enter Student ID To Search : ");
            scanf("%d", &id);
            searchStudent(students, count, id);
            break;
        case 4:
            printf("Enter Student ID To Modify : ");
            scanf("%d", &id);
            modifyStudent(students, count, id);
            break;
        case 5:
            printf("Enter Student ID To Delete : ");
            scanf("%d", &id);
            deleteStudent(students, &count, id);
            break;
        case 6:
            printf("EXITING\n");
            scanf("%d", &id);
        default:
            printf("INVALID CHOICE PLEASE TRY AGAIN\n");
        }
    }
    return 0;
}

// here we declared functions to add students..
void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX)
    {
        printf("CANNOT ADD MORE STUDENTS, BECAUSE DATABASE IS FULL\n");
        return 0;
    }

    struct Student new_student;
    printf("ENTER YOUR STUDENT ID : ");
    scanf("%d", &new_student.id);

    printf("ENTER YOUR NAME : ");
    scanf("%s", &new_student.name);

    printf("ENTER YOUR AGE : ");
    scanf("%d", &new_student.age);

    printf("ENTER YOUR GPA : ");
    scanf("%f", &new_student.gpa);

    printf("ENTER YOUR SEMESTER : ");
    scanf("%s", &new_student.semester);

    printf("ENTER YOUR DEPARTMENT : ");
    scanf("%s", &new_student.department);

    printf("ENTER YOUR PHONE NUMBER: ");
    scanf("%d", &new_student.phone);

    students[*count] = new_student;
    (*count)++;
    printf("STUDENT ADDED SUCCESSFULLY\n");
}

// here we declared a functions to display all students..
void displayStudents(struct Student students[], int count)
{
    printf("\n----- STUDENT RECORD-----\n");
    for (int i = 0; i < count; i++)
    {
        printf("STUDENT FOUND : ID : %d, NAME : %s, AGE: %d, GPA : %.2f, SEMESTER : %s, DEPARTMENT : %s, PHONE : %d\n", students[i].id, students[i].name, students[i].age, students[i].gpa, students[i].semester, students[i].department, students[i].phone);
    }
}

// here we declared function to search students by id
void searchStudent(struct Student students[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("STUDENT FOUND : ID : %d, NAME : %s, AGE: %d, GPA : %.2f, SEMESTER : %s, DEPARTMENT : %s, PHONE : %d\n", students[i].id, students[i].name, students[i].age, students[i].gpa, students[i].semester, students[i].department, students[i].phone);
            return;
        }
    }
    printf("STUDENT WITH ID %d NOT FOUND\n", id);
}
// here we declared a functions to modify students information..
void modifyStudent(struct Student students[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("MODIFYING STUDENT ID %d\n", id);
            printf("ENTER YOUR NEW NAME : ");
            scanf("%s", &students[i].age);

            printf("ENTER NEW AGE : ");
            scanf("%d", &students[i].name);

            printf("ENTER YOUR NEW GPA : ");
            scanf("%f", students[i].gpa);

            printf("ENTER YOUR NEW SEMESTER : ");
            scanf("%s", students[i].semester);

            printf("ENTER YOUR NEW DEPARTMENT : ");
            scanf("%s", students[i].department);

            printf("ENTER YOUR NEW PHONE : ");
            scanf("%d", students[i].phone);
            printf("STUDENT RECORD UPDATED SUCCESSFULLY\n");
            return;
        }
    }
    printf("STUDENT WITH ID %d NOT FOUND\n", id);
}
// here we declared function to delete a student by id..
void deleteStudent(struct Student students[], int *count, int id)
{
    for (int i = 0; i < *count; i++)
    {
        if (students[i].id == id)
        {
            for (int j = i; j < *count - 1; j++)
            {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("STUDENT WITH ID %d DELETED SUCCESSFULLY\n", id);
            return;
        }
    }
    printf("STUDENT WITH ID %d NOT FOUND\n", id);
}
