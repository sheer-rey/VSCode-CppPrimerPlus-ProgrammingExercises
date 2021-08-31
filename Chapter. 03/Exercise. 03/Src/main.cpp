#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //Subject 01
    cout << "Subject 01" << endl;
    cout << "Please enter your body height in unit cm: ___\b\b\b";
    int iHeightCM_1;
    cin >> iHeightCM_1;
    cin.get();
    const int M2CM_1 = 100;
    cout << "Your body height is " << iHeightCM_1 / M2CM_1 << "m " << iHeightCM_1 % M2CM_1 << "cm." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Subject 02
    cout << "Subject 02" << endl;
    cout << "Please enter your body height in unit x foot and y inch:" << endl;
    cout << "x: ";
    float fFoot_2;
    cin >> fFoot_2;
    cout << "y: ";
    float fInch_2;
    cin >> fInch_2;
    cout << "Please enter your body weight in unit pound: ";
    float fPound_2;
    cin >> fPound_2;
    cin.get();
    const int FOOT2INCH_2 = 12;
    const float INCH2M_2 = 0.0254;
    const float KG2POUND_2 = 2.2;
    cout << "Your BMI is: " << fPound_2 / KG2POUND_2 / pow((fFoot_2 * FOOT2INCH_2 + fInch_2) * INCH2M_2, 2) << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    //Subject 03
    cout << "Subject 03" << endl;
    cout << "Please enter a latitude in degree, minutes and seconds:" << endl;
    cout << "First, enter the degrees: ";
    int iDegree_3;
    cin >> iDegree_3;
    cout << "Next, enter the minutes of arc: ";
    int iMinute_3;
    cin >> iMinute_3;
    cout << "Finally, enter the seconds of arc: ";
    int iSecond_3;
    cin >> iSecond_3;
    cin.get();
    const float DEG2MIN_MIN2SEC_3 = 60.0;
    cout << iDegree_3 << " degrees, " << iMinute_3 << " minutes, " << iSecond_3 << " seconds = " << float(iDegree_3 + iMinute_3 / DEG2MIN_MIN2SEC_3 + iSecond_3 / DEG2MIN_MIN2SEC_3 / DEG2MIN_MIN2SEC_3) << " degrees." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    // Subject 04
    cout << "Subject 04" << endl;
    cout << "Please enter the number of seconds: ";
    long lSeconds_4;
    cin >> lSeconds_4;
    cin.get();
    const int DAY2HOUR_4 = 24;
    const int HOUR2MINUTE_4 = 60;
    const int MINUTE2SECOND_4 = 60;
    cout << lSeconds_4 << " seconds = " << lSeconds_4 / (MINUTE2SECOND_4 * HOUR2MINUTE_4 * DAY2HOUR_4) << " days, " << lSeconds_4 % (MINUTE2SECOND_4 * HOUR2MINUTE_4 * DAY2HOUR_4) / (MINUTE2SECOND_4 * HOUR2MINUTE_4) << " hours, " << lSeconds_4 % (MINUTE2SECOND_4 * HOUR2MINUTE_4) / MINUTE2SECOND_4 << " minutes, " << lSeconds_4 % MINUTE2SECOND_4 << " seconds." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    // Subject 05
    cout << "Subject 05" << endl;
    cout << "Please enter the world's population: ";
    long long llWorldPopulation_5;
    cin >> llWorldPopulation_5;
    cout << "Please enter the population of the US: ";
    long long llUSPopulation_5;
    cin >> llUSPopulation_5;
    cin.get();
    cout << "The population of the US is " << double(llUSPopulation_5) / llWorldPopulation_5 * 100.0 << "% of the world population." << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    // Subject 06
    cout << "Subject 06" << endl;
    cout << "Please enter the driving distance in kilometer: ";
    int iKilometer_6;
    cin >> iKilometer_6;
    cout << "Please enter the gas consumption in litre: ";
    int iLitre_6;
    cin >> iLitre_6;
    cin.get();
    cout << "The gas consumption per 100km is: " << float(iLitre_6) / iKilometer_6 * 100.0 << endl;
    cout << "Press any key to continue." << endl;
    cin.get();

    // Subject 07
    cout << "Subject 07" << endl;
    cout << "Please enter the gas consumption in L/100KM: ";
    float fLper100KM_7;
    cin >> fLper100KM_7;
    cin.get();
    const float KM2MILE_7 = 0.6214;
    const float GALLON2LITRE_7 = 3.875;
    cout << "Another express of gas consumption is " << KM2MILE_7 * 100.0 / (fLper100KM_7 / GALLON2LITRE_7) << "mpg." << endl;

    return 0;
}