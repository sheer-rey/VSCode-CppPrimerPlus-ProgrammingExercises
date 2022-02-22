#ifndef SUBJECT10_H_
#define SUBJECT10_H_

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

namespace subject10
{
  using std::shared_ptr;
  using std::sort;
  using std::string;

  struct Review
  {
    std::string title;
    int rating;
    int price;
  };

  bool operator<(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
  bool WorseThan_Rating(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
  bool GreaterThan_Rating(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
  bool WorseThan_Price(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
  bool GreaterThan_Price(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
  bool FillReview(Review &rr);
  void ShowReview(const shared_ptr<Review> &rr);

}

#endif
