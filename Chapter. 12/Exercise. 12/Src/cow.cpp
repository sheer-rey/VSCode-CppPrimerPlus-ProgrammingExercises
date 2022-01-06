#include "cow.h"

Cow::Cow()
{
  strcpy(m_name, "No name");
  m_hobby = new char[20];
  strcpy(m_hobby, "No hobby");
  m_weight = 0;
}

Cow::Cow(const char *name, const char *hobby, double weight)
{
  strncpy(m_name, name, 19);
  m_name[19] = 0;
  m_hobby = new char[sizeof(hobby)];
  strcpy(m_hobby, hobby);
  m_weight = weight;
}

Cow::Cow(const Cow &cow)
{
  strcpy(m_name, cow.m_name);
  m_hobby = new char[sizeof(cow.m_hobby)];
  strcpy(m_hobby, cow.m_hobby);
  m_weight = cow.m_weight;
}

Cow::~Cow()
{
  delete[] m_hobby;
}

Cow &Cow::operator=(const Cow &cow)
{
  if (&cow != this)
  {
    // delete origin memery
    delete[] m_hobby;
    strcpy(m_name, cow.m_name);
    m_hobby = new char[sizeof(cow.m_hobby)];
    strcpy(m_hobby, cow.m_hobby);
    m_weight = cow.m_weight;
  }
  return *this;
}

void Cow::ShowCow() const
{
  cout << "name: " << m_name << endl;
  cout << "hobby: " << m_hobby << endl;
  cout << "weight: " << m_weight << endl;
}
