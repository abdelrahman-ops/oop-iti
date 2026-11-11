/// 8- Program to Find the Length of a String "without Using strlen() or size()"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int length = 0;

    cout << "Enter a string: ";
    cin >> str;

    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }

    cout << "Length of the string: " << length << endl;

    return 0;
}

