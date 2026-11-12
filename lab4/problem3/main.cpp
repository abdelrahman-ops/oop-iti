/// Program to take information of Array of 5 Employees, then display their data. (EmpArr_of_Struct)
#include <iostream>
#include <string>

using namespace std;

struct Employee{
    int id;
    string name;
    float salary;
    float bonus;
    float deduction;
};

void print_employees(Employee emp[]){

    cout <<"\n--------Employees Details-------------\n";

    for(int i = 0; i < 5; i++){
        cout << "Employee " << i+1 << " Data"<< endl ;
        cout << "Employee's ID: " << emp[i].id << endl ;
        cout << "Employee's Name: " << emp[i].name << endl ;
        cout << "Employee's Salary: " << emp[i].salary << endl ;
        cout << "Employee's Bonus: " << emp[i].bonus << endl ;
        cout << "Employee's Deduction: " << emp[i].deduction << endl ;
        cout << "---------------------------------------\n";
    }
}


int main()
{
    Employee employees[5];
    for(int i = 0; i < 5; i++){
        cout << "Enter Data Of Employee " << i+1 << endl ;

        cout << "Employee's ID: " << endl ;
        cin >> employees[i].id;

        cin.ignore();
        cout << "Employee's Name: " << endl ;
        getline(cin, employees[i].name);

        cout << "Employee's Salary: " << endl ;
        cin >> employees[i].salary;

        cout << "Employee's Bonus: " << endl ;
        cin >> employees[i].bonus;

        cout << "Employee's Deduction: " << endl ;
        cin >> employees[i].deduction;
    }



    print_employees(employees);


    return 0;
}
