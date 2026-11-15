/// Return Multiple values from function "Using Pass By Address":
/// void Calculate(int X, int Y, int* SumPtr, int* SubPtr, int* MultipPtr, int* DivPtr);

#include <iostream>

using namespace std;


int SumArray(int* ptr, int size){

    cout << "Array elements: "<< endl;

    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << " ";

        sum += *(ptr + i);
    }

    return sum;

}



int main()
{
    int arr[100];
    int size;

    cout << "Enter size of the array: " << endl;
    cin >> size;

    cout << "Enter array elements: " << endl;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int result = SumArray(arr, size);

    cout << "\nSum = " << result << endl;

    return 0;
}
