//Created by Matt Perry
//Cs202 Fall 2018
//Static Member lab
//Prof James Lon

#include <iostream>
#include "brick.hpp"

static int X = 55;
void numberThing(int number){
    //with a static int we can change its value here without a return
    std::cout << "X is currently: " << (X+=X) << '\n';
}

int main(){
// X is 55
std::cout << "X is currently: " << X << '\n';
numberThing(X);
//X retained the value of 110 from numberThing function
std::cout << "X is currently: " << X << '\n';
Brick a(5);
Brick b(10);
Brick c;
//calling our brick count
std::cout << "There are " << Brick::howMany() << " Bricks currently" <<  '\n';
return 0;
}
