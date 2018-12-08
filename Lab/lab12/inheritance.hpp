//Created by Matthew Perry
//Cs202 Lab12
//Prof James Long
//11/4/18
#ifndef INHERITANCE_HPP_INCLUDED
#define INHERITANCE_HPP_INCLUDED
#include <string>
// base class
class Base{
public:
    //Base(); no longer needed by =0 on Base(int)
    Base(int = 0 );
    virtual ~Base();
    //virtual describe function for poloymorphic properties 
    virtual void describe();
    //standard memeber function for calling a version
    void thing();
    int getNumber();
private:
    int _baseNumber;
};
// Derived class taking in the public memebers of Base
class Derived : public Base{
public:
    //Decleration for using Base calls
    //using Base::Base;
    //Derived(); no longer needed by = 0 on Derived allowing for a default if nothing is passed tobe 0 and ""
    Derived(int = 0 ,std::string = "");
    void describe() override;
    void thing();
    ~Derived();
private:
    std::string _derivedString;

};

#endif // INHERITANCE_HPP_INCLUDED
