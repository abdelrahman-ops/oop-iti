// Program to Generate Multiplication Table "1*3=3, 2*3=6, ..."
#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    for(int i = 1; i <= 12 ; i++){
            cout << i << " X " << num << " = " << i*num << endl;
    }
    return 0;
}
