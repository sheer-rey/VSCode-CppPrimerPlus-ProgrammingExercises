#include <iostream>
using namespace std;

void MyFunc3_1()
{
    cout << "Three blind mice." << endl;
}

void MyFunc3_2()
{
    cout << "See how they run." << endl;
}

float MyFun5_1(float fCelsius)
{
    return fCelsius * 1.8 + 32.0;
}

double MyFun6_1(double dLightYear)
{
    return dLightYear * 63240.0;
}

void MyFun7_1(int iHours, int iMinutes)
{
    cout << "Time: " << iHours << ':' << iMinutes << endl;
}

int main()
{
    //Subject 01
    cout << "Subject 01" << endl;
    cout << "Author: sheer.rey" << endl;
    cout << "Institude: UESTC" << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Subject 02
    cout << "Subject 02" << endl;
    int iDistance;
    cout << "Please input a distance in unit \"long\": ";
    cin >> iDistance;
    cin.get();
    cout << "Tne distance in uint \"码\" is " << iDistance * 220 << "." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Subject 03
    cout << "Subject 03" << endl;
    MyFunc3_1();
    MyFunc3_1();
    MyFunc3_2();
    MyFunc3_2();
    cout << "Press any key to continue." << endl;
    cin.get();

    //Subject 04
    cout << "Subject 04" << endl;
    cout << "Enter your age: ";
    int age;
    cin >> age;
    cin.get();
    cout << "The age contains " << age * 12 << " months." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Subject 05
    cout << "Subject 05" << endl;
    cout << "Please enter a Celsius value: ";
    float fCelsius;
    cin >> fCelsius;
    cin.get();
    cout << fCelsius << " degrees Celsius is " << MyFun5_1(fCelsius) << " degrees Fahrenheit." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Subject 06
    cout << "Subject 06" << endl;
    cout << "Please enter the number of light years: ";
    double dLightYear;
    cin >> dLightYear;
    cin.get();
    cout << dLightYear << " light years = " << MyFun6_1(dLightYear) << " astronomical units." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Subject 07
    cout << "Subject 07" << endl;
    cout << "Please enter the number of hours: ";
    int iHours;
    cin >> iHours;
    cout << "Please enter the number of minutes: ";
    int iMinutes;
    cin >> iMinutes;
    MyFun7_1(iHours, iMinutes);
    return 0;
}