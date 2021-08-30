#include <iostream>
#include <cmath>
#include <string>
#include <array>
#include <cstring>
using namespace std;

int main()
{
    //Exercise 01
    cout << "Exercise 01" << endl;
    cout << "What is your first name? ";
    const int iNAMESIZE_1 = 20;
    char cFirstName_1[iNAMESIZE_1] = {};
    cin.getline(cFirstName_1, iNAMESIZE_1);
    cout << "WHat is your last name? ";
    char cLastName_1[iNAMESIZE_1] = {};
    cin.get(cLastName_1, iNAMESIZE_1).get();
    cout << "What letter grade do you deserve? ";
    char cGrade_1;
    (cin >> cGrade_1).get();
    cout << "What is your age? ";
    int iAge;
    (cin >> iAge).get();
    cout << "Name: " << cLastName_1 << ", " << cFirstName_1 << endl;
    cout << "Grade: " << char(cGrade_1 + 1) << endl;
    cout << "Age: " << iAge << endl;

    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 02
    cout << "Exercise 02" << endl;
    string strName_2, strDessert_2;
    cout << "Please enter your name: ";
    getline(cin, strName_2);
    cout << "Please enter your favorite dessert: ";
    getline(cin, strDessert_2);
    cout << "I hhave some delicious " << strDessert_2 << " for you, " << strName_2 << "." << endl;

    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 03
    cout << "Exercise 03" << endl;
    cout << "Please enter your first name: ";
    const int iARSIZE_3 = 20;
    char cFirstName_3[iARSIZE_3] = {};
    cin.get(cFirstName_3, iARSIZE_3).get();
    cout << "Please enter your last name: ";
    char cLastName_3[iARSIZE_3] = {};
    cin.getline(cLastName_3, iARSIZE_3);
    strcat(cLastName_3, ", ");
    strcat(cLastName_3, cFirstName_3);
    cout << "Here's the information in a single string: " << cLastName_3 << endl;

    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 04
    cout << "Exercise 04" << endl;
    cout << "Please enter your first name: ";
    string strFirstName_4;
    getline(cin, strFirstName_4);
    cout << "Please enter your last name: ";
    string strLastName_4;
    getline(cin, strLastName_4);
    strLastName_4 += ", ";
    strLastName_4.append(strFirstName_4);
    cout << "Here's the information in a single string: " << strLastName_4 << endl;

    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 05
    cout << "Exercise 05" << endl;
    struct CandyBar
    {
        string strBand;
        float fWeight;
        int iCalorie;
    };
    CandyBar snack = {"Mocha Munch", 2.3, 350};
    cout << "snack.strBand: " << snack.strBand << endl;
    cout << "snack.fWeight: " << snack.fWeight << " kg" << endl;
    cout << "snack.iCalorie: " << snack.iCalorie << " kcal" << endl;

    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 06
    cout << "Exercise 06" << endl;
    struct FastFoodBar
    {
        string strBand;
        float fWeight;
        int iCalorie;
    };
    FastFoodBar FastFood_6[3] = {{"Dicos", 1.0, 100}, {"KFC", 1.0, 100}, {"MacDonald", 1.0, 100}};
    cout << "FastFood_6[0].strBand: " << FastFood_6[0].strBand << endl;
    cout << "FastFood_6[0].fWeight: " << FastFood_6[0].fWeight << " kg" << endl;
    cout << "FastFood_6[0].iCalorie: " << FastFood_6[0].iCalorie << " kcal" << endl;
    cout << "FastFood_6[1].strBand: " << FastFood_6[1].strBand << endl;
    cout << "FastFood_6[1].fWeight: " << FastFood_6[1].fWeight << " kg" << endl;
    cout << "FastFood_6[1].iCalorie: " << FastFood_6[1].iCalorie << " kcal" << endl;
    cout << "FastFood_6[2].strBand: " << FastFood_6[2].strBand << endl;
    cout << "FastFood_6[2].fWeight: " << FastFood_6[2].fWeight << " kg" << endl;
    cout << "FastFood_6[2].iCalorie: " << FastFood_6[2].iCalorie << " kcal" << endl;

    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 07
    cout << "Exercise 07" << endl;
    struct PizzaBar
    {
        string strBand;
        float fDiameter;
        float fWeight;
    };
    PizzaBar Pizza_7;
    cout << "Please enter Pizza Band: ";
    getline(cin, Pizza_7.strBand);
    cout << "Please enter Pizza Diameter(inch): ";
    (cin >> Pizza_7.fDiameter).get();
    cout << "Please enter Pizza Weight(g): ";
    (cin >> Pizza_7.fWeight).get();
    cout << "Pizza_7.strBand: " << Pizza_7.strBand << endl;
    cout << "Pizza_7.fDiameter: " << Pizza_7.fDiameter << " inch" << endl;
    cout << "Pizza_7.fWeight: " << Pizza_7.fWeight << " g" << endl;

    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 08
    cout << "Exercise 08" << endl;
    PizzaBar *pPizza_8;
    pPizza_8 = new PizzaBar;
    cout << "Please enter Pizza Band: ";
    getline(cin, pPizza_8->strBand);
    cout << "Please enter Pizza Diameter(inch): ";
    (cin >> pPizza_8->fDiameter).get();
    cout << "Please enter Pizza Weight(g): ";
    (cin >> pPizza_8->fWeight).get();
    cout << "pPizza_8->strBand: " << pPizza_8->strBand << endl;
    cout << "pPizza_8->fDiameter: " << pPizza_8->fDiameter << " inch" << endl;
    cout << "pPizza_8->fWeight: " << pPizza_8->fWeight << " g" << endl;
    delete pPizza_8;

    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 09
    cout << "Exercise 09" << endl;
    FastFoodBar *pFastFood_9 = new FastFoodBar[3];
    *pFastFood_9 = {"Dicos", 1.0, 100};
    *(pFastFood_9 + 1) = {"KFC", 1.0, 100};
    *(pFastFood_9 + 2) = {"MacDonald", 1.0, 100};
    cout << "pFastFood_9[0].strBand: " << pFastFood_9[0].strBand << endl;
    cout << "pFastFood_9[0].fWeight: " << pFastFood_9[0].fWeight << " kg" << endl;
    cout << "pFastFood_9[0].iCalorie: " << pFastFood_9[0].iCalorie << " kcal" << endl;
    cout << "pFastFood_9[1].strBand: " << pFastFood_9[1].strBand << endl;
    cout << "pFastFood_9[1].fWeight: " << pFastFood_9[1].fWeight << " kg" << endl;
    cout << "pFastFood_9[1].iCalorie: " << pFastFood_9[1].iCalorie << " kcal" << endl;
    cout << "pFastFood_9[2].strBand: " << pFastFood_9[2].strBand << endl;
    cout << "pFastFood_9[2].fWeight: " << pFastFood_9[2].fWeight << " kg" << endl;
    cout << "pFastFood_9[2].iCalorie: " << pFastFood_9[2].iCalorie << " kcal" << endl;
    delete[] pFastFood_9;

    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 10
    cout << "Exercise 10" << endl;
    cout << "Please enter the 3 times score in 40-yards running(s): ";
    array<double, 3> arScore;
    (cin >> arScore[0] >> arScore[1] >> arScore[2]).get();
    cout << "The first running score: " << arScore.at(0) << " s." << endl;
    cout << "The second running score: " << arScore.at(1) << " s." << endl;
    cout << "The third running score: " << arScore.at(2) << " s." << endl;
    cout << "The average running score: " << (arScore[0] + arScore[1] + arScore[2]) / 3.0 << " s." << endl;

    return 0;
}