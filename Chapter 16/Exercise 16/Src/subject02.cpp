#include "subject02.h"

namespace subject02
{
  bool Palindrome(const string &str)
  {
    string temp_str;
    for (auto it = str.cbegin(); it < str.cend(); it++)
    {
      if (isalnum(*it))
      {
        if (isupper(*it))
          temp_str.push_back(tolower(*it));
        else
          temp_str.push_back(*it);
      }
    }

    int tail = temp_str.size() - 1;
    int head = 0;
    while (tail != head && tail > head)
    {
      if (temp_str[tail] != temp_str[head])
        return false;
      tail--;
      head++;
    }
    return true;
  }
}