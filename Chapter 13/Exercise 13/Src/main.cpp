#include <iostream>
#include "subject01.h"
#include "subject02.h"
#include "subject03.h"
#include "subject04.h"
using namespace std;

int main()
{
    // Subject 01
    cout << "Subject 01" << endl;
    {
        using namespace subject01;
        Cd c1("Beatles", "Capitol", 14, 35.5);
        Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                             "Alfred Brendel", "Philips", 2, 57.17);
        Cd *pcd = &c1;

        cout << "Using Object Derectly" << endl;
        c1.Report();
        c2.Report();

        cout << "\nUsing Type Cd * Pointer to objects" << endl;
        pcd->Report();
        pcd = &c2;
        pcd->Report();

        cout << "\nCalling the Function with a Cd Reference Argument" << endl;
        Bravo(c1);
        Bravo(c2);

        cout << "\nTesting Assignment" << endl;
        Classic copy;
        copy = c2;
        copy.Report();
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 02
    cout << "Subject 02" << endl;
    {
        using namespace subject02;
        Cd c1("Beatles", "Capitol", 14, 35.5);
        Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                             "Alfred Brendel", "Philips", 2, 57.17);
        Cd *pcd = &c1;

        cout << "Using Object Derectly" << endl;
        c1.Report();
        c2.Report();

        cout << "\nUsing Type Cd * Pointer to objects" << endl;
        pcd->Report();
        pcd = &c2;
        pcd->Report();

        cout << "\nCalling the Function with a Cd Reference Argument" << endl;
        Bravo(c1);
        Bravo(c2);

        cout << "\nTesting Assignment" << endl;
        Classic copy;
        copy = c2;
        copy.Report();
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 03
    cout << "Subject 03" << endl;
    {
        using namespace subject03;
        ABC *pABC[2];
        pABC[1] = new LackDMA("Lack of Dynamic Memery Allocate.");
        pABC[2] = new HasDMA("Has Dynamic Memery Allocate.");
        pABC[1]->View();
        pABC[2]->View();
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 04
    cout << "Subject 04" << endl;
    {
        using namespace subject04;
        Port *port[2];
        port[1] = new Port("Gallo", "twany", 20);
        port[2] = new VintagePort("Vintage", 10, "Vin.t.g", 2000);
        *port[1] -= 2;
        *port[2] += 2;
        port[1]->Show();
        cout << endl;
        port[2]->Show();
        cout << endl;
        cout << *port[1] << endl;
        cout << *port[2] << endl;
    }

    return 0;
}
