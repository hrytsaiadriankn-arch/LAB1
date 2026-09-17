#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    Matrix m;

    m.Read();
    m.Display();

    cout << "Minimum element = " << m.getMin() << endl;
    cout << "Maximum element = " << m.getMax() << endl;
    cout << "Sum of elements = " << m.getSum() << endl;

    Matrix m2 = makeMatrix(2, 3);

    m2.SetElement(0, 0, 1.5);
    m2.SetElement(0, 1, 2.5);
    m2.SetElement(0, 2, 3.5);
    m2.SetElement(1, 0, 4.5);
    m2.SetElement(1, 1, 5.5);
    m2.SetElement(1, 2, 6.5);

    cout << endl << "Matrix created by makeMatrix:" << endl;
    m2.Display();

    cout << "Minimum element = " << m2.getMin() << endl;
    cout << "Maximum element = " << m2.getMax() << endl;
    cout << "Sum of elements = " << m2.getSum() << endl;

    return 0;
}