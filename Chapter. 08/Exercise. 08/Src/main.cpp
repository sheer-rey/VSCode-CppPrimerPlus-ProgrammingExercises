#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

// Subject 01
void PrintString_1(const char *str, int n = 0);

// Subject 02
struct CandyBar_2
{
    char Branch[30];
    double Weight;
    int Heat;
};
const CandyBar_2 &AssignCandy_2(CandyBar_2 &candy, const char *branch = "Millennium Munch", const double weight = 2.85, const int heat = 350);
void DisplayCandy_2(const CandyBar_2 &candy);

// Subject 03
const string &StringtoUpper_3(string &str);

// Subject 04
struct stringy_4
{
    char *str;
    int ct;
};
void Set_4(stringy_4 &stry, const char *str);
void Show_4(const stringy_4 &stry, int n = 1);
void Show_4(const char *str, int n = 1);

// Sucject 05
template <typename T>
T Max5_5(const T *arr);

// Subject 06
template <typename T>
T Maxn_6(const T *arr, int n);
typedef char *arrString_6;
template <>
arrString_6 Maxn_6<arrString_6>(const arrString_6 *arr, int n);

// Subject 07
struct debt_7
{
    char name[50];
    double amount;
};
/* Template A */
template <class T>
T SumArray_7(const T arr[], int n);
/* Template B */
template <class T>
T SumArray_7(T *arr[], int n);

int main()
{
    // Subject 01
    cout << "Subject 01" << endl;
    const char str_1[] = "Demo String of Subject 01.";
    PrintString_1(str_1);
    PrintString_1(str_1);
    PrintString_1(str_1, 1);

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 02
    cout << "Subject 02" << endl;
    CandyBar_2 Candy_2 = {"M M's", 1.25, 666};
    DisplayCandy_2(AssignCandy_2(Candy_2));

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 03
    cout << "Subject 03" << endl;
    cout << "Please enter a string (q to quit) : ";
    string str_3;
    getline(cin, str_3);
    while (str_3 != "q")
    {
        cout << StringtoUpper_3(str_3) << endl;
        cout << "Next string (q to quit) : ";
        getline(cin, str_3);
    }

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 04
    cout << "Subject 04" << endl;
    stringy_4 Beany_4;
    char Testing_4[] = "Reality isn't what it used to be.";

    Set_4(Beany_4, Testing_4);
    Show_4(Beany_4);
    Show_4(Beany_4, 2);
    Testing_4[0] = 'D';
    Testing_4[1] = 'u';
    Show_4(Testing_4);
    Show_4(Testing_4, 3);
    Show_4("Done!");

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 05
    cout << "Subject 05" << endl;
    int iArr_5[5] = {3, 1, 4, 2, 6};
    double dArr_5[5] = {1.2, 5.6, 3.7, 2.4, 5.5};
    cout << "The maximum value of array { ";
    for (int x : iArr_5)
        cout << x << " ";
    cout << "} is " << Max5_5(iArr_5) << endl;

    cout << "The maximum value of array { ";
    for (double x : dArr_5)
        cout << x << " ";
    cout << "} is " << Max5_5<double>(dArr_5) << endl;

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 06
    cout << "Subject 06" << endl;
    int iArr_6[6] = {3, 1, 4, 2, 6, 5};
    double dArr_6[4] = {1.2, 5.6, 3.7, 2.4};
    char pString_6[5][20] = {"Good morning!", "Happy birthday!", "Merry Christmas！", "Happy new year!", "Good night!"};
    char *arrArr_6[5] = {pString_6[0], pString_6[1], pString_6[2], pString_6[3], pString_6[4]};

    cout << "The maximum value of array { ";
    for (int x : iArr_6)
        cout << x << " ";
    cout << "} is " << Maxn_6(iArr_6, 6) << endl;

    cout << "The maximum value of array { ";
    for (double x : dArr_6)
        cout << x << " ";
    cout << "} is " << Maxn_6<double>(dArr_6, 4) << endl;

    cout << "The longest string in string array { ";
    for (char *x : arrArr_6)
        cout << "\"" << x << "\" ";
    cout << "} is \"" << Maxn_6<arrString_6>(arrArr_6, 5) << "\"" << endl;

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 07
    cout << "Subject 07" << endl;
    int iThings_7[6] = {13, 31, 103, 301, 310, 130};
    debt_7 mr_E_7[3] = {{"Ima Wolfe", 2400.0}, {"Ura Foxe", 1300.0}, {"Iby stout", 1800.0}};
    double *pd_7[3];

    for (int i = 0; i < 3; i++)
        pd_7[i] = &mr_E_7[i].amount;

    cout << "The sum of array { ";
    for (int x : iThings_7)
        cout << x << " ";
    cout << "} is " << SumArray_7(iThings_7, 6) << endl;

    cout << "The sum of debt array { ";
    for (debt_7 x : mr_E_7)
        cout << x.name << ":" << x.amount << " ";
    cout << "} is " << SumArray_7(pd_7, 3) << endl;

    return 0;
}

// Subject 01
void PrintString_1(const char *str, int n)
{
    static int CallTime = 0;
    CallTime++;
    if (n == 0)
        cout << str << endl;
    else
        for (int i = CallTime; i > 0; i--)
            cout << CallTime - i + 1 << ": " << str << endl;
}

// Subject 02
const CandyBar_2 &AssignCandy_2(CandyBar_2 &candy, const char *branch, const double weight, const int heat)
{
    strcpy(candy.Branch, branch);
    candy.Weight = weight;
    candy.Heat = heat;
    return candy;
}

void DisplayCandy_2(const CandyBar_2 &candy)
{
    cout << "Candy's Information" << endl;
    cout << "Candy's Branch: " << candy.Branch << endl;
    cout << "Candy's Weight: " << candy.Weight << "g" << endl;
    cout << "Candy's Heat: " << candy.Heat << "J" << endl;
}

// Subject 03
const string &StringtoUpper_3(string &str)
{
    for (char &c : str)
    {
        if (islower(c))
            c = toupper(c);
    }
    return str;
}

// Subject 04
void Set_4(stringy_4 &stry, const char *str)
{
    stry.ct = strlen(str);
    stry.str = new char[stry.ct + 1];
    strcpy(stry.str, str);
}

void Show_4(const stringy_4 &stry, int n)
{
    while (n)
    {
        cout << stry.str << endl;
        n--;
    }
}

void Show_4(const char *str, int n)
{
    while (n)
    {
        cout << str << endl;
        n--;
    }
}

// Sucject 05
template <typename T>
T Max5_5(const T *arr)
{
    T temp = *arr;
    for (int i = 1; i < 5; i++)
        if (arr[i] > temp)
            temp = arr[i];
    return temp;
}

// Subject 06
template <typename T>
T Maxn_6(const T *arr, int n)
{
    T temp = *arr;
    for (int i = 1; i < n; i++)
        if (arr[i] > temp)
            temp = arr[i];
    return temp;
}

template <>
arrString_6 Maxn_6<arrString_6>(const arrString_6 *arr, int n)
{
    arrString_6 temp = *arr;
    for (int i = 1; i < n; i++)
        if (strlen(arr[i]) > strlen(temp))
            temp = arr[i];
    return temp;
}

// Subject 07
/* Template A */
template <class T>
T SumArray_7(const T arr[], int n)
{
    T sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

/* Template B */
template <class T>
T SumArray_7(T *arr[], int n)
{
    T sum = 0;
    for (int i = 0; i < n; i++)
        sum += *arr[i];
    return sum;
}
