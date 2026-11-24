#include <iostream>
#include <graphics.h>
#include <conio.h>
#include "MyLibrary.h"

using namespace std;


class Point
{
private:
    int x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    int getX() { return x; }
    int getY() { return y; }

    void Draw()
    {
        putpixel(x, y, WHITE);
    }
};


class Rect
{
private:
    Point TL, BR;

public:
    Rect() {}

    Rect(Point P1, Point P2)
    {
        TL = P1;
        BR = P2;
    }

    void setTopLeft(Point p) { TL = p; }
    void setBottomRight(Point p) { BR = p; }

    Point getTopLeft() { return TL; }
    Point getBottomRight() { return BR; }

    void Draw()
    {
        rectangle(TL.getX(), TL.getY(),
                  BR.getX(), BR.getY());
    }
};


class Circle
{
private:
    Point center;
    int radius;

public:
    Circle()
    {
        radius = 0;
    }

    Circle(Point c, int r)
    {
        center = c;
        radius = r;
    }

    void setCenter(Point c) { center = c; }
    void setRadius(int r) { radius = r; }

    int getRadius() { return radius; }
    Point getCenter() { return center; }

    void Draw()
    {
        circle(center.getX(), center.getY(), radius);
    }
};

class Line
{
private:
    Point Start, End;

public:
    Line() {}

    Line(Point S, Point E)
    {
        Start = S;
        End = E;
    }

    void setStart(Point S) { Start = S; }
    void setEnd(Point E) { End = E; }

    Point getStart() { return Start; }
    Point getEnd() { return End; }

    void Draw()
    {
        line(Start.getX(), Start.getY(),
             End.getX(), End.getY());
    }
};

/// ========================================================================================== LAMP

class Lamp
{
private:
    Rect Stand;
    Circle Bulb;

    Line Ray1, Ray2, Ray3, Ray4, Ray5;
    Line Ray6, Ray7, Ray8, Ray9, Ray10;

public:
    Lamp()
    {
        /// Vertical stand
        Stand = Rect(Point(200, 490), Point(180, 200));
        /// Bulb
        Bulb = Circle(Point(190, 205), 40);

        /// Rays below and beside the lampshade
        Ray1 = Line(Point(125, 190), Point(65, 260));
        Ray2 = Line(Point(145, 205), Point(105, 300));
        Ray3 = Line(Point(180, 215), Point(180, 320));
        Ray4 = Line(Point(215, 205), Point(255, 300));
        Ray5 = Line(Point(235, 190), Point(295, 260));

        /// Rays above the lampshade
        Ray6 = Line(Point(110, 130), Point(80, 95));
        Ray7 = Line(Point(150, 130), Point(140, 75));
        Ray8 = Line(Point(180, 125), Point(180, 65));
        Ray9 = Line(Point(210, 130), Point(220, 75));
        Ray10 = Line(Point(250, 130), Point(280, 95));
    }

    void Draw(bool isOn)
    {
        setcolor(WHITE);

        Stand.Draw();

        if (isOn)
        {
            setcolor(YELLOW);
            setfillstyle(SOLID_FILL, YELLOW);
            fillellipse(190, 205, 30, 30);

            Ray1.Draw();
            Ray2.Draw();
            Ray3.Draw();
            Ray4.Draw();
            Ray5.Draw();

            Ray6.Draw();
            Ray7.Draw();
            Ray8.Draw();
            Ray9.Draw();
            Ray10.Draw();
        }
        else
        {
            setcolor(DARKGRAY);
            Bulb.Draw();
        }

        setcolor(LIGHTGRAY);
    }
};

// ======================= PERSON =======================

class Person
{
private:
    Circle Head;
    Circle Eye;

    Line Body;
    Line LeftArm, RightArm;
    Line LeftLeg, RightLeg;

public:
    Person()
    {
        Head = Circle(Point(430, 260), 30);
        Eye = Circle(Point(418, 253), 3);

        Body = Line(Point(430, 290), Point(430, 435));

        LeftArm = Line(Point(430, 325), Point(200, 400));

        RightArm = Line(Point(430, 325), Point(470, 385));

        LeftLeg = Line(Point(430, 435), Point(395, 520));
        RightLeg = Line(Point(430, 435), Point(470, 520));
    }

    void Draw(bool reaching)
    {
        setcolor(WHITE);

        Head.Draw();
        Eye.Draw();
        Body.Draw();

        if (reaching)
        {
            LeftArm.Draw();
        }
        else
        {
            Line RelaxedArm(Point(430, 325),Point(385, 375));
            RelaxedArm.Draw();
        }

        RightArm.Draw();

        LeftLeg.Draw();
        RightLeg.Draw();
    }
};

int main()
{
    initwindow(800, 600);

    Lamp L;
    Person P;

    bool isOn = false;
    bool reaching = false;

    char key;

    while (true)
    {
        cleardevice();

        L.Draw(isOn);

        P.Draw(reaching);

        if (isOn)
        {
            setcolor(GREEN);
            outtextxy(330, 40, "LAMP: ON");
        }
        else
        {
            setcolor(RED);
            outtextxy(330, 40, "LAMP: OFF");
        }

        setcolor(WHITE);
        outtextxy(300, 470, "Press O to turn ON");
        outtextxy(300, 490, "Press F to turn OFF");
        outtextxy(300, 510, "Any other key to EXIT");

        if (kbhit())
        {
            key = getch();

            if (key == 'o' || key == 'O')
            {
                isOn = true;
                reaching = true;
            }
            else if (key == 'f' || key == 'F')
            {
                isOn = false;
                reaching = false;
            }
            else
            {
                break;
            }
        }

        delay(20);
    }

    closegraph();

    return 0;
}
