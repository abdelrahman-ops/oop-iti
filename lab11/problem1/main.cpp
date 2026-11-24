#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

/// ======================= ALL CLASSES
class Point{
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


class Rect{
private:
    Point TL, BR;
public:
    Rect();
    Rect(Point P1, Point P2);

    void setTopLeft(Point p);
    void setBottomRight(Point p);

    Point getTopLeft();
    Point getBottomRight();

    void Draw();
};


class Circle{
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

    void Draw();
};


class Line{
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

    void Draw();
};


/// ======================= IMPLEMENTATION
Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(int x, int y){
    this->x = x;
    this -> y = y;
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

}

/// ======================================= RECTANGLE DRAW
Rect::Rect(){
    TL.setX(0);
    BR.setY(0);
    TL.setY(0);
    BR.setX(0);
}

Rect::Rect(Point P1, Point P2){
    TL = P1;
    BR = P2;
}

void Rect::setTopLeft(Point p){
    TL = p;
}

void Rect::setBottomRight(Point p){
    BR = p;
}

Point Rect::getTopLeft(){
    return TL;
}

Point Rect::getBottomRight(){
    return BR;
}

void Rect::Draw(){
    rectangle(TL.getX(), TL.getY(), BR.getX(), BR.getY());
}


/// ======================================= CIRCLE DRAW
Circle::Circle(){
    center.setX(0);
    center.setY(0);
    radius = 0;
}

Circle::Circle(Point c, int r){
    center = c;
    radius = r;
}

void Circle::setCenter(Point c){
    center = c;
}

void Circle::setRadius(int r){
    radius = r;
}

Point Circle::getCenter(){
    return center;
}

int Circle::getRadius(){
    return radius;
}

void Circle::Draw(){
    circle(center.getX(), center.getY(), radius);
}


/// ======================================= LINE DRAW
Line::Line(){
    Start.setX(0);
    End.setY(0);
    setcolor(6);
}

Line::Line(Point S, Point E)
{
    Start = S;
    End = E;
}

void Line::setStart(Point S){
    Start = S;
}

void Line::setEnd(Point E){
    End = E;
}

Point Line::getStart(){
    return Start;
}

Point Line::getEnd(){
    return End;
}

void Line::Draw(){
    line(Start.getX(), Start.getY(), End.getX(), End.getY());
}




int main()
{
    initwindow(800, 600);

    Point P1(100, 100);
    Point P2(300, 250);
    Point P3(200, 200);

    Rect Rec(P1,P2);
    setcolor(1);
    Rec.Draw();


    Circle Cir(P1, 100);
    setcolor(3);
    Cir.Draw();

    Line l(P1,P3);
    setcolor(5);
    l.Draw();



    getch();

    closegraph();
    return 0;
}
