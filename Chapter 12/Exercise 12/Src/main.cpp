#include <iostream>
#include <fstream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime>   // time() prototype
#include "cow.h"
#include "string2.h"
#include "stock.h"
#include "stack_.h"
#include "queue.h"
using namespace std;

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

int main()
{
    srand(time(0)); // seed random-number generator
    ofstream fout;

    // Subject 01
    cout << "Subject 01" << endl;
    {
        Cow cow1;
        Cow cow2("Cow", "Milk", 100);
        Cow cow3(cow2);
        cow1 = cow3;
        cout << "cow1: " << endl;
        cow1.ShowCow();
        cout << "cow2: " << endl;
        cow2.ShowCow();
        cout << "cow3: " << endl;
        cow3.ShowCow();
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 02
    cout << "Subject 02" << endl;
    {
        String s1(" and I am a C++ student.");
        String s2 = "Please enter your name: ";
        String s3;
        cout << s2;
        cin >> s3;
        s2 = "My name is " + s3;
        cout << s2 << ".\n";
        s2 = s2 + s1;
        s2.StringUp();
        cout << "The string\n"
             << s2 << "\ncontains "
             << s2.Has('A') << " 'A' characters in it.\n";
        s1 = "red";
        String rgb[3] = {s1, "green", "blue"};
        cout << "Enter the name of a primary color for mixing light: ";
        String ans;
        bool success = false;
        while (cin >> ans)
        {
            ans.StringLow();
            for (int i = 0; i < 3; i++)
            {
                if (ans == rgb[i])
                {
                    cout << "That's right!" << endl;
                    success = true;
                    break;
                }
            }
            if (success)
                break;
            else
                cout << "Try again!\n";
        }
        cout << "Bye!" << endl;
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 03
    cout << "Subject 03" << endl;
    {
        const int STKS = 4;
        // create an array of initialized objects
        Stock stocks[STKS] = {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Monolithic Obelisks", 130, 3.25),
            Stock("Fleep Enterprises", 60, 6.5)};

        std::cout << "Stock holdings:\n";
        int st;
        for (st = 0; st < STKS; st++)
            std::cout << stocks[st];
        // set pointer to first element
        const Stock *top = &stocks[0];
        for (st = 1; st < STKS; st++)
            top = &top->topval(stocks[st]);
        // now top points to the most valuable holding
        std::cout << "\nMost valuable holding:\n"
                  << *top;
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 04
    cout << "Subject 04" << endl;
    {
        stack_::Item item;
        cout << "Generate Stack s1 and s2..." << endl;
        stack_::Stack s1, s2;
        cout << "Now Stack s1 is ";
        if (!s1.isempty())
            cout << "not ";
        cout << "empty! Stack s2 is ";
        if (!s2.isempty())
            cout << " not ";
        cout << "empty!" << endl
             << endl;

        cout << "Push some items into Stack s1..." << endl;
        while (1)
        {
            item = rand();
            cout << "Push item " << item << " into Stack s1 ";
            if (s1.push(item))
                cout << "successful!" << endl;
            else
            {
                cout << "fail. Stack s1's already full." << endl;
                break;
            }
        }
        cout << "Now Stack s1 is ";
        if (!s1.isfull())
            cout << "not ";
        cout << "full!" << endl
             << endl;

        cout << "Make Stack s2 equal to s1..." << endl;
        s2 = s1;
        cout << "Now Stack s2 is ";
        if (!s2.isfull())
            cout << "not ";
        cout << "full!" << endl
             << endl;

        cout << "Pop some items out of Stack s2..." << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Pop item ";
            if (s2.pop(item))
                cout << item << " out of Stack s2 successful!" << endl;
            else
            {
                cout << "failed. Stack s2's already empty." << endl;
                break;
            }
        }
        cout << "Now Stack s2 is ";
        if (!s2.isfull())
            cout << "not ";
        cout << "full ";
        if (s2.isempty())
            cout << "but empty!" << endl;
        else
            cout << "and not empty!" << endl;
        cout << endl;

        cout << "Generate Stack s3 with s2..." << endl;
        stack_::Stack s3(s2);
        cout << "Now Stack s3 is ";
        if (!s3.isfull())
            cout << "not ";
        cout << "full ";
        if (s3.isempty())
            cout << "but empty!" << endl;
        else
            cout << "and not empty!" << endl;
        cout << endl;

        cout << "Pop some items out of Stack s3..." << endl;
        while (1)
        {
            cout << "Pop item ";
            if (s3.pop(item))
                cout << item << " out of Stack s3 successful!" << endl;
            else
            {
                cout << "failed. Stack s3's already empty." << endl;
                break;
            }
        }
        cout << "Now Stack s3 is ";
        if (!s3.isempty())
            cout << "not " << endl;
        cout << "empty!" << endl;
        cout << endl;
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 05
    cout << "Subject 05" << endl;
    {
        const int MIN_PER_HR = 60;
        cout << "Case Test: Bank of Heather Automatic Teller" << endl;
        cout << "Test Condition: " << endl;
        int qs = 10;
        queue::Queue line(qs); // line queue holds up to qs people
        cout << "Number of ATMs: " << 1
             << "\tMaximum size of queue: " << qs;

        int hours = 100; //  hours of simulation
        // simulation will run 1 cycle per minute
        long cyclelimit = MIN_PER_HR * hours; // # of cycles
        cout << "\tSimulation time span (hours): " << hours << endl;

        cout << "\nTest Beginning..." << endl;
        double perhour = 20; //  average # of arrival customers per hour

        double average_queue_size = 0;
        double average_wait_time = 100;

        while (average_wait_time > 1 && perhour > 0)
        {
            double min_per_cust; //  average time between arrivals
            min_per_cust = MIN_PER_HR / perhour;

            queue::Item temp;   //  new customer data
            long turnaways = 0; //  turned away by full queue
            long customers = 0; //  joined the queue
            long served = 0;    //  served during the simulation
            long sum_line = 0;  //  cumulative line length
            int wait_time = 0;  //  time until autoteller is free
            long line_wait = 0; //  cumulative time in line

            line.Clear();
            cout << "Customers per hour: " << int(perhour--) << endl;

            // running the simulation
            for (int cycle = 0; cycle < cyclelimit; cycle++)
            {
                if (newcustomer(min_per_cust)) // have newcomer
                {
                    if (line.isfull())
                        turnaways++;
                    else
                    {
                        customers++;
                        temp.set(cycle);    // cycle = time of arrival
                        line.enqueue(temp); // add newcomer to line
                    }
                }

                if (wait_time <= 0 && !line.isempty())
                {
                    line.dequeue(temp);       // attend next customer
                    wait_time = temp.ptime(); // for wait_time minutes
                    line_wait += cycle - temp.when();
                    served++;
                }

                if (wait_time > 0)
                    wait_time--;

                sum_line += line.queuecount();
            }

            // results
            if (customers > 0)
            {
                average_queue_size = (double)sum_line / cyclelimit;
                average_wait_time = (double)line_wait / served;
                cout << "customers accepted: " << customers << endl;
                cout << "  customers served: " << served << endl;
                cout << "         turnaways: " << turnaways << endl;
                cout << "average queue size: ";
                cout.precision(2);
                cout.setf(ios_base::fixed, ios_base::floatfield);
                cout << average_queue_size << endl;
                cout << " average wait time: "
                     << average_wait_time << " minutes\n"
                     << endl;
            }
            else
                cout << "No customers!\n";
        }
        cout << "Test done!\n"
             << "Under the specific condition above, "
             << "in order to make average wait time less than 1 min, "
             << "the arrival customers per hour must be " << int(perhour + 1)
             << endl;
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 06
    cout << "Subject 06" << endl;
    {
        const int MIN_PER_HR = 60;
        cout << "Case Test: Bank of Heather Automatic Teller" << endl;
        cout << "Test Condition: " << endl;
        int qs = 10;
        queue::Queue line1(qs); // line queue holds up to qs people
        queue::Queue line2(qs);
        cout << "Number of ATMs: " << 2
             << "\tMaximum size of queue: " << qs;

        int hours = 100; //  hours of simulation
        // simulation will run 1 cycle per minute
        long cyclelimit = MIN_PER_HR * hours; // # of cycles
        cout << "\tSimulation time span (hours): " << hours << endl;

        cout << "\nTest Beginning..." << endl;
        double perhour = 60; //  average # of arrival per hour

        double average_queue_size = 0;
        double average_wait_time = 100;

        while (average_wait_time > 1 && perhour > 0)
        {
            double min_per_cust; //  average time between arrivals
            min_per_cust = MIN_PER_HR / perhour;

            queue::Item temp;   //  new customer data
            long turnaways = 0; //  turned away by full queue
            long customers = 0; //  joined the queue
            long served = 0;    //  served during the simulation
            long sum_line = 0;  //  cumulative line length
            int wait_time1 = 0; //  time until autoteller 1 is free
            int wait_time2 = 0;
            long line_wait = 0; //  cumulative time in line

            line1.Clear();
            line2.Clear();
            cout << "Customers per hour: " << int(perhour--) << endl;

            // running the simulation
            for (int cycle = 0; cycle < cyclelimit; cycle++)
            {
                if (newcustomer(min_per_cust)) // have newcomer
                {
                    if (line1.isfull() && line2.isfull())
                        turnaways++;
                    else
                    {
                        customers++;
                        temp.set(cycle); // cycle = time of arrival
                        if (line1.queuecount() < line2.queuecount())
                            line1.enqueue(temp); // add newcomer to line
                        else
                            line2.enqueue(temp);
                    }
                }

                if (wait_time1 <= 0 && !line1.isempty())
                {
                    line1.dequeue(temp);       // attend next customer
                    wait_time1 = temp.ptime(); // for wait_time minutes
                    line_wait += cycle - temp.when();
                    served++;
                }

                if (wait_time2 <= 0 && !line2.isempty())
                {
                    line2.dequeue(temp);       // attend next customer
                    wait_time2 = temp.ptime(); // for wait_time minutes
                    line_wait += cycle - temp.when();
                    served++;
                }

                if (wait_time1 > 0)
                    wait_time1--;

                if (wait_time2 > 0)
                    wait_time2--;

                sum_line += line1.queuecount() + line2.queuecount();
            }

            // results
            if (customers > 0)
            {
                average_queue_size = (double)sum_line / cyclelimit / 2;
                average_wait_time = (double)line_wait / served;
                cout << "customers accepted (total): " << customers << endl;
                cout << "  customers served (total): " << served << endl;
                cout << "                 turnaways: " << turnaways << endl;
                cout << "        average queue size: ";
                cout.precision(2);
                cout.setf(ios_base::fixed, ios_base::floatfield);
                cout << average_queue_size << endl;
                cout << "         average wait time: "
                     << average_wait_time << " minutes\n"
                     << endl;
            }
            else
                cout << "No customers!\n";
        }
        cout << "Test done!\n"
             << "Under the specific condition above, "
             << "in order to make average wait time less than 1 min, "
             << "the arrival customers per hour must be " << int(perhour + 1)
             << endl;
    }

    return 0;
}
