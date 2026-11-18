#include <iostream>

using namespace std;

class Stack{

private:
    int* Stk;
    int Tos;
    int Size;

public:
    Stack();
    Stack(int Size);
//    Stack(const Stack& S);


    bool IsEmpty();
    bool IsFull();

    void Push(int value);
    int Pop();
    Stack Reverse();

    friend void viewContent(Stack S);

    ~Stack();
};

Stack::Stack(){
    this -> Size = 5;
    this -> Tos = 0;
    this -> Stk = new int[this -> Size];

    cout << "parameterless ctor!" << endl;
}

Stack::Stack(int size){
    this -> Size = size;
    this -> Tos = 0;
    this -> Stk = new int[this -> Size];

    cout << "parameterized ctor!" << endl;
}

//Stack::Stack(const Stack& S){
//    this -> Size = S.Size;
//    this -> Tos = S.Tos;
//    this -> Stk = new int[this -> Size];
//
//    /// here we do deep copy rather than the normal shallow copy
//    for(int i = 0; i < this -> Tos; i++){
//        this -> Stk[i] = S.Stk[i];
//    }
//
//    cout << "copy ctor!" << endl;
//}

bool Stack::IsFull() {
    return Tos == Size;
}

bool Stack::IsEmpty() {
    return Tos == 0;
}

void Stack::Push(int value) {
    if (IsFull()) {
        cout << "Stack is Full!" << endl;
        return;
    }

    Stk[Tos++] = value;
}

int Stack::Pop() {
    if (IsEmpty()) {
        cout << "Stack is Empty!" << endl;
        return -1;
    }

    return Stk[--Tos];
}

Stack Stack::Reverse() {
    Stack reversed(Size);

    for (int i = 0; i < Tos; i++) {
        reversed.Stk[i] = Stk[Tos - 1 - i];
    }

    reversed.Tos = Tos;

    return reversed; /// stack Temp = reversed;
}

void viewContent(Stack S) {
    cout << "Stack Content: ";

    if (S.IsEmpty()) {
        cout << "Empty!" << endl;
        return;
    }

    for (int i = S.Tos - 1; i >= 0; i--) {
        cout << S.Stk[i] << " ";
    }

    cout << endl;
}


Stack::~Stack() {

    for (int i = 0; i < this->Size; i++) {
        this->Stk[i] = -1;
    }

    delete[] this->Stk;

    cout << "Destructor!" << endl;
}


int main() {

    // CASE 1
/*
    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    viewContent(S1);

    cout << "Num = " << S1.Pop() << endl;
    cout << "Num = " << S1.Pop() << endl;
*/


    // CASE 2

/*
    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    Stack SS = S1.Reverse();

    cout << "Num = " << SS.Pop() << endl;
*/
///    parameterless ctor!    // 1. S1
///    parameterized ctor!    // 2. reversed
///    copy ctor!             // 3. Return object
///    Destructor!            // 4. reversed
///    copy ctor!             // 5. SS
///    Destructor!            // 6. Return object
///    Num = 10
///    Destructor!            // 7. SS
///    Destructor!            // 8. S1

    // CASE 3

    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    Stack S3(S1);

    for (int i = 0; i < 10; i++)
        S3.Pop();

    for (int i = 0; i < 10; i++)
        S3.Push(-1);

    cout << "Num = " << S1.Pop() << endl;
    cout << "Num = " << S1.Pop() << endl;



    return 0;
}
