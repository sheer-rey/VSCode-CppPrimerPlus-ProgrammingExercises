#include <iostream>
using namespace std;

int main()
{
    float a,b;

    cout.setf(ios_base::fixed,ios_base::floatfield);    //将Cout输出改为定点表示法，并且使程序显示到小数点后6位

    cout << "Please Enter a Number: ";
    cin >> a;

    cout << "Please Enter Another Number: ";
    cin >> b;

    cout << "a=" << a << ", b=" << b << endl;
    cout << "a+b=" << a+b << endl;
    cout << "a-b=" << a-b << endl;
    cout << "a*b=" << a*b << endl;
    cout << "a/b=" << a/b << endl;

    return 0;
}
