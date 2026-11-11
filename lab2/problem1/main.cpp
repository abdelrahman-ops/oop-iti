// 1- Receive numbers from the user, and exit when the sum exceeds 100.
#include <iostream>

using namespace std;

int main()
{
    int num, sum = 0;

    while(sum <= 100){
        cout << "Enter a number: ";
        cin >> num ;
        sum += num;
        cout << "current sum is: " << sum << endl;
    }
    cout << "Sum is: " << sum << endl;
    return 0;
}
