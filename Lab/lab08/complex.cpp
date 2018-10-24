//Matt Perry
//Lab08 Overloaded Operators on Complex Class
// Prof James Long
//10/3/18
//complex.cpp

#include "complex.hpp"
 std::ostream & operator <<(std::ostream & os, const Complex & c){
    return os << c._real << " + " << c._i << "i ";

 }
Complex operator +(int realNumber,Complex  rhs){
        //checks if the number given is a greater than zero to decided if its imaginary or not
        if(realNumber > 0){
               rhs._real += realNumber;
        }
        else{
            //sets our number back to positive to add it to the imaginary numbers!
            realNumber = realNumber *-1;
            rhs._i += realNumber;
        }
        //returns our object
       return rhs;
}
// basic add operator of two complex objects one as  const ref and the other as standard as it will be modified by using our += operator member function
Complex operator +(Complex lhs, const Complex & rhs){
    return lhs+=rhs;
 }
 //default complex 0,0
Complex::Complex(){
    _real = 0;
    _i = 0;

}
// This is our member function overload allowing for adding of objects with one as a const ref so it cant be modified. returns dereferenced pointer of the object
Complex Complex::operator+=(const Complex & rhs){
    this->_real += rhs._real;
    this->_i+= rhs._i;
    return *this;
}
//User defined values for complex object two doubles
Complex::Complex(double userReal, double userI){
    _real = userReal;
    _i = userI;
    std::cout << "Complex Number Created" << std::endl;
    std::cout << _real << " + " << _i  << "i" << std::endl;
}

