#include "Pay.h"
#include <iostream>
#include <iomanip>

using namespace std;

Pay makePay(double salary, int workedDays)
{
    Pay p;

    if (!p.Init(salary, workedDays))
        cout << "Wrong arguments to Init!" << endl;

    return p;
}

int main()
{
    Pay p;

    p.Init(15000.0, 18);

    p.Display();

    int workingDaysInMonth = 22;

    cout << fixed << setprecision(2);

    cout << "Working days in month = "
        << workingDaysInMonth << endl;

    cout << "Summa = "
        << p.Summa(workingDaysInMonth)
        << endl;

    return 0;
}