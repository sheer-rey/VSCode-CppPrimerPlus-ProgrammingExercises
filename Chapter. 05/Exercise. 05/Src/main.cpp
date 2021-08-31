#include <iostream>
#include <array>
using namespace std;

int main()
{
    //Exercise 01
    cout << "Exercise 01" << endl;
    cout << "Please enter two integer: ";
    int a_1, b_1;
    (cin >> a_1 >> b_1).get();
    if (a_1 > b_1)
    {
        /* exchange values in a_1 and b_1 */
        a_1 ^= b_1;
        b_1 ^= a_1;
        a_1 ^= b_1;
    }
    cout << "The integer sum between " << a_1 << " and " << b_1 << " is: ";
    for (int i = a_1 + 1; i <= b_1; i++)
        a_1 += i;
    cout << a_1 << endl;

    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 02
    cout << "Exercise 02" << endl;
    const int iARSIZE_2 = 16;
    array<long long, iARSIZE_2> llFactorial_2 = {1};
    for (int i = 1; i < int(llFactorial_2.size()); i++)
        llFactorial_2[i] = llFactorial_2[i - 1] * i;
    for (int i = 0; i < int(llFactorial_2.size()); i++)
        cout << i << "! = " << llFactorial_2.at(i) << endl;

    cout << "Press any key to continue." << endl;
    cin.get();

    //Exercise 03
    cout << "Exercise 03" << endl;
    return 0;
}