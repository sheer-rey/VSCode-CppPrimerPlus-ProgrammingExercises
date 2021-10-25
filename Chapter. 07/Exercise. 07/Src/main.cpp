#include <iostream>
#include <string>
using namespace std;

// Subject 01
double HarmonicMean_1(double x, double y);

// Subject 02
int GolfScoreInput_2(double *pGolfScore, int n);
void GolfScoreDisplay_2(double *pGolfScore, int n);
void AverageGolfScore_2(double *pGolfScore, int n);

// Subject 03
struct box_3
{
    char cMaker[40];
    float fHeight;
    float fWidth;
    float fLength;
    float fVolume;
};
void DisplayStructBox_3(box_3 box_3);
void ModifyVolumeofBox_3(box_3 *box_3);

// Subject 04
long double CalculateProbability_4(unsigned totalnums, unsigned picknums);

// Subject 05
long long CalculateFactorial_5(unsigned n);

// Subject 06
int FillArray_6(double *arr, int n);
void ShowArray_6(double *arr, int n);
void ReverseArray_6(double *arr, int n);

// Subject 07
double *FillArray_7(double *arr_head, double *arr_tail);
void ShowArray_7(double *arr_head, double *arr_tail);
void RevalueArray_7(double *arr_head, double *arr_tail, double r);

// Subject 08
const char *QUATER[4] = {"Spring", "Summer", "Autumn", "Winter"};
struct quater_expense_8
{
    double expense;
};
void FillDoubleArray_8(double *arr);
void ShowDoubleArray_8(double *arr);
void FillStructArray_8(quater_expense_8 *arr);
void ShowStructArray_8(quater_expense_8 *arr);

// Subject 09
const int SLEN_9 = 30;
struct student_9
{
    char fullname[SLEN_9];
    char hobby[SLEN_9];
    int opplevel;
};
int GetInfo_9(student_9 pa[], int n);
void display1_9(student_9 st);
void display2_9(student_9 *pst);
void display3_9(student_9 pst[], int n);

// Subject 10
double Calculate_10(double x, double y, double (*pFunc)(double, double));
double Add_10(double x, double y);
double Minus_10(double x, double y);
double Multiple_10(double x, double y);

