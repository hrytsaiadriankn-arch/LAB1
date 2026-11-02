#include "LongLong.h"
#include "Rational.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ukr");

    try
    {
        cout << "=== LONG LONG ===" << endl;

        LongLong a(20);
        LongLong b(5);

        cout << "a = " << a.toString() << endl;
        cout << "b = " << b.toString() << endl;

        cout << "a + b = " << (a + b).toString() << endl;
        cout << "a - b = " << (a - b).toString() << endl;
        cout << "a * b = " << (a * b).toString() << endl;
        cout << "a / b = " << (a / b).toString() << endl;
        cout << "a % b = " << (a % b).toString() << endl;

        cout << "a > b: " << (a > b) << endl;

        cout << "\n=== RATIONAL ===" << endl;

        Rational r1(1, 2);
        Rational r2(1, 3);

        cout << "r1 = " << r1.toString() << endl;
        cout << "r2 = " << r2.toString() << endl;

        cout << "r1 + r2 = " << r1.add(r2).toString() << endl;
        cout << "r1 - r2 = " << r1.sub(r2).toString() << endl;
        cout << "r1 * r2 = " << r1.mul(r2).toString() << endl;
        cout << "r1 / r2 = " << r1.div(r2).toString() << endl;

        cout << "r1 < r2: " << r1.less(r2) << endl;
        cout << "r1 > r2: " << r1.great(r2) << endl;
        cout << "r1 == r2: " << r1.equal(r2) << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}