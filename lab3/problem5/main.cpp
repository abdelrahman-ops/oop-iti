/// 5- Highlight Menu: New Colored Menu "with Arrows"
#include <iostream>
#include <conio.h>
#include "MyLibrary.h"

using namespace std;

int main()
{
    int choice = 0;
    int key;

    const int menuSize = 4;

    while (true)
    {
        clrscr();

        for (int i = 0; i < menuSize; i++)
        {
            gotoxy(10, 3 + i * 2);

            if (i == choice)
            {
                textattr(0x2F);
            }
            else
            {
                textattr(0x07);
            }

            cout << (i == 0 ? "New" :
                     i == 1 ? "Open" :
                     i == 2 ? "Save" : "Exit");
        }

        textattr(0x07);

        key = getch();

        /// ESC: Exit
        if (key == 27)
        {
            break;
        }

        /// Extended keys
        if (key == 0 || key == 224)
        {
            key = getch();

            switch (key)
            {
                case 72: /// Up Arrow
                    choice--;

                    if (choice < 0)
                        choice = menuSize - 1;
                    break;

                case 80: /// Down Arrow
                    choice++;

                    if (choice >= menuSize)
                        choice = 0;
                    break;

                case 73: /// Page Up
                    choice = 0;
                    break;

                case 81: /// Page Down
                    choice = menuSize - 1;
                    break;
            }
        }
        /// Tab: Next item
        else if (key == 9)
        {
            choice++;

            if (choice >= menuSize)
                choice = 0;
        }
        /// Enter: Select
        else if (key == 13)
        {
            clrscr();

            switch (choice)
            {
                case 0:
                    cout << "New selected!";
                    break;

                case 1:
                    cout << "Open selected!";
                    break;

                case 2:
                    cout << "Save selected!";
                    break;

                case 3:
                    cout << "Goodbye!";
                    return 0;
            }

            getch();
        }
    }

    textattr(0x07);
    clrscr();

    cout << "Menu closed!\n";

    return 0;
}
