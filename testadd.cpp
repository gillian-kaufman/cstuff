#include "fraction.h"
#include <iostream>
using namespace std;

int main()
{
    Fraction a(3, 4);
    Fraction b(5, 8);
    Fraction c;

    c = a + b;
    cout << a << " + " << b << " = " << c << endl;
    //  cout << c << endl;
    while (!cin.eof()) {
        cout << "enter a fraction: "; cin >> a;
        cout << "enter a fraction: "; cin >> b;
        cout << a << " + " << b << " = " << a + b << endl;
    }
}