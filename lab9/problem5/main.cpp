#include <iostream>
using namespace std;


/// =================== Complex Class =======================
class Complex
{
private:
    float real;
    float img;

public:
    Complex()
    {
        real = 0;
        img = 0;
        cout << "Complex default constructor!" << endl;
    }

    Complex(float r, float i = 0)
    {
        real = r;
        img = i;
        cout << "Complex parameterized constructor!" << endl;
    }

    void Print() const
    {
        cout << real;

        if (img >= 0)
            cout << " + " << img << "i";
        else
            cout << " - " << -img << "i";

        cout << endl;
    }
};


/// ====================== Function Template: Swap ====================
template <class T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}


/// ===================== Class Template: Stack =====================
template <class T>
class Stack
{
private:
    T* Stk;
    int Tos;
    int Size;

    static int counter;

public:
    Stack();
    Stack(int size);
    Stack(const Stack<T>& S);

    static int getCounter();

    bool IsEmpty();
    bool IsFull();

    void push(const T& value);
    T pop();

    ~Stack();
};


/// =================== Static Member Definition =======================
template <class T>
int Stack<T>::counter = 0;


/// ====================== Static Function ====================
template <class T>
int Stack<T>::getCounter()
{
    return counter;
}


/// ====================== Constructors ====================
template <class T>
Stack<T>::Stack()
{
    Size = 5;
    Tos = 0;
    Stk = new T[Size];

    counter++;

    cout << "Stack default constructor!" << endl;
}


template <class T>
Stack<T>::Stack(int size)
{
    Size = size;
    Tos = 0;
    Stk = new T[Size];

    counter++;

    cout << "Stack parameterized constructor!" << endl;
}


template <class T>
Stack<T>::Stack(const Stack<T>& S)
{
    Size = S.Size;
    Tos = S.Tos;

    Stk = new T[Size];

    for (int i = 0; i < Tos; i++)
    {
        Stk[i] = S.Stk[i];
    }

    counter++;

    cout << "Stack copy constructor!" << endl;
}

/// ====================================
template <class T>
bool Stack<T>::IsEmpty()
{
    return Tos == 0;
}

template <class T>
bool Stack<T>::IsFull()
{
    return Tos == Size;
}


/// ==========================================
template <class T>
void Stack<T>::push(const T& value)
{
    if (IsFull())
    {
        cout << "Stack is Full!" << endl;
        return;
    }

    Stk[Tos++] = value;
}


template <class T>
T Stack<T>::pop()
{
    if (IsEmpty())
    {
        cout << "Stack is Empty!" << endl;
    }

    return Stk[--Tos];
}


/// ==========================================
template <class T>
Stack<T>::~Stack()
{
    for (int i = 0; i < this->Size; i++) {
        this->Stk[i] = -1;
    }

    delete[] Stk;

    counter--;

    cout << "Stack destructor!" << endl;
}


int main()
{
    /// 1. Swap integers

    int a = 3, b = 5;

    Swap<int>(a, b);

    cout << "\nAfter Swap: " << a << ", " << b << endl;


    /// 2. Swap characters

    char Ch1 = 'Z', Ch2 = 'O';

    Swap<char>(Ch1, Ch2);

    cout << "\nAfter Swap: " << Ch1 << ", " << Ch2 << endl;


    // 3. Swap Complex objects

    Complex C1(5);
    Complex C2(2, 7);

    Swap<Complex>(C1, C2);

    cout << "\nComplex1 After Swap: " << endl;
    C1.Print();

    cout << "\nComplex2 After Swap: " << endl;
    C2.Print();


    // 4. Stack of integers

    Stack<int> S;

    S.push(10);
    S.push(20);

    cout << "\nInteger Stack Pop: " << S.pop() << endl;


    // 5. Stack of characters

    Stack<char> S2(3);

    S2.push('A');
    S2.push('B');
    S2.push('C');

    cout << "\nCharacter Stack Pop: " << S2.pop() << endl;


    // 6. Stack of Complex objects

    Stack<Complex> S3(4);

    S3.push(C1);
    S3.push(C2);

    Complex C = S3.pop();

    cout << "\nComplex Stack Pop: " << endl;
    C.Print();


    // 7. Static counters

    cout << "\nStack<int> objects: " << Stack<int>::getCounter() << endl;

    cout << "Stack<char> objects: " << Stack<char>::getCounter() << endl;

    cout << "Stack<Complex> objects: " << Stack<Complex>::getCounter() << endl;


    return 0;
}
