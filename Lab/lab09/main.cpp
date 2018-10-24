#include <iostream>
#include "smartArray.hpp"

int main(){
    SmartArray a(8);
    SmartArray b(6);
    const SmartArray aa(10);
    b.getArray();
    a.getArray();
    a[1] = 6;
    b[3] = 6;
    b.getArray();
    a.getArray();
    if(a[1] == b[3]){
        std::cout << "True \n" ;
    }
    else
    {
        std::cout << "False \n" ;
    }
SmartArray c = aa;
c.getArray();
c[1] = 10;
c.getArray();
std::cout << a[1] << "\n";
std::cout << aa[10] << "\n";
std::cout << aa[8] << "\n";

return 0;
}
