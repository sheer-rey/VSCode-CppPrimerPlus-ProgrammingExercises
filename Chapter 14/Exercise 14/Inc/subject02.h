#ifndef SUBJECT02_H_
#define SUBJECT02_H_

#include <iostream>
#include <string>
#include <valarray>
#include <utility>
#include <cstring>
using std::cout, std::cin, std::endl, std::strcpy, std::strncpy;
using std::string, std::valarray, std::pair, std::getline;

namespace subject02
{
  typedef pair<valarray<int>, valarray<int>> WineInfo;

  class Wine : string, WineInfo
  {
    // Base class string indicate wine lable
    // Base class WineInfo indicate production year and bottles
  private:
    int m_number_of_years;

  public:
    Wine();
    Wine(const char *lable, int number_of_years,
         int *production_year, int *production_bottles);
    Wine(const char *lable, int number_of_years);
    Wine(const Wine &wine) = default;
    Wine(Wine &&wine) = default;
    ~Wine() = default;
    Wine &operator=(const Wine &wine) = default;
    Wine &operator=(Wine &&wine) = default;

    void GetBottles();
    const string &Lable() const { return *this; }
    int Sum();
    void Show();
  };
}

#endif
