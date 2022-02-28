#ifndef SUBJECTS_H_
#define SUBJECTS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cctype>
#include <cstdlib>

namespace subject01
{
  using std::cout, std::cin, std::endl;
  using std::string;
  void GetInstreamCount();
}

namespace subject02
{
  using std::cout, std::cin, std::cerr, std::endl;
  using std::ofstream;

  void GetKeyboardInput2File(const char *file_name);
}

namespace subject03
{
  using std::cout, std::cin, std::cerr, std::endl;
  using std::ofstream, std::ifstream;

  void FileContentsTransfer(const char *file_out, const char *file_in);
}

namespace subject04
{
  using std::cout, std::cin, std::cerr, std::endl;
  using std::ofstream, std::ifstream;
  using std::string, std::getline;

  void FilesMerge(const char *file_in1, const char *file_in2, const char *file_out);
}

namespace subject05
{
  using std::cin, std::cout, std::cerr, std::endl;
  using std::ifstream, std::ofstream;
  using std::ostream_iterator;
  using std::sort, std::unique;
  using std::string, std::getline;
  using std::vector;

  class Person
  {
  private:
    string m_name;
    vector<string> m_friends;

  public:
    Person(const string &name) : m_name(name) {}
    Person(const Person &person) = default;
    Person(Person &&person) = default;
    ~Person() = default;
    Person &operator=(const Person &person) = default;
    Person &operator=(Person &&person) = default;

    Person &GetFriends();
    Person &ShowFriends();
    Person MergeFriends(const Person &person);
    Person &StoreFriends();

    Person operator+(const Person &person);
  };
}

namespace subject06
{
  using std::fstream, std::ifstream, std::ofstream;
  using std::ios_base;
  using std::isspace;
  using std::ostream, std::cout, std::endl, std::istream, std::cin, std::cerr;
  using std::string, std::stoi;
  using std::vector;

  class AbstrEmp
  {
  private:
    string m_first_name;
    string m_last_name;
    string m_job;

  public:
    AbstrEmp() : m_first_name("No"), m_last_name("Name"), m_job("No job") {}
    AbstrEmp(const string &first_name, const string &last_name, const string &job)
        : m_first_name(first_name), m_last_name(last_name), m_job(job) {}
    AbstrEmp(const AbstrEmp &abstr_emp) = default;
    AbstrEmp(AbstrEmp &&abstr_emp) = delete;
    virtual ~AbstrEmp() = 0;
    AbstrEmp &operator=(const AbstrEmp &abstr_emp) = default;
    AbstrEmp &operator=(AbstrEmp &&abstr_emp) = delete;

    virtual void ShowAll() const;
    virtual void SetAll();

    virtual bool SetAll(vector<string> &vec_str);
    virtual void SavetoFile(fstream &fout) const;

    // just display first and last name
    friend ostream &operator<<(ostream &os, const AbstrEmp &abstr_emp);
  };

  class Employee : public AbstrEmp
  {
  public:
    Employee() = default;
    Employee(const string &first_name, const string &last_name, const string &job)
        : AbstrEmp(first_name, last_name, job) {}
    Employee(const Employee &employee) = default;
    Employee(Employee &&employee) = delete;
    virtual ~Employee() = default;
    Employee &operator=(const Employee &employee) = default;
    Employee &operator=(Employee &&employee) = delete;

    virtual void SavetoFile(fstream &fout) const;
  };

  class Manager : virtual public AbstrEmp
  {
  private:
    int m_in_charge_of;

  protected:
    int M_InChargeof() const { return m_in_charge_of; }
    int &M_InChargeof() { return m_in_charge_of; }

  public:
    Manager() = default;
    Manager(const string first_name, const string last_name,
            const string job, int in_charge_of = 0)
        : AbstrEmp(first_name, last_name, job) { m_in_charge_of = in_charge_of; }
    Manager(const AbstrEmp &abstr_emp, int in_charge_of)
        : AbstrEmp(abstr_emp) { m_in_charge_of = in_charge_of; }
    Manager(const Manager &manager) = default;
    Manager(Manager &&manager) = delete;
    virtual ~Manager() = default;
    Manager &operator=(const Manager &manager) = default;
    Manager &operator=(Manager &&manager) = delete;