int main()
{
    // Subject 01
    cout << "Subject 01" << endl;
    cout << "Please enter two values: ";
    double x_1, y_1;
    while (1)
    {
        if (!(cin >> x_1 >> y_1))
        {
            cin.clear();
            cerr << "Invalid input, Please reinput two values: ";
            cin.sync();
        }
        else if (x_1 != 0 && y_1 != 0)
        {
            cout << "The harmonic mean of " << x_1 << " and " << y_1 << " is: ";
            cout << HarmonicMean_1(x_1, y_1) << endl;
            cout << "Please enter two fingers: ";
        }
        else
            break;
    }

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 02
    cout << "Subject 02" << endl;
    const int iNumofScores = 10;
    double dGolfScore[iNumofScores];
    int iActualNumofScore;
    iActualNumofScore = GolfScoreInput_2(dGolfScore, 10);
    if (iActualNumofScore == -1)
        cout << "Internal Error!" << endl;
    else
    {
        GolfScoreDisplay_2(dGolfScore, iActualNumofScore);
        AverageGolfScore_2(dGolfScore, iActualNumofScore);
    }

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 03
    cout << "Subject 03" << endl;
    box_3 box_3 = {"sheer.rey", 1.0, 10.0, 3.3, -1.1};
    cout << "↓ Initial menber's value of struct box_3 ↓" << endl
         << endl;
    DisplayStructBox_3(box_3);
    ModifyVolumeofBox_3(&box_3);
    cout << "\r\n↓ Modified menber's value of struct box_3 ↓" << endl
         << endl;
    DisplayStructBox_3(box_3);

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 04
    cout << "Subject 04" << endl;
    cout << "The probability of wining first prize is: " << CalculateProbability_4(47, 5) * CalculateProbability_4(27, 1) << endl;

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 05
    cout << "Subject 05" << endl;
    cout << "Please enter a integer number, then we'll calculate its factorial: ";
    unsigned uNumber_5;
    while (!(cin >> uNumber_5))
    {
        cout << "Input error! Please enter a integer: ";
        cin.sync();
    }
    cout << "The factorial of integer " << uNumber_5 << " is " << CalculateFactorial_5(uNumber_5) << endl;

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 06
    cout << "Subject 06" << endl;
    const int ARRAYSIZE_6 = 10;
    double dArray_6[ARRAYSIZE_6];
    int iActualArraySize_6;
    iActualArraySize_6 = FillArray_6(dArray_6, ARRAYSIZE_6);
    ShowArray_6(dArray_6, iActualArraySize_6);
    cout << "Reverse Array..." << endl;
    ReverseArray_6(dArray_6, iActualArraySize_6);
    ShowArray_6(dArray_6, iActualArraySize_6);
    cout << "Reverse Partial Array..." << endl;
    ReverseArray_6(dArray_6 + 1, iActualArraySize_6 - 2);
    ShowArray_6(dArray_6, iActualArraySize_6);

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 07
    cout << "Subject 07" << endl;
    const int ARRAYSIZE_7 = 10;
    const double REVALUEFACTOR = 10;
    double dArray_7[ARRAYSIZE_7];
    double *pdArrayTail_7;
    pdArrayTail_7 = FillArray_7(dArray_7, dArray_7 + ARRAYSIZE_7);
    ShowArray_7(dArray_7, pdArrayTail_7);
    cout << "Revalue Array..." << endl;
    RevalueArray_7(dArray_7, pdArrayTail_7, REVALUEFACTOR);
    ShowArray_7(dArray_7, pdArrayTail_7);

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 08
    cout << "Subject 08" << endl;
    cout << "↓ example of double array ↓" << endl;
    double dQuaterExpense_8[4];
    FillDoubleArray_8(dQuaterExpense_8);
    ShowDoubleArray_8(dQuaterExpense_8);
    cout << "↓ example of struct array ↓" << endl;
    quater_expense_8 structQuaterExpense_8[4];
    FillStructArray_8(structQuaterExpense_8);
    ShowStructArray_8(structQuaterExpense_8);

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 09
    cout << "Subject 09" << endl;
    cout << "Please enter class size: ";
    int iClassSize;
    cin >> iClassSize;
    cin.sync();

    student_9 *pstuStudents = new student_9[iClassSize];
    int iActualClassSize = GetInfo_9(pstuStudents, iClassSize);
    cout << "Done! You have input " << iActualClassSize << " informations." << endl;
    cout << "\r\nYour input are as below." << endl;
    for (int i = 0; i < iActualClassSize; i++)
        display1_9(pstuStudents[i]);
    cout << "Again" << endl;
    for (int i = 0; i < iActualClassSize; i++)
        display2_9(&pstuStudents[i]);
    cout << "Again" << endl;
    display3_9(pstuStudents, iActualClassSize);
    delete[] pstuStudents;
    cout << "All done!" << endl;

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 10
    cout << "Subject 10" << endl;
    double (*pFunc[3])(double, double) = {Add_10, Minus_10, Multiple_10};
    const string MESSAGES[3] = {"Addition of 2 values: ", "Substraction of 2 values: ", "Multiplication of 2 values: "};
    for (int i = 0; i < 3; i++)
    {
        cout << "Please enter 2 values (q to quit): ";
        double dVal1_10, dVal2_10;
        /* Input validation */
        if (!(cin >> dVal1_10))
        {
            cin.clear();
            char c = cin.get();
            if (c == 'q')
            {
                cout << "Quit..." << endl;
                break;
            }
            else
            {
                cerr << "Invalid input, Please reinput 2 values (q to quit): ";
                i--;
                cin.sync();
                continue;
            }
        }
        if (!(cin >> dVal2_10))
        {
            cin.clear();
            char c = cin.get();
            if (c == 'q')
            {
                cout << "Quit..." << endl;
                break;
            }
            else
            {
                cerr << "Invalid input, Please reinput 2 values (q to quit): ";
                i--;
                cin.sync();
                continue;
            }
        }
        /* Function Call */
        cout << MESSAGES[i] << endl;
        switch (i)
        {
        case 0:
            cout << dVal1_10 << '+' << dVal2_10 << '=' << pFunc[i](dVal1_10, dVal2_10) << endl;
            cout << dVal1_10 << '+' << dVal2_10 << '=' << Calculate_10(dVal1_10, dVal2_10, pFunc[i]) << endl;
            break;
        case 1:
            cout << dVal1_10 << '-' << dVal2_10 << '=' << pFunc[i](dVal1_10, dVal2_10) << endl;
            cout << dVal1_10 << '-' << dVal2_10 << '=' << Calculate_10(dVal1_10, dVal2_10, pFunc[i]) << endl;
            break;
        case 2:
            cout << dVal1_10 << 'x' << dVal2_10 << '=' << pFunc[i](dVal1_10, dVal2_10) << endl;
            cout << dVal1_10 << 'x' << dVal2_10 << '=' << Calculate_10(dVal1_10, dVal2_10, pFunc[i]) << endl;
            break;
        }
    }

    return 0;
}

