#ifndef SUBJECT06_H_
#define SUBJECT06_H_

#include <iostream>
#include <iterator>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>

namespace subject06
{
  using std::ostream, std::cout, std::cin, std::endl, std::ios_base;
  using std::ostream_iterator;
  using std::queue;
  using std::time;
  using std::unique, std::sort;

  // This queue will contain Customer items
  class Customer
  {
  private:
    long arrive;     // arrival time for customer
    int processtime; // processing time for customer
  public:
    Customer() : arrive(0), processtime(0) {}
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
  };
  typedef Customer Item;

  void BankSimulation();
}

#endif
