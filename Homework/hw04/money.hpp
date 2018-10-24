//Matt Perry
//HW 4
//Money obejects
//  Prof James Long
// all comments for what functions do in .cpp
#ifndef MONEY_HPP_INCLUDED
#define MONEY_HPP_INCLUDED
#include <ostream>
class Money{
    friend Money operator +(Money lhs, const Money & rhs);
    friend Money operator -(Money lhs, const Money & rhs);
    friend Money operator *(Money lhs, double rhs);
    friend Money operator *(const double & lhs, Money rhs);
    friend Money operator /(Money lhs, double rhs);
    friend std::ostream & operator <<(std::ostream & os, const Money & money);
public:
    bool operator ==(const Money & rhs)const;
    bool operator !=(const Money & rhs)const;
    bool operator <(const Money & rhs)const;
    bool operator >(const Money & rhs)const;
    bool operator <=(const Money & rhs)const;
    bool operator >=(const Money & rhs)const;
    Money operator +=(const Money & rhs);
    Money operator -=( const Money & rhs);
    Money operator *=(const double & rhs);
    Money operator /=(const double  & rhs);
    Money operator =(const Money & rhs);
    Money();
    Money(int userDollars, int userCents);
    Money(double userMoney);
    ~Money();
    void setMoney(double userMoney);
    double getMoney()const;
private:
    // decided into inlcude a sign to make managing the negatives easier.
    int _sign;
    int _dollars;
    int _cents;
};


#endif // MONEY_HPP_INCLUDED
