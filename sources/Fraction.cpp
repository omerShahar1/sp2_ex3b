#include "Fraction.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
using namespace ariel;
using namespace std;

Fraction::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("Fraction can't be divided by zero");
    }
    
    int gcd = abs(__gcd(numerator, denominator));
    if(denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
    this->numerator = numerator / gcd;
    this->denominator = denominator / gcd;
    
}

Fraction::Fraction(float num)
{
    int temp = (num * 1000);
    int gcd = __gcd(temp, 1000);
    this->numerator = temp / gcd;
    this->denominator = 1000 / gcd;
}

Fraction::Fraction()
{
    this->numerator = 1;
    this->denominator = 1;
}

int Fraction::getNumerator() const
{
    return this->numerator;
}

int Fraction::getDenominator() const
{
    return this->denominator;
}

void Fraction::over_flow_check(char temp, int num1, int num2, int num3) const
{
    if ((temp != '-' && num1 > 1 && num2 > 1 && (num3 <= num1 || num3 <= num2)))
    {
        throw overflow_error("Overflow error");
    }
    else if (temp == '+' && (num1 < -1 && num2 < -1 && (num3 >= num1 || num3 >= num2)))
    {
        throw overflow_error("Overflow error");
    }
    else if (temp == '-' && (num1 > 0 && num2 < 0 && (num3 <= max(num1, num2))))
    {
        throw overflow_error("Overflow error");
    }
}



Fraction Fraction::operator+(const Fraction &temp) const
{
    int new_numerator = (this->numerator * temp.denominator) + (temp.numerator * this->denominator);
    int new_denominator = this->denominator * temp.denominator;
    int gcd = __gcd(new_numerator, new_denominator);
    
    over_flow_check('+', numerator * temp.getDenominator(), temp.getNumerator() * denominator, new_numerator);
    
    return Fraction(new_numerator/gcd, new_denominator/gcd);
}

Fraction Fraction::operator-(const Fraction &temp) const
{
    int new_numerator = (this->numerator * temp.denominator) - (temp.numerator * this->denominator);
    int new_denominator = this->denominator * temp.denominator;
    int gcd = __gcd(new_numerator, new_denominator);
    
    over_flow_check('-', numerator * temp.getDenominator(), temp.getNumerator() * denominator, new_numerator);
    
    return Fraction(new_numerator/gcd, new_denominator/gcd);
}

Fraction Fraction::operator*(const Fraction &temp) const
{
    int new_numerator = this->numerator * temp.numerator;
    int new_denominator = this->denominator * temp.denominator;
    int gcd = __gcd(new_numerator, new_denominator);

    Fraction result(new_numerator / gcd, new_denominator / gcd);
    over_flow_check('*', numerator, temp.getNumerator(), new_numerator);
    over_flow_check('*', denominator, temp.getDenominator(), new_denominator);
    return result;
}

Fraction Fraction::operator/(const Fraction &temp) const
{
    if (temp.getNumerator() == 0)
    {
        throw runtime_error("Fraction can't be divided by zero");
    }
    Fraction result(temp.getDenominator(), temp.getNumerator());
    return *this * result;
}

bool Fraction::operator>(const Fraction &temp) const
{
    return ((temp.getNumerator()*1.0 / temp.getDenominator()) < (this->getNumerator()*1.0 / this->getDenominator()));
}

bool Fraction::operator<(const Fraction &temp) const
{
    return ((temp.getNumerator()*1.0 / temp.getDenominator()) > (this->getNumerator()*1.0 / this->getDenominator()));
}

bool Fraction::operator>=(const Fraction &temp) const
{
    return ((temp.getNumerator()*1.0 / temp.getDenominator()) <= (this->getNumerator()*1.0 / this->getDenominator()));
}

bool Fraction::operator<=(const Fraction &temp) const
{
    return ((temp.getNumerator()*1.0 / temp.getDenominator()) >= (this->getNumerator()*1.0 / this->getDenominator()));
}

