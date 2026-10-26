#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator)
{
    if (_numerator == 0 && _denominator == 0)
    {
        int num = 0, denom = 1;
        if (cin > num)
        {
            if (cin.peek() == '/')
            {
                char slash;
                cin >> slash >> denom;
                _numerator = num;
                _denominator = denom;
            }
            else
            {
                _numerator = num;
                if (cin > denom)
                {
                    _denominator = denom;
                }
            }
        }
    }
    else
    {
        _numerator = numerator;
        _denominator = denominator;
    }

    if (_denominator == 0)
    {
        _denominator = 1;
    }
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    Fraction result(this->_numerator * frac._denominator + this->_denominator * frac._numerator, this->_denominator * frac._denominator);
    result.simplify();
    return result;
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    Fraction result(this->_numerator * frac._denominator - this->_denominator * frac._numerator, this->_denominator * frac._denominator);
    result.simplify();
    return result;
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    Fraction result(this->_numerator * frac._numerator, this->_denominator * frac._denominator);
    result.simplify();
    return result;
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    Fraction result(this->_numerator * frac._denominator, this->_denominator * frac._numerator);
    result.simplify();
    return result;
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    frac.simplify();
    return frac;
}

void fractions::Fraction::simplify()
{
    int divisor = gcd(this->_numerator, this->_denominator);
    this->_numerator /= divisor;
    this->_denominator /= divisor;
}

int fractions::Fraction::gcd(int a, int b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    // make sure it isn't 0
    if (a == 0) return b;
    if (b == 0) return a;
    // get the min correctly
    int min_val = min(a, b);
    // set the greatest to 1
    int greatest = 1;
    // use a while loop and the min to be the one to be to
    int i = 1;
    while (i <= min_val)
    {
        if (a % i == 0 && b % i == 0)
        {
            greatest = i;
        }
        i++;
    }
    return greatest;
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    return (this->_numerator * frac._denominator == this->_denominator * frac._numerator);
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    os << frac._numerator << "/" << frac._denominator;
    return os;
}