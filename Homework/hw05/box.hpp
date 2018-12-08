//Created by Matthew Perry
//Cs202 HW05
//Prof James Long
//11/10/18
//box.hpp

#ifndef BOX_HPP_INCLUDED
#define BOX_HPP_INCLUDED
#include <string>
#include <ostream>
#include <memory>

//Abstract Class with virtual functions
//////////////////////////////////////////////////////
class Box {
    //friend function for overloading <<
    friend std::ostream & operator<<(std::ostream& os, const Box & b);
public:
    //two pure virtual functions for print and return type
    virtual void print(std::ostream &os) const =0;
    virtual std::string type()const =0;

    //Base Constructors
    Box();
    Box(int userWidth, int userHeight);
    //Pure Virtual Destructor
    virtual ~Box() =0;
    //accessors and mutators for our classes
    void setWidth(int userWidth);
    void setHeight(int userHeight);
    int getWidth()const;
    int getHeight()const;
private:
    int _boxWidth;
    int _boxHeight;
};
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//FilledBox Definition of constructors, destructors , print and return type
class FilledBox : public Box{
public:
     void print(std::ostream & os) const override;
     std::string type()const override;
    FilledBox();
    FilledBox(int userWidth, int userHeight);
    ~FilledBox();
};
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//HollowBox Definition of constructors, destructors , print and return type
class HollowBox : public Box{
public:
     void print(std::ostream & os)const override;
     std::string type() const override;
    HollowBox();
    HollowBox(int userWidth, int userHeight);
    ~HollowBox();
};
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//CheckeredBox Definition of constructors, destructors , print and return type
class CheckeredBox : public Box{
public:
     void print(std::ostream & os)const override;
     std::string type()const override;
    CheckeredBox();
    CheckeredBox(int userWidth, int userHeight);
    ~CheckeredBox();
};
//////////////////////////////////////////////////////

//Factory Definition
std::unique_ptr<Box> boxFactory(char c, int w, int h);

#endif // BOX_HPP_INCLUDED
