// 3. Magic Box.
#include <iostream>
#include "MyLibrary.h"

using namespace std;

int main()
{
    int size = 3;

    int row = 1;
    int col = 2;

    clrscr();

    for(int num = 1; num <= size * size; num++){
        gotoxy((col) * 2, (row) * 2);
        cout << num;
        Sleep(1000);

        if(num % size == 0){
            row++;
            if(row > size) row = 1;
        }
        else {
            row--;
            if(row < 1) row = size;

            col--;
            if(col < 1) col = size;

        }
    }
    return 0;
}
