//About using namespace std;

// //Mothod 01
// #include <iostream>
// using namespace std;

// int main()
// {
//     cout << "Hello WOrld!" << endl;
//     return 0;
// }

// //Method 02
// #include <iostream>
// int main()
// {
//     std::cout << "Hello World!" << std::endl;
//     //若不写 return 0; 则程序默认认为是 return 0;
// }

//Method 03
#include <iostream>
using std::cout; //make std::cout and std::endl available
using std::endl;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
