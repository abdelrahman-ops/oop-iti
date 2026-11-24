#include <iostream>

using namespace std;

class GeoShape{
private:
    float dim1;
    float dim2;
public:
    GeoShape();
    GeoShape(float d1, float d2);

    void setDim1(float d1);
    void setDim2(float d2);

    float getDim1();
    float getDim2();

    float CalcArea();

    ~GeoShape();
};

GeoShape::GeoShape(){
    dim1 = 0;
    dim2 = 0;
}

GeoShape::GeoShape(float d1, float d2){
    dim1 = d1;
    dim2 = d2;
}

GeoShape::~GeoShape(){
    cout << "\nGeoShape Destructor";
}


void GeoShape::setDim1(float d1)
{
    dim1 = d1;
}

void GeoShape::setDim2(float d2)
{
    dim2 = d2;
}

float GeoShape::getDim1()
{
    return dim1;
}

float GeoShape::getDim2()
{
    return dim2;
}


float GeoShape::CalcArea(){
    return 0;
}



/// ======================================== RECTANGLE
class Rectangle : public GeoShape{
public:
    Rectangle(float length, float width);
    float CalcArea();
};

Rectangle::Rectangle(float length, float width) : GeoShape(length, width){
}

float Rectangle::CalcArea(){
    return getDim1() * getDim2();
}


/// ======================================== SQUARE
class Square : public GeoShape{
public:
    Square(float side);
    float CalcArea();
};

Square::Square(float side) : GeoShape(side, side){
}

float Square::CalcArea(){
    return getDim1() * getDim2();
}


/// ======================================== CIRCLE
class Circle : public GeoShape{
public:
    Circle(float radius);
    float CalcArea();
};

Circle::Circle(float radius) : GeoShape(radius, radius){
}

float Circle::CalcArea(){
    const float PI = 3.14159;
    return PI * getDim1() * getDim1();
}

/// ======================================== TRIANGLE
class Triangle : public GeoShape{
public:
    Triangle(float base, float height);
    float CalcArea();
};

Triangle::Triangle(float base, float height) : GeoShape(base, height){
}

float Triangle::CalcArea(){
    const float PI = 3.14159;
    return 0.5 * getDim1() * getDim2();
}



int main()
{

    Rectangle R(10, 5);
    Square S(5);
    Circle C(7);
    Triangle T(10, 6);

    cout << "Rectangle Area = " << R.CalcArea() << endl;
    cout << "Square Area = " << S.CalcArea() << endl;
    cout << "Circle Area = " << C.CalcArea() << endl;
    cout << "Triangle Area = " << T.CalcArea() << endl;


    return 0;
}
