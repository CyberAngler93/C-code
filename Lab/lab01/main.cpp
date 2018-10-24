//Created by Matt Perry
//Cs202 Fall 2018
//Brick Main
//Prof James Long


#include <iostream>
#include <vector>
#include "brick.hpp"
 Brick passByValue(Brick obj) {
	 std::cout << "Brick has a health of " << obj.getHealth() << std::endl;
	 std::cout << "Passing objects by value and then returning them by value" << std::endl;
	 return obj;
}
 void passByReference(Brick & obj) {
	 std::cout << "Brick has been passed by reference so we can change health of both!" << std::endl;
	 obj.setHealth(7);
 }
 void passByConstReference(const Brick & obj) {
	 std::cout << "Our Brick has been passed by const reference and is now safe from changes!" << std::endl;

 }
int main() {
	Brick b;
	b.setHealth(10);
	Brick a(b);
	Brick c(4);
	Brick d(11);
	Brick e(44);
	std::cout << "Brick b has a health of " << b.getHealth() << std::endl;
	std::cout << "Brick a has a health of " << a.getHealth() << std::endl;
	a.setHealth(2);
	std::cout << "Brick a has a health of " << a.getHealth() << std::endl;
	std::vector<Brick> myVector;
	myVector.push_back(a);
	myVector.push_back(b);
	myVector.push_back(c);
	myVector.push_back(d);
	myVector.push_back(e);
	std::cout << "Passing our brick by value " << b.getHealth() << std::endl;
	passByValue(b);
	std::cout << "Brick c has " << c.getHealth() << " health" << std::endl;
	passByReference(c);
	std::cout << "Brick c has " << c.getHealth() << " health" << std::endl;
	passByConstReference(d);


	return 0;
}