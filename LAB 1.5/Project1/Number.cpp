#include "pch.h"
#include "Number.h"
#include <iostream>
using namespace std;

void Number::Init(double value)
{
    setValue(value);
}

void Number::Display() const
{
    cout << "value = " << value << endl;
}

void Number::Read()
{
    double value;

    cout << "value = ? ";
    cin >> value;

    Init(value);
}

void Number::Multiply(double number)
{
    value = value * number;
}

void Number::Subtract(double number)
{
    value = value - number;
}