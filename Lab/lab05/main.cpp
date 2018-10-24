//Created by Matt Perry
//Cs202 Fall 2018
//Namespace Lab
//Prof James Long


#include <iostream>
#include "names.hpp"
// woowee will only be changed by things in this file!
namespace{
    int woowee = 5;
}

int main(){
    //calls woowee
    std::cout << "Calling woowee from anonymous namespace " << woowee << std::endl;
    //calls foo which has a modification to woowee but will not do anything because of namespace
    foo();
    // calling woowee as proof
    std::cout <<"Calling woowee from anonymous namespace after foo() " << woowee << std::endl;
    // chaning woowee in file
    woowee ++;
    //printing again to show change
    std::cout << "Calling woowee from anonymous namespace after modifying values! " << woowee << std::endl;
    //calling namespace test::foo
    test::foo();
    // having 2 bars?!
    int bar = 55;
    // printing bar 1 and test::bar
    std::cout <<"This is bar: " << bar << " and this is test::bar:  " << test::bar << std::endl;
    // changing the value of bar
    test::bar = bar;
    //printing proof
    std::cout <<"the new value of test::bar is: " << test::bar << std::endl;


return 0;
}
