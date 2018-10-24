//Matt Perry
//Lab08 Overloaded Operators on Complex Class
// Prof James Long
//10/3/18
//Test Program

#include <iostream>
#include "complex.hpp"

int main(){
Complex a(2,3);
Complex b(4,5);
Complex d;

std::cout << a << " + " << b << " = ";
a+=b;
std::cout << a << std::endl;
d = b+a;
std::cout << b << " + " << a << " = " << d << std::endl;
std::cout << 5 + Complex(2,3)<< std::endl;
std::cout << -25 + Complex(1,5)<< std::endl;

return 0;
}



