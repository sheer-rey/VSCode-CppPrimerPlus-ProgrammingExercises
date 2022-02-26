#include "complex0.h"

Complex0 Complex0::operator+(const Complex0 &complex) const
{
  Complex0 temporary;
  temporary.m_real = m_real + complex.m_real;
  temporary.m_imaginary = m_imaginary + complex.m_imaginary;
  return temporary;
}

Complex0 Complex0::operator-(const Complex0 &complex) const
{
  Complex0 temporary;
  temporary.m_real = m_real - complex.m_real;
  temporary.m_imaginary = m_imaginary - complex.m_imaginary;
  return temporary;
}

Complex0 Complex0::operator*(const Complex0 &complex) const
{
  Complex0 temporary;
  temporary.m_real = m_real * complex.m_real - m_imaginary * complex.m_imaginary;
  temporary.m_imaginary = m_real * complex.m_imaginary + m_imaginary * complex.m_real;
  return temporary;
}

Complex0 Complex0::operator*(const double n) const
{
  Complex0 temporary;
  temporary.m_real = m_real * n;
  temporary.m_imaginary = m_imaginary * n;
  return temporary;
}

ostream &operator<<(ostream &os, const Complex0 &complex)
{
  os << '(' << complex.m_real << ", " << complex.m_imaginary << "i)";
  return os;
}

istream &operator>>(istream &is, Complex0 &complex)
{
  cout << "real: ";
  is >> complex.m_real;
  if (!is)
    return is;
  cout << "imaginary: ";
  is >> complex.m_imaginary;
  return is;
}