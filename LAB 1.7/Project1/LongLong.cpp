
#include "LongLong.h"
#include <iostream>
#include <cstdint>
#include <limits>
#include <stdexcept>

using namespace std;

namespace
{
    long long CheckedAdd(long long a, long long b)
    {
        long long mn = numeric_limits<long long>::min();
        long long mx = numeric_limits<long long>::max();

        if ((b > 0 && a > mx - b) ||
            (b < 0 && a < mn - b))
            throw overflow_error("Addition overflow");

        return a + b;
    }

    long long CheckedSub(long long a, long long b)
    {
        long long mn = numeric_limits<long long>::min();
        long long mx = numeric_limits<long long>::max();

        if ((b < 0 && a > mx + b) ||
            (b > 0 && a < mn + b))
            throw overflow_error("Subtraction overflow");

        return a - b;
    }

    long long CheckedMul(long long a, long long b)
    {
        long long mn = numeric_limits<long long>::min();
        long long mx = numeric_limits<long long>::max();

        if (a > 0)
        {
            if ((b > 0 && a > mx / b) ||
                (b < 0 && b < mn / a))
                throw overflow_error("Multiplication overflow");
        }
        else if (a < 0)
        {
            if ((b > 0 && a < mn / b) ||
                (b < 0 && a < mx / b))
                throw overflow_error("Multiplication overflow");
        }

        return a * b;
    }
}

LongLong::LongLong() : high(0), low(0)
{
}

LongLong::LongLong(long long value)
{
    uint64_t bits = static_cast<uint64_t>(value);
    uint32_t upper = static_cast<uint32_t>(bits >> 32);

    if (upper <= 2147483647U)
        high = static_cast<long>(upper);
    else
        high = static_cast<long>(
            static_cast<long long>(upper) - 4294967296LL);

    low = static_cast<unsigned long>(
        static_cast<uint32_t>(bits));
}

long LongLong::GetHigh() const
{
    return high;
}

unsigned long LongLong::GetLow() const
{
    return low;
}

void LongLong::SetHigh(long value)
{
    high = value;
}

void LongLong::SetLow(unsigned long value)
{
    low = value;
}

void LongLong::Init(long h, unsigned long l)
{
    high = h;
    low = l;
}

long long LongLong::ToInt64() const
{
    return static_cast<long long>(high) * 4294967296LL
        + static_cast<uint32_t>(low);
}

void LongLong::Read()
{
    long long value;

    cout << "Enter a 64-bit integer: ";

    if (!(cin >> value))
        throw runtime_error("Invalid integer");

    *this = LongLong(value);
}

void LongLong::Display() const
{
    cout << toString();
}

string LongLong::toString() const
{
    return to_string(ToInt64());
}

LongLong LongLong::operator+(const LongLong& other) const
{
    return LongLong(CheckedAdd(ToInt64(), other.ToInt64()));
}

LongLong LongLong::operator-(const LongLong& other) const
{
    return LongLong(CheckedSub(ToInt64(), other.ToInt64()));
}

LongLong LongLong::operator*(const LongLong& other) const
{
    return LongLong(CheckedMul(ToInt64(), other.ToInt64()));
}

LongLong LongLong::operator/(const LongLong& other) const
{
    long long a = ToInt64();
    long long b = other.ToInt64();

    if (b == 0)
        throw invalid_argument("Division by zero");

    if (a == numeric_limits<long long>::min() && b == -1)
        throw overflow_error("Division overflow");

    return LongLong(a / b);
}

LongLong LongLong::operator%(const LongLong& other) const
{
    long long a = ToInt64();
    long long b = other.ToInt64();

    if (b == 0)
        throw invalid_argument("Division by zero");

    if (a == numeric_limits<long long>::min() && b == -1)
        return LongLong(0);

    return LongLong(a % b);
}

LongLong LongLong::operator+() const
{
    return *this;
}

LongLong LongLong::operator-() const
{
    if (ToInt64() == numeric_limits<long long>::min())
        throw overflow_error("Negation overflow");

    return LongLong(-ToInt64());
}

bool LongLong::operator==(const LongLong& other) const
{
    return high == other.high && low == other.low;
}

bool LongLong::operator!=(const LongLong& other) const
{
    return !(*this == other);
}

bool LongLong::operator>(const LongLong& other) const
{
    return ToInt64() > other.ToInt64();
}

bool LongLong::operator<(const LongLong& other) const
{
    return ToInt64() < other.ToInt64();
}

bool LongLong::operator>=(const LongLong& other) const
{
    return !(*this < other);
}

bool LongLong::operator<=(const LongLong& other) const
{
    return !(*this > other);
}