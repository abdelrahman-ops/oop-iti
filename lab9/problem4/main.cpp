#include <iostream>

using namespace std;


class date{
private:
    int day;
    int month;
    int year;

    bool IsLeapYear(int y) const;
    int DaysInMonth(int m, int y) const;
    int ToSerial() const;
    void NextDay();
    void PrevDay();

public:
    date();
    date(int d, int m, int y);

    void PrintDate();

    int operator-(const date& D);
    date operator+(int days);

    date& operator++();
    date operator++(int);

    date& operator=(const date& D);

    bool operator==(const date& D) const;

    operator int() const;

    int operator[](char ch) const;


};

/// ======================================  Constructors

date::date(){
    day = 1;
    month = 1;
    year = 1970;
}

date::date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}


/// ====================================== Helper Functions
bool date::IsLeapYear(int y) const{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 !=0) ;
}

int date::DaysInMonth(int m, int y) const
{
    switch (m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            if (IsLeapYear(y))
                return 29;
            else
                return 28;
    }

    return 0;
}


int date::ToSerial() const
{
    int total = 0;

    for (int y = 1; y < year; y++)
    {
        if (IsLeapYear(y))
            total += 366;
        else
            total += 365;
    }

    for (int m = 1; m < month; m++)
    {
        total += DaysInMonth(m, year);
    }

    total += day;

    return total;
}


void date::NextDay()
{
    day++;

    if (day > DaysInMonth(month, year))
    {
        day = 1;
        month++;

        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

void date::PrevDay()
{
    day--;

    if (day < 1)
    {
        month--;

        if (month < 1)
        {
            year--;
        }

        day = DaysInMonth(month, year);
    }
}

/// ====================================== PrintDate()
void date::PrintDate(){
    cout << day << "/" << month << "/" << year << endl;
}

/// ====================================== operator- /// 19/11/2026 - 6/11/2003
int date::operator-(const date& D){
    return ToSerial() - D.ToSerial();
}

/// ====================================== operator+ /// 19/11/2026 + 15
date date::operator+(int days){
    date res(*this);

    if(days > 0){
        for(int i = 0; i < days; i++){
            res.NextDay();
        }
    }
    else{
        for (int i = 0; i > days; i--)
        {
            if (res.year == 1 && res.month == 1 && res.day == 1)
            {
                cout << "Date cannot be earlier than 1/1/1" << endl;
            }

            res.PrevDay();
        }
    }

    return res;

}


/// ====================================== operator++ prefix /// 19/11/2026 ++
date& date::operator++()
{
    NextDay();

    return *this;
}

/// ====================================== operator++ postfix --> 19/11/2026 ++
date date::operator++(int)
{
    date temp(*this);

    NextDay();

    return temp;
}


/// ====================================== operator= --> this = date
date& date::operator=(const date& D)
{
    day = D.day;
    month = D.month;
    year = D.year;

    return *this;
}


/// ====================================== operator== --> this == date ?
bool date::operator==(const date& D) const
{
    return (day == D.day &&
            month == D.month &&
            year == D.year);
}
/// ====================================== operator int() 19062003--> casting the date to an int YYYYMMDD
date::operator int() const
{
    return year * 10000 + month * 100 + day;
}


/// ======================================  operator[]
int date::operator[](char ch) const
{
    switch (ch)
    {
        case 'd':
        case 'D':
            return day;

        case 'm':
        case 'M':
            return month;

        case 'y':
        case 'Y':
            return year;

        default:
            cout << "Invalid date index!";
            break;
    }
}









int main()
{
    date d1(19, 11, 2026);
    date d2(25, 12, 2026);
    date d3(1, 12, 2026);

    cout << "Original dates:" << endl;

    cout << "d1 = ";
    d1.PrintDate();

    cout << "d2 = ";
    d2.PrintDate();

    cout << "d3 = ";
    d3.PrintDate();


    /// 1. operator-
    cout << "\n1. Subtraction d2 - d3:" << endl;

    int diff = d2 - d3;

    cout << "Difference = " << diff << " days" << endl;


    /// 2. operator+
    cout << "\n2. Addition:" << endl;

    date d4 = d1 + 15;

    cout << "d1 + 15 = ";
    d4.PrintDate();


    /// 3. Prefix ++
    cout << "\n3. Prefix increment:" << endl;

    date d5 = ++d1;

    cout << "d5 = ";
    d5.PrintDate();

    cout << "d1 = ";
    d1.PrintDate();


    /// 4. Postfix ++
    cout << "\n4. Postfix increment:" << endl;

    date d6 = d2++;

    cout << "d6 = ";
    d6.PrintDate();

    cout << "d2 = ";
    d2.PrintDate();


    /// 5. operator=
    cout << "\n5. Assignment:" << endl;

    d3 = date(06,11,2003);

    cout << "d3 = ";
    d3.PrintDate();


    /// 6. operator==
    cout << "\n6. Equality:" << endl;

    if (d1 == d3)
        cout << "Dates are equal" << endl;
    else
        cout << "Dates are not equal" << endl;


    /// 7. Casting operator
    cout << "\n7. Casting:" << endl;

    int x = (int)d1;

    cout << "Integer date = " << x << endl;


    /// 8. operator[]
    cout << "\n8. Array subscript operator:" << endl;

    cout << "Day = " << d1['d'] << endl;
    cout << "Month = " << d1['m'] << endl;
    cout << "Year = " << d1['y'] << endl;


    return 0;
}

