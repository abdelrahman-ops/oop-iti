#include <iostream>
using namespace std;

int* IncrementArray(int& size)
{
    cout << "Enter array size: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter array elements:\n";

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        arr[i] += 10;
    }

    return arr;
}

int main()
{
    int size;
    int* ptr = IncrementArray(size);

    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }

    delete[] ptr;

    return 0;
}
