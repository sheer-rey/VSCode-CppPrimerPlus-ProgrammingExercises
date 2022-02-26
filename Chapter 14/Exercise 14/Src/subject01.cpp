#include "subject01.h"

namespace subject01
{
  Wine::Wine()
  {
    m_lable = "No Lable";
    m_number_of_years = -1;
  }

  Wine::Wine(const char *lable, int number_of_years,
             int *production_year, int *production_bottles)
  {
    m_lable.assign(lable);
    m_number_of_years = number_of_years;
    m_info.first.resize(m_number_of_years);
    m_info.second.resize(m_number_of_years);
    for (int i = 0; i < m_number_of_years; i++)
    {
      m_info.first[i] = production_year[i];
      m_info.second[i] = production_bottles[i];
    }
  }

  Wine::Wine(const char *lable, int number_of_years)
  {
    m_lable = lable;
    m_number_of_years = number_of_years;
    m_info.first.resize(m_number_of_years, -1);
    m_info.second.resize(m_number_of_years, -1);
  }

  void Wine::GetBottles()
  {
    if (m_lable == "No Lable")
    {
      cout << "Enter name of wine: ";
      getline(cin, m_lable);
      cout << "Enter number of years: ";
      while (!(cin >> m_number_of_years))
      {
        cin.clear();
        cin.sync();
        cout << "input error, please reinput number of years: ";
      }
      m_info.first.resize(m_number_of_years);
      m_info.second.resize(m_number_of_years);
    }
    cout << "Enter " << m_lable << " data for " << m_number_of_years;
    if (m_number_of_years > 1)
      cout << " years: " << endl;
    else
      cout << " year: " << endl;
    for (int i = 0; i < m_number_of_years; i++)
    {
      cout << "Enter year: ";
      while (!(cin >> m_info.first[i]))
      {
        cin.clear();
        cin.sync();
        cout << "input error, please reinput year: ";
      }
      cout << "Enter bottles for that year: ";
      while (!(cin >> m_info.second[i]))
      {
        cin.clear();
        cin.sync();
        cout << "input error, please reinput production quantity of "
             << m_info.first[i] << ": ";
      }
    }
    cout << "Input Done!" << endl;
  }

  int Wine::Sum()
  {
    int num = 0;
    for (int i = 0; i < m_number_of_years; i++)
      num += m_info.second[i];
    if (num < 0)
      num = -1;
    return num;
  }

  void Wine::Show()
  {
    cout << "Wine: " << m_lable << endl;
    cout << "      Year\tBottles" << endl;
    for (int i = 0; i < m_number_of_years; i++)
      cout << "      " << m_info.first[i] << '\t' << m_info.second[i] << endl;
  }
}
