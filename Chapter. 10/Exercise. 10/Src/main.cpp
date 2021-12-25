#include <iostream>
#include <string>
#include <cstring>

#include "header.h"

using namespace std;

int main()
{
    // Subject 01
    cout << "Subject 01" << endl;
    cout << "Initialize 2 Object..." << endl;
    BankAccount01 test_bank_account_1_01;
    BankAccount01 test_bank_account_2_01("sheer.rey", "sheer_rey", 1314);
    cout << "\nShow Object Info: " << endl;
    test_bank_account_1_01.ShowBankAccount();
    test_bank_account_2_01.ShowBankAccount();
    cout << "\nDeposit or Withdraw Some Money..." << endl;
    test_bank_account_1_01.AccountDeposit(0.1314);
    test_bank_account_2_01.AccountWithdraw(794);
    cout << "\nShow Object Info: " << endl;
    test_bank_account_1_01.ShowBankAccount();
    test_bank_account_2_01.ShowBankAccount();

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 02
    cout << "Subject 02" << endl;
    Person02 one_02;
    Person02 two_02("Smythecraft");
    Person02 three_03("Dimwiddy", "Sam");
    one_02.Show();
    one_02.FormalShow();
    two_02.Show();
    two_02.FormalShow();
    three_03.Show();
    three_03.FormalShow();

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 03
    cout << "Subject 03" << endl;
    Golf03 test_no_name_03;
    test_no_name_03.ShowGolf();
    cout << "Reset ";
    test_no_name_03.ShowFullName();
    cout << "'s handicap..." << endl;
    test_no_name_03.SetHandicap(0);
    test_no_name_03.ShowGolf();

    Golf03 andy_03;
    while (andy_03.SetGolf())
        andy_03.ShowGolf();

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 04
    cout << "Subject 04" << endl;
    sales04::Sales04 sales1_04;
    double inputSales[sales04::cQuarters] = {10, 20, 30, 40};
    sales04::Sales04 sales2_04(inputSales, 3);
    sales1_04.ShowSales();
    cout << endl;
    sales2_04.ShowSales();

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 05
    cout << "Subject 05" << endl;
    double total_payment = 0;
    Stack05 stack05;
    customer05 customer;
    while (1)
    {
        cout << "Please input customer's name (q to quit):";
        if (cin >> customer.fullname)
        {
            if (!strcmp(customer.fullname, "q"))
                break;
            cout << "Please enter " << customer.fullname << "'s payment:";
            while (!(cin >> customer.payment))
            {
                cin.clear();
                cin.sync();
                cout << "Input error! Please reinput " << customer.fullname
                     << "'s payment:";
            }
            stack05.push(customer);
            if (stack05.isfull())
                break;
        }
        else
        {
            cin.clear();
            cin.sync();
            cout << "Input error! Please reinput customer's name (q to quit):";
        }
    }
    cout << endl;
    while (stack05.pop(customer))
        cout << "customer " << customer.fullname << " has leave,"
             << "total payment is " << (total_payment += customer.payment)
             << endl;

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 06
    cout << "Subject 06" << endl;
    Move06 move06_1(1, 2);
    Move06 move06_2(3, 4);
    cout << "Coordinary 1: " << endl;
    move06_1.showmove();
    cout << "Coordinary 2: " << endl;
    move06_2.showmove();
    cout << "Add 2 coordinarys: " << endl;
    move06_1.add(move06_2).showmove();
    cout << "Reset coordinary 2: " << endl;
    move06_2.reset();
    move06_2.showmove();

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 07
    cout << "Subject 07" << endl;
    Plorg07 plorga;
    Plorg07 plorgb("Plorgb", 100);
    plorga.Show();
    plorgb.Show();
    cout << "\nSet CI" << endl;
    plorga.SetCI(66).Show();
    plorgb.SetCI(88).Show();

    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 08
    cout << "Subject 08" << endl;
    cout << "Generate list..." << endl;
    List08 list08;
    cout << "Is list empty?\t" << list08.IsEmpty() << endl;
    cout << "Add items to list..." << endl;
    list08.Add(1).Add(2).Add(3).Add(4).Add(5);
    cout << "Is list full?\t" << list08.IsFull() << endl;
    cout << "Print items..." << endl;
    list08.Visit(PrintItem08);

    return 0;
}
