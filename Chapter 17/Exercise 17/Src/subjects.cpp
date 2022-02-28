#include "subjects.h"

namespace subject01
{
  void GetInstreamCount()
  {
    cout << "Enter series of characters with the end of '$':" << endl;
    string str;
    int count = 0;
    while (cin.peek() != '$')
    {
      str.push_back(char(cin.get()));
      count++;
    }
    cout << "You have entered " << count << " characters as below: " << endl;
    cout << str << endl;
  }
}

namespace subject02
{
  void GetKeyboardInput2File(const char *file_name)
  {
    ofstream fout(file_name, std::ios_base::out | std::ios_base::trunc);
    if (!fout.is_open())
    {
      cerr << "Open file \"" << file_name << "\" failed." << endl;
      cerr << "Subject02 skiped." << endl;
      return;
    }
    cout << "Open file \"" << file_name << "\" successful!" << endl;
    cout << "Enter series of characters with the end of simulative EOF:" << endl;
    while (cin.peek() != EOF)
      fout << char(cin.get());
    fout.close();
    cin.sync();
    cin.clear();
    cout << "Done!" << endl;
  }
}

namespace subject03
{
  void FileContentsTransfer(const char *file_in, const char *file_out)
  {
    ifstream fin(file_in, std::ios_base::in);
    ofstream fout(file_out, std::ios_base::out | std::ios_base::trunc);
    if (!(fout.is_open() && fin.is_open()))
    {
      if (!fin.is_open())
        cerr << "Open file \"" << file_in << "\" failed." << endl;
      if (!fout.is_open())
        cerr << "Open file \"" << file_out << "\" failed." << endl;
      cerr << "Subject03 skiped." << endl;
      return;
    }
    cout << "Open file \"" << file_in << "\" and \""
         << file_out << "\" successful!" << endl;
    cout << "Transfering contents from \"" << file_in << "\" to \""
         << file_out << "..." << endl;
    while (fin.peek() != EOF)
      fout << char(fin.get());
    fout.close();
    fin.clear();
    fin.close();
    cout << "Done!" << endl;
  }
}

namespace subject04
{
  void FilesMerge(const char *file_in1, const char *file_in2,
                  const char *file_out)
  {
    ifstream fin1(file_in1, std::ios_base::in);
    ifstream fin2(file_in2, std::ios_base::in);
    ofstream fout(file_out, std::ios_base::out | std::ios_base::trunc);
    if (!(fin1.is_open() && fin2.is_open() && fout.is_open()))
    {
      if (!fin1.is_open())
        cerr << "Open file \"" << file_in1 << "\" failed." << endl;
      if (!fin2.is_open())
        cerr << "Open file \"" << file_in1 << "\" failed." << endl;
      if (!fout.is_open())
        cerr << "Open file \"" << file_out << "\" failed." << endl;
      cerr << "Subject04 skiped." << endl;
      return;
    }
    cout << "Open file \"" << file_in1 << "\", \"" << file_in2 << "\" and \""
         << file_out << "\" successful!" << endl;
    cout << "Merge contents from \"" << file_in1 << "\" and \"" << file_in2
         << "\" to \"" << file_out << "..." << endl;

    string str1, str2;
    while (fin1.good() || fin2.good())
    {
      if (fin1.peek() != EOF)
      {
        while (fin1.peek() != '\n')
          str1.push_back(fin1.get());
        fin1.get();
      }
      else
        fin1.clear(std::ios_base::eofbit);

      if (fin2.peek() != EOF)
      {
        while (fin2.peek() != '\n')
          str2.push_back(fin2.get());
        fin2.get();
      }
      else
        fin2.clear(std::ios_base::eofbit);

      if (fin1.good() && fin2.good())
      {
        fout << (str1 + " " + str2) << endl;
        // cout << "merge 1 2" << endl;
      }
      else if (fin1.good())
      {
        fout << str1 << endl;
        // cout << "copy 1" << endl;
      }
      else if (fin2.good())
      {
        fout << str2 << endl;
        // cout << "copy 2" << endl;
      }

      str1.clear();
      str2.clear();
    }

    fin1.clear();
    fin2.clear();
    fin1.close();
    fin2.close();
    fout.close();
    cout << "Done!" << endl;
  }
}

