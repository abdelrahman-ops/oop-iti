///Try to Use Struct inside struct, Create Struct Dept (Dept has: id, name, and Multiple Employees)
#include <iostream>

#define MAX_EMPLOYEES 5
using namespace std;

struct Employee{
    int id;
    string name;
    float salary;
    float bonus;
    float deduction;
    bool isExisted;
};

struct Dept{
    int id;
    string name;
    Employee employees[MAX_EMPLOYEES];
};

int main()
{
    Dept dept;

    cout << "Enter Department ID: ";
    cin >> dept.id;

    cout << "Enter Department Name: ";
    cin >> dept.name;

    int count;

    cout << "Enter number of employees: ";
    cin >> count;

    if (count < 0 || count > MAX_EMPLOYEES)
    {
        cout << "Invalid number of employees!";
        return 0;
    }

    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        dept.employees[i].isExisted = false;
    }

    /// Input employees
    for (int i = 0; i < count; i++)
    {
        cout << "\nEmployee " << i + 1 << endl;

        cout << "Enter ID: ";
        cin >> dept.employees[i].id;

        cout << "Enter Name: ";
        cin >> dept.employees[i].name;

        cout << "Enter Salary: ";
        cin >> dept.employees[i].salary;

        cout << "Enter Bonus: ";
        cin >> dept.employees[i].bonus;

        cout << "Enter Deduction: ";
        cin >> dept.employees[i].deduction;

        dept.employees[i].isExisted = true;
    }

    /// Display department
    cout << "\n========== DEPARTMENT ==========\n";

    cout << "Department ID: " << dept.id << endl;
    cout << "Department Name: " << dept.name << endl;

    // Display employees
    cout << "\n========== EMPLOYEES ==========\n";

    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        if (dept.employees[i].isExisted == true)
        {
            cout << "\nEmployee " << i + 1 << endl;

            cout << "ID: " << dept.employees[i].id << endl;
            cout << "Name: " << dept.employees[i].name << endl;

            cout << "Net Salary: " << dept.employees[i].salary + dept.employees[i].bonus - dept.employees[i].deduction << endl;
        }
    }

    return 0;
}
