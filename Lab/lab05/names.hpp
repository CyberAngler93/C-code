//Created by Matt Perry
//Cs202 Fall 2018
//Namespace Lab
//Prof James Long


#ifndef NAMES_HPP_INCLUDED
#define NAMES_HPP_INCLUDED
#include <iostream>
//namespace test deceleration
namespace test
{
    //extern bar to not define but say exsists
    extern int bar;
    // test::foo deceleration
    void foo();
}
//standard foo deceleration
void foo();

// deceleration of woowee in names.hpp to show no collision
namespace
{
    int wooowee = 5;
}


#endif // NAMES_HPP_INCLUDED
