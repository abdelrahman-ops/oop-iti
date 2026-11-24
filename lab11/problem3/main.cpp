#include <iostream>

using namespace std;

/// CLASSES
class Base{
private:
    int x;
protected:
    int y;
public:
    Base();
    Base(int a, int b);

    void setX(int a);
    void setY(int b);

    int getX();
    int getY();


    int sum();

    ~Base();
};

class Derived : public Base{
private:
    int z;
public:
    Derived();
    Derived(int a, int b, int c);

    void setZ(int c);

    int getZ();

    int sum();

    ~Derived();
};

class Derived_Junior : public Derived
{
private:
    int m;

public:
    Derived_Junior();
    Derived_Junior(int a, int b, int c, int d);

    void setM(int d);
    int getM();

    int sum();

    ~Derived_Junior();
};

/// ===============================================================
/// ================= BASE =================
Base::Base()
{
    x = 0;
    y = 0;
    cout << "Base Default Constructor" << endl;
}

Base::Base(int a, int b)
{
    x = a;
    y = b;
    cout << "Base Parameterized Constructor" << endl;
}

void Base::setX(int a) { x = a; }
void Base::setY(int b) { y = b; }

int Base::getX() { return x; }
int Base::getY() { return y; }

int Base::sum()
{
    return x + y;
}

Base::~Base()
{
    cout << "Base Destructor" << endl;
}

/// ================= DERIVED =================

Derived::Derived() : Base()
{
    z = 0;
    cout << "Derived Default Constructor" << endl;
}

Derived::Derived(int a, int b, int c) : Base(a, b)
{
    z = c;
    cout << "Derived Parameterized Constructor" << endl;
}

void Derived::setZ(int c) { z = c; }
int Derived::getZ() { return z; }

int Derived::sum()
{
    return Base::sum() + z;
}

Derived::~Derived()
{
    cout << "Derived Destructor" << endl;
}

/// ================= DERIVED JUNIOR =================

Derived_Junior::Derived_Junior() : Derived()
{
    m = 0;
    cout << "Derived_Junior Default Constructor" << endl;
}

Derived_Junior::Derived_Junior(int a, int b, int c, int d) : Derived(a, b, c)
{
    m = d;
    cout << "Derived_Junior Parameterized Constructor" << endl;
}

void Derived_Junior::setM(int d) {
    m = d;
}

int Derived_Junior::getM() {
    return m;
}

int Derived_Junior::sum()
{
    return Derived::sum() + m;
}

Derived_Junior::~Derived_Junior()
{
    cout << "Derived_Junior Destructor" << endl;
}


int main()
{
    Base B(10, 20);
    Derived D(10, 20, 30);
    Derived_Junior DJ(10, 20, 30, 40);

    cout << "\n========== BASE POINTER ==========" << endl;

    Base* ptrB;
    ptrB = &B;

    cout << "\nBase pointer -> Base object" << endl;
    cout << "X = " << ptrB->getX() << endl;
    cout << "Y = " << ptrB->getY() << endl;
    cout << "Sum = " << ptrB->sum() << endl;

    ptrB = &D;

    cout << "\nBase pointer -> Derived object" << endl;
    cout << "X = " << ptrB->getX() << endl;
    cout << "Y = " << ptrB->getY() << endl;
    cout << "Sum = " << ptrB->sum() << endl;

    ptrB = &DJ;

    cout << "\nBase pointer -> Derived_Junior object" << endl;
    cout << "X = " << ptrB->getX() << endl;
    cout << "Y = " << ptrB->getY() << endl;
    cout << "Sum = " << ptrB->sum() << endl;


    Derived* ptrD;
    ptrD = &D;
    ptrD = &DJ;

    Derived_Junior* ptrDJ;
    ptrDJ = &DJ;

    return 0;
}





