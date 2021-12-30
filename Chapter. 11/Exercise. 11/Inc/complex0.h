#ifndef _COMPLEX_0_H_
#define _COMPLEX_0_H_

#include <iostream>
using std::cin, std::cout, std::endl;
using std::istream, std::ostream;

class Complex0
{
private:
  double m_real = 0;
  double m_imaginary = 0;

public:
  Complex0() = default;
  Complex0(double real, double imaginary = 0) : m_real(real), m_imaginary(imaginary) {}
  ~Complex0() = default;

  Complex0 operator+(const Complex0 &complex) const;
  Complex0 operator-(const Complex0 &complex) const;
  Complex0 operator*(const Complex0 &complex) const;
  Complex0 operator*(const double n) const;
  Complex0 operator~() const { return Complex0(m_real, -m_imaginary); }

  friend Complex0 operator*(const double n, const Complex0 &complex) { return complex * n; }
  friend ostream &operator<<(ostream &os, const Complex0 &complex);
  friend istream &operator>>(istream &is, Complex0 &complex);
};

#endif
