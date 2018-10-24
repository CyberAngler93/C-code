#ifndef SMARTARRAY_HPP_INCLUDED
#define SMARTARRAY_HPP_INCLUDED
#include <iostream>
class SmartArray {

public:
    SmartArray & operator =(const SmartArray &);
    bool operator ==(int);
    int & operator [] (int);
    const int & operator [](int) const;
    SmartArray(int);
    ~SmartArray();
    void getArray();
private:
    int* _p;
    int _size;


};


#endif // SMARTARRAY_HPP_INCLUDED
