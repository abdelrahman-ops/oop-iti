#include <iostream>
#include <conio.h>
#include "MyLibrary.h"
#include <string>

#define MENU_SIZE 6

using namespace std;

struct Employee
{
    int id;
    string name;
    float salary;
    float bonus;
    float deduction;
    bool isExisted;
};

Employee AddNewEmployee()
{
    Employee emp;

    cout << "Enter your ID: " << endl;
    cin >> emp.id;

    cin.ignore(1000, '\n');

    cout << "Enter your Name: " << endl;
    getline(cin, emp.name);

    cout << "Enter your Salary: " << endl;
    cin >> emp.salary;

    cout << "Enter your Bonus: " << endl;
    cin >> emp.bonus;

    cout << "Enter your Deduction: " << endl;
    cin >> emp.deduction;

    emp.isExisted = true;

    return emp;
}

void DisplayEmployee(Employee emp)
{
    cout << "Employee's ID: " << emp.id << endl;
    cout << "Employee's Name: " << emp.name << endl;
    cout << "Employee's Salary: " << emp.salary << endl;
    cout << "Employee's Bonus: " << emp.bonus << endl;
    cout << "Employee's Deduction: " << emp.deduction << endl;

    cout << "Net Salary: " << emp.salary + emp.bonus - emp.deduction << endl;
}

void DisplayAllEmployees(Employee employees[], int size)
{
    bool found = false;

    cout << "\n--------Employees Details-------------\n";

    for (int i = 0; i < size; i++)
    {
        if (employees[i].isExisted == true)
        {
            cout << "\nEmployee index " << i << endl;

            DisplayEmployee(employees[i]);

            found = true;
        }
    }

    if (found == false)
    {
        cout << "\nNo employees found!";
    }
}

void DeleteEmployee(Employee employees[], int index)
{
    employees[index].isExisted = false;
}

void DeleteAllEmployees(Employee employees[], int size)
{
    for (int i = 0; i < size; i++)
    {
        employees[i].isExisted = false;
    }
}

bool CheckIndexValidation(Employee employees[], int index, int size, bool isNew)
{
    if (index < 0 || index >= size)
    {
        cout << "\nInvalid Index!";
        return false;
    }

    if (isNew == true && employees[index].isExisted == true)
    {
        cout << "\nThis index is already occupied!";
        return false;
    }

    if (isNew == false && employees[index].isExisted == false)
    {
        cout << "\nNo employee exists in this index!";
        return false;
    }

    return true;
}

int ShowMenu()
{
    int choice = 0;
    int key;

    do
    {
        clrscr();

        cout << "========== Employee Menu ==========";

        for (int i = 0; i < MENU_SIZE; i++)
        {
            gotoxy(10, 3 + i * 2);

            if (i == choice)
                textattr(0x2F);
            else
                textattr(0x07);

            switch (i)
            {
                case 0:
                    cout << "New";
                    break;

                case 1:
                    cout << "Display";
                    break;

                case 2:
                    cout << "Display All";
                    break;

                case 3:
                    cout << "Delete";
                    break;

                case 4:
                    cout << "Delete All";
                    break;

                case 5:
                    cout << "Exit";
                    break;
            }
        }

        textattr(0x07);

        key = getch();

        /// ESC: Exit
        if (key == 27)
        {
            return -1;
        }

        /// Extended keys
        if (key == 0 || key == 224)
        {
            key = getch();

            switch (key)
            {
                case 72: /// Up Arrow
                    choice--;

                    if (choice < 0)
                        choice = MENU_SIZE - 1;

                    break;

                case 80: /// Down Arrow
                    choice++;

                    if (choice >= MENU_SIZE)
                        choice = 0;

                    break;

                case 73: /// Page Up
                    choice = 0;
                    break;

                case 81: /// Page Down
                    choice = MENU_SIZE - 1;
                    break;
            }
        }

        /// Tab: Next item
        else if (key == 9)
        {
            choice++;

            if (choice >= MENU_SIZE)
                choice = 0;
        }

    } while (key != 13);

    return choice;
}

int main()
{
    int size;

    cout << "Enter the number of employees: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "\nInvalid array size!";
        return 0;
    }

    /// Dynamic allocation
    Employee* employees = new Employee[size]();

    int choice;
    int index;

    do
    {
        choice = ShowMenu();

        clrscr();

        textattr(0x07);

        switch (choice)
        {
            case 0: /// New
            {
                cout << "Enter employee index (0-" << size - 1 << "): ";
                cin >> index;

                if (CheckIndexValidation(employees, index, size, true))
                {
                    employees[index] = AddNewEmployee();
                }

                getch();
                break;
            }

            case 1: /// Display one
            {
                cout << "Enter employee index (0-" << size - 1 << "): ";
                cin >> index;

                if (CheckIndexValidation(employees, index, size, false))
                {
                    DisplayEmployee(employees[index]);
                }

                getch();
                break;
            }

            case 2: /// Display all
            {
                cout << "Employees Data: ";

                DisplayAllEmployees(employees, size);

                getch();
                break;
            }

            case 3: /// Delete one
            {
                cout << "Enter the index of the employee you want to delete (0-"
                     << size - 1 << "): ";

                cin >> index;

                if (CheckIndexValidation(employees, index, size, false))
                {
                    DeleteEmployee(employees, index);
                    cout << "\nEmployee deleted successfully!";
                }

                getch();
                break;
            }

            case 4: /// Delete all
            {
                DeleteAllEmployees(employees, size);

                cout << "All employees deleted!";

                getch();
                break;
            }

            case 5: /// Exit
            {
                cout << "Goodbye!";
                break;
            }
        }

    } while (choice != 5 && choice != -1);


    delete[] employees;

    textattr(0x07);
    clrscr();

    cout << "Menu closed!\n";

    return 0;
}
