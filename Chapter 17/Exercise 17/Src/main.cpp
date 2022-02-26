/*******************************************************************************
 * @attention
 * Subject 02 and 03 required use the file name specified by command prompt.
 * In this exercise programme, you need to specify all file names as subject02
 * and 03 asked with in only one piece of command line.
 *
 * @example
 * The command line may be like below:
 * $ ./Exercise.\ 17.exe ./Files/subject02.txt ./files/subject03.txt
 * ****************************************************************************/

#include <iostream>
#include "subjects.h"
#include <ios>

int main(int argc, const char *argv[])
{
    // command check
    if (argc < 3)
    {
        std::cerr << "Arguments are not enough for executing!" << std::endl;
        std::cerr << "Programme Terminated!" << std::endl;
        exit(EXIT_FAILURE);
    }

    // // Subject 01
    // std::cout << "Subject 01" << std::endl;
    // {
    //     using namespace subject01;
    //     GetInstreamCount();
    // }
    // std::cin.sync();
    // std::cout << "\nPress any key to continue." << std::endl;
    // std::cin.get();

    // // Subject 02
    // std::cout << "Subject 02" << std::endl;
    // {
    //     using namespace subject02;
    //     GetKeyboardInput2File(argv[1]);
    // }
    // std::cin.sync();
    // std::cout << "\nPress any key to continue." << std::endl;
    // std::cin.get();

    // // Subject 03
    // std::cout << "Subject 03" << std::endl;
    // {
    //     using namespace subject03;
    //     FileContentsTransfer(argv[1], argv[2]);
    // }
    // std::cin.sync();
    // std::cout << "\nPress any key to continue." << std::endl;
    // std::cin.get();

    // // Subject 04
    // std::cout << "Subject 04" << std::endl;
    // {
    //     using namespace subject04;
    //     FilesMerge(argv[1], argv[2], "./Files/subject04.txt");
    // }
    // std::cin.sync();
    // std::cout << "\nPress any key to continue." << std::endl;
    // std::cin.get();

    // Subject 05
    std::cout << "Subject 05" << std::endl;
    {
        using namespace subject05;
        Person mat("Mat"), pat("Pat");
        mat.GetFriends().ShowFriends();
        pat.GetFriends().ShowFriends();
        mat.MergeFriends(pat).StoreFriends();
    }
    std::cin.sync();
    std::cout << "\nPress any key to continue." << std::endl;
    std::cin.get();

    // Subject 06
    std::cout << "Subject 06" << std::endl;
    {
    }
    std::cin.sync();
    std::cout << "\nPress any key to continue." << std::endl;
    std::cin.get();

    // Subject 07
    std::cout << "Subject 07" << std::endl;
    {
    }

    return 0;
}
