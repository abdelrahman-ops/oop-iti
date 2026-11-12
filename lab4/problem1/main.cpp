/// 1. Write a function takes 3 numbers as parameter, and returns the largest one among them...
/// write a program to test it. (Debug, try step-into function)
#include <iostream>

using namespace std;

int findLargest(int a, int b, int c){
    if (b >= a && b >= c)
        return b;
    else if (c >= a && c >= b)
        return c;
    else
        return a;
}
int main()
{
    int a , b , c;
    cout << "Enter the 3 numbers: " << endl;
    cin >> a >> b >> c;

    cout << "Largest is: "  << findLargest(a,b,c);
    return 0;
}
