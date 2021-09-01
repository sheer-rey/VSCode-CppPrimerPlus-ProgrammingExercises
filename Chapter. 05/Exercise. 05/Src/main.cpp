#include <iostream>
#include <array>
#include <string>
using namespace std;

int main()
{
    // //Subject 01
    // cout << "Subject 01" << endl;
    // cout << "Please enter two integer: ";
    // int a_1, b_1;
    // (cin >> a_1 >> b_1).get();
    // if (a_1 > b_1)
    // {
    //     /* exchange values in a_1 and b_1 */
    //     a_1 ^= b_1;
    //     b_1 ^= a_1;
    //     a_1 ^= b_1;
    // }
    // cout << "The integer sum between " << a_1 << " and " << b_1 << " is: ";
    // for (int i = a_1 + 1; i <= b_1; i++)
    //     a_1 += i;
    // cout << a_1 << endl;

    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // //Subject 02
    // cout << "Subject 02" << endl;
    // const int iARSIZE_2 = 16;
    // array<long long, iARSIZE_2> llFactorial_2 = {1};
    // for (int i = 1; i < int(llFactorial_2.size()); i++)
    //     llFactorial_2[i] = llFactorial_2[i - 1] * i;
    // for (int i = 0; i < int(llFactorial_2.size()); i++)
    //     cout << i << "! = " << llFactorial_2.at(i) << endl;

    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // //Subject 03
    // cout << "Subject 03" << endl;
    // cout << "Please enter some nums and set 0 as end of input: " << endl;
    // int iSum_3 = 0, iInput_3 = 0;
    // cin >> iInput_3;
    // while (iInput_3 != 0)
    // {
    //     iSum_3 += iInput_3;
    //     cout << "The sum of total input num is " << iSum_3 << " till now." << endl;
    //     cin >> iInput_3;
    //     cin.get();
    // }
    // cout << "Program end.\nThe total sum of all input num is " << iSum_3 << "." << endl;

    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // //Subject 04
    // cout << "Subject 04" << endl;
    // double dDaphne_4, dCleo_4;
    // const double dPRINCIPAL_4 = 100, dPROFIT_RATE1_4 = 0.1, dPROFIT_RATE2_4 = 0.05;
    // dDaphne_4 = dCleo_4 = dPRINCIPAL_4;
    // int iYear = 0;
    // do
    // {
    //     dDaphne_4 += dPRINCIPAL_4 * dPROFIT_RATE1_4;
    //     dCleo_4 *= 1 + dPROFIT_RATE2_4;
    //     iYear++;
    //     switch (iYear % 10)
    //     {
    //     case 1:
    //         cout << "The " << iYear << "st year, ";
    //         break;
    //     case 2:
    //         cout << "The " << iYear << "nd year, ";
    //         break;
    //     case 3:
    //         cout << "The " << iYear << "rd year, ";
    //         break;
    //     default:
    //         cout << "The " << iYear << "th year, ";
    //     }
    //     cout << "Daphne's total value is $" << dDaphne_4 << ", Cleo's total value is $" << dCleo_4 << "." << endl;
    // } while (dDaphne_4 >= dCleo_4);
    // cout << "Now, Cleo's total value exceeds Daphne's." << endl;

    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // //Subject 05
    // cout << "Subject 05" << endl;
    // cout << "Please enter sales volume for one year:" << endl;
    // const string strMonths_5[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    // int iSalesVolume_5[12], iSalesVolumeSum_5 = 0;
    // for (int i = 0; i < 12; i++)
    // {
    //     cout << strMonths_5[i] << ": ";
    //     cin >> iSalesVolume_5[i];
    // }
    // cin.get();
    // for (int i : iSalesVolume_5)
    //     iSalesVolumeSum_5 += i;
    // cout << "The total sales volume of one year is " << iSalesVolumeSum_5 << "." << endl;

    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // //Subject 06
    // cout << "Subject 06" << endl;
    // cout << "Please enter sales volume for 3 year:" << endl;
    // const string strMonths_6[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    // const string strYear_6[3] = {"first", "second", "third"};
    // int iSalesVolume_6[3][12], iSalesVolumeSum_6 = 0;
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << "Please enter sales volume for the " << strYear_6[i] << " year:" << endl;
    //     for (int j = 0; j < 12; j++)
    //     {
    //         cout << strMonths_6[j] << ": ";
    //         cin >> iSalesVolume_6[i][j];
    //     }
    //     cin.get();
    // }
    // for (int i = 0; i < 3; i++)
    //     for (int j = 0; j < 12; j++)
    //         iSalesVolumeSum_6 += iSalesVolume_6[i][j];
    // cout << "The total sales volume of one year is " << iSalesVolumeSum_6 << "." << endl;

    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    //Subject 07
    cout << "Subject 07" << endl;
    struct car_7
    {
        string strManufacturer;
        int iProductiveYear;
    };
    cout << "How many cars do you wish to catalog? ";
    int iNumberofCars;
    (cin >> iNumberofCars).get();
    car_7 *pUserCars = new car_7[iNumberofCars];
    for (int i = 0; i < iNumberofCars; i++)
    {
        cout << "Car #" << i + 1 << ": " << endl;
        cout << "Please enter the manufacturer: ";
        getline(cin, pUserCars[i].strManufacturer);
        cout << "Please enter the year of manufacture: ";
        cin >> pUserCars[i].iProductiveYear;
        cin.get();
    }
    cout << "Here is your collection: " << endl;
    for (int i = 0; i < iNumberofCars; i++)
        cout << pUserCars[i].iProductiveYear << " " << pUserCars[i].strManufacturer << endl;

    cout << "\nPress any key to continue." << endl;
    cin.get();

    //Subject 08
    cout << "Subject 08" << endl;
    return 0;
}