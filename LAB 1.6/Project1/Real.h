#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Real
{
public:
    class Number
    {
    private:
        double value;

    public:
        double getValue() const { return value; }
        void setValue(double value) { this->value = value; }

        void Init(double value);
        void Display() const;
        void Read();

        Number Multiply(Number n);
        Number Subtract(Number n);
    };

private:
    Number number;

public:
    Number getNumber() const { return number; }
    void setNumber(Number number) { this->number = number; }

    void Init(Number number);
    void Display() const;
    void Read();

    double Root(double degree) const;
    double PiPower(double degree) const;
};
