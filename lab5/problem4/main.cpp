#include <iostream>
#include <conio.h>
#include <string.h>
#include "MyLibrary.h"

using namespace std;

#define MAX_SIZE 80

void DisplayLine(char text[], int length, int cursor)
{
    textattr(0x60);

    gotoxy(5, 5);

    /// display the actual space we have for the editor
    for (int i = 0; i < MAX_SIZE; i++)
        cout << " ";


    /// go to the start
    gotoxy(5, 5);

    for (int i = 0; i < length; i++)
    {
        cout << text[i];
    }

    textattr(0x06);

    /// put the actual console cursor at the current position
    gotoxy(5 + cursor, 5);
}

int main()
{
    char text[MAX_SIZE] = "";
    int length = 0;
    int cursor = 0;
    int key;
    bool finished = false;

    clrscr();

    gotoxy(5, 3);
    cout << "kinda vim editor";

    do
    {
        DisplayLine(text, length, cursor);

        key = getch();

        if (key == 13) /// enter
        {
            finished = true;
        }
        else if (key == 27) /// esc
        {
            finished = true;
            length = 0;
            text[0] = '\0';
        }
        else if (key == 0 || key == 224) /// ex keys
        {
            key = getch();

            if (key == 75 && cursor > 0) /// <-
                cursor--;

            else if (key == 77 && cursor < length) /// ->
                cursor++;

            else if (key == 71) /// home
                cursor = 0;

            else if (key == 79) /// end
                cursor = length;
        }
        else if (key == 8 && cursor > 0) /// backspace
        {
            for (int i = cursor - 1; i < length - 1; i++)
                text[i] = text[i + 1];

            cursor--;
            length--;
            text[length] = '\0';
        }
        else if (key >= 32 && key <= 126 && length < MAX_SIZE)
        {
            if (cursor < length)
            {
                text[cursor] = key;
            }
            else
            {
                text[length] = key;
                length++;
                text[length] = '\0';
            }

            cursor++;
        }

    } while (!finished);

    clrscr();

    cout << "Final text: " << text << endl;

    return 0;
}
