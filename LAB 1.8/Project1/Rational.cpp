
#include "Rational.h"
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

static int64_t GCD(int64_t a, int64_t b)
{
    while (b != 0)
    {
        int64_t remainder = a % b;
        a = b;
        b = remainder;
    }

    return a < 0 ? -a : a;
}

Rational::Rational()
{
    a = LongLong(0);
    b = LongLong(1);
}

Rational::Rational(int64_t numerator, int64_t denominator)
{
    a = LongLong(0);
    b = LongLong(1);

    if (!Init(numerator, denominator))
        throw invalid_argument("Denominator cannot be zero");
}

int64_t Rational::GetNumerator() const
{
    return a.GetValue();
}

int64_t Rational::GetDenominator() const
{
    return b.GetValue();
}

bool Rational::Init(int64_t numerator, int64_t denominator)
{
    if (denominator == 0)
        return false;

    a = LongLong(numerator);
    b = LongLong(denominator);

    Reduce();
    return true;
}

void Rational::Reduce()
{
    int64_t numerator = a.GetValue();
    int64_t denominator = b.GetValue();

    if (denominator == 0)
        throw invalid_argument("Denominator cannot be zero");

    if (numerator == 0)
    {
        a = LongLong(0);
        b = LongLong(1);
        return;
    }

    if (denominator < 0)
    {
        if (denominator == numeric_limits<int64_t>::min() ||
            numerator == numeric_limits<int64_t>::min())
        {
            throw overflow_error("Integer overflow");
        }

        numerator = -numerator;
        denominator = -denominator;
    }

    if (numerator == numeric_limits<int64_t>::min())
        throw overflow_error("Integer overflow");

    int64_t absNumerator =
        numerator < 0 ? -numerator : numerator;

    int64_t divisor = GCD(absNumerator, denominator);

    a = LongLong(numerator / divisor);
    b = LongLong(denominator / divisor);
}

void Rational::Read()
{
    int64_t numerator, denominator;

    while (true)
    {
        cout << "Numerator: ";
        if (!(cin >> numerator))
            throw runtime_error("Invalid numerator");

        cout << "Denominator: ";
        if (!(cin >> denominator))
            throw runtime_error("Invalid denominator");

        if (Init(numerator, denominator))
            break;

        cout << "Error: denominator cannot be zero. Try again.\n";
    }
}

void Rational::Display() const
{
    cout << toString() << endl;
}

string Rational::toString() const
{
    return to_string(a.GetValue()) + "/" +
        to_string(b.GetValue());
}

Rational Rational::add(const Rational& other) const
{
    int64_t numerator =
        a.GetValue() * other.b.GetValue()
        + other.a.GetValue() * b.GetValue();

    int64_t denominator =
        b.GetValue() * other.b.GetValue();

    Rational result(numerator, denominator);
    result.Reduce();

    return result;
}

Rational Rational::sub(const Rational& other) const
{
    int64_t numerator =
        a.GetValue() * other.b.GetValue()
        - other.a.GetValue() * b.GetValue();

    int64_t denominator =
        b.GetValue() * other.b.GetValue();

    Rational result(numerator, denominator);
    result.Reduce();

    return result;
}

Rational Rational::mul(const Rational& other) const
{
    int64_t numerator =
        a.GetValue() * other.a.GetValue();

    int64_t denominator =
        b.GetValue() * other.b.GetValue();

    Rational result(numerator, denominator);
    result.Reduce();

    return result;
}

Rational Rational::div(const Rational& other) const
{
    if (other.a.GetValue() == 0)
        throw runtime_error("Division by zero rational");

    int64_t numerator =
        a.GetValue() * other.b.GetValue();

    int64_t denominator =
        b.GetValue() * other.a.GetValue();

    Rational result(numerator, denominator);
    result.Reduce();

    return result;
}

bool Rational::equal(const Rational& other) const
{
    return a.GetValue() == other.a.GetValue()
        && b.GetValue() == other.b.GetValue();
}

bool Rational::great(const Rational& other) const
{
    long double first =
        static_cast<long double>(a.GetValue()) /
        b.GetValue();

    long double second =
        static_cast<long double>(other.a.GetValue()) /
        other.b.GetValue();

    return first > second;
}

bool Rational::less(const Rational& other) const
{
    long double first =
        static_cast<long double>(a.GetValue()) /
        b.GetValue();

    long double second =
        static_cast<long double>(other.a.GetValue()) /
        other.b.GetValue();

    return first < second;
}
