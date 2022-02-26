#ifndef SUBJECT08_H_
#define SUBJECT08_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

namespace subject08
{
  using std::cin, std::cout, std::endl;
  using std::ostream_iterator;
  using std::sort, std::unique;
  using std::string;
  using std::vector;

  class Person
  {
  private:
    string m_name;
    vector<string> m_friends;

  public:
    Person(const string &name) : m_name(name) {}
    Person(const Person &person) = default;
    Person(Person &&person) = default;
    ~Person() = default;
    Person &operator=(const Person &person) = default;
    Person &operator=(Person &&person) = default;

    Person &GetFriends();
    Person &ShowFriends();
    Person MergeFriends(const Person &person);

    Person operator+(const Person &person);
  };

}

#endif
