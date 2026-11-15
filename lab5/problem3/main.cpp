#include <iostream>

using namespace std;

void Calculate(int X, int Y, int* SumPtr, int* SubPtr, int* MultipPtr, int* DivPtr){
    *SumPtr = X + X;
    *SubPtr = X - Y;
    *MultipPtr = X * Y;

    if(Y != 0){
        *DivPtr = X / Y;
    }
    else
    {
        *DivPtr = 0;
        cout << "\nDivision by zero is not allowed!";
    }
}

int main()
{
    int x, y;

    int sum, sub, multip, div;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    Calculate(x, y, &sum, &sub, &multip, &div);

    cout << "Sum = " << sum << endl;
    cout << "Subtraction = " << sub << endl;
    cout << "Multiplication = " << multip << endl;

    if (y != 0)
        cout << "Division = " << div << endl;

    cout << "Hello world!" << endl;
    return 0;
}
