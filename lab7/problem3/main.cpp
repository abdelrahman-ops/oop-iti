#include <iostream>
using namespace std;

class Stack
{
private:
    int* Stk;
    int Tos;
    int Size;

public:
    Stack(int size);

    /// Stack operations
    void Push(int value);
    int Pop();
    int Peak();

    bool isFull();
    bool isEmpty();

    Stack Reverse();
    void PrintStack();

    ~Stack();
};

/// Constructor
Stack::Stack(int size)
{
    if (size <= 0)
        size = 1;

    this->Size = size;
    this->Tos = 0;
    this->Stk = new int[this->Size];

    cout << "Constructor call!" << endl;
}

/// Check if stack is full
bool Stack::isFull()
{
    return this->Tos == this->Size;
}

/// Check if stack is empty
bool Stack::isEmpty()
{
    return this->Tos == 0;
}

/// Push
void Stack::Push(int value)
{
    if (this->isFull())
    {
        cout << "Stack is Full!" << endl;
        return;
    }

    this->Stk[Tos++] = value;
}

// Pop
int Stack::Pop()
{
    if (this->isEmpty())
    {
        cout << "Stack is Empty!" << endl;
        return -1;
    }

    return this->Stk[--Tos];
}

/// Peak
int Stack::Peak()
{
    if (this->isEmpty())
    {
        cout << "Stack is Empty!" << endl;
        return -1;
    }

    return this->Stk[Tos - 1];
}

/// Reverse
Stack Stack::Reverse()
{
    Stack reversed(this->Size);

    for (int i = 0; i < this->Tos; i++)
    {
        reversed.Stk[i] = this->Stk[Tos - 1 - i];
    }

    reversed.Tos = this->Tos;

    return reversed;
}

// Print Stack
void Stack::PrintStack()
{
    if (this->isEmpty())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }

    cout << "Stack Content: ";

    for (int i = Tos - 1; i >= 0; i--)
    {
        cout << this->Stk[i] << " ";
    }

    cout << endl;
}

// Destructor
Stack::~Stack()
{
    delete[] this->Stk;

    cout << "Destructor call!" << endl;
}

int main()
{
    Stack S1(5);

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);

    cout << "Peak: " << S1.Peak() << endl;
    cout << "Peak: " << S1.Peak() << endl;

    cout << "Pop: " << S1.Pop() << endl;
    cout << "Pop: " << S1.Pop() << endl;

    cout << "\n";

    Stack S2(5);

    S2.Push(3);
    S2.Push(4);
    S2.Push(5);
    S2.Push(6);

    cout << "S2 ";
    S2.PrintStack();

    cout << "Reverse S2 then Pop: " << S2.Reverse().Pop() << endl;

    return 0;
}
