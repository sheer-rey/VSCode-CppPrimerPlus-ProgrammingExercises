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
    two_person.m_friends.erase(unique(two_person.m_friends.begin(), two_person.m_friends.end()), two_person.m_friends.end());

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

}

namespace subject07
{

}
