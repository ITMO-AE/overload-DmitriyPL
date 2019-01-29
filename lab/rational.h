#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
public:

    Rational();
    Rational(int numerator, int denominator);
    int Numerator() const;
    int Denominator() const;

    bool       operator == ( const Rational &r )
    {
        return ( this->Numerator() == r.Numerator() && this->Denominator() == r.Denominator() );
    }
    Rational&  operator =  ( const Rational &r )
    {
        if (this != &r)
        {
            this->p = r.Numerator();
            this->q = r.Denominator();
        }

        return *this;
    }
    Rational   operator +  ( const Rational &r )
    {
        int pNew, qNew;

        if ( this->Denominator() != r.Denominator() )
        {
            pNew = this->Numerator() * r.Denominator() + r.Numerator() * this->Denominator();
            qNew = this->Denominator() * r.Denominator();
        } else {
            pNew = this->Numerator() + r.Numerator();
            qNew = this->Denominator();
        }

        Rational rNew(pNew, qNew);

        return rNew;
    }
    Rational   operator -  ( const Rational &r )
    {
        int pNew, qNew;

        if ( this->Denominator() != r.Denominator() )
        {
            pNew = this->Numerator() * r.Denominator() - r.Numerator() * this->Denominator();
            qNew = this->Denominator() * r.Denominator();
        } else {
            pNew = this->Numerator() - r.Numerator();
            qNew = this->Denominator();
        }

        Rational rNew(pNew, qNew);

        return rNew;
    }
    Rational   operator *  ( const Rational &r )
    {
        int pNew, qNew;

        pNew = this->Numerator() * r.Numerator();
        qNew = this->Denominator() * r.Denominator();

        Rational rNew(pNew, qNew);

        return rNew;
    }
    Rational   operator /  ( const Rational &r )
    {
        int pNew, qNew;

        pNew = this->Numerator() * r.Denominator();
        qNew = this->Denominator() * r.Numerator();

        Rational rNew(pNew, qNew);

        return rNew;
    }

    friend std::ostream& operator << ( std::ostream &os, Rational const &r );
    friend std::istream& operator >> ( std::istream &is, Rational &r );

private:

    int GreatestCommonDivisor (int p, int q);
    int p, q, gcd;
};

#endif // RATIONAL_H
