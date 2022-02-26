#ifndef _COW_H_
#define _COW_H_

#include <iostream>
#include <cstring>
using std::cout, std::endl;

// Subject 01
class Cow
{
private:
  char m_name[20];
  char *m_hobby;
  double m_weight;

public:
  Cow();
  Cow(const char *name, const char *hobby, double weight);
  Cow(const Cow &cow);
  ~Cow();
  Cow &operator=(const Cow &cow);
  void ShowCow() const; // display all Cow data
};

#endif
