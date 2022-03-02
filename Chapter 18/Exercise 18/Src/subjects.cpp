#include "subjects.h"

namespace subject01
{
}

namespace subject02
{
  Cpmv::Cpmv()
  {
    cout << "default constructor" << endl;
    pi = new Info;
    pi->qcode = "default qcode";
    pi->zcode = "defaule zcode";
  }

  Cpmv::Cpmv(string q, string z)
  {
    cout << "regular constructor" << endl;
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
  }

  Cpmv::Cpmv(const Cpmv &cp)
  {
    cout << "copy constructor" << endl;
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
  }

  Cpmv::Cpmv(Cpmv &&cp)
  {
    cout << "move constructor" << endl;
    pi = cp.pi;
    cp.pi = nullptr;
  }

  Cpmv::~Cpmv()
  {
    cout << "destructor" << endl;
    delete pi;
  }

  Cpmv &Cpmv::operator=(const Cpmv &cp)
  {
    cout << "copy operator assignment" << endl;
    if (&cp != this)
    {
      delete pi;
      pi = new Info;
      pi->qcode = cp.pi->qcode;
      pi->zcode = cp.pi->zcode;
    }
    return *this;
  }

  Cpmv &Cpmv::operator=(Cpmv &&cp)
  {
    cout << "move operator assignment" << endl;
    if (&cp != this)
    {
      pi = cp.pi;
      cp.pi = nullptr;
    }
    return *this;
  }

  Cpmv Cpmv::operator+(const Cpmv &obj) const
  {
    cout << "operator add" << endl;
    Cpmv temp;
    temp.pi = new Info;
    temp.pi->qcode = this->pi->qcode + obj.pi->qcode;
    temp.pi->zcode = this->pi->zcode + obj.pi->zcode;
    return temp;
  }

  void Cpmv::Display() const
  {
    cout << "Infomation of Cpmv's Object" << endl;
    cout << "pi->qcode: " << this->pi->qcode << endl;
    cout << "pi->zcode: " << this->pi->zcode << endl;
  }
}

namespace subject03
{
}

namespace subject04
{
}
