/// 6- Program to Find the Frequency of each Character in a String
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int frequencyArr[256] = {0};
    int ch;

    cout << "Enter a string: ";

    while (true)
    {
        ch = getche();
        if (ch == 13)
            break;

        frequencyArr[ch]++;
    }

    cout << "\n\nCharacter frequencies:\n";

    for (int i = 0; i < 256; i++)
    {
        if (frequencyArr[i] > 0)
        {
            cout << (char)i << " = " << frequencyArr[i] << endl;
        }
    }

    return 0;
}