// Subject 01
double HarmonicMean_1(double x, double y)
{
    return 2.0 * x * y / (x + y);
}

// Subject 02
int GolfScoreInput_2(double *pGolfScore, int n)
{
    if (n > 0)
    {
        cout << "Please input Golf Scores(q to quit, " << n;
        if (n > 1)
        {
            cout << " times MAX): ";
        }
        else
            cout << " time MAX): ";
        int i;
        for (i = 0; i < n; i++)
        {
            if (!(cin >> pGolfScore[i]))
            {
                cin.clear();
                char c;
                cin >> c;
                if (c == 'q')
                {
                    i--;
                    break;
                }
                else
                {
                    cout << "Error input! Please reinput Golf Scores(q to quit, " << n;
                    if (n > 1)
                    {
                        cout << " times MAX): ";
                    }
                    else
                        cout << " time MAX): ";
                    cin.sync();
                    i = 0;
                }
            }
        }
        return i;
    }
    else
        return -1;
}

void GolfScoreDisplay_2(double *pGolfScore, int n)
{
    cout << "You has input " << n << " times golf score as below:" << endl;
    while (n > 0)
    {
        cout << *pGolfScore++ << "\t";
        n--;
    }
    cout << endl;
}

void AverageGolfScore_2(double *pGolfScore, int n)
{
    cout << "The average golf score is: ";
    double dAverageScore = 0;
    for (int i = 0; i < n; i++)
        dAverageScore += pGolfScore[i] / n;
    cout << dAverageScore << endl;
}

// Subject 03
void DisplayStructBox_3(box_3 box_3)
{
    cout << "Menbers' value of struct box_3 are as follows." << endl;
    cout << "box_3.cMaker: " << box_3.cMaker << endl;
    cout << "box_3.fHeight: " << box_3.fHeight << endl;
    cout << "box_3.fWidth: " << box_3.fWidth << endl;
    cout << "box_3.fLength: " << box_3.fLength << endl;
    cout << "box_3.fVolume: " << box_3.fVolume << endl;
}

void ModifyVolumeofBox_3(box_3 *box_3)
{
    box_3->fVolume = box_3->fLength * box_3->fWidth * box_3->fHeight;
}

// Subject 04
long double CalculateProbability_4(unsigned totalnums, unsigned picknums)
{
    long double result = 1.0;
    while (picknums > 0)
    {
        result = result * picknums / totalnums;
        picknums--;
        totalnums--;
    }
    return result;
}

// Subject 05
long long CalculateFactorial_5(unsigned n)
{
    if (n > 0)
        return n * CalculateFactorial_5(n - 1);
    else
        return 1;
}

// Subject 06
int FillArray_6(double *arr, int n)
{
    cout << "Please enter values (nonfigure input to quit): ";
    int i = 0;
    while (cin >> arr[i] && i < n)
        i++;
    cin.clear();
    cin.sync();
    return i;
}

void ShowArray_6(double *arr, int n)
{
    cout << "↓ Elements' value of array are as below ↓" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

void ReverseArray_6(double *arr, int n)
{
    int j = n - 1;
    for (int i = 0; i < j; i++, j--)
    {
        arr[i] += arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] -= arr[j];
    }
}

