#include "Rational.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <cstdint>

using namespace std;

namespace
{
    uint64_t Magnitude(long long value)
    {
        if (value < 0)
            return static_cast<uint64_t>(-(value + 1)) + 1;

        return static_cast<uint64_t>(value);
    }

    uint64_t GCD(uint64_t a, uint64_t b)
    {
        while (b != 0)
        {
            uint64_t temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }
}

Rational::Rational() : a(0), b(1)
{
}

Rational::Rational(long long numerator, long long denominator)
    : a(0), b(1)
{
    if (!Init(numerator, denominator))
        throw invalid_argument("Invalid fraction");
}

LongLong Rational::GetA() const
{
    return a;
}

LongLong Rational::GetB() const
{
    return b;
}

bool Rational::SetA(LongLong value)
{
    return Init(value.ToInt64(), b.ToInt64());
}

bool Rational::SetB(LongLong value)
{
    if (value.ToInt64() == 0)
        return false;

    return Init(a.ToInt64(), value.ToInt64());
}

bool Rational::Init(long long numerator, long long denominator)
{
    if (denominator == 0)
        return false;

    if (denominator == numeric_limits<long long>::min())
        return false;

    if (denominator < 0 &&
        numerator == numeric_limits<long long>::min())
        return false;

    LongLong oldA = a;
    LongLong oldB = b;

    try
    {
        a = LongLong(numerator);
        b = LongLong(denominator);

        Reduce();
        return true;
    }
    catch (...)
    {
        a = oldA;
        b = oldB;
        return false;
    }
}

void Rational::Reduce()
{
    long long numerator = a.ToInt64();
    long long denominator = b.ToInt64();

    if (denominator == 0)
        throw invalid_argument("Denominator cannot be zero");

    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    uint64_t g = GCD(
        Magnitude(numerator),
        static_cast<uint64_t>(denominator)
    );

    if (g != 0)
    {
        numerator /= static_cast<long long>(g);
        denominator /= static_cast<long long>(g);
    }

    a = LongLong(numerator);
    b = LongLong(denominator);
}

void Rational::Read()
{
    long long numerator, denominator;

    while (true)
    {
        cout << "Numerator: ";

        if (!(cin >> numerator))
            throw runtime_error("Invalid numerator");

        cout << "Denominator (not zero): ";

        if (!(cin >> denominator))
            throw runtime_error("Invalid denominator");

        if (Init(numerator, denominator))
            return;

        cout << "Incorrect fraction. Try again.\n";
    }
}

void Rational::Display() const
{
    cout << toString();
}

string Rational::toString() const
{
    return a.toString() + "/" + b.toString();
}

Rational Rational::add(const Rational& other) const
{
    LongLong numerator = a * other.b + other.a * b;
    LongLong denominator = b * other.b;

    return Rational(numerator.ToInt64(), denominator.ToInt64());
}

Rational Rational::sub(const Rational& other) const
{
    LongLong numerator = a * other.b - other.a * b;
    LongLong denominator = b * other.b;

    return Rational(numerator.ToInt64(), denominator.ToInt64());
}

Rational Rational::mul(const Rational& other) const
{
    LongLong numerator = a * other.a;
    LongLong denominator = b * other.b;

    return Rational(numerator.ToInt64(), denominator.ToInt64());
}

Rational Rational::div(const Rational& other) const
{
    if (other.a.ToInt64() == 0)
        throw invalid_argument("Division by zero fraction");

    LongLong numerator = a * other.b;
    LongLong denominator = b * other.a;

    return Rational(numerator.ToInt64(), denominator.ToInt64());
}

bool Rational::equal(const Rational& other) const
{
    return a == other.a && b == other.b;
}

bool Rational::great(const Rational& other) const
{
    return a * other.b > other.a * b;
}

bool Rational::less(const Rational& other) const
{
    return a * other.b < other.a * b;
}