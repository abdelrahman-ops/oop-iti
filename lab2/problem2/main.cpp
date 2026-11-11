// 2- Simple Menu with 3 choices.
#include <iostream>
#include "MyLibrary.h"
#include <conio.h>

using namespace std;

int main()
{
    int choice;

    do
    {
        clrscr();

        cout << "1. For Arabic" << endl;
        cout << "2. For English" << endl;
        cout << "3. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "marhaba" << endl;
                break;

            case 2:
                cout << "Hello!" << endl;
                break;

            case 3:
                cout << "Bye Bye!" << endl;
                break;

            default:
                cout << "Not a valid choice!" << endl;
        }

        if (choice != 3)
        {
            cout << "Press any key to continue";
            getch();
        }

    } while (choice != 3);

    return 0;
}
