/// 2.Program to Calculate "Sum of each row" , "Average of each column" in a 2D Array. (3 std, 4 subjects)
#include <iostream>

using namespace std;

int main()
{
    const int students = 3;
    const int subjects = 4;

    int marks[students][subjects];

    for(int i = 0; i < students; i++){
        cout << "Enter marks of the student "  << i+1  << ":\n";
        for(int j = 0; j < subjects; j++){
            cout << "Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    /// Sum of each row

    for(int i = 0; i < students; i++){
        int sum = 0;

        for(int j = 0; j < subjects; j++){

            sum += marks[i][j];
        }

        cout << "Total of Student " << i + 1 << ": " << sum << endl;
    }

    /// Avg of each col

    for(int i = 0; i < subjects; i++){
        int sum = 0;

        for(int j = 0; j < students; j++){

            sum += marks[j][i];
        }
        float avg = (float)sum / students;

        cout << "Average of Subject " << i + 1 << ": " << avg << endl;
    }



    return 0;
}
