// 4. Program to Find the Largest Number Among Three Numbers
#include <iostream>

using namespace std;

int main()
{
    int num1, num2, num3;
    cout << "Enter num1: ";
    cin >> num1;
    cout << "Enter num2: ";
    cin >> num2;
    cout << "Enter num3: ";
    cin >> num3;

    int large ;

    if(num1 > num2 && num1 > num3){
        cout << "largest is: " << num1;
    }
    else if(num2 > num1 && num2 > num3){
        cout << "largest is: " << num2;
    }
    else {
        cout << "largest is: " << num3;
    }
    return 0;
}
