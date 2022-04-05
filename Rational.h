//
//  Rational.h
//  Student name:
//  Date modified:
//  Student supplied synopsis of the Rational class:
//
//  Created by L.Rhodes on 3/16/20.
//

#ifndef Rational_h
#define Rational_h
class Rational {
public:
    Rational();
    Rational(int,int);
    void setValues(int,int);// change the rational number in the object
    int getNumer();
    int getDenom();
    void print();
    void printf();
    void add(Rational); //x.add(y) means x = x + y
    void sub(Rational); // x = x - y
    void mult(Rational);// x = x * y
    void div(Rational); // x = x / y
    void reciprocal();  // x = 1 / x
    void negate(); // x = -x
    // in a later project you will overload operators--don't do it now.
    // Rational operator+(Rational)
    // boolean operator==(Rational)

private:
    int num;
    int den;
    int gcd(int, int);
    void reduce(); //local function to care for reducing to simplest terms
    //and negative sign always in the numerator
}

#endif /* Rational_h */