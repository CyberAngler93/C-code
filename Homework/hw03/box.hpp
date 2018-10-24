//Matt Perry
//9/26/18
//box.hpp HW03 CS202
//Prof James Long

/*
Step 1:
    To add a new type of box to the loop we must start by defining the new state in our ENUM def.
    Then continue to the box.cpp file and add the new type to the string type()const; function to include your newly defined type.
Step 2:
    Move to the box.cpp file and we will be modifying the friend function of the print overloaded operator <<
    your final steps are in the box.cpp file!

*/

#ifndef BOX_HPP_INCLUDED
#define BOX_HPP_INCLUDED
#include <string> //needed for definition of string
#include <ostream> // needed for definition of ostream

// class definition of box!
class Box{
    //Our friend function to print out our boxes overloading << operator
    friend std::ostream & operator<<(std::ostream& os, const Box& userBox);
public:
   //enum state of Filled, Hollow or Checkered
    enum BoxState {FILLED,HOLLOW,CHECKERED};
    // type member passed as const returning string
    std::string type()const;
    // def constructor
    Box();
    //constructor with 2 args
    Box(int userWidth, int userHeight);
    //constructor with 3 args
    Box(int userWidth, int userHeight, BoxState userBoxState);
    //copy constructor
    Box(const Box &oldBox);
    //destructor
    ~Box();
    // set function for width
    void setWidth(int userWidth);
    // set function for height
    void setHeight(int userHeight);
    // get function for width as const so value cant be messed with
    int getWidth()const;
    // get funcith for height as const so value cant be messed with
    int getHeight()const;
    //  static int fuction for whole class returning our box count
    static int howMany();
private:
    //static int for class to keep track of box count
    static int boxCount;
    // ints to hold box width and height
    int _boxWidth;
    int _boxHeight;
    // a box state of ENUM
    BoxState _boxState;
};
#endif // BOX_HPP_INCLUDED

