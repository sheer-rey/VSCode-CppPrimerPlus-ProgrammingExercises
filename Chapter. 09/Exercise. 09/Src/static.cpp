#include <iostream>
#include <string>
#include "static.h"

void strcount(std::string str)
{
    using namespace std;
    static int total = 0; // static local variable
    int count = 0;        // automatic local variable

    cout << "\"" << str << "\" contains ";
    count = str.length();
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
