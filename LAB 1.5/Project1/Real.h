#pragma once

#include "Number.h"

class Real
{
private:
    Number number;

public:
    Number getNumber() const { return number; }

    void setNumber(Number number) { this->number = number; }

    void Init(Number number);
    void Display() const;
    void Read();

    double Root(int degree) const;
    double PiPower(int degree) const;
};
