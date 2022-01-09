#include "subject01.h"

namespace subject01
{
  // Base Class
  Cd::Cd()
  {
    strncpy(m_performers, "No Performers", 49);
    m_performers[49] = 0;
    strncpy(m_lable, "No Lable", 19);
    m_lable[19] = 0;
    m_selections = 0;
    m_playtime = 0;
  }

  Cd::Cd(const char *performers, const char *lable, int selections, double playtime)
  {
    strncpy(m_performers, performers, 49);
    m_performers[49] = 0;
    strncpy(m_lable, lable, 19);
    m_lable[19] = 0;
    m_selections = selections;
    m_playtime = playtime;
  }

  Cd::Cd(const Cd &cd)
  {
    strncpy(m_performers, cd.m_performers, 49);
    m_performers[49] = 0;
    strncpy(m_lable, cd.m_lable, 19);
    m_lable[19] = 0;
    m_selections = cd.m_selections;
    m_playtime = cd.m_playtime;
  }

  Cd &Cd::operator=(const Cd &cd)
  {
    if (&cd != this)
    {
      strncpy(m_performers, cd.m_performers, 49);
      m_performers[49] = 0;
      strncpy(m_lable, cd.m_lable, 19);
      m_lable[19] = 0;
      m_selections = cd.m_selections;
      m_playtime = cd.m_playtime;
    }
    return *this;
  }

  void Cd::Report() const
  {
    cout << "CD Information" << endl;
    cout << "Performers: " << m_performers << endl;
    cout << "     Lable: " << m_lable << endl;
    cout << "Selections: " << m_selections << endl;
    cout << " Play time: " << m_playtime << endl;
  }

  // Derived Class
  Classic::Classic() : Cd()
  {
    strncpy(m_top_music, "No Music", 49);
    m_top_music[49] = 0;
  }

  Classic::Classic(const char *performers, const char *lable, const char *top_music,
                   int selections, double playtime)
      : Cd(performers, lable, selections, playtime)
  {
    strncpy(m_top_music, top_music, 49);
    m_top_music[49] = 0;
  }

  Classic::Classic(const Classic &classic) : Cd(classic)
  {
    strncpy(m_top_music, classic.m_top_music, 49);
    m_top_music[49] = 0;
  }

  Classic &Classic::operator=(const Classic &classic)
  {
    if (&classic != this)
    {
      Cd::operator=(classic);
      strncpy(m_top_music, classic.m_top_music, 49);
      m_top_music[49] = 0;
    }
    return *this;
  }

  void Classic::Report() const
  {
    Cd::Report();
    cout << " Top Music: " << m_top_music << endl;
  }

  void Bravo(const Cd &disk)
  {
    disk.Report();
  }
}
