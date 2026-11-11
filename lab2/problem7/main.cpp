// Program to Count number of Alphabets & number of words in a sentence. (word count "without using built-in String")

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    char ch;
    int no_alphabets = 0;
    int no_words = 0;
    bool inWord = false;

    cout << "Enter a sentence: ";

    while ((ch = getche()) != '\r')
    {
        if ( (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) no_alphabets++;

        if (ch != ' ' && ch != '\t')
        {
            if (inWord == false)
            {
                no_words++;
                inWord = true;
            }
        }
        else
        {
            inWord = false;
        }
    }

    cout << "\nNumber of alphabets: " << no_alphabets << endl;
    cout << "Number of words: " << no_words << endl;

    return 0;
}

