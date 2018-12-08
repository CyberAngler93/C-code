//Created by Matthew Perry
//Cs202 HW05
//Prof James Long
//11/10/18
//box.cpp
#include "box.hpp"

//////////////////////////////////////////////////////
//Base Abstract Class
//friend function for printing and passing ostream
std::ostream & operator<<(std::ostream& os, const Box & b){
    b.print(os);
    return os;
}
//get functions
int Box::getWidth()const{
    return _boxWidth;
}
int Box::getHeight()const{
    return _boxHeight;
}
//set functions
void Box::setWidth(int userWidth){
    _boxWidth = userWidth;
}
void Box::setHeight(int userHeight){
    _boxHeight = userHeight;
}
//base constructor
Box::Box(){
    _boxHeight = 1;
    _boxWidth = 1;
}
//base constructor
Box::Box(int userWidth, int userHeight){
    _boxHeight = userHeight;
    _boxWidth = userWidth;
}
//base destructor
Box::~Box(){
}
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//Definitions of FilledBox using initializer list
FilledBox::FilledBox() : Box(){
}
FilledBox::FilledBox(int userWidth, int userHeight) : Box(userWidth, userHeight){
}
std::string FilledBox::type()const{
    return "Filled";
}
void FilledBox::print(std::ostream & os)const{
    for(auto i = 0; i < Box::getHeight(); i++){
        for(auto ii = 0; ii < Box::getWidth(); ii++){
            os << "x";
        }
        os << std::endl;
    }
}
FilledBox::~FilledBox(){
}
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//Definitions of HollowBox using initializer list
HollowBox::HollowBox() : Box(){
}
HollowBox::HollowBox(int userWidth, int userHeight) : Box(userWidth, userHeight){
}
std::string HollowBox::type()const{
    return "Hollow";
}
void HollowBox::print(std::ostream & os)const{
    for(auto i = 0; i < Box::getHeight(); i++){
        for(auto ii = 0; ii < Box::getWidth(); ii++){
            if(i == 0 || i == Box::getHeight()-1){
                os << "x";
            }
            else{
                if(ii == 0 || ii == Box::getWidth()-1){
                    os << "x";
                }
                else{
                    os << " ";
                }
            }
        }
        os << std::endl;
    }
}
HollowBox::~HollowBox(){
}
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
// Definitions of CheckeredBox using initializer list
CheckeredBox::CheckeredBox() : Box(){
}
CheckeredBox::CheckeredBox(int userWidth, int userHeight) : Box(userWidth, userHeight){
}
std::string CheckeredBox::type()const{
    return "Checkered";
}
void CheckeredBox::print(std::ostream & os)const{
    for(auto i = 0; i < Box::getHeight(); i++){
        for(auto ii = 0; ii < Box::getWidth(); ii++){
            os << ((i+ii) % 2 == 0 ? "x" : " ");
        }
        os << std::endl;
    }
}
CheckeredBox::~CheckeredBox(){
}
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//factory function for making lots of boxes
std::unique_ptr<Box> boxFactory(char c, int w, int h){
    if(c == 'f'){
        std::unique_ptr<Box> b = std::make_unique<FilledBox>(w,h);
         return b;
    }
    if(c=='c'){
        std::unique_ptr<Box> b =  std::make_unique<CheckeredBox>(w,h);
         return b;
    }
    if(c=='h'){
         std::unique_ptr<Box> b =  std::make_unique<HollowBox>(w,h);
         return b;
    }
    return 0;
}
//////////////////////////////////////////////////////
