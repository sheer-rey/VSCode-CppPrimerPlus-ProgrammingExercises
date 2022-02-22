#ifndef SUBJECT05_H_
#define SUBJECT05_H_

#include <iostream>
#include <iterator>
#include <algorithm>

using std::ostream, std::cout, std::endl;
using std::ostream_iterator;
using std::unique, std::sort;

namespace subject05
{
  template <typename T>
  int Reduce(T ar[], int n)
  {
    sort(ar, ar + n);
    T *end = unique(ar, ar + n);
    return int(end - ar);
  }

  template <typename T>
  void DisplayArray(T ar[], int n)
  {
    cout << "The array has " << n << " element as below: " << endl;
    ostream_iterator<T> arr_out(cout, " ");
    for (int i = 0; i < n; i++)
      *arr_out++ = ar[i];
    cout << endl;
  }
}

#endif
