//Matt Perry
//9/26/18
//box.cpp HW03 CS202
//Prof James Long
//For Directions on how to add a new type please see box.hpp
#include "box.hpp"
// type member function checking for objects _boxState to our predetermined ENUM types then returning the string
std::string Box::type()const{
    if(_boxState == FILLED){
        return std::string("Filled");
    }
    if(_boxState == HOLLOW){
        return std::string("Hollow");
    }
    if(_boxState == CHECKERED){
        return std::string("Checkered");
    }
    //error handle if type passed was undefined
    return std::string("Error");
}
/*
Step 2 cont:
    Here is the function we need to add our new print condition too for the newly added ENUM type
    add a new If statement to check after our print function is called
    after complete you have added your new box type to the class.
*/
//our friend function for overloading << to allow print to go to anything
std::ostream & operator<<(std::ostream& os, const Box & userBox){
    //checking for Filledstate
    if(userBox._boxState == Box::FILLED){
            //for loop for height
        for(auto i = 0; i < userBox._boxHeight; i++){
            //nested into for loop for width
            //simple filled just prints all
            for(auto ii = 0; ii < userBox._boxWidth; ii++){
                os << "x";
            }
           //new line before continue loop
            os << std::endl;
        }
    }
    //checks for type hollow
    if(userBox._boxState == Box::HOLLOW){
            //for loop for height
        for(auto i = 0; i < userBox._boxHeight; i++){
            //nested into for loop for width
            for(auto ii = 0; ii < userBox._boxWidth; ii++){
                //condtional statement to test for first and last column
                if(i == 0 || i == userBox._boxHeight-1){
                        os << "x";
                }
                else{
                    //conditional to check for first and last row
                    if(ii == 0 || ii == userBox._boxWidth-1){
                        os << "x";
                    }
                    else{
                            //prints the space if fails previous tests
                        os << " ";
                    }
                }
            }
             //new line before continue loop
            os << std::endl;
        }
    }
    //checking for checkered state
    if(userBox._boxState == Box::CHECKERED){
            //for loop for height
        for(auto i = 0; i < userBox._boxHeight; i++){
            //nested into a loop for width
            for(auto ii = 0; ii < userBox._boxWidth; ii++){
                // takes the count for height and width and mod by 2 to check for even or odd then prints either the x for even " " for odd.
                os << ((i+ii) % 2 == 0 ? "x" : " ");
            }
            //new line before continue loop
            os << std::endl;
        }
    }
    return os;
}
// returning int from getWidth function as const to prevent funny business
int Box::getWidth()const{
    return _boxWidth;
}
//returning int from getHeight function as const to prevent funny business
int Box::getHeight()const{
    return _boxHeight;
}
//setWidth function taking one int as arg to change width of box
void Box::setWidth(int userWidth){
    _boxWidth = userWidth;
}
//setHeight function taking one int as arg to change height of box
void Box::setHeight(int userHeight){
    _boxHeight = userHeight;
}
//decleration of our static member boxCount to zero
int Box::boxCount = 0;
//our static class function returning an int for boxCount
int Box::howMany(){
    return boxCount;
}
//default constructor 1 by 1 FILLED
Box::Box(){
    boxCount ++;
    _boxHeight = 1;
    _boxWidth = 1;
    _boxState = FILLED;
}
//2 arg constructor with 2 uer values and set state to FILLED
Box::Box(int userWidth, int userHeight){
    boxCount ++;
    _boxHeight = userHeight;
    _boxWidth = userWidth;
    _boxState = FILLED;
}
//3 arg constructor with 3 user values width,height,and state
Box::Box(int userWidth, int userHeight, Box::BoxState userBoxState){
    boxCount ++;
    _boxHeight = userHeight;
    _boxWidth = userWidth;
    _boxState = userBoxState;
}
// copy constrcutor taking a const ref to box object and copying all states to a new box
Box::Box(const Box &oldBox){
    _boxHeight = oldBox._boxHeight;
    _boxWidth = oldBox._boxWidth;
    _boxState = oldBox._boxState;
    boxCount ++;
}
//destructor bye bye boxes
Box::~Box(){
    boxCount --;
}

