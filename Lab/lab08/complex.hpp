//Matt Perry
//Lab08 Overloaded Operators on Complex Class
// Prof James Long
//10/3/18
//complex.hpp

#ifndef COMPLEX_HPP_INCLUDED
#define COMPLEX_HPP_INCLUDED

#include <iostream>

class Complex{
//friend functions
// overloaded << operator for printing to what ever ostream is passed.
friend std::ostream & operator <<(std::ostream & os, const Complex & c);
//friend overloaded + operator for adding two complex together
friend Complex operator +(Complex lhs, const Complex & rhs);
//friend overloaded + operator for adding an int to a complex number!
friend Complex operator +(int,Complex rhs);
public:
    //member function += overload taking one value as const ref
    Complex operator += (const Complex & rhs);
    //Constructor taking two doubles
    Complex(double _real , double _i);
    //Default Constructor
    Complex();
private:
    double _real;
    double _i;

};


#endif // COMPLEX_HPP_INCLUDED
