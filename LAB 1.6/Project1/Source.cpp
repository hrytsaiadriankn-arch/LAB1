#include "Real.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    Real r;

    r.Read();
    r.Display();

    double degree;

    cout << endl;
    cout << "Enter the root degree: ";
    cin >> degree;

    if (degree == 0)
    {
        cout << "Root degree cannot be zero." << endl;
    }
    else
    {
        double root = r.Root(degree);

        if (isnan(root))
            cout << "The root is not a real number." << endl;
        else
            cout << "Root = " << root << endl;
    }

    cout << endl;
    cout << "Enter the power for pi: ";
    cin >> degree;

    cout << "Pi power = " << r.PiPower(degree) << endl;

    return 0;
}
