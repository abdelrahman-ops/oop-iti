/// 3.Program to add two matrix and put the result in a third one, then print the result.

#include <iostream>

using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    /// the 3 matricies
    int A[10][10];
    int B[10][10];
    int C[10][10];

    cout << "\nEnter Matrix A:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "\nEnter Matrix B:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> B[i][j];
        }
    }

    // Add matrices
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print result
    cout << "\nResult Matrix:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << C[i][j] << "\t";
        }

        cout << endl;
    }

    return 0;
}

