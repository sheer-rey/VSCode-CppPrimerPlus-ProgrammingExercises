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

#include "subject05.h"

namespace subject05
{
  /* Class AbstrEmp */
  AbstrEmp::~AbstrEmp()
  {
  }

  void AbstrEmp::ShowAll() const
  {
    cout << "Name: " << m_first_name << ' ' << m_last_name << endl;
    cout << "Job: " << m_job << endl;
  }

  void AbstrEmp::SetAll()
  {
    cout << "Enter the information below: " << endl;
    cout << "First Name: ";
    cin >> m_first_name;
    cout << "Last Name: ";
    cin >> m_last_name;
    cout << "Job: ";
    cin >> m_job;
  }

  ostream &operator<<(ostream &os, const AbstrEmp &abstr_emp) // just display first and last name
  {
    os << "Name: " << abstr_emp.m_first_name << ' ' << abstr_emp.m_last_name;
    return os;
  }

  /* Class Manager */
  void Manager::ShowAll() const
  {
    AbstrEmp::ShowAll();
    cout << "In Charge of: " << m_in_charge_of << endl;
  }

  void Manager::SetAll()
  {
    AbstrEmp::SetAll();
    cout << "In Charge of (integer): ";
    while (!(cin >> m_in_charge_of))
    {
      cout << "input error, reinput information of In Charge of (integer): ";
      cin.clear();
      cin.sync();
    }
  }

  /* Class Fink */
  void Fink::ShowAll() const
  {
    AbstrEmp::ShowAll();
    cout << "Reports to: " << m_reports_to << endl;
  }

  void Fink::SetAll()
  {
    AbstrEmp::SetAll();
    cout << "Reports to: ";
    cin >> m_reports_to;
  }

  /* Class HighFink */
  void HighFink::ShowAll() const
  {
    AbstrEmp::ShowAll();
    cout << "Reports to: " << M_Reportsto() << endl;
    cout << "In Charge of: " << M_InChargeof() << endl;
  }

  void HighFink::SetAll()
  {
    AbstrEmp::SetAll();
    cout << "Reports to: ";
    cin >> M_Reportsto();
    cout << "In Charge of (integer): ";
    while (!(cin >> M_InChargeof()))
    {
      cout << "input error, reinput information of In Charge of (integer): ";
      cin.clear();
      cin.sync();
    }
  }
}
