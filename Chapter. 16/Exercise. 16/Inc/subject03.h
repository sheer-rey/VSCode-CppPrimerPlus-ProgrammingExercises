#ifndef SUBJECT_03_HPP_
#define SUBJECT_03_HPP_

#include <iostream>

#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
using std::cout, std::cin, std::cerr, std::endl;
using std::ifstream, std::ofstream;
using std::string;
using std::vector;

namespace subject03
{
  extern vector<string> word_list;
  void GetWordList();
  void HangMan();
}
#endif
