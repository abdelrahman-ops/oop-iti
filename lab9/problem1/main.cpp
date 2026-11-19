#include <iostream>
using namespace std;


int SUM(int x = 10, int y = 20, int z = 30);



int main()
{
    int x, y, z = 99;
    cout << "SUM(1, 2, 3) = " << SUM(1, 2, 3) << endl;
    cout << "SUM(1, 2) = " << SUM(1, 2) << endl;
    cout << "SUM(1) = " << SUM(1) << endl;
    cout << "SUM() = " << SUM() << endl;

    return 0;
}


int SUM(int x, int y, int z)
{
    int result;

    result = x + y + z;

    return result;
}
