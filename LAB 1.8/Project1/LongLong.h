
#pragma once
#include <cstdint>

class LongLong
{
private:
    long high;
    unsigned long low;

    void SetValue(int64_t value);

public:
    LongLong();
    LongLong(int64_t value);

    int64_t GetValue() const;

    LongLong operator+(const LongLong& other) const;
    LongLong operator-(const LongLong& other) const;
    LongLong operator*(const LongLong& other) const;
    LongLong operator/(const LongLong& other) const;
    LongLong operator%(const LongLong& other) const;

    LongLong operator+() const;
    LongLong operator-() const;

    LongLong& operator++();
    LongLong operator++(int);
    LongLong& operator--();
    LongLong operator--(int);

    bool operator==(const LongLong& other) const;
    bool operator!=(const LongLong& other) const;
    bool operator>(const LongLong& other) const;
    bool operator<(const LongLong& other) const;
    bool operator>=(const LongLong& other) const;
    bool operator<=(const LongLong& other) const;
};
