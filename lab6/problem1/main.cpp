/// int* IncrementArray()
///	- declare Array inside this function, read data from user and increment each value by 10.
///	- try to return fixed Array first, see what happened.
///	- then rerun dynamically allocated array.

#include <iostream>
using namespace std;

int* IncrementArray()
{
    int arr[5];

    cout << "Enter 5 elements:\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        arr[i] += 10;
    }

    return arr;
}

int main()
{
    int* ptr = IncrementArray();

    for (int i = 0; i < 5; i++)
        cout << ptr[i] << " ";

    return 0;
}
