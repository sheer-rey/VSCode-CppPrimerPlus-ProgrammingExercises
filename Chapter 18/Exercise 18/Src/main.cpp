#include <iostream>
#include "subjects.h"

int main(int argc, const char *argv[])
{
    // Subject 01
    std::cout << "Subject 01" << std::endl;
    {
        using namespace subject01;
        auto q = AverageList({15.4, 10.7, 9.0});
        std::cout << q << std::endl;

        std::cout << AverageList({20, 30, 19, 17, 45, 38}) << std::endl;

        auto ad = AverageList<double>({'A', 70, 65.33});
        std::cout << ad << std::endl;
    }
    std::cin.sync();
    std::cout << "\nPress any key to continue." << std::endl;
    std::cin.get();

    // Subject 02
    std::cout << "Subject 02" << std::endl;
    {
        using namespace subject02;

        cout << "Use Default Constructor" << endl;
        Cpmv default_obj;

        cout << "\nUse Regular Constructor" << endl;
        Cpmv regular_obj("first par", "second par");

        cout << "\nUse Copy Constructor" << endl;
        Cpmv copy_obj(regular_obj);

        cout << "\nUse Move Constructor and Operator Add" << endl;
        Cpmv move_obj(move(Cpmv("1st parameter", "2nd parameter")));

        cout << "\nUse Copy Operator Assignment" << endl;
        default_obj = move_obj;

        cout << "\nUse Move Operator Assignment and Operator Add" << endl;
        copy_obj = regular_obj + move_obj;

        cout << "\nUse Display Function" << endl;
        copy_obj.Display();
        cout << endl;
    }
    std::cin.sync();
    std::cout << "\nPress any key to continue." << std::endl;
    std::cin.get();

    // Subject 03
    std::cout << "Subject 03" << std::endl;
    {
        using namespace subject03;
        cout << SumValue("sheer.rey", 'd', 41.3, 1, string("abcde"), 10, 2, 100)
             << endl;
    }
    std::cin.sync();
    std::cout << "\nPress any key to continue." << std::endl;
    std::cin.get();

    // Subject 04
    std::cout << "Subject 04" << std::endl;
    {
        using namespace subject04;

        int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
        list<int> yadayada(vals, vals + 10); // range constructor
        list<int> etcetera(vals, vals + 10);

        cout << "Original lists:\n";
        for_each(yadayada.begin(), yadayada.end(), outint);
        cout << endl;
        for_each(etcetera.begin(), etcetera.end(), outint);
        cout << endl;
        // use two anonymous lambda expression
        yadayada.remove_if([](const int &v)
                           { return v > 100; });
        etcetera.remove_if([](const int &v)
                           { return v > 200; });
        cout << "Trimmed lists:\n";
        for_each(yadayada.begin(), yadayada.end(), outint);
        cout << endl;
        for_each(etcetera.begin(), etcetera.end(), outint);
        cout << endl;
    }

    return 0;
}
