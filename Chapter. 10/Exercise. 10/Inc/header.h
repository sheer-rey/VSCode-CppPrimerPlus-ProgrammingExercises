#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <cstring>

// Subject 01
class BankAccount01
{
private:
  std::string m_user_name;
  std::string m_account;
  double m_balance;

public:
  BankAccount01();
  BankAccount01(const std::string &user_name, const std::string &account, const double balance);
  void ShowBankAccount();
  void AccountDeposit(const double n);
  void AccountWithdraw(const double n);
};

// Subject 02
class Person02
{
private:
  static const int cLimit = 25;
  std::string m_first_name;
  char m_last_name[cLimit];

public:
  Person02()
  {
    m_first_name = "";
    m_last_name[0] = '\0';
  }
  Person02(const std::string &first_name, const char *last_name = "Hey you");
  void Show() const;       // firstname lastname format
  void FormalShow() const; // lastname firstname format
};

// Subject 03
class Golf03
{
private:
  static const int cLen = 40;
  char m_full_name[cLen];
  int m_handicap;

public:
  Golf03(const char *full_name = "TestNoName", const int handicap = 10);
  int SetGolf();
  void SetHandicap(int handicap);
  void ShowFullName() const { std::cout << m_full_name; }
  void ShowHandicap() const { std::cout << m_handicap; }
  void ShowGolf() const;
};

// Subject 04
namespace sales04
{
  const int cQuarters = 4;
  class Sales04
  {
  private:
    double m_sales[cQuarters];
    double m_average;
    double m_max;
    double m_min;

  public:
    Sales04();
    Sales04(const double ar[], int n);
    void ShowSales();
  };
}

// Subject 05
struct customer05
{
  char fullname[35];
  double payment;
};

typedef customer05 Item05;

class Stack05
{
private:
  enum
  {
    MAX = 10
  };                 // constant specific to class
  Item05 items[MAX]; // holds stack items
  int top;           // index for top stack item
public:
  Stack05();
  bool isempty() const;
  bool isfull() const;
  // push() returns false if stack already is full, true otherwise
  bool push(const Item05 &item); // add item to stack
  // pop() returns false if stack already is empty, true otherwise
  bool pop(Item05 &item); // pop top into item
};

// subject 06
class Move06
{
private:
  double x;
  double y;

public:
  Move06(double a = 0, double b = 0) : x(a), y(b) {} // sets x, y to a, b
  void showmove() const;                             // shows current x, y values
  Move06 add(const Move06 &m) const;
  void reset(double a = 0, double b = 0); // rsets x, y to a, b
};

// subject 07
class Plorg07
{
private:
  char m_name[20];
  int m_satisfication_index;

public:
  Plorg07(const char *name = "Plorga", const int satisfication_index = 50);
  Plorg07 &SetCI(int satisfication_index);
  void Show() const;
};

// subject 08
typedef int Item08;
class List08
{
private:
  Item08 m_list[20];
  unsigned m_max_size = 20;
  unsigned m_size;

public:
  List08() { m_size = 0; }
  List08 &Add(const Item08 &item);
  bool IsEmpty() { return !m_size; }
  bool IsFull() { return m_size == m_max_size ? true : false; }
  void Visit(void (*pf)(Item08 &));
};
void PrintItem08(Item08 &item);

#endif
