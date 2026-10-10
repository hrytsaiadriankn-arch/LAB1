#include "Real.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    Real r;

    r.Read();
    r.Display();

    double number;

    cout << endl;
    cout << "Number for multiplication = ";
    cin >> number;

    Number n = r.getNumber();
    n.Multiply(number);

    cout << "After multiplication: ";
    n.Display();

    cout << endl;
    cout << "Number for subtraction = ";
    cin >> number;

    n.Subtract(number);

    cout << "After subtraction: ";
    n.Display();

    int degree;

    cout << endl;
    cout << "Root degree = ";
    cin >> degree;

    double root = r.Root(degree);

    if (isnan(root))
        cout << "Root is not defined in real numbers." << endl;
    else
        cout << "Root = " << root << endl;

    cout << endl;
    cout << "Pi power degree = ";
    cin >> degree;

    cout << "Pi power = " << r.PiPower(degree) << endl;

    return 0;
}