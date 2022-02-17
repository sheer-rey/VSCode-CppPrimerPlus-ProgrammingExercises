#include "subject01.h"

namespace subject01
{
  bool Tv::volup()
  {
    if (m_volume < MaxVal)
    {
      m_volume++;
      return true;
    }
    else
      return false;
  }
  bool Tv::voldown()
  {
    if (m_volume > MinVal)
    {
      m_volume--;
      return true;
    }
    else
      return false;
  }

  void Tv::chanup()
  {
    if (m_channel < m_max_channel)
      m_channel++;
    else
      m_channel = 1;
  }

  void Tv::chandown()
  {
    if (m_channel > 1)
      m_channel--;
    else
      m_channel = m_max_channel;
  }

  void Tv::settings() const
  {
    using std::cout;
    using std::endl;
    cout << "TV is " << (m_state == Off ? "Off" : "On") << endl;
    if (m_state == On)
    {
      cout << "Volume setting = " << m_volume << endl;
      cout << "Channel setting = " << m_channel << endl;
      cout << "Mode = "
           << (m_mode == Antenna ? "antenna" : "cable") << endl;
      cout << "Input = "
           << (m_input == TV ? "TV" : "DVD") << endl;
    }
  }

  void Remote::settings() const
  {
    using std::cout;
    using std::endl;
    cout << "Remote's mode is " << (m_mode == Tv::Off ? "Off" : "On")
         << " and" << (isinteractive() ? "" : " not") << " interactive"
         << endl;
  }

  void Tv::set_interactive(Remote &remote, int interactive)
  {
    if (m_state == On)
      remote.m_interactive = interactive;
  }

}
