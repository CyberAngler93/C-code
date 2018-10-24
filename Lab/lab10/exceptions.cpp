// Matt Perry
//CS202
// LAB10
//Exceptions
//Prof James Long
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void functionC()
{
    //one statement if you get this far throw an error
    throw std::runtime_error("Oh no we are all the way down at function C and its broken!");
}

void functionB()
{
    //trying a function that may throw an error so we set it up in try and catch block
    try{
    cout << "Starting functionB()" << endl;
    functionC();
    }
      catch (std::exception & e){
        cout << "Caught an exception: " << e.what() << endl;
    }
    // should call end ing function if error handled properly
    cout << "Ending functionB()" << endl;
}

void functionA()
{
    //trying a function that may throw an error so we set it up in try and catch block, so that if a error is caught we can continue
    try{
        functionB();
    }
    catch (std::exception & e){
        cout << "Caught an exception: " << e.what() << endl;
    }
}

int main()
{
  cout << "Starting main()" << endl;
  functionA();
  cout << "Ended normally." << endl;
  return 0;
}
