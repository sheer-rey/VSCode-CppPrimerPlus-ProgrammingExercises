/*******************************************************************************
 * @p Question:
 * In my compile enviroment (Windows 10, MinGW-W64 with gcc 8.1.0 and
 * Microsoft's C/C++ plugin of visual studio code), there's a critial problem.
 *
 * While running this programme VSCode's integrated terminal (Git Bash shell),
 * the EOF bit of ifstream cannot be set correctly while reading the file,
 * and it will stuck in while loop and continue to extract the last word of file
 * to be read at around line 56 of this file.
 *
 * But it can work correctly via running the executable (.exe) file directly in
 * Windows's File Explorer.
 *
 * I wonder know WHY?
 *
 * @p Temporary_Answer:
 * The reason may because of the difference of EOF sign between Linux and
 * Windows operating system ( my system is Windows 10, and Git Bash shell based
 * on Linux ).
 *
 * On Unix/Linux, every line in a file has an End-Of-Line ( EOL ) character and
 * the EOF character is after the last line.
 * On windows, each line has an EOL characters except the last line.
 *
 * So Unix/Linux file's last line is stuff, EOL and EOF, whereas Windows file's
 * last line, if the cursor is on the line, is stuff and EOF.
 *
 * In order to set up data files on Windows to be the same as on Unix/Linux, we
 * need to correctly determine EOF under both Unix/Linux and Windows.
 * In general, we just need to set the cursor at the end of last line of data
 * file in Windows, and press Enter, then save the file. This will make Windows
 * data file the same as which on Linux.
 *
 * It doesn't work in my Windows enviroment. So I just modified the EOF checking
 * method as below ( line 62~65 ), now it gonna to work cocrrectly.
 * But the deep reason I still haven't figure out. I will keep looking for it.
 * ****************************************************************************/

#include "subject03.h"

namespace subject03
{
  vector<string> word_list;
  void GetWordList()
  {
    ifstream fin(R"(./Files/word_list)");
    if (!fin.is_open())
    {
      cerr << "Could not open file \"word_list\"\nProgramme Terminated."
           << endl;
      exit(EXIT_FAILURE);
    }
    cout << "Open file \"word_list\" successful!" << endl;
    string temp;
    fin >> temp;
    while (fin.good())
    {
      word_list.push_back(temp);
      // cout << temp << endl; // stream info checkout, to be commented
      fin >> temp;

      /* Temporary Solution Begin */
      if (fin.peek() == EOF)
        fin.clear(std::ios_base::eofbit);
      /* Temporary Solution End */
    }
    if (fin.eof())
    {
      fin.clear();
      cout << "Get Word List Success!" << endl;
      fin.close();
    }
    else
    {
      fin.clear();
      cerr << "Unknown error in reading file \"word_list\"\nProgramme Terminated." << endl;
      fin.close();
      exit(EXIT_FAILURE);
    }
  }

  void HangMan()
  {
    GetWordList();
    std::srand(std::time(0));
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
      string target = word_list[std::rand() % word_list.size()];
      int length = target.length();
      string attempt(length, '-');
      string badchars;
      int guesses = 6;
      cout << "Guess my secret word. It has " << length
           << " letters, and you guess\n"
           << "one letter at a time. You get " << guesses
           << " wrong guesses.\n";
      cout << "Your word: " << attempt << endl;
      while (guesses > 0 && attempt != target)
      {
        char letter;
        cout << "Guess a letter: ";
        cin >> letter;
        if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
        {
          cout << "You already guessed that. Try again.\n";
          continue;
        }
        auto loc = target.find(letter);
        if (loc == string::npos)
        {
          cout << "Oh, bad guess!\n";
          --guesses;
          badchars += letter; // add to string
        }
        else
        {
          cout << "Good guess!\n";
          attempt[loc] = letter;
          // check if letter appears again
          loc = target.find(letter, loc + 1);
          while (loc != string::npos)
          {
            attempt[loc] = letter;
            loc = target.find(letter, loc + 1);
          }
        }
        cout << "Your word: " << attempt << endl;
        if (attempt != target)
        {
          if (badchars.length() > 0)
            cout << "Bad choices: " << badchars << endl;
          cout << guesses << " bad guesses left\n";
        }
      }
      if (guesses > 0)
        cout << "That's right!\n";
      else
        cout << "Sorry, the word is " << target << ".\n";

      cout << "Will you play another? <y/n> ";
      cin >> play;
      play = tolower(play);
    }

    cout << "Bye\n";
  }
}
