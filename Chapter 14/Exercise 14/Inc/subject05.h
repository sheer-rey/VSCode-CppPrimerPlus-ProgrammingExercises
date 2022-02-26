/* ****************************************************************************
 *                            Answers of Subject05
 * 1. There's six special memberfunctions in class (default constructor, copy
 *    constructor, move constructor, destructor, copy assignment operator and
 *    move assignment operator). while no definition in class but used them in
 *    code, the compiler will automatic generate the correspoinding definition.
 * 2. The pointer to base class can point to inheritance class’s object. The
 *    virtual function can select the corresponding function version according
 *    to the object type pointed by base class’s pointer. If there’s no virtual
 *    keyword in function declaration, the function will select the version by
 *    using the pointer’s type.
 * 3. The class abstr_emp derives two inheritance classes which is Fink and
 *    Manager, and class HighFink inherits from these two. In order to prevent
 *    class HighFink inherits two base class’s object entities by different path,
 *    we need to declare abstr_emp as virtual base class of class Fink and Manager.
 * 4. Class HighFink is derived from class Fink and Manager, and both two classes
 *    are derived from virtual base class abstr_emp. So class highfink has both
 *    three base class’s data members.
 * 5. Because base class’s pointer or reference can point to inheritance class’s
 *    object. In this case, the operator<< function can only access the base 
 *    class’s part of inheritance class’s object.
 * 6. The ShowAll function will only show name and job, in other words, program
 *    will always call base class’s ShowAll function. Because the first line of
 *    code snippets just define an array of objects of base class abstr_emp by
 *    copy constructor, not an array of pointers or references of base class.
 * ****************************************************************************/

#ifndef _SUBJECT05_H_
#define _SUBJECT05_H_

#include <iostream>
#include <string>

using std::ostream, std::cout, std::endl, std::istream, std::cin;
using std::string;

namespace subject05
{
  class AbstrEmp
  {
  private:
    string m_first_name;
    string m_last_name;
    string m_job;

  public:
    AbstrEmp() : m_first_name("No"), m_last_name("Name"), m_job("No job") {}
    AbstrEmp(const string &first_name, const string &last_name, const string &job) : m_first_name(first_name), m_last_name(last_name), m_job(job) {}
    AbstrEmp(const AbstrEmp &abstr_emp) = default;
    AbstrEmp(AbstrEmp &&abstr_emp) = delete;
    virtual ~AbstrEmp() = 0;
    AbstrEmp &operator=(const AbstrEmp &abstr_emp) = default;
    AbstrEmp &operator=(AbstrEmp &&abstr_emp) = delete;

    virtual void ShowAll() const;
    virtual void SetAll();

    friend ostream &operator<<(ostream &os, const AbstrEmp &abstr_emp); // just display first and last name
  };

  class Employee : public AbstrEmp
  {
  public:
    Employee() = default;
    Employee(const string &first_name, const string &last_name, const string &job) : AbstrEmp(first_name, last_name, job) {}
    Employee(const Employee &employee) = default;
    Employee(Employee &&employee) = delete;
    virtual ~Employee() = default;
    Employee &operator=(const Employee &employee) = default;
    Employee &operator=(Employee &&employee) = delete;

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
    Manager(const string first_name, const string last_name, const string job, int in_charge_of = 0) : AbstrEmp(first_name, last_name, job) { m_in_charge_of = in_charge_of; }
    Manager(const AbstrEmp &abstr_emp, int in_charge_of) : AbstrEmp(abstr_emp) { m_in_charge_of = in_charge_of; }
    Manager(const Manager &manager) = default;
    Manager(Manager &&manager) = delete;
    virtual ~Manager() = default;
    Manager &operator=(const Manager &manager) = default;
    Manager &operator=(Manager &&manager) = delete;

    virtual void ShowAll() const;
    virtual void SetAll();
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
    Fink(const string &first_name, const string &last_name, const string &job, const string &reports_to) : AbstrEmp(first_name, last_name, job) { m_reports_to = reports_to; }
    Fink(const AbstrEmp &emp, const string reports_to) : AbstrEmp(emp) { m_reports_to = reports_to; }
    Fink(const Fink &fink) = default;
    Fink(Fink &&fink) = delete;
    virtual ~Fink() = default;
    Fink &operator=(const Fink &fink) = default;
    Fink &operator=(Fink &&fink) = delete;

    virtual void ShowAll() const;
    virtual void SetAll();
  };

  class HighFink : public Fink, public Manager
  {
  public:
    HighFink() = default;
    HighFink(const string &first_name, const string &last_name, const string &job, const string reports_to, int in_charge_of) : AbstrEmp(first_name, last_name, job), Fink(first_name, last_name, job, reports_to), Manager(first_name, last_name, job, in_charge_of) {}
    HighFink(const AbstrEmp &emp, const string reports_to, int in_charge_of) : AbstrEmp(emp), Fink(emp, reports_to), Manager(emp, in_charge_of) {}
    HighFink(const Fink &fink, int in_charge_of) : AbstrEmp(fink), Fink(fink), Manager(fink, in_charge_of) {}
    HighFink(const Manager &manager, const string &reports_to) : AbstrEmp(manager), Fink(manager, reports_to), Manager(manager) {}
    HighFink(const HighFink &h) = default;
    HighFink(HighFink &&high_fink) = delete;
    virtual ~HighFink() = default;
    HighFink &operator=(const HighFink &high_fink) = default;
    HighFink &operator=(HighFink &&high_fink) = delete;

    virtual void ShowAll() const;
    virtual void SetAll();
  };
}

#endif