#ifndef SUBJECT01_H_
#define SUBJECT01_H_

#include <iostream>
#include <cstring>
using std::cout, std::endl, std::strcpy, std::strncpy;

namespace subject01
{
  class Cd
  {
  private:
    char m_performers[50];
    char m_lable[20];
    int m_selections;  // number of selections
    double m_playtime; // playing time in minutes
  public:
    Cd();
    Cd(const char *performers, const char *lable, int selections, double playtime);
    Cd(const Cd &cd);
    virtual ~Cd() = default;
    Cd &operator=(const Cd &Cd);
    virtual void Report() const;
  };

  class Classic : public Cd
  {
  private:
    char m_top_music[50];

  public:
    Classic();
    Classic(const char *performers, const char *lable, const char *top_music,
            int selections, double playtime);
    Classic(const Classic &classic);
    virtual ~Classic() = default;
    Classic &operator=(const Classic &classic);
    virtual void Report() const;
  };

  void Bravo(const Cd &disk);
}

#endif
