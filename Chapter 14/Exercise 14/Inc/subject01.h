#ifndef SUBJECT01_H_
#define SUBJECT01_H_

#include <iostream>
#include <string>
#include <valarray>
#include <utility>
#include <cstring>
using std::cout, std::cin, std::endl, std::strcpy, std::strncpy;
using std::string, std::valarray, std::pair, std::getline;

namespace subject01
{
  typedef pair<valarray<int>, valarray<int>> WineInfo;
  class Wine
  {
  private:
    string m_lable;
    int m_number_of_years;
    WineInfo m_info; // include production year and bottles

  public:
    Wine();
    Wine(const char *lable, int number_of_years,
         int *production_year, int *production_bottles);
    Wine(const char *lable, int number_of_years);
    Wine(const Wine &wine) = default;
    ~Wine() = default;
    Wine &operator=(const Wine &wine) = default;

    void GetBottles();
    const string &Lable() const { return m_lable; }
    int Sum();
    void Show();
  };
}

#endif
