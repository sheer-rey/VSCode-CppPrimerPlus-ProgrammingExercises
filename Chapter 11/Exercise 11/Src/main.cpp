#include <iostream>
#include <fstream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime>   // time() prototype
#include "vect.h"
#include "mytime3.h"
#include "stonewt.h"
#include "complex0.h"

using namespace std;
using VECTOR::Vector;

int main()
{
    srand(time(0)); // seed random-number generator
    ofstream fout;

    // // Subject 01
    // cout << "Subject 01: Random Walk" << endl;
    // fout.open(R"(./Files/Subject 01.txt)");
    // if (fout.is_open())
    // {
    //     double direction;
    //     Vector step;
    //     Vector result(0.0, 0.0);
    //     unsigned long steps = 0;
    //     double target;
    //     double dstep;
    //     cout << "Enter target distance (q to quit): ";
    //     while (1)
    //     {
    //         // distance input
    //         if (!(cin >> target))
    //         {
    //             cin.clear();
    //             if (cin.get() == 'q')
    //                 break;
    //             else
    //             {
    //                 cin.sync();
    //                 cout << "Input error, please reinput target distance (q to quit): ";
    //                 continue;
    //             }
    //         }

    //         // step input
    //         cout << "Enter step length: ";
    //         while (!(cin >> dstep))
    //         {
    //             cin.clear();
    //             cin.sync();
    //             cout << "Input error, please reinput step length: ";
    //         }

    //         // output to file
    //         fout << "Target Distance: " << target
    //              << ",\tStep Size: " << dstep << endl; // headline
    //         fout << steps << ": " << result << endl;   // origin location

    //         // random walk
    //         while (result.magval() < target)
    //         {
    //             direction = rand() % 360;
    //             step.reset(dstep, direction, Vector::POL);
    //             result = result + step;
    //             steps++;
    //             fout << steps << ": " << result << endl; // walk location
    //         }

    //         fout << "After " << steps
    //              << " steps, the subject has the following location:\n";
    //         fout << result;

    //         result.polar_mode();
    //         fout << "\tor\t" << result << endl;

    //         fout << "Average outward distance per step = "
    //              << result.magval() / steps << endl
    //              << endl;

    //         cout << "Steps' information of random walk "
    //              << "has stored in \"Subject 01.txt" << endl;
    //         steps = 0;
    //         result.reset(0.0, 0.0);
    //         cout << "Enter target distance (q to quit): ";
    //     }
    // }
    // else
    // {
    //     cerr << "Error in opening \"Subject 01.txt\"!" << endl;
    //     fout.clear();
    // }

    // fout.close();

    // cin.sync();
    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // // Subject 03
    // cout << "Subject 03: Random Walk" << endl;
    // {
    //     double direction;
    //     Vector step;
    //     Vector result(0.0, 0.0);
    //     unsigned long steps(0);
    //     double target;
    //     double dstep;

    //     unsigned test_num(0);
    //     unsigned long max_step;
    //     unsigned long min_step;
    //     double avg_step;
    //     bool first = true;

    //     // test number input
    //     cout << "Enter test number (integer, q to quit): ";
    //     while (!(cin >> test_num))
    //     {
    //         cin.clear();
    //         if (cin.get() == 'q')
    //             break;
    //         else
    //         {
    //             cin.sync();
    //             cout << "Input error, please reinput step length: ";
    //         }
    //     }
    //     cin.sync();

    //     // distance input
    //     if (test_num)
    //         cout << "Enter target distance: ";
    //     while (test_num && !(cin >> target))
    //     {
    //         cin.clear();
    //         cin.sync();
    //         cout << "Input error, please reinput target distance: ";
    //     }

    //     // step input
    //     if (test_num)
    //         cout << "Enter step length: ";
    //     while (test_num && !(cin >> dstep))
    //     {
    //         cin.clear();
    //         cin.sync();
    //         cout << "Input error, please reinput step length: ";
    //     }

    //     // headline
    //     if (test_num)
    //         cout << "Target Distance: " << target
    //              << ",\tStep Size: " << dstep
    //              << ",\ttest number: " << test_num
    //              << endl;

    //     // main loop
    //     for (unsigned i = 0; i < test_num; i++)
    //     {
    //         // random walk
    //         while (result.magval() < target)
    //         {
    //             direction = rand() % 360;
    //             step.reset(dstep, direction, Vector::POL);
    //             result = result + step;
    //             steps++;
    //         }
    //         if (first)
    //         {
    //             max_step = min_step = steps;
    //             avg_step = double(steps) / test_num;
    //             first = false;
    //         }
    //         else
    //         {
    //             if (steps > max_step)
    //                 max_step = steps;
    //             if (steps < min_step)
    //                 min_step = steps;
    //             avg_step += double(steps) / test_num;
    //         }
    //         steps = 0;
    //         result.reset(0.0, 0.0);
    //     }
    //     if (test_num)
    //     {
    //         cout << "In " << test_num << " test";
    //         if (test_num > 1)
    //             cout << 's';
    //         cout << ", the maximum step is " << max_step
    //              << ", the minimal step is " << min_step
    //              << ", and the average step is " << unsigned(avg_step)
    //              << endl;
    //     }
    // }

    // cin.sync();
    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // // Subject 04
    // cout << "Subject 04" << endl;
    // {
    //     Time aida(3, 35);
    //     Time tosca(2, 48);
    //     Time temp;

    //     cout << "Aida and Tosca:\n";
    //     cout << aida << "; " << tosca << endl;
    //     temp = aida + tosca; // operator+()
    //     cout << "Aida + Tosca: " << temp << endl;
    //     temp = aida * 1.17; // operator*()
    //     cout << "Aida * 1.17: " << temp << endl;
    //     cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
    // }
    // cin.sync();
    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // // Subject 05
    // cout << "Subject 05" << endl;
    // {
    //     Stonewt incognito = 275; // uses constructor to initialize
    //     Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7;
    //     Stonewt taft(21, 8);

    //     cout << "The celebrity weighed ";
    //     cout << incognito.SwitchUnit(cSTONE) << '.' << endl;
    //     cout << "The detective weighed ";
    //     cout << wolfe.SwitchUnit(cSTONE) << '.' << endl;
    //     cout << "The President weighed ";
    //     cout << taft.SwitchUnit(cFLOAT_POUNDS) << '.' << endl;
    //     incognito = incognito + 5.2; // uses constructor for conversion: Stonewt(5.2)
    //     taft = 325;                  // same as taft = Stonewt(325);
    //     cout << "After dinner, the celebrity weighed ";
    //     cout << incognito.SwitchUnit(cSTONE) << '.' << endl;
    //     cout << "After dinner, the President weighed ";
    //     cout << taft.SwitchUnit(cFLOAT_POUNDS) << '.' << endl;
    //     cout << "Wow! " << taft.SwitchUnit(cFLOAT_POUNDS) << '!' << endl;
    //     cout << "The wrestler weighed even more.\n";
    //     cout << "Wow! " << Stonewt(422) - Stonewt(1.5) * 10 << '!' << endl;
    //     cout << "No stone left unearned\n";
    // }
    // cin.sync();
    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // // Subject 06
    // cout << "Subject 06" << endl;
    // {
    //     Stonewt st[6] = {12.3, 666, 65.5};
    //     Stonewt _11stone(11, 0);
    //     Stonewt max, min;
    //     unsigned n = 0;
    //     max = min = st[0];
    //     for (int i = 3; i < 6; i++)
    //         st[i] = i * 21.21;
    //     for (Stonewt x : st)
    //     {
    //         if (x > max)
    //             max = x;
    //         if (x < min)
    //             min = x;
    //         if (x >= _11stone)
    //             n++;
    //     }
    //     cout << "The maximum weight is: " << max << '.' << endl;
    //     cout << "The minimal weight is: " << min << '.' << endl;
    //     cout << n << " weight";
    //     if (n > 1)
    //         cout << "s are";
    //     else
    //         cout << " is";
    //     cout << " greater than 11 stones." << endl;
    // }
    // cin.sync();
    // cout << "\nPress any key to continue." << endl;
    // cin.get();

    // Subject 07
    cout << "Subject 07" << endl;
    {
        Complex0 a(3.0, 4.0);
        Complex0 c;
        cout << "Enter a complex number (q to quit) " << endl;
        while (cin >> c)
        {
            cout << "c is " << c << endl;
            cout << "complex conjugate is " << ~c << endl;
            cout << "a is " << a << endl;
            cout << "a + c is " << a + c << endl;
            cout << "a - c is " << a - c << endl;
            cout << "a * c is " << a * c << endl;
            cout << "2 * c is " << 2 * c << endl;
            cout << "Enter a complex number (q to quit) " << endl;
        }
        cout << "Done!" << endl;
    }

    return 0;
}
