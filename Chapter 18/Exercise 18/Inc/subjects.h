#ifndef SUBJECTS_H_
#define SUBJECTS_H_

#include <iostream>
#include <initializer_list>
#include <string>
#include <utility>
#include <list>
#include <iterator>
#include <algorithm>

namespace subject01
{
  using std::initializer_list;

  template <typename T>
  T AverageList(initializer_list<T> list)
  {
    T avr = 0;
    for (T x : list)
      avr += x;
    avr /= list.size();
    return avr;
  }
}

namespace subject02
{
  using std::cout, std::endl;
  using std::move;
  using std::string;

  class Cpmv
  {
  public:
    struct Info
    {
      string qcode;
      string zcode;
    };

  private:
    Info *pi;

  public:
    Cpmv();
    Cpmv(string q, string z);
    Cpmv(const Cpmv &cp);
    Cpmv(Cpmv &&cp);
    ~Cpmv();
    Cpmv &operator=(const Cpmv &cp);
    Cpmv &operator=(Cpmv &&cp);

    Cpmv operator+(const Cpmv &obj) const;
    void Display() const;
  };
}

namespace subject03
{
  using std::cout, std::endl;
  using std::string;

  template <typename T>
  long double SumValue(T first)
  {
    return first;
  }

  template <typename T, typename... Args>
  long double SumValue(T first, Args... args)
  {
    return first + SumValue(args...);
  }
}

// the listing 16.5 subject04 described should be listing 16.15
namespace subject04
{
  using std::cout;
  using std::endl;
  using std::for_each;
  using std::list;
  using std::remove_if;

  auto outint = [](int n)
  { std::cout << n << " "; };
}

#endif