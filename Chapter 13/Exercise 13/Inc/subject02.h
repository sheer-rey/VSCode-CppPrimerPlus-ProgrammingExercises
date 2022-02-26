#ifndef SUBJECT02_H_
#define SUBJECT02_H_

#include <iostream>
#include <cstring>
using std::cout, std::endl, std::strcpy, std::strncpy;

namespace subject02
{
  class Cd
  {
  private:
    char *m_performers;
    char *m_lable;
    int m_selections;  // number of selections
    double m_playtime; // playing time in minutes
  public:
    Cd();
    Cd(const char *performers, const char *lable, int selections, double playtime);
    Cd(const Cd &cd);
    virtual ~Cd();
    Cd &operator=(const Cd &Cd);
    virtual void Report() const;
  };

  class Classic : public Cd
  {
  private:
    char *m_top_music;

  public:
    Classic();
    Classic(const char *performers, const char *lable, const char *top_music,
            int selections, double playtime);
    Classic(const Classic &classic);
    virtual ~Classic();
    Classic &operator=(const Classic &classic);
    virtual void Report() const;
  };

  void Bravo(const Cd &disk);
}

#endif