Fraction &Fraction::operator++()
{
    this->numerator += this->denominator;
    return *this;
}

const Fraction Fraction::operator++(int flag)
{
    Fraction temp(*this);
    this->numerator += this->denominator;
    return temp;
}

Fraction &Fraction::operator--()
{
    this->numerator -= this->denominator;
    return *this;
}

const Fraction Fraction::operator--(int flag)
{
    Fraction temp(*this);
    this->numerator -= this->denominator;
    return temp;
}



bool ariel::operator>(float num, const Fraction &fruction)
{
    return (Fraction(num) > fruction);
}

bool ariel::operator>(const Fraction &fruction, float num)
{
    return (Fraction(num) < fruction);
}

bool ariel::operator<(float num, const Fraction &fruction)
{
    return (Fraction(num) < fruction);  
}

bool ariel::operator<(const Fraction &fruction, float num)
{
    return (Fraction(num) > fruction);
}

bool ariel::operator>=(float num, const Fraction &fruction)
{
    return (Fraction(num) >= fruction);
}

bool ariel::operator>=(const Fraction &fruction, float num)
{
    return (Fraction(num) <= fruction);
}

bool ariel::operator<=(float num, const Fraction &fruction)
{
    return (Fraction(num) <= fruction);
}

bool ariel::operator<=(const Fraction &fruction, float num)
{
    return (Fraction(num) >= fruction);
}

bool ariel::operator==(const Fraction &fruc1, const Fraction &fruc2)
{
    return ((fruc1.getNumerator()*1.0 / fruc1.getDenominator()) == (fruc2.getNumerator()*1.0 / fruc2.getDenominator()));
}

Fraction ariel::operator+(float num, const Fraction &fruction)
{
    return Fraction(Fraction(num) + fruction);
}

Fraction ariel::operator+(const Fraction &fruction, float num)
{
    return Fraction(Fraction(num) + fruction);
}

Fraction ariel::operator-(float num, const Fraction &fruction)
{
    return Fraction(Fraction(num) - fruction);
}

Fraction ariel::operator-(const Fraction &fruction, float num)
{
    return Fraction(fruction - Fraction(num));
}

Fraction ariel::operator*(float num, const Fraction &fruction)
{
    return Fraction(Fraction(num) * fruction);  
}

Fraction ariel::operator*(const Fraction &fruction, float num)
{
    return Fraction(Fraction(num) * fruction);  
}

Fraction ariel::operator/(float num, const Fraction &fruction)
{
    if (fruction.getNumerator() == 0)
    {
        throw runtime_error("Fraction can't be divided by zero");
    }
    return Fraction(Fraction(num) / fruction);
}

Fraction ariel::operator/(const Fraction &fruction, float num)
{
    if (num == 0)
    {
        throw runtime_error("Fraction can't be divided by zero");
    }
    return Fraction(fruction / Fraction(num));
}



ostream &ariel::operator<<(ostream &out, const Fraction &frac)
{
    out << frac.getNumerator() << "/" << frac.getDenominator();
    return out;
}

istream &ariel::operator>>(istream &in, Fraction &frac)
{
    int numerator = 0;
    int denominator = 1;
    int slash = '/';

    in >> numerator;
    in >> slash;
    if (slash == '/')
    {
        in >> denominator;
        if (in.fail() || denominator == 0)
        {
            // in was not a number
            throw runtime_error("The denominator you provide is not valid");
        }
        Fraction temp(numerator, denominator);
        frac.numerator = temp.getNumerator();
        frac.denominator = temp.getDenominator();
    }
    else
    {
        if (slash == 0)
        {
            throw runtime_error("The denominator you provide is not valid");
        }
        Fraction temp(numerator, slash);
        frac.numerator = temp.getNumerator();
        frac.denominator = temp.getDenominator();
    }
    return in;
}