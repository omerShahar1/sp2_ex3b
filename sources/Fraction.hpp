#pragma once
#include <iostream>

namespace ariel
{
    class Fraction
    {
    private:
        int numerator, denominator;

    public:
        Fraction(int, int);
        Fraction(float);
        Fraction();

        int getNumerator() const;
        int getDenominator() const;
        void over_flow_check(char, int, int, int) const;
        
        Fraction operator+(const Fraction &temp) const;
        Fraction operator-(const Fraction &temp) const;
        Fraction operator*(const Fraction &temp) const;
        Fraction operator/(const Fraction &temp) const;
        bool operator>(const Fraction &temp) const;
        bool operator<(const Fraction &temp) const;
        bool operator>=(const Fraction &temp) const;
        bool operator<=(const Fraction &temp) const;
        Fraction &operator++();
        const Fraction operator++(int);
        Fraction &operator--();
        const Fraction operator--(int);

        friend bool operator==(const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator+(float, const Fraction &fruction);
        friend Fraction operator+(const Fraction &fruction, float);
        friend Fraction operator-(float, const Fraction &fruction);
        friend Fraction operator-(const Fraction &fruction, float);
        friend Fraction operator*(float, const Fraction &fruction);
        friend Fraction operator*(const Fraction &fruction, float);
        friend Fraction operator/(float, const Fraction &fruction);
        friend Fraction operator/(const Fraction &fruction, float);
        
        
        
        
        
        friend bool operator>(float, const Fraction &fruction);
        friend bool operator>(const Fraction &fruction, float);
        friend bool operator<(float, const Fraction &fruction);
        friend bool operator<(const Fraction &fruction, float);
        friend bool operator>=(float, const Fraction &fruction);
        friend bool operator>=(const Fraction &fruction, float);
        friend bool operator<=(float, const Fraction &fruction);
        friend bool operator<=(const Fraction &fruction, float);

        friend std::ostream &operator<<(std::ostream &output, const Fraction &fruction);
        friend std::istream &operator>>(std::istream &input, Fraction &fruction);
    };
}