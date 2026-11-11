/// 9. Program to Implement a Jagged Array without Using Pointers

#include <iostream>

using namespace std;

int main()
{
    const int MAX_ROWS = 10;
    const int MAX_COLS = 10;

    int arr[MAX_ROWS][MAX_COLS];
    int sizes[MAX_ROWS];

    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    if (rows < 1 || rows > MAX_ROWS)
    {
        cout << "Invalid number of rows!" << endl;
        return 0;
    }

    for (int i = 0; i < rows; i++)
    {
        cout << "\nEnter number of elements in row " << i + 1 << ": ";

        cin >> sizes[i];

        if (sizes[i] < 1 || sizes[i] > MAX_COLS)
        {
            cout << "Invalid number of elements!" << endl;
            return 0;
        }

        for (int j = 0; j < sizes[i]; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "\nJagged Array:\n";

    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << ": ";

        for (int j = 0; j < sizes[i]; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
