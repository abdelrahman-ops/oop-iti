// Program to Check Whether a Character is an Alphabet or not
#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout << "Enter the thing to check if it is an alphabet or not: ";
    cin >> ch;

    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        cout << "Yes it is an alphabet ^_^";
    else
        cout << "No it is not an alphabet >_<";

    return 0;
}
