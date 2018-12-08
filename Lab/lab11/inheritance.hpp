//Created by Matthew Perry
//Cs202 Lab11
//Prof James Long
//11/3/18
#ifndef INHERITANCE_HPP_INCLUDED
#define INHERITANCE_HPP_INCLUDED
#include <string>
// base class
class Base{
public:
    //Base(); no longer needed by =0 on Base(int)
    Base(int = 0 );
    ~Base();
private:
    int _baseNumber;
};
// Derived class taking in the public memebers of Base
class Derived : public Base{
public:
    //Decleration for using Base calls
    using Base::Base;
    //Derived(); no longer needed by = 0 on Derived allowing for a default if nothing is passed tobe 0 and ""
    Derived(int = 0 ,std::string = "");
    ~Derived();
private:
    std::string _derivedString;

};

#endif // INHERITANCE_HPP_INCLUDED
