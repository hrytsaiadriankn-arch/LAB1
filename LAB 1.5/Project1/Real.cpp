#include "pch.h"
#include "Real.h"
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

void Real::Init(Number number)
{
    setNumber(number);
}

void Real::Display() const
{
    cout << endl;
    cout << "number = " << endl;
    number.Display();
}

void Real::Read()
{
    Number n;

    cout << endl;
    cout << "Number = ?" << endl;
    n.Read();

    Init(n);
}

double Real::Root(int degree) const
{
    double value = number.getValue();

    if (degree <= 0)
        return numeric_limits<double>::quiet_NaN();

    if (value < 0 && degree % 2 == 0)
        return numeric_limits<double>::quiet_NaN();

    if (value < 0)
        return -pow(-value, 1.0 / degree);

    return pow(value, 1.0 / degree);
}

double Real::PiPower(int degree) const
{
    return pow(acos(-1.0), degree);
}
