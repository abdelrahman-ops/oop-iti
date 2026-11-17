#include <iostream>

using namespace std;

class myTestClass
{
	// Function Add: Add 2 integer numbers:  int Add(int, int)
	// Function Add: Add 3 integer numbers:  int Add(int, int, int)
    // Function Add: Add 3 characters  // concatenate them: void Add(char c1, char c2, char ch)
	// Function Add: Add 2 Strings  // concatenate them: void Add(char* str1, char* str2)

public:
    int Add(int x, int y);
    int Add(int x, int y, int z);
    void Add(char c1, char c2, char ch);
    void Add(char* str1, char* str2);
};

int myTestClass::Add(int x, int y){
    return x+y;
}

int myTestClass::Add(int x, int y, int z){
    return x+y+z;
}

void myTestClass::Add(char c1, char c2, char ch){
    cout << c1 << c2 << ch << endl;
}

void myTestClass::Add(char* str1, char* str2){
    cout << str1 << str2 << endl;
}

int main()
{
    myTestClass obj;

    cout << "Add 2 integers: " << obj.Add(5,6) << endl;
    cout << "Add 3 integers: " << obj.Add(5,6,7) << endl;


    cout << "Concatenate 3 characters: ";
    obj.Add('A', 'B', 'C');

    char str1[50] = "Hello ";
    char str2[] = "World";

    cout << "Concatenate 2 strings: ";
    obj.Add(str1, str2);

    return 0;
}
