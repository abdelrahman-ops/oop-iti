#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

/// ======================= POINT =======================

class Point
{
private:
    int x, y;

public:
    Point();
    Point(int x, int y);

    void setX(int x);
    void setY(int y);

    int getX();
    int getY();

    void Draw();
};

/// ======================= SHAPE =======================

class Shape
{
private:
    int color;

public:
    Shape();
    Shape(int c);

    void setColor(int c);
    int getColor();

    virtual void Draw() = 0;

    ~Shape();
};

/// ======================= RECTANGLE =======================

class Rect : public Shape
{
private:
    Point TL, BR;

public:
    Rect();
    Rect(Point P1, Point P2);

    void setTopLeft(Point p);
    void setBottomRight(Point p);

    Point getTopLeft();
    Point getBottomRight();

    void Draw() override;
};

/// ======================= CIRCLE =======================

class Circle : public Shape
{
private:
    Point center;
    int radius;

public:
    Circle();
    Circle(Point c, int r);

    void setCenter(Point c);
    void setRadius(int r);

    int getRadius();
    Point getCenter();

    void Draw() override;
};

/// ======================= LINE =======================

class Line : public Shape
{
private:
    Point Start;
    Point End;

public:
    Line();
    Line(Point S, Point E);

    void setStart(Point S);
    void setEnd(Point E);

    Point getStart();
    Point getEnd();

    void Draw() override;
};

/// ======================= PICTURE =======================

class Picture
{
private:
    Shape** pShapes;
    int numShapes;

public:
    Picture();

    Picture(Shape* S[], int n);

    void setShapes(Shape* S[], int n);

    void Paint();
};


/// ======================= POINT IMPLEMENTATION =======================

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

void Point::Draw()
{
    setcolor(WHITE);
    putpixel(x, y, WHITE);
}


/// ======================= SHAPE IMPLEMENTATION =======================

Shape::Shape()
{
    color = WHITE;
}

Shape::Shape(int c)
{
    color = c;
}

void Shape::setColor(int c)
{
    color = c;
}

int Shape::getColor()
{
    return color;
}

Shape::~Shape()
{
}


/// ======================= RECTANGLE IMPLEMENTATION =======================

Rect::Rect() : Shape()
{
}

Rect::Rect(Point P1, Point P2) : Shape()
{
    TL = P1;
    BR = P2;
}

void Rect::setTopLeft(Point p)
{
    TL = p;
}

void Rect::setBottomRight(Point p)
{
    BR = p;
}

Point Rect::getTopLeft()
{
    return TL;
}

Point Rect::getBottomRight()
{
    return BR;
}

void Rect::Draw()
{
    setcolor(getColor());

    rectangle(TL.getX(), TL.getY(), BR.getX(), BR.getY());
}


/// ======================= CIRCLE IMPLEMENTATION =======================

Circle::Circle() : Shape()
{
    radius = 0;
}

Circle::Circle(Point c, int r) : Shape()
{
    center = c;
    radius = r;
}

void Circle::setCenter(Point c)
{
    center = c;
}

void Circle::setRadius(int r)
{
    radius = r;
}

Point Circle::getCenter()
{
    return center;
}

int Circle::getRadius()
{
    return radius;
}

void Circle::Draw()
{
    setcolor(getColor());

    circle(
        center.getX(),
        center.getY(),
        radius
    );
}


/// ======================= LINE IMPLEMENTATION =======================

Line::Line() : Shape()
{
}

Line::Line(Point S, Point E) : Shape()
{
    Start = S;
    End = E;
}

void Line::setStart(Point S)
{
    Start = S;
}

void Line::setEnd(Point E)
{
    End = E;
}

Point Line::getStart()
{
    return Start;
}

Point Line::getEnd()
{
    return End;
}

void Line::Draw()
{
    setcolor(getColor());

    line(
        Start.getX(),
        Start.getY(),
        End.getX(),
        End.getY()
    );
}


/// ======================= PICTURE IMPLEMENTATION =======================

Picture::Picture()
{
    pShapes = NULL;
    numShapes = 0;
}

Picture::Picture(Shape* S[], int n)
{
    pShapes = S;
    numShapes = n;
}

void Picture::setShapes(Shape* S[], int n)
{
    pShapes = S;
    numShapes = n;
}

void Picture::Paint()
{
    for (int i = 0; i < numShapes; i++)
    {
        pShapes[i]->Draw();
    }
}


int main()
{
    initwindow(800, 600);

    Point P1(100, 100);
    Point P2(300, 250);
    Point P3(200, 200);
    Point P4(400, 100);
    Point P5(500, 250);

    /// rectangles
    Rect R1(P1, P2);
    Rect R2(P4, P5);

    R1.setColor(RED);
    R2.setColor(BLUE);


    /// circles
    Circle C1(P1, 100);
    Circle C2(P3, 50);

    C1.setColor(GREEN);
    C2.setColor(YELLOW);


    /// lines
    Line L1(P1, P3);
    Line L2(P4, P5);

    L1.setColor(MAGENTA);
    L2.setColor(CYAN);


    /// Array of Shape pointers

    Shape* Shapes[6] = { &R1, &R2, &C1, &C2, &L1, &L2 };


    /// Picture

    Picture P(Shapes, 6);

    P.Paint();

    getch();

    closegraph();

    return 0;
}
