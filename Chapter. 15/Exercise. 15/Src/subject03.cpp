#include "subject03.h"

namespace subject03
{
  bad_hmean::bad_hmean(string func_name, double a, double b) : logic_error(func_name), v1(a), v2(b)
  {
    err_info = logic_error::what();
    err_info += ": invalid arguments: a = -b, a = " + to_string(v1) + ", b = " + to_string(v2);
  }

  bad_gmean::bad_gmean(string func_name, double a, double b) : logic_error(func_name), v1(a), v2(b)
  {
    err_info = logic_error::what();
    err_info += ": arguments should be >= 0\nValues used: a = " + to_string(v1) + ", b = " + to_string(v2);
  }

  double hmean(double a, double b)
  {
    if (a == -b)
      throw bad_hmean("double hmean(double a, double b)", a, b);
    return 2.0 * a * b / (a + b);
  }

  double gmean(double a, double b)
  {
    if (a < 0 || b < 0)
      throw bad_gmean("double gmean(double a, double b)", a, b);
    return std::sqrt(a * b);
  }
}
