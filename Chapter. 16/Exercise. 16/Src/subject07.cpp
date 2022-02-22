#include "subject07.h"

namespace subject07
{
  vector<int> Lotto(int num_of_dots, int num_of_shufful_choose)
  {
    vector<int> vec;
    while (num_of_dots)
      vec.push_back(num_of_dots--);
    random_shuffle(vec.begin(), vec.end());
    return vector<int>(vec.begin(), vec.begin() + num_of_shufful_choose);
  }

  void ShowWinnersValue(vector<int> &winners)
  {
    ostream_iterator<int> os_it(std::cout, " ");
    for (int x : winners)
      *os_it = x;
  }

}
