#include "subject01.h"

namespace subject01
{
  bool Palindrome(const string &str)
  {
    int tail = str.size() - 1;
    int head = 0;
    while (tail != head && tail > head)
    {
      if (str[tail] != str[head])
        return false;
      tail--;
      head++;
    }
    return true;
  }
}