namespace subject05
{
  Person &Person::GetFriends()
  {
    ifstream fin("./Files/" + m_name + ".dat");
    if (!fin.is_open())
    {
      cerr << "Open file \"" << m_name << ".dat\" failed." << endl;
      return *this;
    }
    cout << "Open file \"" << m_name << ".dat\" successful!" << endl;

    string friend_name;
    while (fin.good())
    {
      if (fin.peek() != EOF)
      {
        getline(fin, friend_name);
        m_friends.push_back(friend_name);
      }
      else
      {
        // fin.exceptions(std::ios_base::goodbit);
        fin.clear(std::ios_base::eofbit);
      }
    }
    fin.clear();
    fin.close();

    sort(m_friends.begin(), m_friends.end());
    m_friends.erase(unique(m_friends.begin(), m_friends.end()), m_friends.end());
    cout << "Done!" << endl;
    return *this;
  }

  Person &Person::ShowFriends()
  {
    ostream_iterator<string> os_it(cout, " ");
    cout << m_name << "'s friends are as follow: ";
    for (const auto &x : m_friends)
      *os_it = x;
    cout << endl;
    return *this;
  }

  Person Person::MergeFriends(const Person &person)
  {
    Person two_person(this->m_name + " and " + person.m_name);
    two_person.m_friends = m_friends;
    for (const string &x : person.m_friends)
      two_person.m_friends.push_back(x);

    sort(two_person.m_friends.begin(), two_person.m_friends.end());
    two_person.m_friends.erase(unique(two_person.m_friends.begin(),
                                      two_person.m_friends.end()),
                               two_person.m_friends.end());

    return two_person;
  }

  Person &Person::StoreFriends()
  {
    string file_name;
    for (char x : m_name)
      if (x == ' ')
        file_name.push_back('_');
      else
        file_name.push_back(x);

    ofstream fout("./Files/" + file_name + ".dat");
    if (!fout.is_open())
    {
      cerr << "Open file \"" << file_name << ".dat\" failed." << endl;
      return *this;
    }
    cout << "Open file \"" << file_name << ".dat\" successful!" << endl;

    ostream_iterator<string> os_it(fout, "\n");
    for (const auto &x : m_friends)
      *os_it = x;
    fout.close();
    cout << "Done!" << endl;

    return *this;
  }

  Person Person::operator+(const Person &person)
  {
    Person two_person(this->m_name + " and " + person.m_name);
    two_person.m_friends = m_friends;
    for (const string &x : person.m_friends)
      two_person.m_friends.push_back(x);

    sort(two_person.m_friends.begin(), two_person.m_friends.end());
    two_person.m_friends.erase(unique(two_person.m_friends.begin(), two_person.m_friends.end()), two_person.m_friends.end());

    return two_person;
  }
}

