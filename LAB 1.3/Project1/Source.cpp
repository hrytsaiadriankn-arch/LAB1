#include <iostream>
#include "Money.h"
using namespace std;

int main()
{
    Money a, b;

    cout << "Enter first money amount:" << endl;
    a.Read();

    cout << "Enter second money amount:" << endl;
    b.Read();

    cout << endl << "First amount: ";
    a.Display();

    cout << "Second amount: ";
    b.Display();

    cout << endl << "Subtraction: ";
    Money c = a.Subtract(b);
    c.Display();

    double k;
    cout << endl << "Enter multiplier: ";
    cin >> k;

    cout << "Multiplication: ";
    Money d = a.Multiply(k);
    d.Display();

    cout << endl << "Comparison:" << endl;

    if (a.Equal(b))
        cout << "Amounts are equal" << endl;

    if (a.NotEqual(b))
        cout << "Amounts are not equal" << endl;

    if (a.Less(b))
        cout << "First amount is less than second" << endl;

    if (a.Greater(b))
        cout << "First amount is greater than second" << endl;

    return 0;
}