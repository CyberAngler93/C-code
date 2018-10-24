#include "brick.hpp"
#include <iostream>
#ifndef brick_HPP_
#define brick_HPP_
Brick::Brick() {
	_health = 5;
	std::cout << "Brick was created with default health of 5" << std::endl;
}
Brick::Brick(int health) {
	_health = health;
	std::cout << "Brick was created with user defined health of " << health << std::endl;
}
Brick::Brick(const Brick & obj) {
	std::cout << "A copy of Brick has been made" << std::endl;
	_health = obj._health; //copy part
}
Brick::~Brick() {
	std::cout << "The Brick was destroyed!" << std::endl;
}
int Brick::getHealth() {
	return _health;
}
void Brick::setHealth(int health) {
	_health = health;
}

#endif /*Brick_HPP_*/