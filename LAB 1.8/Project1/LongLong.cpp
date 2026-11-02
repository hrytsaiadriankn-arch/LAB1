
#include "LongLong.h"
#include <stdexcept>
#include <cstring>
#include <limits>

LongLong::LongLong()
{
    high = 0;
    low = 0;
}

LongLong::LongLong(int64_t value)
{
    SetValue(value);
}

void LongLong::SetValue(int64_t value)
{
    uint64_t bits;
    std::memcpy(&bits, &value, sizeof(bits));

    uint32_t highBits = static_cast<uint32_t>(bits >> 32);
    int32_t signedHigh;

    std::memcpy(&signedHigh, &highBits, sizeof(signedHigh));

    high = static_cast<long>(signedHigh);
    low = static_cast<unsigned long>(
        static_cast<uint32_t>(bits));
}

int64_t LongLong::GetValue() const
{
    uint64_t bits =
        (static_cast<uint64_t>(
            static_cast<uint32_t>(high)) << 32)
        | static_cast<uint32_t>(low);

    int64_t value;
    std::memcpy(&value, &bits, sizeof(value));

    return value;
}

LongLong LongLong::operator+(const LongLong& other) const
{
    return LongLong(GetValue() + other.GetValue());
}

LongLong LongLong::operator-(const LongLong& other) const
{
    return LongLong(GetValue() - other.GetValue());
}

LongLong LongLong::operator*(const LongLong& other) const
{
    return LongLong(GetValue() * other.GetValue());
}

LongLong LongLong::operator/(const LongLong& other) const
{
    int64_t x = GetValue();
    int64_t y = other.GetValue();

    if (y == 0)
        throw std::runtime_error("Division by zero");

    if (x == INT64_MIN && y == -1)
        throw std::overflow_error("Integer overflow");

    return LongLong(x / y);
}

LongLong LongLong::operator%(const LongLong& other) const
{
    int64_t x = GetValue();
    int64_t y = other.GetValue();

    if (y == 0)
        throw std::runtime_error("Division by zero");

    if (x == INT64_MIN && y == -1)
        return LongLong(0);

    return LongLong(x % y);
}

LongLong LongLong::operator+() const
{
    return *this;
}

LongLong LongLong::operator-() const
{
    if (GetValue() == INT64_MIN)
        throw std::overflow_error("Integer overflow");

    return LongLong(-GetValue());
}

LongLong& LongLong::operator++()
{
    if (GetValue() == INT64_MAX)
        throw std::overflow_error("Integer overflow");

    SetValue(GetValue() + 1);
    return *this;
}

LongLong LongLong::operator++(int)
{
    LongLong temp = *this;
    ++(*this);
    return temp;
}

LongLong& LongLong::operator--()
{
    if (GetValue() == INT64_MIN)
        throw std::overflow_error("Integer overflow");

    SetValue(GetValue() - 1);
    return *this;
}

LongLong LongLong::operator--(int)
{
    LongLong temp = *this;
    --(*this);
    return temp;
}

bool LongLong::operator==(const LongLong& other) const
{
    return GetValue() == other.GetValue();
}

bool LongLong::operator!=(const LongLong& other) const
{
    return GetValue() != other.GetValue();
}

bool LongLong::operator>(const LongLong& other) const
{
    return GetValue() > other.GetValue();
}

bool LongLong::operator<(const LongLong& other) const
{
    return GetValue() < other.GetValue();
}

bool LongLong::operator>=(const LongLong& other) const
{
    return GetValue() >= other.GetValue();
}

bool LongLong::operator<=(const LongLong& other) const
{
    return GetValue() <= other.GetValue();
}
