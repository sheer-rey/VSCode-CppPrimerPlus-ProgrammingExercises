#include "subject04.h"

namespace subject04
{
  int Reduce(long ar[], int n)
  {
    sort(ar, ar + n);
    long *end = unique(ar, ar + n);
    return int(end - ar);
  }

  void DisplayArray(long ar[], int n)
  {
    cout << "The array has " << n << " element as below: " << endl;
    ostream_iterator<long> arr_out(cout, " ");
    for (int i = 0; i < n; i++)
      *arr_out++ = ar[i];
    cout << endl;
  }
}
