#include <iostream>
#include <typeinfo>

#include "subject01.h"
#include "subject02.h"
#include "subject03.h"
#include "subject04.h"
#include "subject05.hpp"
#include "subject06.h"
#include "subject07.h"
#include "subject08.h"
#include "subject09.h"
#include "subject10.h"

int main()
{
    // Subject 01
    cout << "Subject 01" << endl;
    {
        using namespace subject01;
        string str("ottTo");
        cout << '"' << str << '"' << " is";
        if (!Palindrome(str))
            cout << " not";
        cout << " a palindrome string." << endl;
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 02
    cout << "Subject 02" << endl;
    {
        using namespace subject02;
        string str("Madam, I'm Adam.");
        cout << '"' << str << '"' << " is";
        if (!Palindrome(str))
            cout << " not";
        cout << " a palindrome string." << endl;
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 03
    cout << "Subject 03" << endl;
    {
        using namespace subject03;
        HangMan();
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 04
    cout << "Subject 04" << endl;
    {
        using namespace subject04;
        long arr[14] = {11, 33, 22, 99, 77, 88, 44, 55, 22, 44, 22, 66, 99, 11};
        int n = Reduce(arr, 14);
        DisplayArray(arr, n);
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 05
    cout << "Subject 05" << endl;
    {
        using namespace subject05;
        long arr[14] = {11, 33, 22, 99, 77, 88, 44, 55, 22, 44, 22, 66, 99, 11};
        int n = Reduce(arr, 14);
        DisplayArray(arr, n);

        cout << endl;
        string str[8] = {"Sheer.rey",
                         "W+0",
                         "Pink Pather",
                         "W+0",
                         "Lover",
                         "Sheer.rey",
                         "Baby",
                         "Lover"};
        n = Reduce(str, 8);
        DisplayArray(str, n);
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 06
    cout << "Subject 06" << endl;
    {
        using namespace subject06;
        BankSimulation();
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 07
    cout << "Subject 07" << endl;
    {
        using namespace subject07;
        int num_range = 51;
        int num_choose = 6;
        cout << "The number range of lotto is 1~" << num_range
             << ", and ramdom choose " << num_choose << " values." << endl;
        vector<int> winners = Lotto(num_range, num_choose);
        cout << "Winner's value is: ";
        ShowWinnersValue(winners);
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 08
    cout << "Subject 08" << endl;
    {
        using namespace subject08;
        Person mat("Mat"), pat("Pat");
        mat.GetFriends().ShowFriends();
        pat.GetFriends().ShowFriends();
        mat.MergeFriends(pat).ShowFriends();
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 09
    cout << "Subject 09" << endl;
    {
        using namespace subject09;
        srand(time(nullptr));
        int array_size = 1000000;
        vector<int> vi0, vi;
        list<int> li;
        int val;
        while (array_size--)
        {
            val = rand();
            vi0.push_back(val);
            vi.push_back(val);
            li.push_back(val);
        }
        clock_t start = clock();
        sort(vi.begin(), vi.end());
        clock_t end = clock();
        cout << "Sorting vector takes "
             << double(end - start) / CLOCKS_PER_SEC << "s." << endl;

        start = clock();
        li.sort();
        end = clock();
        cout << "Sorting list takes "
             << double(end - start) / CLOCKS_PER_SEC << "s." << endl;

        copy(vi0.begin(), vi0.end(), li.begin());
        start = clock();
        copy(li.begin(), li.end(), vi.begin());
        sort(vi.begin(), vi.end());
        copy(vi.begin(), vi.end(), li.begin());
        end = clock();
        cout << "Sorting list (with the aid of vector) takes "
             << double(end - start) / CLOCKS_PER_SEC << "s." << endl;
    }
    cin.sync();
    cout << "\nPress any key to continue." << endl;
    cin.get();

    // Subject 10
    cout << "Subject 10" << endl;
    {
        using namespace subject10;

        vector<shared_ptr<Review>> books;
        Review temp;
        while (FillReview(temp))
        {
            shared_ptr<Review> temp_ptr(new Review(temp));
            books.push_back(temp_ptr);
        }
        if (books.size() > 0)
        {
            cout << "Enter review order as below: " << endl;
            cout << "o : origin            t : title" << endl;
            cout << "ra: rating ascending  rd: rating descending" << endl;
            cout << "pa: price ascending   pd: price descending" << endl;
            cout << "q : quit " << endl;
            string option;
            bool quit = false;

            vector<shared_ptr<Review>> back_up(books);

            while (cin >> option)
            {
                switch (option[0])
                {
                case 'o':
                    cout << "You entered the following "
                         << books.size() << " ratings:\n"
                         << "Rating\tBook\tPrice\n";
                    for_each(books.begin(), books.end(), ShowReview);
                    break;

                case 't':
                    sort(back_up.begin(), back_up.end());
                    cout << "Sorted by title:\nRating\tBook\tPrice\n";
                    for_each(back_up.begin(), back_up.end(), ShowReview);
                    break;

                case 'r':
                    if (option[1] == 'a')
                    {
                        sort(back_up.begin(), back_up.end(), WorseThan_Rating);
                        cout << "Sorted by rating (Ascending):\nRating\tBook\tPrice\n";
                    }
                    else if (option[1] == 'd')
                    {
                        sort(back_up.begin(), back_up.end(), GreaterThan_Rating);
                        cout << "Sorted by rating (Descending):\nRating\tBook\tPrice\n";
                    }
                    for_each(back_up.begin(), back_up.end(), ShowReview);
                    break;

                case 'p':
                    if (option[1] == 'a')
                    {
                        sort(back_up.begin(), back_up.end(), WorseThan_Price);
                        cout << "Sorted by price (Ascending):\nRating\tBook\tPrice\n";
                    }
                    else if (option[1] == 'd')
                    {
                        sort(back_up.begin(), back_up.end(), GreaterThan_Price);
                        cout << "Sorted by price (Descending):\nRating\tBook\tPrice\n";
                    }
                    for_each(back_up.begin(), back_up.end(), ShowReview);
                    break;

                case 'q':
                    quit = true;
                    break;

                default:
                    cout << "Input error!" << endl;
                    break;
                }
                if (quit)
                {
                    cout << "Bye.\n";
                    break;
                }
                else
                {
                    cout << endl;
                    cout << "Enter review order as below: " << endl;
                    cout << "o : origin            t : title" << endl;
                    cout << "ra: rating ascending  rd: rating descending" << endl;
                    cout << "pa: price ascending   pd: price descending" << endl;
                    cout << "q : quit " << endl;
                }
            }
        }
        else
            cout << "No entries. ";
    }

    return 0;
}
