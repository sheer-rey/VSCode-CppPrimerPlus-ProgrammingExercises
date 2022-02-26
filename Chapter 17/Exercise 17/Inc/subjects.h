#ifndef SUBJECTS_H_
#define SUBJECTS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>

namespace subject01
{
  using std::cout, std::cin, std::endl;
  using std::string;
  void GetInstreamCount();
}

namespace subject02
{
  using std::cout, std::cin, std::cerr, std::endl;
  using std::ofstream;

  void GetKeyboardInput2File(const char *file_name);
}

namespace subject03
{
  using std::cout, std::cin, std::cerr, std::endl;
  using std::ofstream, std::ifstream;

  void FileContentsTransfer(const char *file_out, const char *file_in);
}

namespace subject04
{
  using std::cout, std::cin, std::cerr, std::endl;
  using std::ofstream, std::ifstream;
  using std::string, std::getline;

  void FilesMerge(const char *file_in1, const char *file_in2, const char *file_out);
}

namespace subject05
{
  using std::cin, std::cout, std::cerr, std::endl;
  using std::ifstream, std::ofstream;
  using std::ostream_iterator;
  using std::sort, std::unique;
  using std::string, std::getline;
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
    Person &StoreFriends();

    Person operator+(const Person &person);
  };
}

namespace subject06
{

}

namespace subject07
{

}

#endif
