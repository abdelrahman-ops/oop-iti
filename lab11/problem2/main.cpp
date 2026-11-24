#include <iostream>
using namespace std;

class GeoShape
{
private:
    float dim1, dim2;

public:
    GeoShape();
    GeoShape(float d1, float d2);
    ~GeoShape();

    void setDim1(float d1);
    void setDim2(float d2);

    float getDim1();
    float getDim2();

    virtual float CalcArea()=0;
};

/// ==================== Rectangle ====================

class Rectangle : public GeoShape
{
public:
    Rectangle(float length, float width);
    ~Rectangle();

    float CalcArea();
};

/// ==================== Square ====================

class Square : protected GeoShape
{
public:
    Square(float side);
    ~Square();

    void setSide(float side);
    float getSide();

    float CalcArea();
};

/// ==================== Circle ====================

class Circle : protected GeoShape
{
public:
    Circle(float radius);
    ~Circle();

    void setRadius(float radius);
    float getRadius();

    float CalcArea();
};

/// ==================== Triangle ====================

class Triangle : public GeoShape
{
public:
    Triangle(float base, float height);
    ~Triangle();

    float CalcArea();
};

/// ==================== GeoShape ====================

GeoShape::GeoShape()
{
    dim1 = 0;
    dim2 = 0;
}

GeoShape::GeoShape(float d1, float d2)
{
    dim1 = d1;
    dim2 = d2;
}

GeoShape::~GeoShape()
{
    cout << "GeoShape Destructor" << endl;
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

//float GeoShape::CalcArea()
//{
//    return 0;
//}

/// ==================== Rectangle ====================

Rectangle::Rectangle(float length, float width): GeoShape(length, width)
{
}

Rectangle::~Rectangle()
{
    cout << "Rectangle Destructor" << endl;
}

float Rectangle::CalcArea()
{
    return getDim1() * getDim2();
}

/// ==================== Square Implementation ====================

Square::Square(float side)
    : GeoShape(side, side)
{
}

Square::~Square()
{
    cout << "Square Destructor" << endl;
}

void Square::setSide(float side)
{
    setDim1(side);
    setDim2(side);
}

float Square::getSide()
{
    return getDim1();
}

float Square::CalcArea()
{
    return getDim1() * getDim2();
}

/// ==================== Circle ====================

Circle::Circle(float radius)
    : GeoShape(radius, radius)
{
}

Circle::~Circle()
{
    cout << "Circle Destructor" << endl;
}

void Circle::setRadius(float radius)
{
    setDim1(radius);
    setDim2(radius);
}

float Circle::getRadius()
{
    return getDim1();
}

float Circle::CalcArea()
{
    const float PI = 3.14159;
    return PI * getDim1() * getDim1();
}

/// ==================== Triangle Implementation ====================

Triangle::Triangle(float base, float height)
    : GeoShape(base, height)
{
}

Triangle::~Triangle()
{
    cout << "Triangle Destructor" << endl;
}

float Triangle::CalcArea()
{
    return 0.5 * getDim1() * getDim2();
}

int main()
{
    Rectangle R(10, 5);
    Square S(5);
    Circle C(7);
    Triangle T(10, 6);
//    GeoShape G(1,2);

//    cout << "+++++++++++++++Rectangle Area = " << G.CalcArea() << endl;

    cout << "Rectangle Area = " << R.CalcArea() << endl;
    cout << "Square Area = " << S.CalcArea() << endl;
    cout << "Circle Area = " << C.CalcArea() << endl;
    cout << "Triangle Area = " << T.CalcArea() << endl;

    cout << "\nChanging dimensions:" << endl;

    R.setDim1(20);
    R.setDim2(10);

    S.setSide(10);

    C.setRadius(3);

    T.setDim1(12);
    T.setDim2(8);

    cout << "Rectangle Area = " << R.CalcArea() << endl;
    cout << "Square Area = " << S.CalcArea() << endl;
    cout << "Circle Area = " << C.CalcArea() << endl;
    cout << "Triangle Area = " << T.CalcArea() << endl;

    return 0;
}
