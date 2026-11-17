#include <iostream>
using namespace std;

class Queue{
private:
    int* Q;
    int Head;
    int Tail;
    int Size;

public:
    Queue();
    Queue(int size);

    bool IsFull();
    bool IsEmpty();

    void EnQueue(int value);
    int DeQueue();

    void PrintQueue();

    ~Queue();
};

// Parameterless Constructor
Queue::Queue()
{
    Size = 5;
    Q = new int[Size];

    Head = 0;
    Tail = -1;

    cout << "Default Constructor!" << endl;
}

// Parameterized Constructor
Queue::Queue(int size)
{
    if (size <= 0)
        size = 1;

    Size = size;
    Q = new int[Size];

    Head = 0;
    Tail = -1;

    cout << "Parameterized Constructor!" << endl;
}


bool Queue::IsFull()
{
    return Tail == Size - 1;
}

bool Queue::IsEmpty()
{
    return Tail == -1;
}


/// 1 2 3 4 5 - -
/// 0 1 2 3 4 5 6
/// head = 0 tail = 4
/// en-> increment first the tail = 5, Q[5] = new value;
void Queue::EnQueue(int value)
{
    if (IsFull())
    {
        cout << "Queue is Full!" << endl;
        return;
    }

    Q[++Tail] = value;
}

/// 1 2 3 4 5 - -
/// 0 1 2 3 4 5 6
/// head = 0 tail = 4
/// de->
/// 1. head =0
/// 2. shift elements starting from head till tail
/// 3. decrement the tail--;
int Queue::DeQueue()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return -1;
    }

    int value = Q[Head];

    for (int i = Head; i < Tail; i++)
    {
        Q[i] = Q[i + 1];
    }

    Tail--;

    return value;
}

// Print Queue
void Queue::PrintQueue()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Queue: ";

    for (int i = Head; i <= Tail; i++)
    {
        cout << Q[i] << " ";
    }

    cout << endl;
}

// Destructor
Queue::~Queue()
{
    delete[] Q;
    cout << "Destructor!" << endl;
}

int main()
{
    Queue Q1(5);

    Q1.EnQueue(10);
    Q1.EnQueue(20);
    Q1.EnQueue(30);
    Q1.EnQueue(40);

    Q1.PrintQueue();

    cout << "Deleted: " << Q1.DeQueue() << endl;

    Q1.PrintQueue();

    Q1.EnQueue(50);
    Q1.EnQueue(60);

    Q1.PrintQueue();

    return 0;
}
