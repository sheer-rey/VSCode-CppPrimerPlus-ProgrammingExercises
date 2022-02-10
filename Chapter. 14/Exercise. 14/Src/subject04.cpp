#include "subject04.h"

namespace subject04
{
  /* Class Person */
  ostream &operator<<(ostream &os, const Person &person)
  {
    os << "Name: " << person.m_first_name << ' ' << person.m_last_name;
    return os;
  }

  /* Class Gunslinger */
  Gunslinger::Gunslinger() : Person()
  {
    srand(time(0));
    m_draw = rand() / 10000.0;
    m_nick = rand() % 12;
  }

  Gunslinger::Gunslinger(string first_name, string last_name) : Person(first_name, last_name)
  {
    srand(time(0));
    m_draw = rand() / 10000.0;
    m_nick = rand() % 12;
  }

  Gunslinger::Gunslinger(string first_name, string last_name, double draw, int nick) : Person(first_name, last_name)
  {
    m_draw = draw;
    m_nick = nick;
  }

  void Gunslinger::Show() const
  {
    Person::Show();
    cout << endl;
    cout << "Draw time: " << m_draw << 's' << endl;
    cout << "Gun nick: " << m_nick;
  }

  ostream &operator<<(ostream &os, const Gunslinger &gun_slinger)
  {
    os << Person(gun_slinger) << endl;
    cout << "Draw time: " << gun_slinger.m_draw << 's' << endl;
    cout << "Gun nick: " << gun_slinger.m_nick;
    return os;
  }

  /* Class Card */
  Card::Card()
  {
    srand(time(0));
    m_suit = CardSuit(rand() % 4);
    m_value = CardValue(rand() % 13 + 1);
  }

  ostream &operator<<(ostream &os, const Card &card)
  {
    os << "The " << card.cCardValue[card.m_value] << " of " << card.cCardSuit[card.m_suit];
    return os;
  }

  /* Class PokerPlayer */
  void PokerPlayer::Show() const
  {
    Person::Show();
    cout << endl;
    cout << "Next Card: " << m_next_card;
  }
  ostream &operator<<(ostream &os, const PokerPlayer &poker_player)
  {
    os << Person(poker_player) << endl;
    os << "Next Card: " << poker_player.m_next_card;
    return os;
  }

  /* Class BadDude */
  void BadDude::Show() const
  {
    Person::Show();
    cout << endl;
    cout << "Draw time: " << Gunslinger::M_Draw() << 's' << endl;
    cout << "Gun nick: " << Gunslinger::M_Nick() << endl;
    cout << "Next Card: " << PokerPlayer::M_Next_Card();
  }
  ostream &operator<<(ostream &os, BadDude &bad_dude)
  {
    os << Person(bad_dude) << endl;
    os << "Draw time: " << bad_dude.M_Draw() << 's' << endl;
    os << "Gun nick: " << bad_dude.M_Nick() << endl;
    os << "Next Card: " << bad_dude.M_Next_Card();
    return os;
  }
}
