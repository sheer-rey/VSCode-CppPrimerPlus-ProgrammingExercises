#ifndef SUBJECT01_H_
#define SUBJECT01_H_

#include <iostream>
using std::cout, std::cin, std::endl;

namespace subject01
{
  class Remote;
  class Tv
  {
  private:
    int m_state;       // on or off
    int m_volume;      // assumed to be digitized
    int m_max_channel; // maximum number of channels
    int m_channel;     // current channel setting
    int m_mode;        // broadcast or cable
    int m_input;       // TV or DVD

  public:
    enum
    {
      Off,
      On
    };
    enum
    {
      MinVal,
      MaxVal = 20
    };
    enum
    {
      Antenna,
      Cable
    };
    enum
    {
      TV,
      DVD
    };

    Tv(int state = Off, int max_channel = 125) : m_state(state), m_volume(5), m_max_channel(max_channel),
                                                 m_channel(2), m_mode(Cable), m_input(TV) {}
    Tv(const Tv &tv) = delete;
    Tv(Tv &&tv) = delete;
    ~Tv() = default;
    Tv &operator=(const Tv &tv) = delete;
    Tv &operator=(Tv &&tv) = delete;

    void onoff() { m_state = (m_state == On) ? Off : On; }
    bool ison() const { return m_state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { m_mode = (m_mode == Antenna) ? Cable : Antenna; }
    void set_input() { m_input = (m_input == TV) ? DVD : TV; }
    void settings() const; // display all settings

    void set_interactive(Remote &remote, int interactive);

    friend class Remote; // Remote can access Tv private parts
  };

  class Remote
  {
  private:
    int m_mode; // controls TV or DVD
    int m_interactive;

  public:
    Remote(int mode = Tv::TV, int interactive = Tv::Off)
        : m_mode(mode), m_interactive(interactive) {}
    Remote(const Remote &remote) = delete;
    Remote(Remote &&remote) = delete;
    ~Remote() = default;
    Remote &operator=(const Remote &remote) = delete;
    Remote &operator=(Remote &&remote) = delete;

    bool isinteractive() const { return (m_interactive == Tv::On) ? true : false; }
    void settings() const;

    bool volup(Tv &t) { return t.volup(); }
    bool voldown(Tv &t) { return t.voldown(); }
    void onoff(Tv &t) { t.onoff(); }
    void chanup(Tv &t) { t.chanup(); }
    void chandown(Tv &t) { t.chandown(); }
    void set_chan(Tv &t, int c) { t.m_channel = c; }
    void set_mode(Tv &t) { t.set_mode(); }
    void set_input(Tv &t) { t.set_input(); }

    friend class Tv;
  };

}

#endif
