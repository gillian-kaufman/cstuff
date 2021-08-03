#include <string>
using namespace std;

class Fraction {
  private: int num, den;

  // constructors
public:
    Fraction ();
    Fraction (int n, int d);

 // methods
    void setNum(int n);
    void setDen(int d);
    int getNum();
    int getDen();
    string toString();
    Fraction add(Fraction b);
};
