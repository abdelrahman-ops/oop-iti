/// Employee with Functions (try to divide Ass#2 into 2 functions):
	/// Employee AddNewEmployee();
	/// void DisplayEmployee(Employee);

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

void DisplayEmployee(Employee emp){

    float net_salary = emp.salary + emp.bonus - emp.deduction;

    cout <<"\n--------Employee Details-------------\n";
    cout << "Employee's Name: " << emp.name <<endl ;
    cout << "Employee's ID: " << emp.id << endl ;
    cout << "Employee's Net Salary: " << net_salary << endl ;
}

Employee AddNewEmployee(){
    Employee emp;
    cout << "Enter your ID: " << endl ;
    cin >> emp.id;

    cin.ignore();

    cout << "Enter your Name: " << endl ;
    getline(cin, emp.name);

    cout << "Enter your Salary: " << endl ;
    cin >> emp.salary;

    cout << "Enter your Bonus: " << endl ;
    cin >> emp.bonus;

    cout << "Enter your Deduction: " << endl ;
    cin >> emp.deduction;

    return emp;
}

int main()
{
    Employee emp;
    emp = AddNewEmployee();
    DisplayEmployee(emp);

    return 0;
}
