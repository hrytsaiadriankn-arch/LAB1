
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
    Rational(int64_t numerator, int64_t denominator);

    int64_t GetNumerator() const;
    int64_t GetDenominator() const;

    bool Init(int64_t numerator, int64_t denominator);

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