    virtual void ShowAll() const;
    virtual void SetAll();

    virtual bool SetAll(vector<string> &vec_str);
    virtual void SavetoFile(fstream &fout) const;
  };

  class Fink : virtual public AbstrEmp
  {
  private:
    string m_reports_to;

  protected:
    const string M_Reportsto() const { return m_reports_to; }
    string &M_Reportsto() { return m_reports_to; }

  public:
    Fink() = default;
    Fink(const string &first_name, const string &last_name,
         const string &job, const string &reports_to)
        : AbstrEmp(first_name, last_name, job) { m_reports_to = reports_to; }
    Fink(const AbstrEmp &emp, const string reports_to)
        : AbstrEmp(emp) { m_reports_to = reports_to; }
    Fink(const Fink &fink) = default;
    Fink(Fink &&fink) = delete;
    virtual ~Fink() = default;
    Fink &operator=(const Fink &fink) = default;
    Fink &operator=(Fink &&fink) = delete;

    virtual void ShowAll() const;
    virtual void SetAll();

    virtual bool SetAll(vector<string> &vec_str);
    virtual void SavetoFile(fstream &fout) const;
  };

  class HighFink : public Fink, public Manager
  {
  public:
    HighFink() = default;
    HighFink(const string &first_name, const string &last_name,
             const string &job, const string reports_to, int in_charge_of)
        : AbstrEmp(first_name, last_name, job),
          Fink(first_name, last_name, job, reports_to),
          Manager(first_name, last_name, job, in_charge_of) {}
    HighFink(const AbstrEmp &emp, const string reports_to, int in_charge_of)
        : AbstrEmp(emp), Fink(emp, reports_to), Manager(emp, in_charge_of) {}
    HighFink(const Fink &fink, int in_charge_of) : AbstrEmp(fink), Fink(fink),
                                                   Manager(fink, in_charge_of) {}
    HighFink(const Manager &manager, const string &reports_to)
        : AbstrEmp(manager), Fink(manager, reports_to), Manager(manager) {}
    HighFink(const HighFink &h) = default;
    HighFink(HighFink &&high_fink) = delete;
    virtual ~HighFink() = default;
    HighFink &operator=(const HighFink &high_fink) = default;
    HighFink &operator=(HighFink &&high_fink) = delete;

    virtual void ShowAll() const;
    virtual void SetAll();

    virtual bool SetAll(vector<string> &vec_str);
    virtual void SavetoFile(fstream &fout) const;
  };

  enum FileStatus
  {
    cEmpty,
    cNotEmpty,
    cDamage
  };
  FileStatus ReadFile(fstream &fin, vector<AbstrEmp *> &employee_vec);
  void WriteFile(fstream &fout, const vector<AbstrEmp *> &employee_vec);
  void ShowInfo(const vector<AbstrEmp *> &employee_vec);
  void SetInfo(vector<AbstrEmp *> &employee_vec);
}

namespace subject07
{
  using std::cout, std::cin, std::cerr, std::endl;
  using std::exit;
  using std::for_each;
  using std::ifstream, std::ofstream;
  using std::ios_base;
  using std::string, std::getline;
  using std::vector;

  void ShowStr(const string &str);

  class Store
  {
  private:
    ofstream &m_fout;

  public:
    Store() = delete;
    Store(ofstream &fout) : m_fout(fout) {}
    Store(const Store &) = default;
    Store(Store &&) = default;
    ~Store() = default;
    Store &operator=(const Store &) = default;
    Store &operator=(Store &&) = default;

    void operator()(const string &str);
  };

  void GetStrs(ifstream &fin, vector<string> &vec_str);
}

#endif
