#include <iostream>
#include <string>
#include <cstring>
#include <new>

#include "golf.h"
#include "static.h"
#include "namespace.h"

using namespace std;

int main()
{
    // Subject 01
    cout << "Subject 01" << endl;
    golf ann;
    Setgolf(ann, "Ann birdfree", 24);
    Showgolf(ann);
    cout << "Reset Ann's handicap..." << endl;
    Handicap(ann, 0);
    Showgolf(ann);

    golf andy;
    while (Setgolf(andy))
        Showgolf(andy);

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 02
    cout << "Subject 02" << endl;
    cout << "Please enter a line (empty line to quit): ";
    string Input_2;
    getline(cin, Input_2);
    while (Input_2.length() != 0)
    {
        cin.sync();
        strcount(Input_2);
        cout << "Enter next line (empty line to quit): ";
        getline(cin, Input_2);
    }
    cout << "Bye\n";

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 03
    cout << "Subject 03" << endl;
    struct chaff_3
    {
        char dross[20];
        int slag;
    };

    chaff_3 *chaff_1_3 = new chaff_3;
    strcpy(chaff_1_3->dross, "qwe");
    chaff_1_3->slag = 123;

    chaff_3 *PlacementNewBuffer = new chaff_3[5];
    chaff_3 *chaff_2_3 = new (PlacementNewBuffer) chaff_3[2]{{"asd", 123}, {"zxc", 123}};

    cout << "struct with operator new: " << endl;
    cout << "dross: " << chaff_1_3->dross << "\tslag: " << chaff_1_3->slag << endl;

    cout << "struct with placement operator new: " << endl;
    for (int i = 0; i < 2; i++)
        cout << "dross: " << (chaff_2_3 + i)->dross << "\tslag: " << (chaff_2_3 + i)->slag << endl;

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 04
    cout << "Subject 04" << endl;
    SALES::Sales sales_4[2];
    double inputSales[SALES::QUARTERS] = {10, 20, 30, 40};
    SALES::setSales(*sales_4, inputSales, 3);
    SALES::setSales(*(sales_4 + 1));
    SALES::showSales(*sales_4);
    cout << endl;
    SALES::showSales(*(sales_4 + 1));

    return 0;
}
