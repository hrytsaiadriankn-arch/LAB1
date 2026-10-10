#pragma once

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

    void Multiply(double number);
    void Subtract(double number);
};
