//Matt Perry
//Cs202
//Lab13
//Prof Jim Long
#include <iostream>
#include <string>
//Template name as Copy Type
template<typename CPT>
//copything fucntion returning a Typename and taking a Typname by ref
CPT copyThing(CPT num){
  CPT t = num;
  return (num = t+num);
}
std::string copyThing (const char* num){
  std::string num1 = num;
  return (num1 = num1 + num1);
}
// use of copyThing
int main(){
  std::cout << copyThing(2) << "\n";
  std::cout << copyThing(2.3) << "\n";
  std::cout << copyThing("Hello") << "\n";
  std::cout << copyThing(4343434) << "\n";


  return 0;
}
