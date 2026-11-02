#pragma once
#include "LongLong.h"
#include <string>

class Rational
{
private:
    LongLong a;
    LongLong b;

    void Reduce();

public:
    Rational();
    Rational(long long numerator, long long denominator);

    LongLong GetA() const;
    LongLong GetB() const;

    bool SetA(LongLong value);
    bool SetB(LongLong value);

    bool Init(long long numerator, long long denominator);
    void Read();
    void Display() const;
    std::string toString() const;

    Rational add(const Rational& other) const;
    Rational sub(const Rational& other) const;
    Rational mul(const Rational& other) const;
    Rational div(const Rational& other) const;

    bool equal(const Rational& other) const;
    bool great(const Rational& other) const;
    bool less(const Rational& other) const;
};