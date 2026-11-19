#include <iostream>

using namespace std;


class Complex{
private:
    float real;
    float img;

public:

    ///CONSTRUCTORS
    Complex();
    Complex(float r, float i = 0);
    Complex (const Complex& C);

    /// SETTERS + GETTERS
    void InitValue(float r, float i);
    void setReal(float r);
    void setImg(float i);
    float getReal() const;
    float getImg() const;

    /// MEMBER FUNCTIONS
    Complex Add(Complex C);
    Complex Sub(Complex C);
    void PrintComplex();


    /// OVERLOADING OPERATORS
    /// 1.    C3 = C1 - C2;
    Complex operator- (const Complex& C){
        Complex res(this -> real - C.real, this -> img - C.img);
        return res;
    }

    /// 3.   C3 = C2 - 7;
    Complex operator- (float Num){
        Complex res(this -> real - Num, this -> img);
        return res;
    }

    /// 4.   C1-=C2; c1=c1-c2;
    Complex& operator-= (const Complex& C){
        real -= C.real;
        img -= C.img;

        return *this;
    }

    /// 5.   C2=--C1; //prefix we minus then equal
    Complex& operator-- (){
        real--;
        img--;

        return *this;
    }

    /// 6.   C2 = C1--; //postfix
    Complex operator-- (int){
        Complex temp(*this); /// copy of current complex
        real--;
        img--;

        return temp;
    }

    /// 7.   C1 == C2
    bool operator== (const Complex& C){
        return (real == C.real && img == C.img);
    }

    /// 8.   C1 != C2
    bool operator!= (const Complex& C){
        /// return (real != C.real || img != C.img);
        return !(*this == C);
    }

    /// 9.   C1 > C2,  C1 >= C2,
    float magnitudeSquared() const
    {
        return real * real + img * img;
    }
    bool operator> (const Complex& C){
        return magnitudeSquared() > C.magnitudeSquared();
    }
    bool operator>= (const Complex& C){
        return magnitudeSquared() >= C.magnitudeSquared();
    }

    /// 10.  C1 < C2, C1 <= C2,
    bool operator< (const Complex& C){
        return magnitudeSquared() < C.magnitudeSquared();
    }
    bool operator<= (const Complex& C){
        return magnitudeSquared() <= C.magnitudeSquared();
    }

    /// 11.  (int) C1
    operator int(){
        return (int)real;
    }

    /// 12.  cout<< C1['R'];
    float& operator[](char ch){
        if(ch == 'R' || ch == 'r')
            return real;
        else if(ch == 'I' || ch == 'i')
            return img;
    }

    /// DESTRUCTOR
    ~Complex();
};

/// 2.   C3 = 7 - C2;
Complex operator- (float Num, const Complex& C){
    Complex res(Num - C.getReal(), -C.getImg());
    return res;
}

/// bonus
ostream& operator<<(ostream& out, const Complex& C)
{
    out << C.getReal();

    if (C.getImg() >= 0)
        out << " + " << C.getImg() << "i";
    else
        out << " - " << -C.getImg() << "i";

    return out;
}

istream& operator>>(istream& in, Complex& C)
{
    float r, i;
    cout << "Enter real: ";
    in >> r;

    cout << "Enter imaginary: ";
    in >> i;

    C.setReal(r);
    C.setImg(i);


    return in;
}

/// ======================== CONSTRUCTORS =======================
Complex::Complex(){
    this -> real=0;
    this -> img=0;

    /// cout << "Parameterless Ctor says Hi!" << endl;
}

Complex::Complex(float r, float i){
    this -> real=r;
    this -> img=i;

    /// cout << "Parametrized Ctor says Hi!" << endl;
}

Complex::Complex(const Complex& C){
    this -> real = C.real;
    this -> img = C.img;

    /// cout << "Copy Ctor says Hi!" << endl;
}


/// ======================== SETTERS & GETTERS FUNCTIONS =======================
void Complex::InitValue(float r, float i){
    this -> real=r;
    this -> img = i;
}

void Complex::setReal(float r)
{
    this->real = r;
}

void Complex::setImg(float i)
{
    this->img = i;
}

float Complex::getReal() const{
    return this->real;
}

float Complex::getImg() const{
    return this->img;
}


/// ======================== MEMBER FUNCTIONS =======================
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

void Complex::PrintComplex(){
    cout << this->real;

    if(this->img > 0)
        cout<< " + " << this->img << "i" <<endl;
    else if(this->img < 0)
        cout<< " - " << -this->img << "i" <<endl;
}

/// ======================== DESTRUCTOR =======================
Complex::~Complex(){
    /// cout << "Destructor says Hi!!" << endl;
}


int main()
{
    Complex C1, C2, C3, C4;

    C1.InitValue(5, 6);
    C2.InitValue(30, 50);

/// 1.    C3 = C1 - C2;
//    C3 = C1 - C2;
//    cout << "C3 = C1 - C2 = ";
//    C3.PrintComplex();
//    cout << endl;

/// 2.   C3 = 7 - C2;
//    C3 = 7 - C2;
//    cout << "C3 = 7 - C2 = ";
//    C3.PrintComplex();
//    cout << endl;

/// 3.   C3 = C2 - 7;
//    C3 = C2 - 7;
//    cout << "C3 = C2 - 7 = ";
//    C3.PrintComplex();
//    cout << endl;

/// 4.   C1-=C2; c1=c1-c2;
//    C1-=C2;
//    cout << "C1 -= C2 = ";
//    C1.PrintComplex();
//    cout << endl;

/// 5.   C2=--C1;
//    C2=--C1;
//    cout << "C2 = --C1 = ";
//    C2.PrintComplex();
//    cout << endl;

/// 6.   C2 = C1--;
//    C2=C1--;
//    cout << "C2 = C1-- = ";
//    C2.PrintComplex();
//    cout << endl;

/// 7.   C1 == C2
    cout << "C1 == C2: " << (C1 == C2) << endl;

/// 8.   C1 != C2
    cout << "C1 != C2: " << (C1 != C2) << endl;

/// 9.   C1 > C2,  C1 >= C2,
    cout << "C1 > C2: " << (C1 > C2) << endl;
    cout << "C1 >= C2: " << (C1 >= C2) << endl;

/// 10.  C1 < C2, C1 <= C2,
    cout << "C1 < C2: " << (C1 < C2) << endl;
    cout << "C1 <= C2: " << (C1 <= C2) << endl;


/// 11.  (int) C1
    int num = (int)C1;
    cout << "(int) C1 = " << num << endl;

/// 12.  cout<< C1['R'];
    cout << "C1['R'] = " << C1['R'] << endl;
    cout << "C1['I'] = " << C1['I'] << endl;


    /// bonus
    cout << "Enter the C4: " << endl;
    cin >> C4;
    cout << "C4 value: "<< C4 << endl;


    return 0;
}
