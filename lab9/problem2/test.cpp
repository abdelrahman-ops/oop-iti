
#include <iostream>
#include <stdexcept>
using namespace std;

class Complex
{
private:
    float real;
    float img;

public:

    // Constructors
    Complex()
    {
        real = 0;
        img = 0;
    }

    Complex(float r, float i = 0)
    {
        real = r;
        img = i;
    }

    // Print
    void PrintComplex()
    {
        cout << real;

        if (img >= 0)
            cout << " + " << img << "i";
        else
            cout << " - " << -img << "i";

        cout << endl;
    }

    // 1) Complex - Complex
    Complex operator-(const Complex& C)
    {
        Complex result;

        result.real = real - C.real;
        result.img = img - C.img;

        return result;
    }

    // 2) Complex - Number
    Complex operator-(float num)
    {
        Complex result;

        result.real = real - num;
        result.img = img;

        return result;
    }

    // 3) Number - Complex
    friend Complex operator-(float num, const Complex& C)
    {
        Complex result;

        result.real = num - C.real;
        result.img = -C.img;

        return result;
    }

    // 4) -=
    Complex& operator-=(const Complex& C)
    {
        real -= C.real;
        img -= C.img;

        return *this;
    }

    // 5) Prefix --
    Complex& operator--()
    {
        real--;
        img--;

        return *this;
    }

    // 6) Postfix --
    Complex operator--(int)
    {
        Complex temp(*this);

        real--;
        img--;

        return temp;
    }

    // 7) ==
    bool operator==(const Complex& C)
    {
        return (real == C.real && img == C.img);
    }

    // 8) !=
    bool operator!=(const Complex& C)
    {
        return !(*this == C);
    }

    // Helper: Squared Magnitude
    float magnitudeSquared()
    {
        return real * real + img * img;
    }

    // 9) >
    bool operator>(const Complex& C)
    {
        return magnitudeSquared() > C.magnitudeSquared();
    }

    // 10) >=
    bool operator>=(const Complex& C)
    {
        return magnitudeSquared() >= C.magnitudeSquared();
    }

    // 11) <
    bool operator<(const Complex& C)
    {
        return magnitudeSquared() < C.magnitudeSquared();
    }

    // 12) <=
    bool operator<=(const Complex& C)
    {
        return magnitudeSquared() <= C.magnitudeSquared();
    }

    // 13) Type Conversion
    operator int()
    {
        return (int)real;
    }

    // 14) Subscript Operator
    float& operator[](char ch)
    {
        if (ch == 'R')
            return real;

        if (ch == 'I')
            return img;

        throw invalid_argument("Invalid component");
    }
};

int main()
{
    Complex C1(8, 6);
    Complex C2(3, 2);
    Complex C3;

    // 1) Complex - Complex
    C3 = C1 - C2;
    cout << "C1 - C2 = ";
    C3.PrintComplex();

    // 2) Number - Complex
    C3 = 7 - C2;
    cout << "7 - C2 = ";
    C3.PrintComplex();

    // 3) Complex - Number
    C3 = C2 - 7;
    cout << "C2 - 7 = ";
    C3.PrintComplex();

    // 4) -=
    C1 -= C2;
    cout << "C1 -= C2: ";
    C1.PrintComplex();

    // 5) Prefix --
    C2 = --C1;
    cout << "Prefix C1: ";
    C1.PrintComplex();
    cout << "C2: ";
    C2.PrintComplex();

    // 6) Postfix --
    C2 = C1--;
    cout << "Postfix C1: ";
    C1.PrintComplex();
    cout << "C2: ";
    C2.PrintComplex();

    // 7) ==
    cout << "C1 == C2: " << (C1 == C2) << endl;

    // 8) !=
    cout << "C1 != C2: " << (C1 != C2) << endl;

    // 9-12) Relational Operators
    cout << "C1 > C2: " << (C1 > C2) << endl;
    cout << "C1 >= C2: " << (C1 >= C2) << endl;
    cout << "C1 < C2: " << (C1 < C2) << endl;
    cout << "C1 <= C2: " << (C1 <= C2) << endl;

    // 13) Type Conversion
    int num = (int)C1;
    cout << "(int) C1 = " << num << endl;

    // 14) Subscript Operator
    cout << "C1['R'] = " << C1['R'] << endl;
    cout << "C1['I'] = " << C1['I'] << endl;

    // Modify using []
    C1['R'] = 100;

    cout << "After C1['R'] = 100: ";
    C1.PrintComplex();

    return 0;
}
