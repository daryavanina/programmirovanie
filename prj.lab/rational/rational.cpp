#include "include/rational/rational.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>

int Rational::NOD(int x, int y){
    x = std::abs(x);
    y = std::abs(y);
    if (x == y || x == 0){
        return y;
    }
    if (x > y){
        return NOD(x-y, y);
    }
    return NOD(x, y-x);
}

Rational& Rational::round(){
    if (denum_ < 0){
        num_*=-1;
        denum_*=-1;
    }
    int nod = Rational::NOD(num_,denum_);
    num_ /= nod;
    denum_ /= nod;
    return *this;
}
bool Rational::operator==(const Rational& second) const{
    return (num_ == second.num_ && denum_ == second.denum_);
}

bool Rational::operator!=(const Rational& second) const{
    return !operator==(second);
}

Rational::Rational (const int num, const int denum) {
    if (denum == 0)
        throw std::invalid_argument("Creating Rational with 0 denum");
    num_ = num;
    denum_ = denum;
    this->round();
}
Rational::Rational(const int second)
{
    num_ = second;
    denum_ = 1;
    this->round();
}

Rational::Rational(const Rational& second)
{
    num_ = second.num_;
    denum_ = second.denum_;
    this->round();
}

bool Rational::operator>(const Rational& second) const{
    if(num_*second.num_ < 0){
        return num_ > 0;
    }
    return num_*second.denum_ > second.num_*denum_;
}

bool Rational::operator<(const Rational& second) const{
    if(num_*second.num_ < 0){
        return num_ < 0;
    }
    return num_*second.denum_ < second.num_*denum_;
}

Rational& Rational::operator+=(const Rational& second){
    int nod = NOD(denum_,second.denum_);
    num_ = (num_*second.denum_)/nod + second.num_*denum_/nod;
    denum_ = (denum_*second.denum_)/nod;
    this->round();
    return *this;
}

Rational& Rational::operator-=(const Rational& second){
    int nod = NOD(denum_,second.denum_);
    num_ = (num_*second.denum_)/nod - second.num_*denum_/nod;
    denum_ = (denum_*second.denum_)/nod;
    this->round();
    return *this;
}

Rational Rational::operator-() const noexcept{
    return Rational(-num_, denum_);
}

Rational& Rational::operator*= (const Rational& second){
    num_ *= second.num_;
    denum_ *= second.denum_;
    this->round();
    return *this;
}

Rational& Rational::operator/= (const Rational& second){
    denum_ *= second.num_;
    if (denum_ == 0 || second.denum_ == 0){
        throw std::invalid_argument("division by zero");
    }
    num_ *= second.denum_;
    this->round();
    return *this;
}

std::ostream& operator<< (std::ostream& ostrm, const Rational& second)
{
    return second.writeTo(ostrm);
}
std::istream& operator>> (std::istream& istrm, Rational& second)
{
    return second.readFrom(istrm);
}
std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << num_ << slash << denum_;
    return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm)
{
    int num1(0);
    char slash(0);
    int denum1(1);
    istrm >> num1;
    istrm.get(slash);
    int trash = istrm.peek();
    istrm >> denum1;
    if (!istrm || trash > '9' || trash < '0') {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    if (istrm.good() || istrm.eof()) {
        if (Rational::slash == slash && denum1 > 0) {
            *this = Rational(num1, denum1);
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
