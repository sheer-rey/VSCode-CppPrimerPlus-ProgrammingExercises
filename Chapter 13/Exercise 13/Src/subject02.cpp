#include "subject02.h"

namespace subject02
{
  // Base Class
  Cd::Cd()
  {
    m_performers = new char[strlen("No Performers") + 1];
    strcpy(m_performers, "No Performers");
    m_lable = new char[strlen("No Lable") + 1];
    strcpy(m_lable, "No Lable");
    m_selections = 0;
    m_playtime = 0;
  }

  Cd::Cd(const char *performers, const char *lable, int selections, double playtime)
  {
    m_performers = new char[strlen(performers) + 1];
    strcpy(m_performers, performers);
    m_lable = new char[strlen(lable) + 1];
    strcpy(m_lable, lable);
    m_selections = selections;
    m_playtime = playtime;
  }

  Cd::Cd(const Cd &cd)
  {
    m_performers = new char[strlen(cd.m_performers) + 1];
    strcpy(m_performers, cd.m_performers);
    m_lable = new char[strlen(cd.m_lable) + 1];
    strcpy(m_lable, cd.m_lable);
    m_selections = cd.m_selections;
    m_playtime = cd.m_playtime;
  }

  Cd::~Cd()
  {
    delete[] m_performers;
    delete[] m_lable;
  }

  Cd &Cd::operator=(const Cd &cd)
  {
    if (&cd != this)
    {
      delete[] m_performers;
      delete[] m_lable;
      m_performers = new char[strlen(cd.m_performers) + 1];
      strcpy(m_performers, cd.m_performers);
      m_lable = new char[strlen(cd.m_lable) + 1];
      strcpy(m_lable, cd.m_lable);
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
    m_top_music = new char[strlen("No Music") + 1];
    strcpy(m_top_music, "No Music");
  }

  Classic::Classic(const char *performers, const char *lable, const char *top_music,
                   int selections, double playtime)
      : Cd(performers, lable, selections, playtime)
  {
    m_top_music = new char[strlen(top_music) + 1];
    strcpy(m_top_music, top_music);
  }

  Classic::Classic(const Classic &classic) : Cd(classic)
  {
    m_top_music = new char[strlen(classic.m_top_music) + 1];
    strcpy(m_top_music, classic.m_top_music);
  }

  Classic::~Classic()
  {
    delete[] m_top_music;
  }

  Classic &Classic::operator=(const Classic &classic)
  {
    if (&classic != this)
    {
      Cd::operator=(classic);
      delete[] m_top_music;
      m_top_music = new char[strlen(classic.m_top_music) + 1];
      strcpy(m_top_music, classic.m_top_music);
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
