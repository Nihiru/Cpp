#include <iostream>
typedef long IntType;
// struct Rationals_DataType{
//     int numerator;
//     int denominator;
// };
class Rational{
    private: 
        IntType numer;
        IntType denom;
        
        void fixSigns();
        void reduce();

    public:
        // constructor with default parameters
        // order non-dependent
        Rational(const IntType& numerator  = 0)
        :numer(numerator), denom(1) {};
        // parameterized constructors
        Rational(const IntType& numerator, const IntType& denominator)
        : numer(numerator), denom(denominator){
            fixSigns(); reduce();
        }
        // copy constructor
        Rational(const Rational& rhs)
        : numer(rhs.numer), denom(rhs.denom){}
        // destructor
        ~Rational(){}

        // Assignment operators (operator overloading)
        const Rational &operator=(const Rational &rhs);
        const Rational &operator+=(const Rational &rhs);
        const Rational &operator-=(const Rational &rhs);
        const Rational &operator*=(const Rational &rhs);
        const Rational &operator/=(const Rational &rhs);

        // Match Binary Ops
        Rational operator+(const Rational &rhs) const;
        Rational operator-(const Rational &rhs) const;
        Rational operator*(const Rational &rhs) const;
        Rational operator/(const Rational &rhs) const;

        // Relational & Equality Ops
        bool operator< (const Rational &rhs) const;
        bool operator> (const Rational &rhs) const;
        bool operator<=(const Rational &rhs) const;
        bool operator>=(const Rational &rhs) const;
        bool operator==(const Rational &rhs) const;
        bool operator!=(const Rational &rhs) const;

        // Unary operators
        const Rational & operator++();  //Prefix
        Rational operator++(int);       //Postfix
        const Rational & operator--();  //Prefix
        Rational operator--(int);       //Prefix
        const Rational & operator+() const;
        Rational operator-() const;
        bool operator!() const;

        // Member functions
        double toDouble() const{
            return static_cast<double> (numer) / denom;
        }

        // I/O operations
        friend ostream & operator<<(ostream & out, const Rational &value);
        friend istream & operator>>(isream & in, Rational & value);


};

