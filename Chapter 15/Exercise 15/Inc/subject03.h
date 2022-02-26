#ifndef SUBJECT_03_HPP_
#define SUBJECT_03_HPP_

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
using std::cout, std::cin, std::endl;
using std::logic_error, std::domain_error, std::invalid_argument;
using std::sqrt;
using std::string, std::to_string;

namespace subject03
{
  class bad_hmean : public logic_error
  {
  private:
    string err_info;
    double v1;
    double v2;

  public:
    bad_hmean() = delete;
    explicit bad_hmean(string func_name, double a, double b);
    bad_hmean(const bad_hmean &bh) = default;
    bad_hmean(bad_hmean &&bh) = delete;
    ~bad_hmean() = default;
    bad_hmean &operator=(const bad_hmean &bh) = delete;
    bad_hmean &operator=(bad_hmean &&bh) = delete;

    virtual const char *what() const noexcept { return err_info.c_str(); }
  };

  class bad_gmean : public logic_error
  {
  private:
    string err_info;
    double v1;
    double v2;

  public:
    bad_gmean() = delete;
    explicit bad_gmean(string func_name, double a, double b);
    bad_gmean(const bad_gmean &bh) = default;
    bad_gmean(bad_gmean &&bh) = delete;
    ~bad_gmean() = default;
    bad_gmean &operator=(const bad_gmean &bh) = delete;
    bad_gmean &operator=(bad_gmean &&bh) = delete;

    virtual const char *what() const noexcept { return err_info.c_str(); }
  };

  double hmean(double a, double b);
  double gmean(double a, double b);

}
#endif
