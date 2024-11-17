#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
// here we define structure of students
struct Student
{
    int id;
    char name[100];
    char department[100];
    float cgpa;
    int age;
    char phone[100];
    char blood_group[100];
};

// here we declared function prototype

void addStudent(struct Student students[], int *count);
void showStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count, int id);
void deleteStudent(struct Student students[], int *count, int id);

int main()
{
    struct Student students[MAX];
    int count = 0;
    int choice, id;
    while (1)
    {
        printf("\n***** Student Record Management System *****\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Search Student By Id\n");
        printf("4. Delete Student By Id\n");
        printf("5. Exit\n");
        printf("Enter Your Choice = ");
        scanf("%d", &choice);

        // here we used switch case function

        switch (choice)
        {
        case 1:
            addStudent(students, &count);
            break;

        case 2:
            showStudents(students, count);
            break;

        case 3:
            printf("Enter Student Id To Search :");
            scanf("%d", &id);
            searchStudent(students, count, id);
            break;

        case 4:
            printf("Enter Student Id To Delete :");
            scanf("%d", &id);
            deleteStudent(students, &count, id);
            break;

        case 5:
            printf("Exiting.....\n");
            exit(0);

        default:
            printf("Invalid Choice Please Try Again\n");
        }
    }
    return 0;
}

// here we added new student record

void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX)
    {
        printf("Database Is Full ! Cant't Add More Student\n");
        return;
    }

    struct Student new_student;
    printf("Enter Student Id :");
    scanf("%d", &new_student.id);
    // here we used getchar function to consume extra new line
    getchar();

    printf("Enter Name :");
    fgets(new_student.name, sizeof(new_student.name), stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0';

    printf("Enter Department : ");
    fgets(new_student.department, sizeof(new_student.department), stdin);
    new_student.department[strcspn(new_student.department, "\n")] = '\0';

    printf("Enter Cgpa :");
    scanf("%f", &new_student.cgpa);

    printf("Enter Age :");
    scanf("%d", &new_student.age);
    getchar();

    printf("Enter Phone Number :");
    fgets(new_student.phone, sizeof(new_student.phone), stdin);
    new_student.phone[strcspn(new_student.phone, "\n")] = '\0';

    printf("Enter Blood Group :");
    fgets(new_student.blood_group, sizeof(new_student.blood_group), stdin);
    new_student.blood_group[strcspn(new_student.blood_group, "\n")] = '\0';

    students[*count] = new_student;
    (*count)++;
    printf("Student Added Successfully \n");
}

// here we showed all student record

void showStudents(struct Student students[], int count)
{
    if (count == 0)
    {
        printf("No Student Records Available At That Moment\n");
        return;
    }

    // here we print all student records

    printf("\n***** All student Records*****\n");
    for (int i = 0; i < count; i++)
    {
        printf("ID : %d\n", students[i].id);

        printf("Name : %s\n", students[i].name);

        printf("Department : %s\n", students[i].department);

        printf("CGPA : %.1f\n", students[i].cgpa);

        printf("Age : %d\n", students[i].age);

        printf("Phone : %s\n", students[i].phone);

        printf("Blood Group : %s\n", students[i].blood_group);
        printf("********************************\n");
    }
}

// here we can search student by id

void searchStudent(struct Student students[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("Student Found : \n");
            printf("ID : %d\n", students[i].id);

            printf("Name : %s\n", students[i].name);

            printf("Department : %s\n", students[i].department);

            printf("CGPA : %.1f\n", students[i].cgpa);

            printf("Age : %d\n", students[i].age);

            printf("Phone : %s\n", students[i].phone);

            printf("Blood Group : %s\n", students[i].blood_group);

            return;
        }
    }
    printf("Student With ID %d Isn't Found\n", id);
}

// here deleted student record by id

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
            printf("Student With Id %d Deleted Successfully\n", id);
            return;
        }
    }
    printf("Student With Id %d Isn't Found\n", id);
}

// Finally Completed the whole projects...!!
