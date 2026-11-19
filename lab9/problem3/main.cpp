#include <iostream>

using namespace std;

class Stack{

private:
    int* Stk;
    int Tos;
    int Size;

    static int counter;

public:
    Stack();
    Stack(int Size);
    Stack(const Stack& S);

    static int getCounter();


    bool IsEmpty();
    bool IsFull();

    void Push(int value);
    int Pop();
    Stack Reverse();

    friend void viewContent(Stack S);

    /// ===================================================
    Stack& operator= (const Stack& S);

    Stack operator+ (const Stack& S);

    int& operator[](int index);

    ~Stack();
};
int Stack::counter = 0;

int Stack::getCounter()
{
    return counter;
}

Stack::Stack(){
    this -> Size = 5;
    this -> Tos = 0;
    this -> Stk = new int[this -> Size];

    counter++;

    cout << "parameterless ctor!" << endl;
}

Stack::Stack(int size){
    this -> Size = size;
    this -> Tos = 0;
    this -> Stk = new int[this -> Size];

    counter++;

    cout << "parameterized ctor!" << endl;
}

Stack::Stack(const Stack& S){
    this -> Size = S.Size;
    this -> Tos = S.Tos;
    this -> Stk = new int[this -> Size];


    /// here we do deep copy rather than the normal shallow copy
    for(int i = 0; i < this -> Tos; i++){
        this -> Stk[i] = S.Stk[i];
    }

    counter++;

    cout << "copy ctor!" << endl;
}



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


/// ========================== NEW =======================
Stack& Stack::operator=(const Stack& S){
    if(this == &S)
        return *this;

    delete[] Stk;

    Size = S.Size;
    Tos = S.Tos;
    Stk = new int[Size];

    for(int i = 0; i < Tos; i++){
        Stk[i] = S.Stk[i];
    }

    return *this;
}


Stack Stack::operator+(const Stack& S) {
    Stack res(Size + S.Size);

    for(int i =0; i < Tos; i++){
        res.Stk[i] = Stk[i];
    }
    for(int i =0; i < S.Tos; i++){
        res.Stk[Tos+i] = S.Stk[i];
    }
    res.Tos = Tos + S.Tos;

    return res;
}


int& Stack::operator[](int index){
    if(index < 0 || index >= Tos){
        cout << "- Invalid index!" << endl;
        cout << "- Check index 0: ";
        return Stk[0];
    }

    return Stk[index];
}


/// ======================================================

Stack::~Stack() {

    for (int i = 0; i < this->Size; i++) {
        this->Stk[i] = -1;
    }

    delete[] this->Stk;

    counter--;

    cout << "Destructor!" << endl;
}


int main() {

//    Stack S1;
//
//    S1.Push(10);
//    S1.Push(20);
//    S1.Push(30);
//    S1.Push(40);
//
//
//    cout<< S1[7] << endl;
//    S1[3] = 9999;
//    cout<< "S1[3]: " <<S1[3] << endl;


    Stack S1;
    Stack S2(10);
    Stack S3(S1);

    cout << "Number of Stack objects: " << Stack::getCounter() << endl;
    return 0;
}
