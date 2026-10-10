#include "pch.h"
#include "Real.h"
#include <iostream>
#include <cmath>
using namespace std;

// Number methods
void Real::Number::Init(double value)
{
    setValue(value);
}

void Real::Number::Display() const
{
    cout << "Number = " << value << endl;
}

void Real::Number::Read()
{
    double value;
    cout << "Enter a number: ";
    cin >> value;
    Init(value);
}

Real::Number Real::Number::Multiply(Number n)
{
    Number result;
    result.Init(value * n.value);
    return result;
}

Real::Number Real::Number::Subtract(Number n)
{
    Number result;
    result.Init(value - n.value);
    return result;
}

// Real methods
void Real::Init(Number number)
{
    setNumber(number);
}

void Real::Display() const
{
    cout << endl;
    cout << "Number object:" << endl;
    number.Display();
}

void Real::Read()
{
    Number n;
    cout << endl;
    cout << "Enter data for Real:" << endl;
    n.Read();
    Init(n);
}

double Real::Root(double degree) const
{
    if (degree == 0)
        return NAN;

    double value = number.getValue();

    if (value < 0)
    {
        if (fmod(fabs(degree), 2.0) != 1.0)
            return NAN;

        return -pow(-value, 1.0 / degree);
    }

    return pow(value, 1.0 / degree);
}

double Real::PiPower(double degree) const
{
    return pow(acos(-1.0), degree);
}