// Subject 07
double *FillArray_7(double *arr_head, double *arr_tail)
{
    cout << "Please enter values (nonfigure input to quit): ";
    while (cin >> *arr_head && arr_head < arr_tail)
        arr_head++;
    cin.clear();
    cin.sync();
    return arr_head;
}

void ShowArray_7(double *arr_head, double *arr_tail)
{
    cout << "↓ Elements' value of array are as below ↓" << endl;
    while (arr_head < arr_tail)
    {
        cout << *arr_head << '\t';
        arr_head++;
    }
    cout << endl;
}

void RevalueArray_7(double *arr_head, double *arr_tail, double r)
{
    while (arr_head < arr_tail)
    {
        *arr_head *= r;
        arr_head++;
    }
}

// Subject 08
void FillDoubleArray_8(double *arr)
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter " << QUATER[i] << " expenses: ";
        while (!(cin >> *(arr + i)))
        {
            cout << "Error input, renter " << QUATER[i] << " expenses: ";
            cin.clear();
            cin.sync();
        }
    }
}

void ShowDoubleArray_8(double *arr)
{
    cout << "EXPENSES" << endl;
    for (int i = 0; i < 4; i++)
        cout << QUATER[i] << ": $" << arr[i] << endl;
    cout << "Total: $" << arr[0] + arr[1] + arr[2] + arr[3] << endl;
}

void FillStructArray_8(quater_expense_8 *arr)
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter " << QUATER[i] << " expenses: ";
        while (!(cin >> (arr + i)->expense))
        {
            cout << "Error input, renter " << QUATER[i] << " expenses: ";
            cin.clear();
            cin.sync();
        }
    }
}

void ShowStructArray_8(quater_expense_8 *arr)
{
    cout << "EXPENSES" << endl;
    for (int i = 0; i < 4; i++)
        cout << QUATER[i] << ": $" << arr[i].expense << endl;
    cout << "Total: $" << arr[0].expense + arr[1].expense + arr[2].expense + arr[3].expense << endl;
}

// Subject 09
int GetInfo_9(student_9 pa[], int n)
{
    cout << "Please enter students' infomation, quit by a blank line" << endl;
    int i;
    for (i = 0; i < n; i++)
    {
        switch (i % 10 + 1)
        {
        case 1:
            cout << "The " << i + 1 << "st student: " << endl;
            break;
        case 2:
            cout << "The " << i + 1 << "nd student: " << endl;
            break;
        case 3:
            cout << "The " << i + 1 << "rd student: " << endl;
            break;
        default:
            cout << "The " << i + 1 << "th student: " << endl;
            break;
        }
        cout << "Fullname: ";
        cin.get(pa[i].fullname, SLEN_9);
        if (cin.fail() == true)
        {
            cin.clear();
            cin.sync();
            return i;
        }
        else
            cin.get();
        cout << "Hobby: ";
        while (!(cin.get(pa[i].hobby, SLEN_9)))
        {
            cerr << "Invalid input, Please reinput Hobby: ";
            cin.clear();
            cin.sync();
        }
        cout << "Ooplevel: ";
        cin >> pa[i].opplevel;
        cin.sync();
    }
    return i;
}

void display1_9(student_9 st)
{
    cout << "Students' fullname: " << st.fullname << endl;
    cout << "Students' hobby: " << st.hobby << endl;
    cout << "Students' ooplevel: " << st.opplevel << endl
         << endl;
}

void display2_9(student_9 *pst)
{
    cout << "Students' fullname: " << pst->fullname << endl;
    cout << "Students' hobby: " << pst->hobby << endl;
    cout << "Students' ooplevel: " << pst->opplevel << endl
         << endl;
}

void display3_9(student_9 pst[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Students' fullname: " << pst[i].fullname << endl;
        cout << "Students' hobby: " << pst[i].hobby << endl;
        cout << "Students' ooplevel: " << pst[i].opplevel << endl
             << endl;
    }
}

// Subject 10
double Calculate_10(double x, double y, double (*pFunc)(double, double))
{
    return pFunc(x, y);
}

double Add_10(double x, double y)
{
    return x + y;
}

double Minus_10(double x, double y)
{
    return x - y;
}

double Multiple_10(double x, double y)
{
    return x * y;
}