//Created by: Matthew Perry
// 9/12/2018
//box.cpp HW1 CS202
//Prof James Long
//Definitions of functions of class Box


#include "box.hpp"
void Box::print(std::ostream & os)const {
	//for loop for printing filled box
	if (_boxFilled == true) {
		for (auto i = 0; i < _boxHeight; i++) {
			for (auto ii = 0; ii < _boxWidth; ii++) {
				os << "x";
			}
			os << std::endl;
		}
	}
	//for loops for prining hollow box
	if (_boxFilled == false) {
		for (auto i = 0; i < _boxHeight; i++) {
			for (auto ii = 0; ii < _boxWidth; ii++) {
				if (i == 0 || i == _boxHeight - 1) {
					os << "x";
				}
				else {
					if (ii == 0 || ii == _boxWidth - 1) {
						os << "x";
					}
					else {
						os << " ";
					}
				}
			}
			os << std::endl;
		}
	}

}
//return type function testing bool
std::string Box::type()const {
	if (_boxFilled == true) {
		return "Filled";
	}
	else {
		return "Hollow";
	}
}
//definitions of get and set
int Box::getWidth()const {
	return _boxWidth;
}
int Box::getHeight()const {
	return _boxHeight;
}
void Box::setWidth(int userWidth) {
	_boxWidth = userWidth;
}
void Box::setHeight(int userHeight) {
	_boxHeight = userHeight;
}
//definitions of constructors
Box::Box() {
	_boxHeight = 1;
	_boxWidth = 1;
	_boxFilled = true;
}

Box::Box(int userWidth, int userHeight) {
	_boxHeight = userHeight;
	_boxWidth = userWidth;
	_boxFilled = true;
}
Box::Box(int userWidth, int userHeight, bool filled) {
	_boxHeight = userHeight;
	_boxWidth = userWidth;
	_boxFilled = filled;
}
Box::Box(const Box &oldBox) {
	_boxHeight = oldBox._boxHeight;
	_boxWidth = oldBox._boxWidth;
	_boxFilled = oldBox._boxFilled;
}
Box::~Box() {
}