namespace subject06
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

  bool AbstrEmp::SetAll(vector<string> &vec_str)
  {
    if (vec_str.size() < 3)
      return false;
    m_first_name = vec_str[0];
    m_last_name = vec_str[1];
    m_job = vec_str[2];
    return true;
  }

  void AbstrEmp::SavetoFile(fstream &fout) const
  {
    fout << m_first_name << endl;
    fout << m_last_name << endl;
    fout << m_job << endl;
  }

  // just display first and last name
  ostream &operator<<(ostream &os, const AbstrEmp &abstr_emp)
  {
    os << "Name: " << abstr_emp.m_first_name << ' ' << abstr_emp.m_last_name;
    return os;
  }

  /* Class Employee */
  void Employee::SavetoFile(fstream &fout) const
  {
    fout << "Employee" << endl;
    AbstrEmp::SavetoFile(fout);
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

  bool Manager::SetAll(vector<string> &vec_str)
  {
    if (vec_str.size() < 4)
      return false;
    AbstrEmp::SetAll(vec_str);
    m_in_charge_of = stoi(vec_str[3]);
    return true;
  }

  void Manager::SavetoFile(fstream &fout) const
  {
    fout << "Manager" << endl;
    AbstrEmp::SavetoFile(fout);
    fout << m_in_charge_of << endl;
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

  bool Fink::SetAll(vector<string> &vec_str)
  {
    if (vec_str.size() < 4)
      return false;
    AbstrEmp::SetAll(vec_str);
    m_reports_to = vec_str[3];
    return true;
  }

  void Fink::SavetoFile(fstream &fout) const
  {
    fout << "Fink" << endl;
    AbstrEmp::SavetoFile(fout);
    fout << m_reports_to << endl;
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

  bool HighFink::SetAll(vector<string> &vec_str)
  {
    if (vec_str.size() < 5)
      return false;
    AbstrEmp::SetAll(vec_str);
    M_InChargeof() = stoi(vec_str[3]);
    M_Reportsto() = vec_str[4];
    return true;
  }

  void HighFink::SavetoFile(fstream &fout) const
  {
    fout << "HighFink" << endl;
    AbstrEmp::SavetoFile(fout);
    fout << M_InChargeof() << endl;
    fout << M_Reportsto() << endl;
  }

  FileStatus ReadFile(fstream &fin, vector<AbstrEmp *> &employee_vec)
  {
    while (isspace(fin.peek()))
      fin.get();
    if (fin.peek() == EOF)
    {
      fin.clear();
      return cEmpty;
    }
    else
    {
      cout << "Reading file..." << endl;
      AbstrEmp *temp;
      string str;
      vector<string> obj_info;
      int info_number;
      while (getline(fin, str))
      {
        if (str.size()) // not an empty line
        {
          if (str == "Employee")
          {
            temp = new Employee;
            info_number = 3;
          }
          else if (str == "Manager")
          {
            temp = new Manager;
            info_number = 4;
          }
          else if (str == "Fink")
          {
            temp = new Fink;
            info_number = 4;
          }
          else if (str == "HighFink")
          {
            temp = new HighFink;
            info_number = 5;
          }
          else
          {
            cerr << "Data file damaged!" << endl;
            return cDamage;
          }

          // Extract object's information
          for (int i = 0; i < info_number; i++)
          {
            getline(fin, str);
            if (fin)
              obj_info.push_back(str);
            else
            {
              cerr << "Data file damaged!" << endl;
              return cDamage;
            }
          }
          temp->SetAll(obj_info);
          obj_info.clear();
          // store boject's pointer
          employee_vec.push_back(temp);
        }
        else
          continue;
      }

      if (fin.eof())
      {
        cout << "Reading file done!" << endl;
        fin.clear();
        return cNotEmpty;
      }
      else
      {
        cerr << "Data file damaged!" << endl;
        fin.clear();
        return cDamage;
      }
    }
  }

  void WriteFile(fstream &fout, const vector<AbstrEmp *> &employee_vec)
  {
    if (employee_vec.size())
    {
      cout << "Writing file..." << endl;
      fout.seekp(0, ios_base::end);
      for (auto x : employee_vec)
      {
        fout << endl;
        x->SavetoFile(fout);
      }
      cout << "Writing file done." << endl;
    }
  }

  void ShowInfo(const vector<AbstrEmp *> &employee_vec)
  {
    for (AbstrEmp *x : employee_vec)
    {
      x->ShowAll();
      cout << endl;
    }
  }

  void SetInfo(vector<AbstrEmp *> &employee_vec)
  {
    cout << "Which category's infomation you want to input? (q to quit)" << endl;
    cout << "e: employee        m: manager" << endl;
    cout << "f: fink            h: highfink" << endl;
    char c;
    cin >> c;
    AbstrEmp *temp;
    bool error_flag = false;
    while (c != 'q')
    {
      switch (c)
      {
      case 'e':
        temp = new Employee;
        break;

      case 'm':
        temp = new Manager;
        break;

      case 'f':
        temp = new Fink;
        break;

      case 'h':
        temp = new HighFink;
        break;

      default:
        cout << "input error!" << endl;
        error_flag = true;
        break;
      }
      if (error_flag)
        error_flag = false;
      else
      {
        temp->SetAll();
        employee_vec.push_back(temp);
      }
      cout << endl;
      cout << "Okay, which category's infomation next you want to input? (q to quit)" << endl;
      cout << "e: employee        m: manager" << endl;
      cout << "f: fink            h: highfink" << endl;
      cin >> c;
    }
    cout << "Done!" << endl;
  }
}

namespace subject07
{
  void ShowStr(const string &str)
  {
    cout << str << endl;
  }

  void Store::operator()(const string &str)
  {
    long str_lenth = str.size();
    m_fout.write((char *)(&str_lenth), sizeof(str_lenth));
    m_fout.write(str.data(), str.size());
  }

  void GetStrs(ifstream &fin, vector<string> &vec_str)
  {
    long str_lenth;
    char *str;
    fin.read((char *)&str_lenth, sizeof(str_lenth));
    while (fin)
    {
      str = new char[str_lenth + 1];
      str[str_lenth] = 0;
      fin.read(str, str_lenth);
      vec_str.push_back(string(str));
      delete str;
      fin.read((char *)&str_lenth, sizeof(str_lenth));
    }
  }
}
