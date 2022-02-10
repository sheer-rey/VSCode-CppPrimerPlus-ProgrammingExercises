#include <iostream>
#include "subject01.h"
#include "subject02.h"
#include "subject03.hpp"
#include "subject04.h"
#include "subject05.h"
using namespace std;

int main()
{
    // // Subject 01
    // cout << "Subject 01" << endl;
    // {
    //     using namespace subject01;
    //     Wine holding;
    //     holding.GetBottles();
    //     holding.Show();

    //     const int YRS = 3;
    //     int y[YRS] = {1993, 1995, 1998};
    //     int b[YRS] = {48, 60, 72};
    //     Wine more("Gushing Grape Red", YRS, y, b);
    //     more.Show();
    //     cout << "Total bottles for " << more.Lable()
    //          << ": " << more.Sum() << endl;
    //     cout << "Bye!" << endl;
    // }
    // cin.sync();
    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // // Subject 02
    // cout << "Subject 02" << endl;
    // {
    //     using namespace subject02;
    //     Wine holding;
    //     holding.GetBottles();
    //     holding.Show();

    //     const int YRS = 3;
    //     int y[YRS] = {1993, 1995, 1998};
    //     int b[YRS] = {48, 60, 72};
    //     Wine more("Gushing Grape Red", YRS, y, b);
    //     more.Show();
    //     cout << "Total bottles for " << more.Lable()
    //          << ": " << more.Sum() << endl;
    //     cout << "Bye!" << endl;
    // }
    // cin.sync();
    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // // Subject 03
    // cout << "Subject 03" << endl;
    // {
    //     using namespace subject03;
    //     WorkerQueue lolas;
    //     Worker *worker_temp;

    //     const int SIZE = 5;
    //     int ct;
    //     for (ct = 0; ct < SIZE; ct++)
    //     {
    //         char choice;
    //         cout << "Enter the employee category:\n"
    //              << "w: waiter  s: singer  "
    //              << "t: singing waiter  q: quit\n";
    //         cin >> choice;
    //         while (strchr("wstq", choice) == NULL)
    //         {
    //             cout << "Please enter a w, s, t, or q: ";
    //             cin >> choice;
    //         }
    //         if (choice == 'q')
    //             break;
    //         switch (choice)
    //         {
    //         case 'w':
    //             worker_temp = new Waiter;
    //             break;
    //         case 's':
    //             worker_temp = new Singer;
    //             break;
    //         case 't':
    //             worker_temp = new SingingWaiter;
    //             break;
    //         }
    //         cin.get();
    //         worker_temp->Set();
    //         lolas.EnQueue(worker_temp);
    //     }

    //     cout << "\nHere is your staff:\n";
    //     int i;

    //     for (i = 0; i < ct; i++)
    //     {
    //         cout << endl;
    //         lolas.Dequeue(worker_temp);
    //         worker_temp->Show();
    //         delete worker_temp;
    //     }
    //     cout << "Bye.\n";
    // }
    // cin.sync();
    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // // Subject 04
    // cout << "Subject 04" << endl;
    // {
    //     using namespace subject04;

    //     const int SIZE = 5;
    //     Person *persons[SIZE];

    //     int ct;
    //     for (ct = 0; ct < SIZE; ct++)
    //     {
    //         char choice;
    //         cout << "Enter the person category:\n"
    //              << "n: normal        g: gun slinger\n"
    //              << "p: poker player  b: bad dude\n"
    //              << "q: quit\n";
    //         cin >> choice;
    //         while (strchr("ngpbq", choice) == NULL)
    //         {
    //             cout << "Please enter a n, g, p, ,b , or q: ";
    //             cin.sync();
    //             cin >> choice;
    //         }
    //         if (choice == 'q')
    //             break;
    //         switch (choice)
    //         {
    //         case 'n':
    //             persons[ct] = new Person("Wolly", "West");
    //             break;
    //         case 'g':
    //             persons[ct] = new Gunslinger("Iris West", "Allen");
    //             break;
    //         case 'p':
    //             persons[ct] = new PokerPlayer("Barry", "Allen");
    //             break;
    //         case 'b':
    //             persons[ct] = new BadDude("Tony", "Tomphson");
    //             break;
    //         }
    //         cin.get();
    //     }

    //     cout << "\nHere is your inputed information:\n";

    //     for (int i = 0; i < ct; i++)
    //     {
    //         cout << endl;
    //         persons[i]->Show();
    //         cout << endl;
    //         delete persons[i];
    //     }
    //     cout << "Bye.\n";
    // }
    // cin.sync();
    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // Subject 05
    cout << "Subject 05" << endl;
    {
        using namespace subject05;
        Employee em("Trip", "Harris", "Thumper");
        cout << em << endl;
        Manager ma("Amorphia", "Spindragon", "Nuancer", 5);
        cout << ma << endl;
        ma.ShowAll();

        Fink fi("Matt", "Oggs", "Olier", "Juno Barr");
        cout << fi << endl;
        fi.ShowAll();
        HighFink hf(ma, "Curly Kew");
        hf.ShowAll();
        cout << "Press a key for next phase:\n";
        cin.get();
        HighFink hf2;
        hf2.SetAll();

        cout << "Using an AbstrEmp * pointer:\n";
        AbstrEmp *tri[4] = {&em, &fi, &hf, &hf2};
        for (int i = 0; i < 4; i++)
            tri[i]->ShowAll();
    }

    return 0;
}
