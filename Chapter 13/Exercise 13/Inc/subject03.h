#ifndef SUBJECT_03_H_
#define SUBJECT_03_H_
#include <iostream>
#include <cstring>
using std::strcpy, std::strncpy, std::strlen, std::cout, std::endl;
/*******************************************************************************
 * @note There're some misunderstanding in sunject03. 'LackDMA' and 'hasDMA' may
 * derived from 'baseDMA', but subject03 demand for both three drived from 'ABC'.
 * So in my opinion, there's no necessary to create class 'baseDMA'.
 ******************************************************************************/

namespace subject03
{
  class ABC
  {
  private:
    int m_number_of_characters;

  protected:
    void SetABC(int number_of_characters) { m_number_of_characters = number_of_characters; }
    int Output() const { return m_number_of_characters; }

  public:
    ABC(int number_of_characters = 0) { m_number_of_characters = number_of_characters; }
    virtual ~ABC() = default;
    virtual void View() const = 0;
  };

  class LackDMA : public ABC
  {
  private:
    char m_str[50];

  public:
    LackDMA(const char *str = "Default string");
    virtual ~LackDMA() = default;
    virtual void View() const;
  };

  class HasDMA : public ABC
  {
  private:
    char *m_str;

  public:
    HasDMA(const char *str = "Default string");
    virtual ~HasDMA();
    virtual void View() const;
  };
}
#endif
