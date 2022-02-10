#include "subject02.h"

namespace subject02
{
  Wine::Wine() : string("No Lable"), WineInfo()
  {
    m_number_of_years = -1;
  }

  Wine::Wine(const char *lable, int number_of_years,
             int *production_year, int *production_bottles)
      : string(lable), WineInfo()
  {
    m_number_of_years = number_of_years;
    WineInfo::first.resize(m_number_of_years);
    WineInfo::second.resize(m_number_of_years);
    for (int i = 0; i < m_number_of_years; i++)
    {
      WineInfo::first[i] = production_year[i];
      WineInfo::second[i] = production_bottles[i];
    }
  }

  Wine::Wine(const char *lable, int number_of_years) : string(lable), WineInfo()
  {
    m_number_of_years = number_of_years;
  }

  void Wine::GetBottles()
  {

    if (string(*this) == "No Lable")
    {
      cout << "Enter name of wine: ";
      getline(cin, *this);
      cout << "Enter number of years: ";
      while (!(cin >> m_number_of_years))
      {
        cin.clear();
        cin.sync();
        cout << "input error, please reinput number of years: ";
      }
      WineInfo::first.resize(m_number_of_years);
      WineInfo::second.resize(m_number_of_years);
    }
    cout << "Enter " << string(*this) << " data for " << m_number_of_years;
    if (m_number_of_years > 1)
      cout << " years: " << endl;
    else
      cout << " year: " << endl;
    for (int i = 0; i < m_number_of_years; i++)
    {
      cout << "Enter year: ";
      while (!(cin >> WineInfo::first[i]))
      {
        cin.clear();
        cin.sync();
        cout << "input error, please reinput year: ";
      }
      cout << "Enter bottles for that year: ";
      while (!(cin >> WineInfo::second[i]))
      {
        cin.clear();
        cin.sync();
        cout << "input error, please reinput production quantity of "
             << WineInfo::first[i] << ": ";
      }
    }
    cout << "Input Done!" << endl;
  }

  int Wine::Sum()
  {
    int num = 0;
    for (int i = 0; i < m_number_of_years; i++)
      num += WineInfo::second[i];
    if (num < 0)
      num = -1;
    return num;
  }

  void Wine::Show()
  {
    cout << "Wine: " << string(*this) << endl;
    cout << "      Year\tBottles" << endl;
    for (int i = 0; i < m_number_of_years; i++)
      cout << "      " << WineInfo::first[i] << '\t'
           << WineInfo::second[i] << endl;
  }
}
