#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n_char_bits = CHAR_BIT;
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << "The Bits of Type char is " << n_char_bits << " bits." << endl;
    cout << "Type short is " << sizeof(n_short) << " Bytes." << endl;
    cout << "Type int is " << sizeof(n_int) << " Bytes." << endl;
    cout << "Type long is " << sizeof(n_long) << " Bytes." << endl;
    cout << "Type long long is " << sizeof(n_llong) << " Bytes." << endl;

    cout << endl;

    cout << "The Bits of Type char is " << n_char_bits << " bits." << endl;
    cout << "Type short is " << sizeof(short) << " Bytes." << endl;
    cout << "Type int is " << sizeof(int) << " Bytes." << endl;
    cout << "Type long is " << sizeof(long) << " Bytes." << endl;
    cout << "Type long long is " << sizeof(long long) << " Bytes." << endl;

    return 0;
}