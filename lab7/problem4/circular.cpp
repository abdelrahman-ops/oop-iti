#include <iostream>
using namespace std;

class Queue
{
private:
    int* Q;
    int Head;
    int Tail;
    int Size;
    int Count;

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
    Count = 0;

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
    Count = 0;

    cout << "Parameterized Constructor!" << endl;
}

bool Queue::IsFull()
{
    return Count == Size;
}

bool Queue::IsEmpty()
{
    return Count == 0;
}


/// 10 20 30 40 50 - -
///  0  1  2  3  4 5 6
/// Head = 0, Tail = 4, Size = 6
/// Count = 4 (not full)

/// EnQueue(60):
/// 1. Check if the queue is full.
/// 2. increment Tail++;
/// 3. if Tail == Size, set Tail = 0.
/// 4. insert the new value: Q[Tail] = value.
/// 5. increment Count++.
void Queue::EnQueue(int value)
{
    if (IsFull())
    {
        cout << "Queue is Full!" << endl;
        return;
    }

    Tail++;

    if (Tail == Size)
        Tail = 0;

    Q[Tail] = value;

    Count++;
}

int Queue::DeQueue()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return -1;
    }

    int value = Q[Head];

    Head++;

    if (Head == Size)
        Head = 0;

    Count--;

    return value;
}

void Queue::PrintQueue()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Queue: ";

    int index = Head;

    for (int i = 0; i < Count; i++)
    {
        cout << Q[index] << " ";

        index++;

        if (index == Size)
            index = 0;
    }

    cout << endl;
}

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
    Q1.EnQueue(50);

    Q1.PrintQueue();

    cout << "Deleted: " << Q1.DeQueue() << endl;
    cout << "Deleted: " << Q1.DeQueue() << endl;

    Q1.PrintQueue();

    Q1.EnQueue(60);
    Q1.EnQueue(70);

    Q1.PrintQueue();

    return 0;
}
