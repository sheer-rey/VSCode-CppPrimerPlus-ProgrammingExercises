/*******************************************************************************
 *                         Answers of Subject 04
 * \p Question02 Derived class has some new data members, which need to be
 *               printed by the same function. So Drived class has to override
 *               some functions.
 *               In the same way, some functions do the same things in both
 *               derived class and base class. So there's no need to override.
 * \p Question03 About "operator=": This function cannot be inherited. So it
 *               doesn't has 'virtual' keyword in declaration.
 *               About "operator<<": This function is a friend function, isn't
 *               the member function of neither base class nor derived class. So
 *               it doesn't has 'virtual' keyword in declaration.
 * ****************************************************************************/

#include "subject04.h"

namespace subject04
{
  Port::Port(const char *brand, const char *style, int bottles)
  {
    m_brand = new char[strlen(brand) + 1];
    strcpy(m_brand, brand);
    strncpy(m_style, style, 19);
    m_style[19] = 0;
    m_bottles = bottles;
  }

  Port::Port(const Port &port)
  {
    m_brand = new char[strlen(port.m_brand) + 1];
    strcpy(m_brand, port.m_brand);
    strncpy(m_style, port.m_style, 19);
    m_style[19] = 0;
    m_bottles = port.m_bottles;
  }

  Port &Port::operator=(const Port &port)
  {
    if (&port != this)
    {
      delete[] m_brand;
      m_brand = new char[strlen(port.m_brand) + 1];
      strcpy(m_brand, port.m_brand);
      strncpy(m_style, port.m_style, 19);
      m_style[19] = 0;
      m_bottles = port.m_bottles;
    }
    return *this;
  }

  Port &Port::operator+=(int bottles)
  {
    m_bottles += bottles;
    return *this;
  }

  Port &Port::operator-=(int bottles)
  {
    m_bottles -= bottles;
    return *this;
  }

  void Port::Show() const
  {
    cout << "   Brand: " << m_brand << endl;
    cout << "    Kind: " << m_style << endl;
    cout << "Bbottles: " << m_bottles << endl;
  }

  ostream &operator<<(ostream &os, const Port &port)
  {
    os << port.m_brand << ", " << port.m_style << ", " << port.m_bottles;
    return os;
  }

  VintagePort::VintagePort() : Port()
  {
    m_nickname = new char[5];
    strcpy(m_nickname, "none");
    m_year = -1;
  }

  VintagePort::VintagePort(const char *brand, int bottles, const char *nickname, int year) : Port(brand, "none", bottles)
  {
    m_nickname = new char[strlen(nickname) + 1];
    strcpy(m_nickname, nickname);
    m_year = year;
  }

  VintagePort::VintagePort(const VintagePort &vintage_port) : Port(vintage_port)
  {
    m_nickname = new char[strlen(vintage_port.m_nickname) + 1];
    strcpy(m_nickname, vintage_port.m_nickname);
    m_year = vintage_port.m_year;
  }

  VintagePort &VintagePort::operator=(const VintagePort &vintage_port)
  {
    if (&vintage_port != this)
    {
      Port::operator=(vintage_port);
      delete[] m_nickname;
      m_nickname = new char[strlen(vintage_port.m_nickname) + 1];
      strcpy(m_nickname, vintage_port.m_nickname);
      m_year = vintage_port.m_year;
    }
    return *this;
  }
  void VintagePort::Show() const
  {
    Port::Show();
    cout << "Nickname: " << m_nickname << endl;
    cout << "    Year: " << m_year << endl;
  }

  ostream &operator<<(ostream &os, const VintagePort &vintage_port)
  {
    os << Port(vintage_port) << ", " << vintage_port.m_nickname << ", " << vintage_port.m_year;
    return os;
  }
}
