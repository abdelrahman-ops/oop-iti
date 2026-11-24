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

/// ======================= RECTANGLE =======================

class Rect
{
private:
    Point TL, BR;
    int color;

public:
    Rect();
    Rect(Point P1, Point P2);

    void setTopLeft(Point p);
    void setBottomRight(Point p);
    void setColor(int c);

    Point getTopLeft();
    Point getBottomRight();

    void Draw();
};

/// ======================= CIRCLE =======================

class Circle
{
private:
    Point center;
    int radius;
    int color;

public:
    Circle();
    Circle(Point c, int r);

    void setCenter(Point c);
    void setRadius(int r);
    void setColor(int c);

    int getRadius();
    Point getCenter();

    void Draw();
};

/// ======================= LINE =======================

class Line
{
private:
    Point Start;
    Point End;
    int color;

public:
    Line();
    Line(Point S, Point E);

    void setStart(Point S);
    void setEnd(Point E);
    void setColor(int c);

    Point getStart();
    Point getEnd();

    void Draw();
};

/// ======================= PICTURE =======================

class Picture
{
private:
    Rect* pRects;
    Circle* pCircles;
    Line* pLines;

    int numRects;
    int numCircles;
    int numLines;

public:
    Picture();

    Picture(Rect* R, int nR, Circle* C, int nC, Line* L, int nL);

    void setRects(Rect* R, int nR);
    void setCircles(Circle* C, int nC);
    void setLines(Line* L, int nL);

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


/// ======================= RECTANGLE IMPLEMENTATION =======================

Rect::Rect()
{
    color = WHITE;
}

Rect::Rect(Point P1, Point P2)
{
    TL = P1;
    BR = P2;
    color = WHITE;
}

void Rect::setTopLeft(Point p)
{
    TL = p;
}

void Rect::setBottomRight(Point p)
{
    BR = p;
}

void Rect::setColor(int c)
{
    color = c;
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
    setcolor(color);

    rectangle(TL.getX(), TL.getY(), BR.getX(), BR.getY());
}


/// ======================= CIRCLE IMPLEMENTATION =======================

Circle::Circle()
{
    radius = 0;
    color = WHITE;
}

Circle::Circle(Point c, int r)
{
    center = c;
    radius = r;
    color = WHITE;
}

void Circle::setCenter(Point c)
{
    center = c;
}

void Circle::setRadius(int r)
{
    radius = r;
}

void Circle::setColor(int c)
{
    color = c;
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
    setcolor(color);

    circle(
        center.getX(),
        center.getY(),
        radius
    );
}


/// ======================= LINE IMPLEMENTATION =======================

Line::Line()
{
    color = WHITE;
}

Line::Line(Point S, Point E)
{
    Start = S;
    End = E;
    color = WHITE;
}

void Line::setStart(Point S)
{
    Start = S;
}

void Line::setEnd(Point E)
{
    End = E;
}

void Line::setColor(int c)
{
    color = c;
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
    setcolor(color);

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
    pRects = NULL;
    pCircles = NULL;
    pLines = NULL;

    numRects = 0;
    numCircles = 0;
    numLines = 0;
}

Picture::Picture(Rect* R, int nR, Circle* C, int nC, Line* L, int nL)
{
    pRects = R;
    numRects = nR;

    pCircles = C;
    numCircles = nC;

    pLines = L;
    numLines = nL;
}

void Picture::setRects(Rect* R, int nR)
{
    pRects = R;
    numRects = nR;
}

void Picture::setCircles(Circle* C, int nC)
{
    pCircles = C;
    numCircles = nC;
}

void Picture::setLines(Line* L, int nL)
{
    pLines = L;
    numLines = nL;
}

void Picture::Paint()
{
    /// Draw all rectangles
    for (int i = 0; i < numRects; i++)
    {
        pRects[i].Draw();
    }

    /// Draw all circles
    for (int i = 0; i < numCircles; i++)
    {
        pCircles[i].Draw();
    }

    /// Draw all lines
    for (int i = 0; i < numLines; i++)
    {
        pLines[i].Draw();
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

    /// Picture

    Rect Rectangles[2] = { R1, R2 };
    Circle Circles[2] = { C1, C2 };
    Line Lines[2] = { L1, L2 };

    Picture P( Rectangles, 2, Circles, 2,Lines, 2);

    P.Paint();

    getch();

    closegraph();

    return 0;
}
