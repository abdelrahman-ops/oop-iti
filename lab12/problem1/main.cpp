#include <iostream>
using namespace std;

class GeoShape
{
private:
    float dim1, dim2;

public:
    GeoShape(float d1, float d2)
    {
        dim1 = d1;
        dim2 = d2;
    }

    void setDim1(float d1)
    {
        dim1 = d1;
    }

    void setDim2(float d2)
    {
        dim2 = d2;
    }

    float getDim1()
    {
        return dim1;
    }

    float getDim2()
    {
        return dim2;
    }

    virtual float CalcArea() = 0;

    ~GeoShape()
    {
    }
};


class Rectangle : public GeoShape
{
public:
    Rectangle(float length, float width)
        : GeoShape(length, width)
    {
    }

    float CalcArea()
    {
        return getDim1() * getDim2();
    }
};


class Square : public GeoShape
{
public:
    Square(float side)
        : GeoShape(side, side)
    {
    }

    void setSide(float side)
    {
        setDim1(side);
        setDim2(side);
    }

    float getSide()
    {
        return getDim1();
    }

    float CalcArea()
    {
        return getDim1() * getDim2();
    }
};


class Circle : public GeoShape
{
private:
    const float PI = 3.14f;

public:
    Circle(float radius)
        : GeoShape(radius, radius)
    {
    }

    void setRadius(float radius)
    {
        setDim1(radius);
        setDim2(radius);
    }

    float getRadius()
    {
        return getDim1();
    }

    float CalcArea()
    {
        return PI * getDim1() * getDim1();
    }
};

class Triangle : public GeoShape
{
public:
    Triangle(float base, float height)
        : GeoShape(base, height)
    {
    }

    float CalcArea()
    {
        return 0.5 * getDim1() * getDim2();
    }
};


float sumOfAllShapesArea( GeoShape* S1, GeoShape* S2, GeoShape* S3, GeoShape* S4)
{
    return S1->CalcArea() + S2->CalcArea() + S3->CalcArea() + S4->CalcArea();

}

int main()
{
    Rectangle R(10, 5);
    Square S(4);
    Circle C(3);
    Triangle T(8, 6);

    cout << "Rectangle Area = " << R.CalcArea() << endl;
    cout << "Square Area = " << S.CalcArea() << endl;
    cout << "Circle Area = " << C.CalcArea() << endl;
    cout << "Triangle Area = " << T.CalcArea() << endl;

    float total = sumOfAllShapesArea(&R, &S, &C, &T);

    cout << "\nTotal Area = " << total << endl;

    return 0;
}
