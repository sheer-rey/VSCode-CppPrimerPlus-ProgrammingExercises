#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    // Subject 01
    cout << "Subject 01" << endl;
    cout << "Please enter a serise of letter, end with '@': " << endl;
    string str_1 = {};
    char ch;
    while (cin.get(ch))
    {
        if (ch != '@')
            str_1 += ch;
        else
            break;
    }
    if (!cin)
    {
        cerr << "Unexpected Error!" << endl;
        cin.sync();
    }
    else
    {
        for (char x : str_1)
        {
            if (isdigit(x))
                continue;
            else if (isalpha(x))
            {
                if (islower(x))
                    cout << char(toupper(x));
                else if (isupper(x))
                    cout << char(tolower(x));
            }
            else
                cout << x;
        }
        cout << endl;
    }
    cin.sync();

    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 02
    cout << "Subject 02" << endl;
    cout << "Please enter at most 10 donations: ";
    const int iMaxSize_2 = 10;
    array<double, iMaxSize_2> arrDonation_2 = {0};
    double dSum_2 = 0;
    int iNumber_2 = 0;
    for (auto &x : arrDonation_2)
        if (cin >> x)
        {
            dSum_2 += x;
            iNumber_2++;
        }
        else
            break;
    dSum_2 /= iNumber_2;
    cout << "The average value of the input is " << dSum_2 << ", ";
    iNumber_2 = 0;
    for (auto x : arrDonation_2)
        if (x > dSum_2)
            iNumber_2++;
    cout << "and there're " << iNumber_2 << " values greater than average." << endl;
    if (!cin)
    {
        cin.clear();
        cin.sync();
    }

    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 03
    cout << "Subject 03" << endl;
    cout << "Please enter one of the following choices: " << endl;
    cout << "c) carnivore\t\tp) pianist" << endl;
    cout << "t) tree\t\t\tg) game" << endl;
    char cEnter_3;
    cin >> cEnter_3;
    cin.sync();
    while (cEnter_3 != 'c' && cEnter_3 != 'p' && cEnter_3 != 't' && cEnter_3 != 'g')
    {
        cout << "Please enter 'c', 'p', 't' or 'g': ";
        cin >> cEnter_3;
        cin.sync();
    }
    cout << "A maple is a ";
    switch (cEnter_3)
    {
    case 'c':
        cout << "carnivore." << endl;
        break;
    case 'p':
        cout << "pianist." << endl;
        break;
    case 't':
        cout << "tree." << endl;
        break;
    case 'g':
        cout << "game." << endl;
    }

    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 04
    cout << "Subject 04" << endl;
    const int iSTRSIZE = 20;
    struct bop_4
    {
        char cFullName[iSTRSIZE]; // real name
        char cTitle[iSTRSIZE];    // job title
        char cBopName[iSTRSIZE];  // secret BOP name
        int iPreference;          // 0 = fullname, 1 = title, 2 = bopname
    };
    // Initialization
    bop_4 bopBopMember_4[2] = {{"Edward", "Husband", "sheer.rey", 2}, {"W+0", "Wife", "Isabella", 0}};
    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name\tb. display by title" << endl;
    cout << "c. display by bopname\td. display by preference" << endl;
    cout << "q. quit" << endl;
    cout << "Please enter your choice: ";
    char cChoice_4;
    cin >> cChoice_4;
    cin.sync();
    while (cChoice_4 != 'q')
    {
        switch (cChoice_4)
        {
        case 'a':
            for (auto x : bopBopMember_4)
                cout << x.cFullName << endl;
            cout << "Next choice: ";
            break;
        case 'b':
            for (auto x : bopBopMember_4)
                cout << x.cTitle << endl;
            cout << "Next choice: ";
            break;
        case 'c':
            for (auto x : bopBopMember_4)
                cout << x.cBopName << endl;
            cout << "Next choice: ";
            break;
        case 'd':
            for (auto x : bopBopMember_4)
                switch (x.iPreference)
                {
                case 0:
                    cout << x.cFullName << endl;
                    break;
                case 1:
                    cout << x.cTitle << endl;
                    break;
                case 2:
                    cout << x.cBopName << endl;
                }
            cout << "Next choice: ";
            break;
        default:
            cout << "Please enter your choice (with 'a', 'b', 'c', 'd' or 'q'): ";
        }
        cin >> cChoice_4;
        cin.sync();
    }
    cout << "Bye!" << endl;

    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 05
    cout << "Subject 05" << endl;
    cout << "Please enter your income(tvarps): ";
    float iIncome_5;
    cin >> iIncome_5;
    while (cin && iIncome_5 >= 0)
    {
        if (iIncome_5 <= 5000)
            cout << "Your individual income tax is 0 tvarps." << endl;
        else if (iIncome_5 > 5000 && iIncome_5 <= 15000)
            cout << "Your individual income tax is " << (iIncome_5 - 5000) * 0.1 << " tvarps." << endl;
        else if (iIncome_5 > 15000 && iIncome_5 <= 35000)
            cout << "Your individual income tax is " << (iIncome_5 - 15000) * 0.15 + 1000 << " tvarps." << endl;
        else
            cout << "Your individual income tax is " << (iIncome_5 - 35000) * 0.2 + 4000 << " tvarps." << endl;
        cout << "Please enter your income(tvarps): ";
        cin >> iIncome_5;
    }
    if (!cin)
    {
        cin.clear();
        cin.sync();
    }
    else
        cin.get();
    cout << "Calculation end!" << endl;

    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 06
    cout << "Subject 06" << endl;
    cout << "Please enter the number of donator: ";
    int iNumberofDonator_6;
    (cin >> iNumberofDonator_6).sync();
    struct donator_6
    {
        string strName;
        double dAmount;
    };
    donator_6 *dntDonators_6 = new donator_6[iNumberofDonator_6];
    for (int i = 0; i < iNumberofDonator_6; i++)
    {
        cout << "Please enter the donator's name: ";
        getline(cin, dntDonators_6[i].strName);
        cout << "Please enter the donator's donation amount($): ";
        cin >> dntDonators_6[i].dAmount;
        cin.get();
    }
    cout << "List of Grand Patrons" << endl;
    bool bStatus_6 = false;
    for (int i = 0; i < iNumberofDonator_6; i++)
        if (dntDonators_6[i].dAmount > 10000)
        {
            bStatus_6 = true;
            cout << dntDonators_6[i].strName << "\t$" << dntDonators_6[i].dAmount << endl;
        }
    if (!bStatus_6)
    {
        cout << "none" << endl;
        bStatus_6 = false;
    }
    cout << "List of Patrons" << endl;
    for (int i = 0; i < iNumberofDonator_6; i++)
        if (dntDonators_6[i].dAmount <= 10000)
        {
            bStatus_6 = true;
            cout << dntDonators_6[i].strName << "\t";
        }
    if (!bStatus_6)
        cout << "none" << endl;
    delete[] dntDonators_6;
    cin.sync();

    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 07
    cout << "Subject 07" << endl;
    cout << "Enter words (q to quit) : " << endl;
    string strWords_7;
    cin >> strWords_7;
    int iNumofVowels_7 = 0, iNumofConsonants_7 = 0, iNumofOthers_7 = 0;
    while (strWords_7 != "q")
    {
        if (isalpha(strWords_7.at(0)))
            if (strWords_7.at(0) == 'a' || strWords_7.at(0) == 'e' || strWords_7.at(0) == 'i' || strWords_7.at(0) == 'o' || strWords_7.at(0) == 'u' || strWords_7.at(0) == 'A' || strWords_7.at(0) == 'E' || strWords_7.at(0) == 'I' || strWords_7.at(0) == 'O' || strWords_7.at(0) == 'U')
                iNumofVowels_7++;
            else
                iNumofConsonants_7++;
        else
            iNumofOthers_7++;
        cin >> strWords_7;
    }
    cout << iNumofVowels_7 << " words beginning with vowels." << endl;
    cout << iNumofConsonants_7 << " words beginning with consonants." << endl;
    cout << iNumofOthers_7 << " others." << endl;

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 08
    cout << "Subject 08" << endl;
    ifstream ifsInFile_8;
    ifsInFile_8.open(R"(../Files/Subject_08.txt)");
    if (!ifsInFile_8.is_open())
    {
        cout << "Could not open file \"Subject_08.txt\"\nProgramme Terminated." << endl;
        exit(EXIT_FAILURE);
    }
    char cInVal_8;
    ifsInFile_8 >> cInVal_8;
    int iAlphaNum = 0;
    while (!ifsInFile_8.eof())
    {
        if (isalpha(cInVal_8))
            iAlphaNum++;
        ifsInFile_8 >> cInVal_8;
    }
    cout << "There's " << iAlphaNum << " alphabetical characters in file \"Subject_08.txt\"." << endl;

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 09
    cout << "Subject 09" << endl;
    ifstream ifsInFile_9;
    ifsInFile_9.open(R"(../Files/Subject_09)");
    if (!ifsInFile_9.is_open())
    {
        cout << "Could not open file \"Subject_09\"\nProgramme Terminated." << endl;
        exit(EXIT_FAILURE);
    }
    int iNumberofDonator_9;
    ifsInFile_9 >> iNumberofDonator_9;
    ifsInFile_9.get();
    struct donator_9
    {
        char strName[50];
        double dAmount;
    };
    donator_9 *dntDonators_9 = new donator_9[iNumberofDonator_9];
    for (int i = 0; i < iNumberofDonator_9; i++)
    {
        ifsInFile_9.getline(dntDonators_9[i].strName, 50);
        ifsInFile_9 >> dntDonators_9[i].dAmount;
        ifsInFile_9.get();
    }
    cout << "List of Grand Patrons" << endl;
    bool bStatus_9 = false;
    for (int i = 0; i < iNumberofDonator_9; i++)
        if (dntDonators_9[i].dAmount > 10000)
        {
            bStatus_9 = true;
            cout << dntDonators_9[i].strName << "\t$" << dntDonators_9[i].dAmount << endl;
        }
    if (!bStatus_9)
    {
        cout << "none" << endl;
        bStatus_9 = false;
    }
    cout << "List of Patrons" << endl;
    for (int i = 0; i < iNumberofDonator_9; i++)
        if (dntDonators_9[i].dAmount <= 10000)
        {
            bStatus_9 = true;
            cout << dntDonators_9[i].strName << "\t";
        }
    if (!bStatus_9)
        cout << "none" << endl;
    delete[] dntDonators_9;

    cin.get();

    return 0;
}