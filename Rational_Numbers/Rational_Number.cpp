#include "Rational_Number.h"

// Constructor definition
Rational:: Rational(const IntType& numerator) : numerator(numerator) {
}

void Rational::fixSigns(){
    if(denom < 0){
        denom = -denom;
        numer = -numer;
    }
}
void Rational::reduce(){
    IntType  d = 1;
    if(denom != 0 && numer != 0)
        d = gcd(numer,denom);
    if(d > 1){
        numer /= d;
        denom /= d;
    }
}
const Rational & Rational::operator=(const Rational & rhs){
    if(this != &rhs){
        numer = rhs.numer;
        denom = rhs.denom;
    }
    return *this;
}

const Rational & Rational :: operator+=(const Rational & rhs){
    numer = numer * rhs.denom + rhs.numer *denom;
    denom = denom * rhs.denom;
    reduce();

    return *this;
}
Rational Rational::operator+(const Rational & rhs) const{
    Rational answer(*this);
    answer += rhs;
    return answer;
}
// comparing two objects of the same class
bool Rational::operator==(const Rational & rhs)const{
    return numer * rhs.denom == denom * rhs.numer;
}
int main(){
    Rational r(10);
    r.Display();
    return 0;
}