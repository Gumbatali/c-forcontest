#include <iostream>

#include <cmath>

#include <complex.h>

class Complex
{
public:
    Complex(double re = 0.0, double im = 0.0) : re_(re), im_(im) {}

    double Re() const { return re_; }
    double Im() const { return im_; }

    Complex operator+() const { return *this; }
    Complex operator-() const { return Complex(-re_, -im_); }

    Complex operator+(const Complex& other) const
    {
        return Complex(re_ + other.re_, im_ + other.im_);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(re_ - other.re_, im_ - other.im_);
    }

    Complex operator*(const Complex& other) const
    {
        return Complex(re_ * other.re_ - im_ * other.im_, re_ * other.im_ + im_ * other.re_);
    }

    Complex operator/(const Complex& other) const
    {
        double denominator = other.re_ * other.re_ + other.im_ * other.im_;
        return Complex((re_ * other.re_ + im_ * other.im_) / denominator,
                       (im_ * other.re_ - re_ * other.im_) / denominator);
    }

    Complex operator+(double rhs) const
    {
        return Complex(re_ + rhs, im_);
    }
    friend Complex operator+(double lhs, const Complex& rhs);

    Complex operator-(double rhs) const
    {
        return Complex(re_ - rhs, im_);
    }
    friend Complex operator-(double lhs, const Complex& rhs);

    Complex operator*(double rhs) const
    {
        return Complex(re_ * rhs, im_ * rhs);
    }
    friend Complex operator*(double lhs, const Complex& rhs);

    Complex operator/(double rhs) const
    {
        return Complex(re_ / rhs, im_ / rhs);
    }
    friend Complex operator/(double lhs, const Complex& rhs);

    bool operator==(const Complex& other) const
    {
        return re_ == other.re_ && im_ == other.im_;
    }

    bool operator!=(const Complex& other) const
    {
        return !(*this == other);
    }

private:
    double re_, im_;
};

Complex operator+(double lhs, const Complex& rhs)
{
    return Complex(lhs + rhs.Re(), rhs.Im());
}

Complex operator-(double lhs, const Complex& rhs)
{
    return Complex(lhs - rhs.Re(), -rhs.Im());
}

Complex operator*(double lhs, const Complex& rhs)
{
    return Complex(lhs * rhs.Re(), lhs * rhs.Im());
}

Complex operator/(double lhs, const Complex& rhs)
{
    double denominator = rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im();
    return Complex(lhs * rhs.Re() / denominator, -lhs * rhs.Im() / denominator);
}

double abs(const Complex& x)
{
    return std::sqrt(x.Re() * x.Re() + x.Im() * x.Im());
}
