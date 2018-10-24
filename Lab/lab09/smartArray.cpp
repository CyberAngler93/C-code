#include "smartArray.hpp"
SmartArray::SmartArray(int userNumber){
    _p = new int [userNumber];
    for(int i = 0; i < userNumber; i++){
        *(_p+userNumber) = 0;
        _size = userNumber;
    }
}
SmartArray::~SmartArray(){
    delete _p;
}
void SmartArray::getArray(){
    for (int i = 0; i < _size; i++){
        std::cout << *(_p+i) << "   ";
    }
    std::cout << std::endl;
}

SmartArray & SmartArray::operator =(const SmartArray & rhs){
    if (this == &rhs){
        return *this;
    }
    else{
        this->_size = rhs._size;
        this->_p = new int[this->_size];
        for(int i = 0; i < _size; i++){
            *(this->_p+i)=*(rhs._p+i);
        }
        return *this;
    }
}

bool SmartArray::operator==(int userNumber){
    if(*_p == userNumber){
        return true;
    }else{
        return false;
    }

}
const int & SmartArray::operator []( int userNumber)const{
    if(userNumber < 0 || userNumber >= _size ){
        std::cout << "out of bounds!" << std::endl;
         exit(1);
    }
    else if(userNumber >= 0 && userNumber < _size)
    {
        return *(_p + userNumber);
    }
    else
    {

    }
}

int & SmartArray::operator[](int userNumber){
    if(userNumber < 0|| userNumber >= _size){
        std::cout << "out of bounds!" << std::endl;
        exit(1);
    }else if(userNumber >= 0 && userNumber < _size)
    {
        return *(_p + userNumber);
    }else
    {
        int *new_p=new int[userNumber+1];
			for(int i = 0; i < userNumber; i++)
				*(new_p+i) = 0;
			for(int ii = 0; ii < _size; ii++)
			{
				*(new_p + ii)=*(_p + ii);
			}
			_size = userNumber;
			delete[] _p;
			_p=new_p;
			return *(_p+userNumber);
    }
}
