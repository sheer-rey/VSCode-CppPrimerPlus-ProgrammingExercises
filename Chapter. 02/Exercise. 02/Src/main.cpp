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
    //Exercise 01
    cout << "Exercise 01" << endl;
    cout << "Author: sheer.rey" << endl;
    cout << "Institude: UESTC" << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 02
    cout << "Exercise 02" << endl;
    int iDistance;
    cout << "Please input a distance in unit \"long\": ";
    cin >> iDistance;
    cin.get();
    cout << "Tne distance in uint \"码\" is " << iDistance * 220 << "." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 03
    cout << "Exercise 03" << endl;
    MyFunc3_1();
    MyFunc3_1();
    MyFunc3_2();
    MyFunc3_2();
    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 04
    cout << "Exercise 04" << endl;
    cout << "Enter your age: ";
    int age;
    cin >> age;
    cin.get();
    cout << "The age contains " << age * 12 << " months." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 05
    cout << "Exercise 05" << endl;
    cout << "Please enter a Celsius value: ";
    float fCelsius;
    cin >> fCelsius;
    cin.get();
    cout << fCelsius << " degrees Celsius is " << MyFun5_1(fCelsius) << " degrees Fahrenheit." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 06
    cout << "Exercise 06" << endl;
    cout << "Please enter the number of light years: ";
    double dLightYear;
    cin >> dLightYear;
    cin.get();
    cout << dLightYear << " light years = " << MyFun6_1(dLightYear) << " astronomical units." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 07
    cout << "Exercise 07" << endl;
    cout << "Please enter the number of hours: ";
    int iHours;
    cin >> iHours;
    cout << "Please enter the number of minutes: ";
    int iMinutes;
    cin >> iMinutes;
    MyFun7_1(iHours, iMinutes);
    return 0;
}