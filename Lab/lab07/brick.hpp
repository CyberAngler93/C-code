//Created by Matt Perry
//Cs202 Fall 2018
//Static Member lab
//Prof James Lon
#ifndef brick_HPP_
#define brick_HPP_

#include <ostream>
using std::ostream;

class Brick
{
    //friend function for overloading <<
    friend ostream & operator<<(ostream& os, Brick & obj );
public:
    //member function for overloading +
    int operator +(Brick & obj);
	int getHealth(); //get health function
	static int howMany(); // static function to return how many bricks we have made
	void setHealth(int health); //set health function
	Brick(); //default constructor
	Brick(int health); //constructor with health decided
	Brick(const Brick & obj); // copy constructor
	~Brick(); //destructor
private:
    static int brickCount; // the brick count class static var
	int _health; //var holding health
};
#endif /*Brick_HPP_*/
