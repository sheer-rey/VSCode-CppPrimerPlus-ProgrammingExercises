#include <iostream>
#include "namespace.h"

namespace SALES
{
  void setSales(Sales &s, const double ar[], int n)
  {
    int i;
    s.max = s.min = *ar;
    s.average = 0;
    for (i = 0; i < n && i < QUARTERS; i++)
    {
      s.sales[i] = ar[i];
      if (ar[i] > s.max)
        s.max = ar[i];
      if (ar[i] < s.min)
        s.min = ar[i];
      s.average += ar[i] / QUARTERS;
    }
    while (i < QUARTERS)
    {
      s.sales[i] = 0;
      if (ar[i] > s.max)
        s.max = ar[i];
      if (ar[i] < s.min)
        s.min = ar[i];
      i++;
    }
  }

  void setSales(Sales &s)
  {
    using namespace std;
    cout << "Please enter quarters' revenue: ";
    s.max = s.average = 0;
    s.min = -1;
    for (int i = 0; i < QUARTERS; i++)
    {
      cin >> s.sales[i];

      /* Error Check begin */
      while (!cin || s.sales[i] < 0)
      {
        cin.clear();
        cin.sync();
        cout << "\nInput error! Renter quarters' revenue: ";
        s.max = s.average = 0;
        s.min = -1;
        i = -1;
      }
      if (i == -1)
        continue;
      /* Error Check end */

      if (s.sales[i] > s.max)
        s.max = s.sales[i];
      if (s.sales[i] < s.min && s.min >= 0)
        s.min = s.sales[i];
      else if (s.min == -1)
        s.min = s.sales[i];
      s.average += s.sales[i] / QUARTERS;
    }
  }

  void showSales(const Sales &s)
  {
    using namespace std;
    cout << "Quarters' sales are as below" << endl;
    for (int i = 0; i < QUARTERS; i++)
      cout << "Season " << i + 1 << ": " << s.sales[i] << "\t";
    cout << "\nMaximum: " << s.max << "\tMinimum: " << s.min << "\tAverage: " << s.average << endl;
  }
}
