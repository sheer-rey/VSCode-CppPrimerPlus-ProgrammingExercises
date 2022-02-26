#include "header.h"

#include <iostream>
#include <string>
#include <cstring>

/* Menber Function */

// Subject 01
BankAccount01::BankAccount01()
{
  m_user_name = "Test No Name";
  m_account = "TestNoAccount";
  m_balance = 520;
}

BankAccount01::BankAccount01(const std::string &user_name, const std::string &account, const double balance)
{
  m_user_name = user_name;
  m_account = account;
  m_balance = balance;
}

void BankAccount01::ShowBankAccount()
{
  using namespace std;
  cout << "\nBank Account Infomation" << endl;
  cout << "username: " << m_user_name << endl;
  cout << "account: " << m_account << endl;
  cout << "balance: " << m_balance << endl;
}

void BankAccount01::AccountDeposit(const double n)
{
  m_balance += n;
}

void BankAccount01::AccountWithdraw(const double n)
{
  m_balance -= n;
}

// Subject 02
Person02::Person02(const std::string &first_name, const char *last_name)
{
  m_first_name = first_name;
  strcpy(m_last_name, last_name);
}

void Person02::Show() const // firstname lastname format
{
  std::cout << "\nName: " << m_first_name << " " << m_last_name << std::endl;
}
void Person02::FormalShow() const // lastname firstname format
{
  std::cout << "\nName: " << m_last_name << " " << m_first_name << std::endl;
}

// Subject 03
Golf03::Golf03(const char *full_name, const int handicap)
{
  strcpy(m_full_name, full_name);
  m_handicap = handicap;
}

int Golf03::SetGolf()
{
  using std::cout, std::cin, std::endl;
  char name[Golf03::cLen];
  int handicap;
  cout << "Please enter your name (empty line to quit):";
  cin.get(name, Golf03::cLen).get();
  if (!cin)
  {
    cin.clear();
    cin.sync();
    cout << "quit!" << endl;
    return 0;
  }
  cout << "Please enter your handicap (integer): ";
  cin >> handicap;
  while (!cin)
  {
    cin.clear();
    cin.sync();
    cout << "Input error! Renter your handicap (integer): ";
    cin >> handicap;
  }
  cin.clear();
  cin.sync();
  Golf03 temperary_golf(name, handicap);
  *this = temperary_golf;
  return 1;
}

void Golf03::SetHandicap(int handicap)
{
  m_handicap = handicap;
}

void Golf03::ShowGolf() const
{
  std::cout << "Fullname: " << m_full_name << "\tHandicap: " << m_handicap << std::endl;
}

// Subject 04
sales04::Sales04::Sales04(const double sales[], int n)
{
  int i;
  m_max = m_min = *sales;
  m_average = 0;
  for (i = 0; i < n && i < cQuarters; i++)
  {
    m_sales[i] = sales[i];
    if (sales[i] > m_max)
      m_max = sales[i];
    if (sales[i] < m_min)
      m_min = sales[i];
    m_average += sales[i] / cQuarters;
  }
  while (i < cQuarters)
  {
    m_sales[i] = 0;
    if (sales[i] > m_max)
      m_max = sales[i];
    if (sales[i] < m_min)
      m_min = sales[i];
    i++;
  }
}

sales04::Sales04::Sales04()
{
  using namespace std;
  cout << "Please enter quarters' revenue: ";
  m_max = m_average = 0;
  m_min = -1;
  for (int i = 0; i < cQuarters; i++)
  {
    cin >> m_sales[i];

    /* Error Check begin */
    while (!cin || m_sales[i] < 0)
    {
      cin.clear();
      cin.sync();
      cout << "\nInput error! Renter quarters' revenue: ";
      m_max = m_average = 0;
      m_min = -1;
      i = -1;
    }
    if (i == -1)
      continue;
    /* Error Check end */

    if (m_sales[i] > m_max)
      m_max = m_sales[i];
    if (m_sales[i] < m_min && m_min >= 0)
      m_min = m_sales[i];
    else if (m_min == -1)
      m_min = m_sales[i];
    m_average += m_sales[i] / cQuarters;
  }
}

void sales04::Sales04::ShowSales()
{
  using namespace std;
  cout << "Quarters' sales are as below" << endl;
  for (int i = 0; i < cQuarters; i++)
    cout << "Season " << i + 1 << ": " << m_sales[i] << "\t";
  cout << "\nMaximum: " << m_max << "\tMinimum: " << m_min << "\tAverage: " << m_average << endl;
}

// Subject 05
Stack05::Stack05() // create an empty stack
{
  top = 0;
}

bool Stack05::isempty() const
{
  return top == 0;
}

bool Stack05::isfull() const
{
  return top == MAX;
}

bool Stack05::push(const Item05 &item)
{
  if (top < MAX)
  {
    items[top++] = item;
    return true;
  }
  else
    return false;
}

bool Stack05::pop(Item05 &item)
{
  if (top > 0)
  {
    item = items[--top];
    return true;
  }
  else
    return false;
}

// subject 06
void Move06::showmove() const
{
  std::cout << "current x, y value is: (" << x << ", " << y << ")" << std::endl;
}

Move06 Move06::add(const Move06 &m) const
{
  Move06 temporary;
  temporary.x = x + m.x;
  temporary.y = y + m.y;
  return temporary;
}

void Move06::reset(double a, double b)
{
  x = a;
  y = b;
}

// subject 07
Plorg07::Plorg07(const char *name, const int satisfication_index)
{
  strncpy(m_name, name, 19);
  m_name[19] = 0;
  m_satisfication_index = satisfication_index;
}

Plorg07 &Plorg07::SetCI(int satisfication_index)
{
  m_satisfication_index = satisfication_index;
  return *this;
}

void Plorg07::Show() const
{
  std::cout << "Plorg Information" << std::endl;
  std::cout << "name: " << m_name
            << "\t satisfication index: " << m_satisfication_index << std::endl;
}

// subject 08
List08 &List08::Add(const Item08 &item)
{
  m_list[m_size++] = item;
  return *this;
}

void List08::Visit(void (*pf)(Item08 &))
{
  for (unsigned i = 0; i < m_size; i++)
    pf(m_list[i]);
}

void PrintItem08(Item08 &item)
{
  std::cout << item << '\t';
}
