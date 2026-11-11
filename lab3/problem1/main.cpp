/// 1. Program to find the minimum & maximum value of array elements. (Min_Max Array)
#include <iostream>

using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    int arr[size] = {};

    cout << "Enter the array elements: " << endl;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    int min = arr[0];
    int max = arr[0];

    for(int i = 1; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
        if(arr[i] > max){
            max = arr[i];
        }
    }

    cout << "Minimum is: " << min << endl;
    cout << "Max is: " << max << endl;

    return 0;
}
