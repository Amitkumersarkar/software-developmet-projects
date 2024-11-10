/*
Student Record Management system project
using c program created by A.S ID-22235103283 Int-51..!
*/
// here we define important libraries to include..
#include <stdio.h>
#include <math.h>
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

void addStudent(struct Student Students[], int *count);
void displayStudents(struct Student Students[], int count);
void searchStudent(struct Student Students[], int count, id);
void modifyStudent(struct Student Students[], int count, int id);
void deleteStudent(struct Student Students[], int *count);
// void exitStudents(struct Student Students[], int *count, int id);

// here we declared main functions..

int main()
{
    struct Student students[max];
    int count = 0;
    int choice, id;
    while (1)
    {
        printf("\n*****STUDENTS RECORD MANAGEMENT SYSTEM PROJECTS****\n");
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
            printf("EXITING.....\n");
            scanf("%d", &id);
        default:
            printf("INVALID CHOICE.! PLEASE TRY AGAIN..\n");
        }
    }
    return 0;
}

// here we declared functions to add students..
void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX)
    {
        printf("CAN'T ADD MORE STUDENTS, BECAUSE DATABASE IS FULL..!!\n");
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
    scanf("%f", &new_student.semester);

    printf("ENTER YOUR DEPARTMENT : ");
    scanf("%f", &new_student.department);

    printf("ENTER YOUR PHONE NUMBER: ");
    scanf("%f", &new_student.phone);
}