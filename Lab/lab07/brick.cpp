//Created by Matt Perry
//Cs202 Fall 2018
//Static Member lab
//Prof James Long

#include "brick.hpp"
#include <iostream>
//deceleration of brick count to 0;
int Brick::brickCount = 0;
// overloaded operator for <<
std::ostream & operator << (std::ostream & os, Brick & obj){
    return os << obj.getHealth() << std::endl;
}
// overloaded operator for +
int Brick::operator+(Brick & obj){
    // temp to hold the values
    int temp;
    temp = this->getHealth() + obj.getHealth();
return temp;
}
//def constructor with base health of 5
Brick::Brick() {
	_health = 5;
	brickCount ++;
	std::cout << "Brick was created with default health of 5" << std::endl;
}
//constructor taking an int to set health as
Brick::Brick(int health) {
    brickCount ++;
	_health = health;
	std::cout << "Brick was created with user defined health of " << health << std::endl;
}
//copy constructor passed as const ref
Brick::Brick(const Brick & obj) {
    brickCount ++;
	std::cout << "A copy of Brick has been made" << std::endl;
	_health = obj._health; //copy part
}
//def destructor with box count going down.
Brick::~Brick() {
    brickCount --;
	std::cout << "The Brick was destroyed!" << std::endl;
}
//basic get function for health
int Brick::getHealth() {
	return _health;
}
//basic set function for health
void Brick::setHealth(int health) {
	_health = health;
}
//our static member function that returns our brick count
int Brick::howMany(){
    return brickCount;
}
