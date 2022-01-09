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

#ifndef SUBJECT04_H_
#define SUBJECT04_H_

#include <iostream>
#include <cstring>

using std::strcpy, std::strncpy, std::ostream, std::cout, std::endl;

namespace subject04
{
  class Port
  {
  private:
    char *m_brand;
    char m_style[20];
    int m_bottles;

  public:
    Port(const char *brand = "none", const char *style = "none", int bottles = 0);
    Port(const Port &port);
    virtual ~Port() { delete[] m_brand; }
    Port &operator=(const Port &port);
    Port &operator+=(int bottles);
    Port &operator-=(int bottles);
    int BottleCount() const { return m_bottles; }
    virtual void Show() const;
    friend ostream &operator<<(ostream &os, const Port &port);
  };

  class VintagePort : public Port
  {
  private:
    char *m_nickname;
    int m_year;

  public:
    VintagePort();
    VintagePort(const char *brand, int bottles, const char *nickname, int year);
    VintagePort(const VintagePort &vintage_port);
    virtual ~VintagePort() { delete[] m_nickname; }
    VintagePort &operator=(const VintagePort &vintage_port);
    virtual void Show() const;
    friend ostream &operator<<(ostream &os, const VintagePort &vintage_port);
  };
}

#endif
