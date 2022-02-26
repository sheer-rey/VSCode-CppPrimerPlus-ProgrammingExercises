#include <iostream>
using namespace std;

int main()
{
    const int iARRAY_SIZE = 20;
    char cName[iARRAY_SIZE];
    char cDessert[iARRAY_SIZE];

    //cin.getline() func read a whole input line include line break, and then replace line break with NUL('\0')
    cout << "Please enter your name: ";
    cin.getline(cName, iARRAY_SIZE);
    cout << "Please enter your favorite dessert: ";
    cin.getline(cDessert, iARRAY_SIZE);
    cout << "I have some delicious " << cDessert << " for you, " << cName << "." << endl;

    cout << "Press any key to try again...";
    cin.get();

    //one version of cin.get() func read a whole input line but keep line break in input queue, so we need use a no-parameter cin.get() func to get rid of line break.
    cout << "Please enter your name: ";
    cin.get(cName, iARRAY_SIZE);
    cin.get();
    cout << "Please enter your favorite dessert: ";
    cin.get(cDessert, iARRAY_SIZE);
    cin.get();
    cout << "I have some delicious " << cDessert << " for you, " << cName << "." << endl;

    cout << "Press any key to try again...";
    cin.get();

    //concatenate two class member func
    cout << "Please enter your name: ";
    cin.get(cName, iARRAY_SIZE).get();
    cout << "Please enter your favorite dessert: ";
    cin.get(cDessert, iARRAY_SIZE).get();
    cout << "I have some delicious " << cDessert << " for you, " << cName << "." << endl;

    return 0;
}