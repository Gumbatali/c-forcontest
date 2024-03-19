#include <iostream>
#include <numeric>

class Rational
{
public:
    Rational(int numerator = 0, int denominator = 1)
    {
        if (denominator == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        int gcd = std::gcd(numerator, denominator);
        this->numerator_ = numerator / gcd;
        this->denominator_ = denominator / gcd;
        if (this->denominator_ < 0)
        {
            this->numerator_ = -this->numerator_;
            this->denominator_ = -this->denominator_;
        }
    }

    Rational& operator+=(const Rational& rhs)
    {
        int num = numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_;
        int denom = denominator_ * rhs.denominator_;
        *this = Rational(num, denom);
        return *this;
    }

    Rational& operator-=(const Rational& rhs)
    {
        int num = numerator_ * rhs.denominator_ - rhs.numerator_ * denominator_;
        int denom = denominator_ * rhs.denominator_;
        *this = Rational(num, denom);
        return *this;
    }

    Rational& operator*=(const Rational& rhs)
    {
        int num = numerator_ * rhs.numerator_;
        int denom = denominator_ * rhs.denominator_;
        *this = Rational(num, denom);
        return *this;
    }

    Rational& operator/=(const Rational& rhs)
    {
        if (rhs.numerator_ == 0)
        {
            throw std::invalid_argument("Division by zero");
        }
        int num = numerator_ * rhs.denominator_;
        int denom = denominator_ * rhs.numerator_;
        *this = Rational(num, denom);
        return *this;
    }

    Rational operator+() const
    {
        return *this;
    }

    Rational operator-() const
    {
        return Rational(-numerator_, denominator_);
    }

    bool operator==(const Rational& rhs) const
    {
        return numerator_ == rhs.numerator_ && denominator_ == rhs.denominator_;
    }

    bool operator!=(const Rational& rhs) const
    {
        return !(*this == rhs);
    }

    Rational& operator++()
    {
        numerator_ += denominator_;
        return *this;
    }

    Rational operator++(int)
    {
        Rational temp = *this;
        ++(*this);
        return temp;
    }

    Rational& operator--()
    {
        numerator_ -= denominator_;
        return *this;
    }

    Rational operator--(int)
    {
        Rational temp = *this;
        --(*this);
        return temp;
    }

    int numerator() const
    {
        return numerator_;
    }

    int denominator() const
    {
        return denominator_;
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs) += rhs;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs) -= rhs;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs) *= rhs;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs) /= rhs;
}
