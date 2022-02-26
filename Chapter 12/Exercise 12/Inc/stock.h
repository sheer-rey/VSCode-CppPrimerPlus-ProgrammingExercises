#ifndef STOCK_H_
#define STOCK_H_
#include <string>
#include <iostream>
using std::ostream, std::istream;

class Stock
{
private:
  char *company;
  int shares;
  double share_val;
  double total_val;
  void set_tot() { total_val = shares * share_val; }

public:
  Stock(const char *co = "No name", long n = 0, double pr = 0.0);
  ~Stock() { delete[] company; }
  void buy(long num, double price);
  void sell(long num, double price);
  void update(double price);
  const Stock &topval(const Stock &s) const;
  friend ostream &operator<<(ostream &os, const Stock &stock);
};

#endif
