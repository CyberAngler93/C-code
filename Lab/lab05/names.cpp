//Created by Matt Perry
//Cs202 Fall 2018
//Namespace Lab
//Prof James Long


#include "names.hpp"
// deceleration of woowee
namespace
{
     int woowee;
}
//namespace foo definition
void test::foo(){
    std::cout << "Using test::foo() how cool!" << std::endl;
}
// standard foo definition
void foo(){
    // woowee change to 66;
   woowee = 66;
    std::cout << "This is normal foo()!" << std::endl;
}
int test::bar = 5;
