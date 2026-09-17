#include "Money.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

bool Money::SetHryvnias(long value)
{
    if (value >= 0)
    {
        hryvnias = value;
        return true;
    }
    else
    {
        hryvnias = 0;
        return false;
    }
}

bool Money::SetKopecks(int value)
{
    if (value >= 0 && value < 100)
    {
        kopecks = (unsigned char)value;
        return true;
    }
    else
    {
        kopecks = 0;
        return false;
    }
}

bool Money::Init(long h, int k)
{
    return SetHryvnias(h) && SetKopecks(k);
}

void Money::Read()
{
    long h;
    int k;

    do
    {
        cout << "Hryvnias = ? ";
        cin >> h;

        cout << "Kopecks = ? ";
        cin >> k;
    } while (!Init(h, k));
}

string Money::toString() const
{
    stringstream sout;

    sout << hryvnias << "," << setw(2) << setfill('0')
        << (int)kopecks << " UAH";

    return sout.str();
}

void Money::Display() const
{
    cout << toString() << endl;
}

Money Money::Subtract(const Money& other) const
{
    long long a = (long long)hryvnias * 100 + kopecks;
    long long b = (long long)other.hryvnias * 100 + other.kopecks;

    long long result = a - b;

    Money temp;

    if (result < 0)
    {
        temp.Init(0, 0);
        return temp;
    }

    temp.Init(result / 100, result % 100);

    return temp;
}

Money Money::Multiply(double value) const
{
    long long total = (long long)hryvnias * 100 + kopecks;
    long long result = (long long)(total * value + 0.5);

    Money temp;

    if (result < 0)
    {
        temp.Init(0, 0);
        return temp;
    }

    temp.Init(result / 100, result % 100);

    return temp;
}

bool Money::Equal(const Money& other) const
{
    return hryvnias == other.hryvnias &&
        kopecks == other.kopecks;
}

bool Money::NotEqual(const Money& other) const
{
    return !Equal(other);
}

bool Money::Less(const Money& other) const
{
    if (hryvnias != other.hryvnias)
        return hryvnias < other.hryvnias;

    return kopecks < other.kopecks;
}

bool Money::Greater(const Money& other) const
{
    if (hryvnias != other.hryvnias)
        return hryvnias > other.hryvnias;

    return kopecks > other.kopecks;
}