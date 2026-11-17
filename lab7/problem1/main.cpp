#include <iostream>

using namespace std;


class Complex{
private:
    float real;
    float img;

public:
    Complex();
    Complex(float r, float i = 0);

    void setReal(float r);
    void setImg(float i);

    float getReal();
    float getImg();


    Complex AddComplex(Complex C);
    Complex SubComplex(Complex C);

    void PrintComplex();

    ~Complex();
};

/// constructor
Complex::Complex(){
    this -> real=0;
    this -> img=0;

    cout << "Parameterless Constructor!" << endl;
}

Complex::Complex(float r, float i){
    this -> real=r;
    this -> img=i;

    cout << "Parametrized Constructor!" << endl;
}


/// setters & getters functions
void Complex::setReal(float r)
{
    this->real = r;
}

void Complex::setImg(float i)
{
    this->img = i;
}

float Complex::getReal(){
    return this->real;
}

float Complex::getImg(){
    return this->img;
}


/// member functions
Complex Complex::AddComplex(Complex C){
    Complex res;

    res.setReal(this->real+C.real);
    res.setImg(this->img+C.img);

    return res;
}

Complex Complex::SubComplex(Complex C){
    Complex res;

    res.setReal(this->real-C.real);
    res.setImg(this->img-C.img);

    return res;
}

void Complex::PrintComplex(){
    cout << this->real;


    if(this->img > 0)
        cout<< " + " << this->img << "i" <<endl;
    else if(this->img < 0)
        cout<< " - " << -this->img << "i" <<endl;
}

/// Destructor

Complex::~Complex(){
    cout << "Destructor flag!" << endl;
}

int main()
{
    Complex C1(3,4), C2(5), C3;
	C3 = C1.AddComplex(C2);

	cout << "\nC1 = ";
    C1.PrintComplex();

    cout << "C2 = ";
    C2.PrintComplex();

    cout << "\nC3 = ";
    C3.PrintComplex();

    cout << "Hello world!" << endl;
    return 0;
}
