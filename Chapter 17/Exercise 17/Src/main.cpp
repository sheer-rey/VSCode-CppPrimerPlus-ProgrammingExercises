/*******************************************************************************
 * @attention
 * Subject 02 and 03 required use the file name specified by command prompt.
 * In this exercise programme, you need to specify all file names as subject02
 * and 03 asked with in only one piece of command line.
 *
 * @example
 * The command line may be like below:
 * $ ./Exercise\ 17.exe ./Files/subject02.txt ./Files/subject03.txt
 * or
 * $ ./Exercise\ 17 ./Files/subject02.txt ./Files/subject03.txt
 * ****************************************************************************/

#include <iostream>
#include "subjects.h"
#include <ios>

int main(int argc, const char *argv[])
{
    // command check
    if (argc < 3)
    {
        std::cerr << "Arguments are not enough for executing!" << std::endl;
        std::cerr << "Programme Terminated!" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Subject 01
    std::cout << "Subject 01" << std::endl;
    {
        using namespace subject01;
        GetInstreamCount();
    }
    std::cin.sync();
    std::cout << "\nPress any key to continue." << std::endl;
    std::cin.get();

    // Subject 02
    std::cout << "Subject 02" << std::endl;
    {
        using namespace subject02;
        GetKeyboardInput2File(argv[1]);
    }
    std::cin.sync();
    std::cout << "\nPress any key to continue." << std::endl;
    std::cin.get();

    // Subject 03
    std::cout << "Subject 03" << std::endl;
    {
        using namespace subject03;
        FileContentsTransfer(argv[1], argv[2]);
    }
    std::cin.sync();
    std::cout << "\nPress any key to continue." << std::endl;
    std::cin.get();

    // Subject 04
    std::cout << "Subject 04" << std::endl;
    {
        using namespace subject04;
        FilesMerge(argv[1], argv[2], "./Files/subject04.txt");
    }
    std::cin.sync();
    std::cout << "\nPress any key to continue." << std::endl;
    std::cin.get();

    // Subject 05
    std::cout << "Subject 05" << std::endl;
    {
        using namespace subject05;
        Person mat("Mat"), pat("Pat");
        mat.GetFriends().ShowFriends();
        pat.GetFriends().ShowFriends();
        mat.MergeFriends(pat).StoreFriends();
    }
    std::cin.sync();
    std::cout << "\nPress any key to continue." << std::endl;
    std::cin.get();

    // Subject 06
    std::cout << "Subject 06" << std::endl;
    {
        using namespace subject06;
        bool skip = false;
        const char *file_name = "./Files/subject06.dat";
        fstream finout(file_name, ios_base::in | ios_base::out);
        if (!finout.is_open())
        {
            cerr << "Open file \"" << file_name << "\" failed." << endl;
            cerr << "Skipeed subject06." << endl;
            skip = true;
        }
        else
            cout << "Open file \"" << file_name << "\" successful!" << endl;

        vector<AbstrEmp *> employee_vec;
        switch (ReadFile(finout, employee_vec))
        {
        case cEmpty:
            cout << "File is empty!" << endl;
            break;

        case cNotEmpty:
            cout << endl;
            cout << "Employee infomations in file are as below: " << endl;
            ShowInfo(employee_vec);
            break;

        default:
            cout << "Skipped subject06." << endl;
            skip = true;
            break;
        }

        if (!skip)
        {
            vector<AbstrEmp *> add_employee_vec;
            SetInfo(add_employee_vec);
            WriteFile(finout, add_employee_vec);
            for (auto x : add_employee_vec)
                employee_vec.push_back(x);
            cout << endl;
            cout << "All employee infomations are as below: " << endl;
            ShowInfo(employee_vec);
        }
        for (auto x : employee_vec)
            delete x;
    }
    std::cin.sync();
    std::cout << "\nPress any key to continue." << std::endl;
    std::cin.get();

    // Subject 07
    std::cout << "Subject 07" << std::endl;
    {
        using namespace subject07;
        vector<string> vec_str;
        string temp;

        // acquire strings
        cout << "Enter strings (empty line to quit): " << endl;
        while (getline(cin, temp) && temp[0] != '\0')
            vec_str.push_back(temp);
        cout << "Here is your input." << endl;
        for_each(vec_str.begin(), vec_str.end(), ShowStr);

        // store in file
        ofstream fout("./Files/subject07.dat", ios_base::out | ios_base::binary | ios_base::app);
        if (!fout.is_open())
        {
            cerr << "Could not open file \"./Files/subject07.dat\"." << endl;
            exit(EXIT_FAILURE);
        }
        for_each(vec_str.begin(), vec_str.end(), Store(fout));
        fout.close();

        // recover file contents
        vector<string> vec_str_bak;
        ifstream fin("./Files/subject07.dat", ios_base::in | ios_base::binary);
        if (!fin.is_open())
        {
            cerr << "Could not open file \"./Files/subject07.dat\"." << endl;
            exit(EXIT_FAILURE);
        }
        GetStrs(fin, vec_str_bak);
        cout << "\nHere are the strings read from the file:" << endl;
        for_each(vec_str_bak.begin(), vec_str_bak.end(), ShowStr);
    }

    return 0;
}
