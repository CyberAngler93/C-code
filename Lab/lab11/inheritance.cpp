//Created by Matthew Perry
//Cs202 Lab11
//Prof James Long
//11/3/18
#include "inheritance.hpp"
#include <iostream>
// Base constructor that doubles as a 0 defualt if no value is passes. 
Base::Base(int userNumber) : _baseNumber(userNumber){
    std::cout << "Constructing Base Object With Number: " << userNumber << "\n";
    _baseNumber = userNumber;
}
Base::~Base(){
    std::cout << "Destructing Base Object With Number: " << _baseNumber << "\n";
}
//Derived class with intializer list on string and base calls. 
// As well as defaults if nonthing is passed.
Derived::Derived(int userNumber, std::string userString) : Base(userNumber) , _derivedString(userString){
    std::cout << "Constructing Derived Object With String: " << userString << "\n";
}
Derived::~Derived(){
    std::cout << "Destructing Derived Object With String: " << _derivedString << "\n";
}
