// test fraction Class
#include "fraction.h"
#include <iostream>
using namespace std;

int main() {
  Fraction a(3,4);
  Fraction b(5,8);

  cout << a.add(b).toString() << endl;

}
