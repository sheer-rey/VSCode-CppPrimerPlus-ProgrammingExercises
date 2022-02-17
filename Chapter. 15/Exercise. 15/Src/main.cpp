#include <iostream>
#include <typeinfo>
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
        Tv s42;
        cout << "Initial settings for 42\" TV:\n";
        s42.settings();
        s42.onoff();
        s42.chanup();
        cout << "\nAdjusted settings for 42\" TV:\n";
        s42.settings();

        Remote grey;
        cout << "Initial settings for grey remote:\n";
        grey.settings();
        cout << "\nAdjusted settings for grey remote:\n";
        s42.set_interactive(grey, Tv::On);
        grey.settings();

        grey.set_chan(s42, 10);
        grey.volup(s42);
        grey.volup(s42);
        cout << "\n42\" settings after using remote:\n";
        s42.settings();

        Tv s58(Tv::On);
        s58.set_mode();
        grey.set_chan(s58, 28);
        cout << "\n58\" settings:\n";
        s58.settings();
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 02
    cout << "Subject 02" << endl;
    {
        using namespace subject02;

        double x, y, z;

        cout << "Enter two numbers: ";
        while (cin >> x >> y)
        {
            try
            { // start of try block
                z = hmean(x, y);
                cout << "Harmonic mean of " << x << " and " << y
                     << " is " << z << endl;
                z = gmean(x, y);
                cout << "Geometric mean of " << x << " and " << y
                     << " is " << z << endl;
                cout << "Enter next set of numbers <q to quit>: ";
            }                                // end of try block
            catch (domain_error &domain_err) // start of catch block
            {
                cout << domain_err.what() << endl;
                cout << "Try again.\n";
                continue;
            }
            catch (invalid_argument &invalid_arg)
            {
                cout << invalid_arg.what() << endl;
                break;
            } // end of catch block
        }
        cout << "Bye!\n";
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 03
    cout << "Subject 03" << endl;
    {
        using namespace subject03;

        double x, y, z;

        cout << "Enter two numbers: ";
        while (cin >> x >> y)
        {
            try
            { // start of try block
                z = hmean(x, y);
                cout << "Harmonic mean of " << x << " and " << y
                     << " is " << z << endl;
                z = gmean(x, y);
                cout << "Geometric mean of " << x << " and " << y
                     << " is " << z << endl;
                cout << "Enter next set of numbers <q to quit>: ";
            }                              // end of try block
            catch (logic_error &logic_err) // start of catch block
            {
                cout << logic_err.what() << endl;
                cout << "Sorry, you don't get to play any more." << endl;
                break;
            } // end of catch block
        }
        cout << "Bye!\n";
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 04
    cout << "Subject 04" << endl;
    {
        using namespace subject04;

        double vals1[12] =
            {
                1220, 1100, 1122, 2212, 1232, 2334,
                2884, 2393, 3302, 2922, 3002, 3544};

        double vals2[12] =
            {
                12, 11, 22, 21, 32, 34,
                28, 29, 33, 29, 32, 35};

        Sales sales1(2011, vals1, 12);
        LabeledSales sales2("Blogstar", 2012, vals2, 12);

        cout << "First try block:\n";
        try
        {
            int i;
            cout << "Year = " << sales1.Year() << endl;
            for (i = 0; i < 12; ++i)
            {
                cout << sales1[i] << ' ';
                if (i % 6 == 5)
                    cout << endl;
            }
            cout << "Year = " << sales2.Year() << endl;
            cout << "Label = " << sales2.Label() << endl;
            for (i = 0; i <= 12; ++i)
            {
                cout << sales2[i] << ' ';
                if (i % 6 == 5)
                    cout << endl;
            }
            cout << "End of try block 1.\n";
        }
        catch (logic_error &error)
        {
            if (typeid(error) == typeid(LabeledSales::nbad_index))
            {
                LabeledSales::nbad_index &bad = dynamic_cast<LabeledSales::nbad_index &>(error);
                cout << bad.what();
                cout << "Company: " << bad.label_val() << endl;
                cout << "bad index: " << bad.bi_val() << endl;
            }
            if (typeid(error) == typeid(Sales::bad_index))
            {
                Sales::bad_index &bad = dynamic_cast<Sales::bad_index &>(error);
                cout << bad.what();
                cout << "bad index: " << bad.bi_val() << endl;
            }
        }

        cout << "\nNext try block:\n";
        try
        {
            sales2[2] = 37.5;
            sales1[20] = 23345;
            cout << "End of try block 2.\n";
        }
        catch (LabeledSales::nbad_index &bad)
        {
            cout << bad.what();
            cout << "Company: " << bad.label_val() << endl;
            cout << "bad index: " << bad.bi_val() << endl;
        }
        catch (Sales::bad_index &bad)
        {
            cout << bad.what();
            cout << "bad index: " << bad.bi_val() << endl;
        }
        cout << "done\n";
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    return 0;
}
