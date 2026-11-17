#include <iostream>
#include <conio.h>
#include "MyLibrary.h"

using namespace std;

void DisplayLine(char* text, int length, int cursor, int maxSize)
{
    textattr(0x40);

    gotoxy(5, 5);

    for (int i = 0; i < maxSize; i++)
        cout << " ";

    gotoxy(5, 5);

    for (int i = 0; i < length; i++)
    {
        cout << text[i];
    }

    textattr(0x04);

    gotoxy(5 + cursor, 5);
}

int main()
{
    int maxSize;

    cout << "Enter the max size: ";
    cin >> maxSize;

    if (maxSize <= 0 )
    {
        cout << "\nInvalid size! Enter a size > 0";
        return 0;
    }

    char* text = new char[maxSize];

    text[0] = '\0';

    int length = 0;
    int cursor = 0;
    int key;
    bool finished = false;

    clrscr();

    gotoxy(5, 3);
    cout << "Notepad editor";

    do
    {
        DisplayLine(text, length, cursor, maxSize);

        key = getch();

        if (key == 13) // Enter
        {
            finished = true;
        }

        else if (key == 27) // ESC
        {
            finished = true;
            length = 0;
        }

        else if (key == 0 || key == 224) // Extended keys
        {
            key = getch();

            if (key == 75 && cursor > 0) // Left
                cursor--;

            else if (key == 77 && cursor < length) // Right
                cursor++;

            else if (key == 71) // Home
                cursor = 0;

            else if (key == 79) // End
                cursor = length;

            else if (key == 83 && cursor < length) // Delete
            {
                for (int i = cursor; i < length - 1; i++)
                    text[i] = text[i + 1];

                length--;
            }
        }

        else if (key == 8 && cursor > 0) // Backspace
        {
            for (int i = cursor - 1; i < length - 1; i++)
                text[i] = text[i + 1];

            cursor--;
            length--;
        }

        else if (key >= 32 && key <= 126)
        {
            if (cursor < length)
            {
                // Overwrite existing character
                text[cursor] = key;
                cursor++;
            }
            else if (length < maxSize)
            {
                // Append new character
                text[length] = key;

                length++;
                cursor++;
            }
        }

    } while (!finished);

    clrscr();

    cout << "Final text: " << text << endl;

    delete[] text;

    return 0;
}
