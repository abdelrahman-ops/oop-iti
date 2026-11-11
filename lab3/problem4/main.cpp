/// 4- Program to take char and displays if it is "Normal or Extended key" along with its Ascii value.

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int ch;

    while(true){

        cout << "Press any key: ";
        ch = getch();

        if (ch == 0 || ch == 224)
        {
            int extendedCode = getch();

            cout << "\n Extended key - ASCII: " << extendedCode << endl;
        }
        else
        {
            cout << "\n Normal key / ASCII: " << ch << endl;
        }
    }



    return 0;
}


