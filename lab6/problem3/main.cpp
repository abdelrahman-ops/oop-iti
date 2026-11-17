#include <iostream>

using namespace std;

int main()
{
    int students;
    int subjects;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of subjects: ";
    cin >> subjects;

    if (students <= 0 || subjects <= 0)
    {
        cout << "\nInvalid array dimensions!";
        return 0;
    }

    int** marks = new int*[students];

    for (int i = 0; i < students; i++)
    {
        marks[i] = new int[subjects];
    }

    for (int i = 0; i < students; i++)
    {
        cout << "\nEnter marks of student " << i + 1 << ":\n";

        for (int j = 0; j < subjects; j++)
        {
            cout << "Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\n-------- Students Sum --------\n";

    for (int i = 0; i < students; i++)
    {
        int sum = 0;

        for (int j = 0; j < subjects; j++)
        {
            sum += marks[i][j];
        }

        cout << "Total of Student " << i + 1 << ": " << sum << endl;
    }

    cout << "\n-------- Subjects Average --------\n";

    for (int i = 0; i < subjects; i++)
    {
        float sum = 0.0;

        for (int j = 0; j < students; j++)
        {
            sum += marks[j][i];
        }

        float avg = sum / students;

        cout << "Average of Subject " << i + 1 << ": " << avg << endl;
    }

    for (int i = 0; i < students; i++)
    {
        delete[] marks[i];
    }

    delete[] marks;

    return 0;
}
