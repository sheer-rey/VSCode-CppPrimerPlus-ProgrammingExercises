#include "golf.h"
#include <cstring>
#include <iostream>

void Setgolf(golf &g, const char *name, int hc)
{
  std::strcpy(g.fullname, name);
  g.handicap = hc;
}

int Setgolf(golf &g)
{
  using std::cout, std::cin, std::endl;
  cout << "Please enter your name (empty line to quit):";
  cin.get(g.fullname, Len).get();
  if (!cin)
  {
    cin.clear();
    cin.sync();
    cout << "quit!" << endl;
    return 0;
  }
  cout << "Please enter your handicap (integer): ";
  cin >> g.handicap;
  while (!cin)
  {
    cin.clear();
    cin.sync();
    cout << "Input error! Renter your handicap (integer): ";
    cin >> g.handicap;
  }
  cin.clear();
  cin.sync();
  return 1;
}

void Handicap(golf &g, int hc)
{
  g.handicap = hc;
}

void Showgolf(const golf &g)
{
  std::cout << "Fullname: " << g.fullname << "\tHandicap: " << g.handicap << std::endl;
}