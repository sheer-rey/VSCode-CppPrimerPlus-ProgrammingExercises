#ifndef SUBJECT07_H_
#define SUBJECT07_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace subject07
{
  using std::ostream_iterator;
  using std::random_shuffle;
  using std::vector;

  vector<int> Lotto(int num_of_dots, int num_of_shufful_choose);
  void ShowWinnersValue(vector<int> &winners);
}

#endif
