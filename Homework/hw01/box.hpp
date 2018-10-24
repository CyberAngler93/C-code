//Created by: Matthew Perry
//9/12/2018
//box.hpp HW#1 CS202
//Prof James Long
//Box class declerations


#ifndef BOX_HPP_INCLUDED
#define BOX_HPP_INCLUDED
#include <string>
#include <ostream>
using std::string;
using std::ostream;

class Box {
	
public:
	void print(ostream & os)const; //Print function passing as ref const
	string type()const; // returning type of box by string const.
	Box(); // default
	Box(int userWidth, int userHeight); // construct taking two parameters
	Box(int userWidth, int userHeight, bool filled); // constructor taking three parameters
	Box(const Box &oldBox); // copy constructors
	~Box(); // def destructor
	 // set functions
	void setWidth(int userWidth);
	void setHeight(int userHeight);
	// get functions
	int getWidth()const;
	int getHeight()const;
private:
	//private memebers of the function
	bool _boxFilled;
	int _boxWidth;
	int _boxHeight;

};
#endif // BOX_HPP_INCLUDED
