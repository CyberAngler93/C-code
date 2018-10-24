//Created by Matt Perry
//Cs202 Fall 2018
//Brick Pointer Lab
//Prof James Long


#include <iostream>
#include <vector>
#include <memory>
#include "brick.hpp"

int main() {
    //Raw pointer to a default brick
    Brick *myPtr = new Brick();
    //unique ptr to a brick with 25 health
    auto myUniquePtr = std::make_unique<Brick>(25);
    //transfer ownership of unique pointers
    auto myUniquePtrTwo = std::move(myUniquePtr);
    //calling member function on the now in control pointer
  std::cout << "My unique Pointer is pointing to a brick with " << myUniquePtrTwo->getHealth()<< " health!" << std::endl;
  //shared pointer creation with brick health 7
  auto mySharedPtrOne = std::make_shared<Brick>(7);
  //second shared pointer pointing to the same object as the first
  auto mySharedPtrTwo = mySharedPtrOne;
  //proof of same object
  std::cout << "Shared Pointers pointing to the same brick " << mySharedPtrOne->getHealth() << " and " << mySharedPtrTwo->getHealth() << std::endl << "Both are the same!" << std::endl;

    // required to clear up memory
    delete myPtr;

    std::cout<< "Post deleting my raw pointer!" << std::endl;
    //only 3 calls of destructor as in the end only 3 bricks were created!
	return 0;
}
