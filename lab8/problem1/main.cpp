#include <iostream>

using namespace std;


class Complex{
private:
    float real;
    float img;

public:
    /// Parameterless
    Complex();

    /// Parameterized
    Complex(float r, float i = 0);

    /// Copy Ctor
//    Complex (const Complex& C);

    /// setters + getters
    void setReal(float r);
    void setImg(float i);
    float getReal();
    float getImg();

    /// member functions
    Complex Add(Complex C);
    Complex Sub(Complex C);
    void PrintComplex();

    /// destructor
    ~Complex();
};

/// constructor
Complex::Complex(){
    this -> real=0;
    this -> img=0;

    cout << "Parameterless Ctor says Hi!" << endl;
}

Complex::Complex(float r, float i){
    this -> real=r;
    this -> img=i;

    cout << "Parametrized Ctor says Hi!" << endl;
}



//Complex::Complex(const Complex& C){
//    this -> real = C.real;
//    this -> img = C.img;
//
//    cout << "Copy Ctor says Hi!" << endl;
//}



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
Complex Complex::Add(Complex C){
    Complex res;

    res.setReal(this->real+C.real);
    res.setImg(this->img+C.img);

    return res;
}

Complex Complex::Sub(Complex C){
    Complex res;

    res.setReal(this->real-C.real);
    res.setImg(this->img-C.img);

    return res;
}

//void Complex::PrintComplex(){
//    cout << this->real;
//
//
//    if(this->img > 0)
//        cout<< " + " << this->img << "i" <<endl;
//    else if(this->img < 0)
//        cout<< " - " << -this->img << "i" <<endl;
//}

/// Destructor
Complex::~Complex(){
    cout << "Destructor says Hi!!" << endl;
}

int main()
{
    Complex C1(3,4), C2(5), C3;
	C3 = C1.Add(C2);
    return 0;
}
