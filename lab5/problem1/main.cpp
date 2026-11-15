#include <iostream>
using namespace std;

/// Pass by Value
void SwapByValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;

    cout << "Swap by value function: x = " << x << ", y = " << y << endl;
}

// Pass by Address
void SwapByAddress(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

    cout << "Swap by address function: x = " << *x << ", y = " << *y << endl;
}

// Pass by Reference
void SwapByReference(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;

    cout << "Swap by reference function: x = " << x << ", y = " << y << endl;
}

int main()
{
    int a_v = 20, b_v = 10;
    int a_a = 20, b_a = 10;
    int a_r = 20, b_r = 10;

    SwapByValue(a_v, b_v);

    cout << "In main: a_value = " << a_v << ", b_value = " << b_v << endl;

    cout << "\n";

    SwapByAddress(&a_a, &b_a);

    cout << "In main: a_address = " << a_a << ", b_address = " << b_a << endl;

    cout << "\n";

    SwapByReference(a_r, b_r);

    cout << "In main: a_ref = " << a_r << ", b_ref = " << b_r << endl;

    return 0;
}
