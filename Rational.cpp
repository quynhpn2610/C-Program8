//  Created by Chi Hoang on 3/23/21.
//  Updated by Chi Hoang on 4/13/21
//  Project 11
//  Rational.cpp
//  Member-function definitions for class Rational
//  Added overloading operators
//  Added exception handlings

#include <iostream>
#include "Rational.h"
#include "DividedByZeroException.h"

using namespace std;
using std::cout;

//Rational class definition
Rational::Rational() {
    num = 0;
    den = 1;
}

//Set values
void Rational::setValues(int a, int b) {
    num = a;
    den = b;
    //throw zero exception
    if (den==0)
        throw DividedByZeroException();
    reduce();
}

//Return numer values
int Rational::getNumer()
{
    return num;
}

//Return denom values
int Rational::getDenom()
{
    return den;
}

//Addition function
void Rational::add(Rational x) {
    num = (num * x.den) + (den * x.num);
    den =  den * x.den;
    reduce();
}
//Substraction function
void Rational::sub(Rational x) {
    num = (num * x.den) - (den * x.num);
    den = den * x.den;
    reduce();
}
//Multiply function
void Rational::mult (Rational x) {
    num = num * x.num;
    den = den * x.den;
    reduce();
}
//Division function
void Rational::div (Rational x) {
    num = num * x.den;
    den = den * x.num;
    reduce();
}
//Reciprocal function
void Rational::reciprocal() {

    int newNum;
    int newDen;

    newNum = den;
    newDen = num;

    //throw exception if newDen results in 0
    if (newDen == 0) {
        throw DividedByZeroException();
    }
    setValues(newNum, newDen);
}
//Negate function
void Rational::negate() {
    int newNum = -num;
    int newDen = den;
    setValues(newNum, newDen);
}
//Great commmon divisor
int Rational::gcd (int a, int b){
    if(b ==0) {
        return a;
    }
    return gcd(b, a%b);
}

//Simplest reduction
void Rational::reduce() {

    //throw exception if den results in 0
    if (den == 0) {
        throw DividedByZeroException();
    }
    int largest = gcd(num, den);
    num = num / largest;
    den = den / largest;

    if (den < 0) {
        den = -den;
        num = -num;
    }
}

//Overloading operators
//Addition
Rational Rational::operator+(Rational x) {
    Rational temp = *this;
    temp.add(x);
    return temp;
}

//Substraction
Rational Rational::operator-(Rational x) {
    Rational temp = *this;
    temp.sub(x);
    return temp;
}

//Multiply
Rational Rational::operator*(Rational x) {
    Rational temp = *this;
    temp.mult(x);
    return temp;
}

//Division
Rational Rational::operator/(Rational x){
    Rational temp = *this;
    temp.div(x);

    //throw zero exception
    if(temp.den == 0){
        throw DividedByZeroException();
    }
    return temp;
}

//Negate
Rational Rational::operator-(){
    Rational temp = *this;
    temp.negate();
    return temp;
}
//Reciprocal
Rational Rational::operator!(){
    Rational temp = *this;
    temp.reciprocal();
    return temp;
}

bool Rational::operator>(Rational x) {
    return this->num * x.den > this->den * x.num;
}

bool Rational::operator<=(Rational x) {
    return !(*this>x);
}

bool Rational::operator<(Rational x) {
    return this->num * x.den < this->den * x.num;
}

bool Rational::operator>=(Rational x) {
    return !(*this<x);
}

bool Rational::operator==(Rational x) {
    return this->num == x.num && this->den == x.den;
}

bool Rational::operator!=(Rational x) {
    return !(*this==x);
}

//Print number as double
void Rational::printf() {
    cout<< static_cast<double>(num)/den;
}

//Print number as rational
void Rational::print() {
    cout << getNumer() << '/' << getDenom();
}
