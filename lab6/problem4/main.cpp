#include <iostream>

using namespace std;

class Complex
{
private:
    float real;
    float img;

public:
    void SetReal(float r)
    {
        real = r;
    }

    void SetImg(float i)
    {
        img = i;
    }

    float GetReal()
    {
        return real;
    }

    float GetImg()
    {
        return img;
    }

    Complex Add(Complex C)
    {
        Complex result;

        result.real = C.real + real;
        result.img = C.img + img;

        return result;
    }
};


Complex Add(Complex C1, Complex C2)
{
    Complex result;

    result.SetReal(C1.GetReal() + C2.GetReal());
    result.SetImg(C1.GetImg() + C2.GetImg());

    return result;
}


Complex Subtract(Complex C1, Complex C2)
{
    Complex result;

    result.SetReal(C1.GetReal() - C2.GetReal());
    result.SetImg(C1.GetImg() - C2.GetImg());

    return result;
}


void print(Complex C)
{
    float r = C.GetReal();
    float i = C.GetImg();

    cout << "C = ";

    if (r == 0 && i == 0)
    {
        cout << "0";
    }
    else if (i == 0)
    {
        cout << r;
    }
    else if (r == 0)
    {
        if (i == 1)
            cout << "i";
        else if (i == -1)
            cout << "-i";
        else
            cout << i << "i";
    }
    else
    {
        cout << r;

        if (i > 0)
            cout << " + ";
        else
            cout << " - ";

        if (i == 1 || i == -1)
            cout << "i";
        else
            cout << (i > 0 ? i : -i) << "i";
    }

    cout << endl;
}

int main()
{
    Complex C1, C2, result;

    float r, i;

    cout << "Enter real part of C1: ";
    cin >> r;

    cout << "Enter imaginary part of C1: ";
    cin >> i;

    C1.SetReal(r);
    C1.SetImg(i);

    cout << "\nEnter real part of C2: ";
    cin >> r;

    cout << "Enter imaginary part of C2: ";
    cin >> i;

    C2.SetReal(r);
    C2.SetImg(i);

    cout << "\nFirst Complex Number:\n";
    print(C1);

    cout << "\nSecond Complex Number:\n";
    print(C2);

    cout << "\nStandalone Addition:\n";
    result = Add(C1, C2);
    print(result);

    cout << "\nSubtraction:\n";
    result = Subtract(C1, C2);
    print(result);

    cout << "\nMember Function Addition:\n";
    result = C1.Add(C2);
    print(result);

    return 0;
}
