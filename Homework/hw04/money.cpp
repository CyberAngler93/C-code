//Matt Perry
//HW 4
//Money obejects
//  Prof James Long
#include "money.hpp"
#include <iostream>
//print for money objects
std::ostream & operator <<(std::ostream & os, const Money & money){
//+ operator for money objects lhs is the morphing side
    double myMoney = money.getMoney();
    if(myMoney ==0){
        return os << "$0.00";
    }
    if (money._sign ==1){
        return os << "-$" << myMoney;
    }
    return os << "$" << myMoney;

}
Money operator +(Money lhs, const Money & rhs){
//- operator for money objects lhs is the morphing side
    lhs._dollars += rhs._dollars;
    lhs._cents += rhs._cents;
    return lhs;
}
Money operator -(Money lhs, const Money & rhs){
//* operator for a const double and money object
    lhs._dollars -= rhs._dollars;
    lhs._cents -= rhs._cents;
    return lhs;
}
Money operator *(const double & lhs, Money  rhs){
// * operator for a money and a double
    rhs._cents *= lhs;
    rhs._dollars *=lhs;
    return rhs;
}
Money operator *(Money lhs, double rhs){
// / operator for a money and double
    lhs._cents *= rhs;
    lhs._dollars*=rhs;
    return lhs;
}
Money operator /(Money lhs, double rhs){
// start of bool operators passing const reference objects
// nothing fancy in bool objects just checking both from a cent to dollar and dollar to cent method. so we do not get a false true or false.
    lhs._cents /= rhs;
    lhs._dollars /=rhs;
    return lhs;
}
bool Money::operator ==(const Money & rhs)const{
    if(this->_cents == rhs._cents){
        if(this->_dollars == rhs._dollars){
            return true;
        }
    }
    if(this->_dollars == rhs._dollars){
        if(this->_cents == rhs._cents){
            return true;
        }
    }
    return false;
}
bool Money::operator !=(const Money & rhs)const{
    if(this->_cents == rhs._cents){
        if(this->_dollars == rhs._dollars){
            return false;
        }
    }
    if(this->_dollars == rhs._dollars){
        if(this->_cents == rhs._cents){
            return false;
        }
    }
    return true;
}
bool Money::operator <(const Money & rhs)const{
    if (*this == 0 && rhs != 0){
        return true;
    }
    if(this->_dollars < rhs._dollars){
        if(this->_cents < rhs._cents){
            return true;
        }
    }
    if(this->_cents < rhs._cents){
        if(this->_dollars < rhs._dollars){
            return true;
        }
    }
    return false;

}
bool Money::operator >(const Money & rhs)const{
       if (*this == 0 && rhs != 0){
        return false;
    }
    if(this->_cents > rhs._cents){
        if(this->_dollars > rhs._dollars){
            return true;
        }
    }
    if(this->_dollars > rhs._dollars){
        if(this->_cents > rhs._cents){
            return true;
        }
        return true;
    }
    return false;
}
bool Money::operator <=(const Money & rhs)const{
    if(this->_cents <= rhs._cents){
        if(this->_dollars <= rhs._dollars){
            return true;
        }
    }
    if(this->_dollars <= rhs._dollars){
        if(this->_cents <= rhs._cents){
            return true;
        }
    }
    return false;
}
bool Money::operator >=(const Money & rhs)const{

// operators for += , -=, *= and /= all taking a pointer to our object and one passing in
// all utilize the use of a system to correct cents and dollars after doing math
// possibly could move to a seperate function call.
    if(this->_cents >= rhs._cents){
        if(this->_dollars >= rhs._dollars){
            return true;
        }
    }
    if(this->_dollars >= rhs._dollars){
        if(this->_cents >= rhs._cents){
            return true;
        }
    }
    return false;
}
Money Money::operator +=(const Money & rhs){
    this->_dollars +=rhs._dollars;
    this->_cents += rhs._cents;
    while(this->_cents >= 100){
        this->_dollars++;
        this->_cents -=100;
    }
    return *this;
}
Money Money::operator -=(const Money & rhs){
    this->_dollars -=rhs._dollars;
    this->_cents -= rhs._cents;
    while(this->_cents < 0){
        this->_dollars--;
        this->_cents +=100;
    }
    return *this;
}
Money Money::operator *=(const double & rhs){
    this->_dollars *=rhs;
    this->_cents *= rhs;
    while(this->_cents < 0){
        this->_dollars--;
        this->_cents +=100;
    }
    while(this->_cents >= 100){
        this->_dollars++;
        this->_cents -=100;
    }
    return *this;
}
Money Money::operator /=(const double  & rhs){
// constuctors of our money objects
    this->_dollars /=rhs;
    this->_cents /= rhs;
    while(this->_cents < 0){
        this->_dollars--;
        this->_cents +=100;
    }
    while(this->_cents >= 100){
        this->_dollars++;
        this->_cents -=100;
    }
    return *this;
}
Money::Money(){
    _sign = 0;
    _cents = 0;
    _dollars = 0;
}
Money::Money(int userDollars , int userCents){
// for double we do some type casting to trim the numbers. type casting the double to an int strips the decimal, then we sub the int form the double then multiply by 100 and strip the dec again. then check for rounding.
    if(userDollars < 0){
        _sign = 1;
        userDollars *= -1;
    }
    _cents = userCents;
    _dollars = userDollars;
}
Money::Money(double userMoney){
    int sign = 0;
    if(userMoney < 0 ){
        sign = 1;
        userMoney = userMoney * -1;
    }
    //type cast the double to an int to cut the decimal
    int userDollars = int(userMoney);
    // sub the int from the double to get only cents in the double form multiply by 10 to get the first 2 out of double.
    double temp = (userMoney - userDollars)*100;
    //type cast the double to an int to cut the decimal.
    int userCents = int(temp);
    //checking for proper rounding.
    if((temp - userCents) >= .5){
        userCents++;
    }
    if(sign == 1){
        _sign = 1;
    }
    _cents = userCents;
    _dollars = userDollars;
}
void Money::setMoney(double userMoney){
// get funciton uses our typecast in reverse to make a single double representing money.
    int sign = 0;
    if(userMoney < 0 ){
        sign = 1;
        userMoney = userMoney * -1;
    }
    //type cast the double to an int to cut the decimal
    int userDollars = int(userMoney);
    std::cout << userDollars << std::endl;
    // sub the int from the double to get only cents in the double form multiply by 10 to get the first 2 out of double.
    double temp = (userMoney - userDollars)*100;
    //type cast the double to an int to cut the decimal.
    int userCents = int(temp);
    //checking for proper rounding.
    if((temp - userCents) >= .5 ){
        userCents++;
    }
    if(userCents == 0){
        userCents = .00;
    }
    if(sign == 1){
        _sign = 1;
    }
    _cents = userCents;
    _dollars = userDollars;
}
double Money::getMoney()const{
    double userCents = _cents;
    double userDollars = _dollars;
    userCents = userCents/100;
    if(userCents == 0){
        userCents = .00;
    }
    std::cout << (userDollars + userCents) << std::endl;
    return (userDollars + userCents);
}
Money::~Money(){
// copy operator
}
Money Money::operator =(const Money & rhs){
    this->_cents = this->_cents + rhs._cents;
    this ->_dollars = this->_dollars + rhs._dollars;
    return *this;
}
