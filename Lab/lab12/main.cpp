//Created by Matthew Perry
//Cs202 Lab11
//Prof James Long
//11/3/18
#include <iostream>
#include "inheritance.hpp"
#include <memory>

int main(){
  std::cout << "\n";
  std::cout << "This is a pointer of Base Object type pointing to Derived Object" << "\n";
  {
    std::unique_ptr<Base> p = std::make_unique<Derived>(444,"Matt");
    std::cout << "This is the Nonvirtual Function Thing and will always call the version matching type of pointer" << "\n";
    p->thing();
    std::cout << "This is the Virtual Function describe and will call the version matching the object type the pointer is pointing to" << "\n";
    p->describe();
  }
  std::cout << "\n";
  std::cout << "This is a pointer of Base Object type pointing to Base Object" << "\n";
  {
    std::unique_ptr<Base> p = std::make_unique<Base>(100);
    std::cout << "This is the Nonvirtual Function Thing and will always call the version matching type of pointer" << "\n";
    p->thing();
    std::cout << "This is the Virtual Function describe and will call the version matching the object type the pointer is pointing to" << "\n";
    p->describe();
  }
  std::cout << "\n";
  std::cout << "This is a pointer of Derived Object type pointing to Derived Object" << "\n";
  {
    std::unique_ptr<Derived> p = std::make_unique<Derived>(545,"moo");
    std::cout << "This is the Nonvirtual Function Thing and will always call the version matching type of pointer" << "\n";
    p->thing();
    std::cout << "This is the Virtual Function describe and will call the version matching the object type the pointer is pointing to" << "\n";
    p->describe();
  }
  std::cout << "\n";
  //Our two objects for testing morphing of objects
  Base b(55);
  Derived d(55,"matt");
  std::cout << "Now to show dynamic memory was occuring by showing with reference passing type of virtual does not change based on object passed to class" << "\n";
  std::cout << "\n";
  std::cout << "Base Object Reference to Base Object" << "\n";
  {
    Base a = b;
    a.thing();
    a.describe();
  }
  std::cout << "\n";
  std::cout << "Base Object Reference to Derived Object" << "\n";
  {
    Base a = d;
    a.thing();
    a.describe();
  }
  std::cout << "\n";
  std::cout << "Derived Object Reference to Derived Object" << "\n";
  {
    Derived a = d;
    a.thing();
    a.describe();
  }
  std::cout << "\n";

  return 0;
}
