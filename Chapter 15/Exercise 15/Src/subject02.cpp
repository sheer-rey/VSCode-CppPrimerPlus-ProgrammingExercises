#include "subject02.h"

namespace subject02
{
  double hmean(double a, double b)
  {
    if (a == -b)
      throw domain_error(string("hmean(") + to_string(a) + ", " + to_string(b) + "): invalid arguments: a = -b");
    return 2.0 * a * b / (a + b);
  }

  double gmean(double a, double b)
  {
    if (a < 0 || b < 0)
      throw invalid_argument(string("gmean() arguments should be >= 0\n") + "Values used: " + to_string(a) + ", " + to_string(b) + "\nSorry, you don't get to play any more.");
    return std::sqrt(a * b);
  }
}