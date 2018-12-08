#include <iostream>
#include "inheritance.hpp"

int main(){
    {Base b;}
    std::cout << "\n";
    {Base b{333};}
    std::cout << "\n";
    {Derived d;}
    std::cout << "\n";
    {Derived d{4444,"Blah Blah"};}
    std::cout << "\n";
    Derived d{5555};
return 1;
}
