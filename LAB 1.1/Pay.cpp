#include "Pay.h"
#include <iostream>

using namespace std;

bool Pay::SetFirst(double value)
{
    if (value > 0)
    {
        first = value;
        return true;
    }
    else
    {
        first = 0;
        return false;
    }
}

bool Pay::SetSecond(int value)
{
    if (value > 0)
    {
        second = value;
        return true;
    }
    else
    {
        second = 0;
        return false;
    }
}

bool Pay::Init(double salary, int workedDays)
{
    return SetFirst(salary) && SetSecond(workedDays);
}

void Pay::Read()
{
    double salary;
    int workedDays;

    do
    {
        cout << "Input salary = ";
        cin >> salary;

        cout << "Input worked days = ";
        cin >> workedDays;

        if (!Init(salary, workedDays))
            cout << "Wrong arguments!" << endl;

    } while (first <= 0 || second <= 0);
}

void Pay::Display() const
{
    cout << endl;
    cout << "Salary = " << first << endl;
    cout << "Worked days = " << second << endl;
}

double Pay::Summa(int workingDaysInMonth) const
{
    if (workingDaysInMonth <= 0)
        return 0;

    return first / workingDaysInMonth * second;
}