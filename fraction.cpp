// create a fraction class implementing constructors and basic math functions - add, subtract, multiply, divide, reciprocate.
// then implement a test program

#include "fraction.h"

Fraction::Fraction (){
  num = 0;
  den = 1;
}

Fraction::Fraction (int n, int d){
  num = n;
  den = d;
}

// methods
void Fraction::setNum(int n){
  num = n;
}

void Fraction::setDen(int d){
  den = d;
}

int Fraction::getNum(){
  return num;
}

int Fraction::getDen(){
  return den;
}

string Fraction::toString(){
  return(to_string(num) + "/" + to_string(den));
}

Fraction Fraction::add(Fraction b){
  Fraction ans;
  ans.setNum(num * b.getDen() + den * b.getNum());
  ans.setDen(den * b.getDen());
  return(ans);
}
