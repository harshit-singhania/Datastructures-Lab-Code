#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee
{
    int id, age, salary;
    char name[30], designation[30], department[30];
};

int main()
{
    struct Employee e;
    int num_records;

    printf("enter the number of records: ");
    scanf("%d", &num_records);

    for (int i = 0; i < num_records; i++)
    {
        printf("Enter the id of the Employee: ");
        scanf("%d", &e.id);

        printf("Enter the age of the Employee: ");
        scanf("%d", &e.age);

        printf("Enter the name of the Employee: ");
        getchar();
        fgets(e.name, 30, stdin);

        printf("Enter the designation of the Employee: ");
        fgets(e.designation, 30, stdin);

        printf("Enter the department of the Employee: ");
        fgets(e.department, 30, stdin);

        printf("Enter the salary of the Employee: ");
        scanf("%d", &e.salary);

        int gross_pay = e.salary + (0.25 * e.salary) + (0.75 * e.salary);

        printf("\nEmployee Details:\n");
        printf("Employee Id: %d\n", e.id);
        printf("Employee Name: %s", e.name);
        printf("Employee age: %d\n", e.age);
        printf("Employee designation: %s", e.designation);
        printf("Employee department: %s", e.department);
        printf("Employee gross salary: %d\n", gross_pay);
    }

    return 0;
}