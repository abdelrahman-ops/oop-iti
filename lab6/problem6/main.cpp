#include <iostream>

using namespace std;

int main()
{
    int** arr;
    int* sizes;

    int rows;

    cout << "Enter number of students: ";
    cin >> rows;

    if (rows < 1)
    {
        cout << "Invalid number of students!" << endl;
        return 0;
    }

    arr = new int*[rows];

    sizes = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        cout << "\nEnter number of subjects for student " << i + 1 << ": ";

        cin >> sizes[i];

        if (sizes[i] < 1)
        {
            cout << "Invalid number of subjects!" << endl;

            for (int j = 0; j < i; j++)
                delete[] arr[j];

            delete[] arr;
            delete[] sizes;

            return 0;
        }

        arr[i] = new int[sizes[i]];

        for (int j = 0; j < sizes[i]; j++)
        {
            cout << "Enter mark [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "\nJagged Array:\n";

    for (int i = 0; i < rows; i++)
    {
        cout << "Student " << i + 1 << ": ";

        for (int j = 0; j < sizes[i]; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    delete[] sizes;

    return 0;
}
