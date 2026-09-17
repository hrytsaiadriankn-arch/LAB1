#pragma once
#include <string>
using namespace std;

class Money
{
private:
    long hryvnias;
    unsigned char kopecks;

public:
    long GetHryvnias() const { return hryvnias; }
    unsigned char GetKopecks() const { return kopecks; }

    bool SetHryvnias(long);
    bool SetKopecks(int);

    bool Init(long, int);
    void Read();
    void Display() const;
    string toString() const;

    Money Subtract(const Money&) const;
    Money Multiply(double) const;

    bool Equal(const Money&) const;
    bool NotEqual(const Money&) const;
    bool Less(const Money&) const;
    bool Greater(const Money&) const;
};