/// 7- Program to Remove all Characters in a String Except Alphabet
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    int j = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            str[j] = str[i];
            j++;
        }
    }

    cout << "Result: " << str << endl;

    return 0;
}



