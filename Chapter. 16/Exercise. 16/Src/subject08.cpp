#include "subject08.h"

namespace subject08
{
  Person &Person::GetFriends()
  {
    cout << "Hello, " << m_name << "!" << endl;
    cout << "Please enter your friends' name (q to quit): ";
    string friend_name;
    while (cin >> friend_name)
    {
      if (friend_name == "q")
        break;
      m_friends.push_back(friend_name);
    }
    sort(m_friends.begin(), m_friends.end());
    m_friends.erase(unique(m_friends.begin(), m_friends.end()), m_friends.end());
    cout << "Done!" << endl;
    return *this;
  }

  Person &Person::ShowFriends()
  {
    ostream_iterator<string> os_it(cout, " ");
    cout << m_name << "'s friends are as follow: ";
    for (const auto &x : m_friends)
      *os_it = x;
    cout << endl;
    return *this;
  }

  Person Person::MergeFriends(const Person &person)
  {
    Person two_person(this->m_name + " and " + person.m_name);
    two_person.m_friends = m_friends;
    for (const string &x : person.m_friends)
      two_person.m_friends.push_back(x);

    sort(two_person.m_friends.begin(), two_person.m_friends.end());
    two_person.m_friends.erase(unique(two_person.m_friends.begin(), two_person.m_friends.end()), two_person.m_friends.end());

    return two_person;
  }

  Person Person::operator+(const Person &person)
  {
    Person two_person(this->m_name + " and " + person.m_name);
    two_person.m_friends = m_friends;
    for (const string &x : person.m_friends)
      two_person.m_friends.push_back(x);

    sort(two_person.m_friends.begin(), two_person.m_friends.end());
    two_person.m_friends.erase(unique(two_person.m_friends.begin(), two_person.m_friends.end()), two_person.m_friends.end());

    return two_person;
  }
}
