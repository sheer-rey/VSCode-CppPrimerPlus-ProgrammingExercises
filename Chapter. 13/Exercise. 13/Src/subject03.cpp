#include "subject03.h"

namespace subject03
{
  LackDMA::LackDMA(const char *str) : ABC(strlen(str))
  {
    strncpy(m_str, str, 49);
    m_str[49] = 0;
  }

  void LackDMA::View() const
  {
    cout << "         String: " << m_str << endl;
    cout << "Number of chars: " << Output() << endl;
  }

  HasDMA::HasDMA(const char *str) : ABC(strlen(str))
  {
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
  }

  HasDMA::~HasDMA()
  {
    delete[] m_str;
  }

  void HasDMA::View() const
  {
    cout << "         String: " << m_str << endl;
    cout << "Number of chars: " << Output() << endl;
  }

}
