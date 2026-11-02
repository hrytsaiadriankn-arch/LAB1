#pragma once
#include <string>

class LongLong
{
private:
    long high;
    unsigned long low;

public:
    LongLong();
    LongLong(long long value);

    long GetHigh() const;
    unsigned long GetLow() const;

    void SetHigh(long value);
    void SetLow(unsigned long value);

    void Init(long h, unsigned long l);
    void Read();
    void Display() const;
    std::string toString() const;
    long long ToInt64() const;

    LongLong operator+(const LongLong& other) const;
    LongLong operator-(const LongLong& other) const;
    LongLong operator*(const LongLong& other) const;
    LongLong operator/(const LongLong& other) const;
    LongLong operator%(const LongLong& other) const;

    LongLong operator+() const;
    LongLong operator-() const;

    bool operator==(const LongLong& other) const;
    bool operator!=(const LongLong& other) const;
    bool operator>(const LongLong& other) const;
    bool operator<(const LongLong& other) const;
    bool operator>=(const LongLong& other) const;
    bool operator<=(const LongLong& other) const;
};