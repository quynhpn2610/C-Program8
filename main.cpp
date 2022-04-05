//  Created by Chi Hoang on 3/23/21.
//  Updated by Chi Hoang on 4/13/21
//  Project 11
//  Main.cpp
//  Driver class to test the Rational program. The program uses integer variables as the numerator and denominator of rational numbers to perform arithmetic with fractions.
//  Added overloading operators
//  Added exception handlings

#include <iostream>
#include <iomanip>
#include "Rational.h"
#include "DividedByZeroException.h"

using std::cout;
using std::cin;
using std::endl;
using namespace std;

int main(){
    //declare variables
    Rational a;
    Rational b;
    Rational z;
    int x;
    int y=1;
    int c;
    int d=1;
    //declare answer
    char answer;
    do {
        bool valid = false;
        cout << "Enter a rational number separating the numerator and denominator with a space: "<<endl;
        cin >> a;
        while (!valid){
            cout << "Enter 1st number's denominator: "<<endl;
            cin >> b;
            try {
                x.setValues(a,b);
                valid = true;
            } catch (DividedByZeroException &dividedbyZeroException) {
                cout << dividedbyZeroException.what() << "Try again!" <<endl;
            }
        }

        valid = false;
        cout << "Enter 2nd number's numerator: "<<endl;
        cin >> c;
        while (!valid) {
            cout << "Enter 2nd number's denominator: "<<endl;
            cin >> d;
            try {
                y.setValues(c,d);
                valid = true;
            } catch (DividedByZeroException & dividedbyZeroException) {
                cout << dividedbyZeroException.what() << "Try again!" <<endl;
            }
        }
        valid = false;

        //Print 1st rational number
        cout << "First fraction: ";
        x.print();
        cout << " or ";
        x.printf();
        cout << endl;

        //Print 2nd rational number
        cout << "Second fraction: ";
        y.print();
        cout << " or ";
        y.printf();
        cout << endl;

        //Addition
        x.print();
        cout << " + ";
        y.print();
        cout << " = ";
        z = x.add(y);
        z.print();
        cout << " or ";
        z.printf();
        cout << endl;

        //Substraction
        x.print();
        cout << " - ";
        y.print();
        cout << " = ";
        z = x - y;
        z.print();
        cout << " or ";
        z.printf();
        cout << endl;

        //Multiply
        x.print();
        cout << " * ";
        y.print();
        cout << " = ";
        z = x * y;
        z.print();
        cout << " or ";
        z.printf();
        cout << endl;

        //Division
        x.print();
        cout << " / ";
        y.print();
        cout << " = ";
        try {
            z = x / y;
            z.print();
            cout << " or ";
            z.printf();
            cout << endl;
        } catch (DividedByZeroException &dividedbyZeroException) {
            cout << endl;
            cout << "Division results in denominator of 0!" <<endl;
        }

        // Addition/Substraction
        cout << "(";
        x.print();
        cout << " + ";
        y.print();
        cout << ") / ";
        x.print();
        cout << " - ";
        y.print();
        cout << " = ";
        try {
            z = (x+y)/(x-y);
            z.print();
            cout << " or ";
            z.printf();
            cout << endl;
        } catch (DividedByZeroException &dividedbyZeroException) {
            cout << endl;
            cout << "Operation results in denominator of 0! " <<endl;
        }

        //Negate
        x.print();
        cout << " negated is ";
        z = - x;
        z.print();
        cout << " or ";
        z.printf();
        cout << endl;


        cout << "Would you like to enter the rational number again? (Y/N)"<<endl;
        cin >> answer;

    } while(answer != 'N');
    return 0;
}

