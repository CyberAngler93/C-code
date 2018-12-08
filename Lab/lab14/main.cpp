//Matthew Perry
//CS202 Lab 14 Class Templates
// 11/12/18
//Prof long

#include <iostream>
#include <ostream>
template <typename ObjectType>
class Wrapper
{
friend std::ostream & operator<< (std::ostream& os, const Wrapper<ObjectType> & userObj){
     os << userObj._myPart ;
     return os;
}
public:
    Wrapper(ObjectType b){
            _myPart = b;
    }
private:
    ObjectType _myPart;
};

int main(){


Wrapper<int>w(555);
Wrapper<std::string>s("Hello World!");
std::cout << w << " " << s << std::endl;

return 0;

}
