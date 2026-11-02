
#include "Rational.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    try
    {
        Rational first, second;

        cout << "Enter the first rational number:\n";
        first.Read();

        cout << "\nEnter the second rational number:\n";
        second.Read();

        cout << "\nFirst number: ";
        first.Display();

        cout << "Second number: ";
        second.Display();

        cout << "\nAddition: ";
        first.add(second).Display();

        cout << "Subtraction: ";
        first.sub(second).Display();

        cout << "Multiplication: ";
        first.mul(second).Display();

        cout << "Division: ";
        first.div(second).Display();

        cout << "\nComparison:\n";

        cout << "Equal: "
            << (first.equal(second) ? "true" : "false")
            << endl;

        cout << "Greater: "
            << (first.great(second) ? "true" : "false")
            << endl;

        cout << "Less: "
            << (first.less(second) ? "true" : "false")
            << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
