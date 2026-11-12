/// Recursive: Power.
#include <iostream>

using namespace std;

int Power(int base, int exponent){

    if(exponent == 0){
        return 1;
    }
    return base * Power(base, exponent - 1);


}
int main()
{
    int base, exponent;
    cout << "Enter the base and the exponent: " << endl;
    cin >> base >> exponent;
    if(exponent < 0){
        cout << "Can't perform this operation - add a positive number for the exponent!";
    }
    else cout << base << "^" << exponent << " = " << Power(base, exponent);
    return 0;
}
