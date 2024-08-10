#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
};

struct Employee employees[MAX];
int employeeCount = 0;

main() 
{
    int choice;
    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Modify Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                viewEmployees();
                break;
            case 3:
                modifyEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void addEmployee() {
    if (employeeCount >= MAX) {
        printf("Employee list is full!\n");
        return;
    }

    struct Employee e;
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    printf("Enter Employee Name: ");
    scanf("%s", e.name);
    printf("Enter Employee Age: ");
    scanf("%d", &e.age);
    printf("Enter Employee Salary: ");
    scanf("%f", &e.salary);

    employees[employeeCount++] = e;
    printf("Employee added successfully!\n");
}

void viewEmployees() {
    if (employeeCount == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\nEmployee List:\n");
    printf("ID\tName\tAge\tSalary\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%d\t%s\t%d\t%.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }
}

void modifyEmployee() {
    int id, found = 0;
    printf("Enter Employee ID to modify: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            found = 1;
            printf("Enter new Employee Name: ");
            scanf("%s", employees[i].name);
            printf("Enter new Employee Age: ");
            scanf("%d", &employees[i].age);
            printf("Enter new Employee Salary: ");
            scanf("%f", &employees[i].salary);
            printf("Employee details updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void deleteEmployee() 
{
    int id, found = 0;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            found = 1;
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

