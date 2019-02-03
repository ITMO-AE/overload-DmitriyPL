#include "rational.h"
#include <assert.h>
#include <algorithm>
#include <iostream>

Rational::Rational():
    p(0), q(1), gcd(1) {}

Rational::Rational(int numerator, int denominator):
    p(numerator), q(denominator)
{
    assert( q != 0  );

    if ( p == 0 ) q = 1;
    if ( (p > 0 && q < 0) || (p < 0 && q < 0) ) { p *= -1; q *= -1; }

    gcd = GreatestCommonDivisor( abs(p), abs(q) );
}

int Rational::Numerator() const
{
    return ( this->p / this->gcd );
}

int Rational::Denominator() const
{
    return ( this->q / this->gcd );
}

int Rational::GreatestCommonDivisor(int p, int q)
{
    if (p == 0)
        return 1;

    if (p == q)
        return p;

    if (p > q)
        std::swap( p , q );

    return GreatestCommonDivisor(p, q - p);
}

std::ostream& operator<< ( std::ostream &os, Rational const &r )
{
    os << r.Numerator() << "/" << r.Denominator();
    return os;
}

std::istream& operator>> ( std::istream &is, Rational &r )
{
    if( is.rdbuf() -> in_avail() )
    {
        int p, q;
        char ch;

        is >> p>>ch>>q;
        r = Rational(p, q);
    }

    return is;
}
