#ifndef SUBJECT04_H_
#define SUBJECT04_H_

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>

using std::strcpy, std::strncpy, std::ostream, std::cout, std::endl;
using std::string;
using std::time, std::rand, std::srand;

namespace subject04
{
  class Person
  {

  private:
    string m_first_name;
    string m_last_name;

  public:
    Person(const string first_name = "No", const string last_name = "Name") : m_first_name(first_name), m_last_name(last_name) {}
    Person(const Person &person) = default;
    Person(Person &&person) = delete;
    virtual ~Person() = default;
    Person &operator=(const Person &person) = default;
    Person &operator=(Person &&person) = delete;
    virtual void Show() const { cout << "Name: " << m_first_name << ' ' << m_last_name; }

    friend ostream &operator<<(ostream &os, const Person &person);
  };

  class Gunslinger : virtual public Person
  {
  private:
    double m_draw;
    int m_nick;

  protected:
    double M_Draw() const { return m_draw; }
    int M_Nick() const { return m_nick; }

  public:
    Gunslinger();
    Gunslinger(string first_name, string last_name);
    Gunslinger(string first_name, string last_name, double draw, int nick);
    Gunslinger(const Gunslinger &gun_slinger) = default;
    Gunslinger(Gunslinger &&gun_slinger) = delete;
    virtual ~Gunslinger() = default;
    Gunslinger &operator=(const Gunslinger &gun_slinger) = default;
    Gunslinger &operator=(Gunslinger &&gun_slinger) = delete;
    double Draw() const { return m_draw; }
    virtual void Show() const;
    friend ostream &operator<<(ostream &os, const Gunslinger &gun_slinger);
  };

  class Card
  {
  private:
    enum CardSuit
    {
      cDIAMOND,
      cSPADE,
      cHEART,
      cCLUB
    };
    static constexpr char cCardSuit[4][9] = {"diamonds", "spades", "hearts", "clubs"};
    enum CardValue
    {
      cACE = 1,
      cTWO,
      cTHREE,
      cFOUR,
      cFIVE,
      cSIX,
      cSEVEN,
      cEIGHT,
      cNINE,
      cTEN,
      cJACK,
      cQUEEN,
      cKING
    };
    static constexpr char cCardValue[14][6] = {"", "ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king"};
    CardSuit m_suit;
    CardValue m_value;

  public:
    Card();
    Card(const Card &card) = default;
    Card(Card &&card) = delete;
    virtual ~Card() = default;
    Card &operator=(const Card &card) = default;
    Card &operator=(Card &&card) = delete;
    void Show() const { cout << "the " << cCardValue[m_value] << " of " << cCardSuit[m_suit]; }
    friend ostream &operator<<(ostream &os, const Card &card);
  };

  class PokerPlayer : virtual public Person
  {
  private:
    Card m_next_card;

  protected:
    Card M_Next_Card() const { return m_next_card; }

  public:
    PokerPlayer() = default;
    PokerPlayer(string first_name, string last_name) : Person(first_name, last_name) {}
    PokerPlayer(const PokerPlayer &poker_player) = default;
    PokerPlayer(PokerPlayer &&poker_player) = delete;
    virtual ~PokerPlayer() = default;
    PokerPlayer &operator=(const PokerPlayer &poker_player) = default;
    PokerPlayer &operator=(PokerPlayer &&poker_player) = delete;
    Card Draw() const { return m_next_card; }
    virtual void Show() const;
    friend ostream &operator<<(ostream &os, const PokerPlayer &poker_player);
  };

  class BadDude : public Gunslinger, public PokerPlayer
  {
  public:
    BadDude() = default;
    BadDude(string first_name, string last_name) : Person(first_name, last_name) {}
    BadDude(const BadDude &bad_dude) = default;
    BadDude(BadDude &&bad_dude) = delete;
    virtual ~BadDude() = default;
    BadDude &operator=(const BadDude &bad_dude) = default;
    BadDude &operator=(BadDude &&bad_dude) = delete;
    double GDraw() const { return Gunslinger::Draw(); }
    Card CDraw() const { return PokerPlayer::Draw(); }
    virtual void Show() const;
    friend ostream &operator<<(ostream &os, BadDude &bad_dude);
  };
}

#endif
