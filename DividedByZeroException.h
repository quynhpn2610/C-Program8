//
//  DividedByZeroException.h
//  Project 11
//  Created by Chi Hoang on 4/13/21.
//

#ifndef DividedByZeroException_h
#define DividedByZeroException_h

#include <stdexcept>
using namespace std;

class DividedByZeroException : public runtime_error
{
public:
    //constructor specifies default error message
    DividedByZeroException()
            : runtime_error("Attempted to divide by zero. ")
    {
    }
};

#endif /* DividedByZeroException_h */
