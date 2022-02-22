#include "subject10.h"

namespace subject10
{
  bool operator<(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
  {
    if (r1->title < r2->title)
      return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
      return true;
    else
      return false;
  }

  bool WorseThan_Rating(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
  {
    if (r1->rating < r2->rating)
      return true;
    else
      return false;
  }

  bool GreaterThan_Rating(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
  {
    if (r1->rating > r2->rating)
      return true;
    else
      return false;
  }

  bool WorseThan_Price(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
  {
    if (r1->price < r2->price)
      return true;
    else
      return false;
  }

  bool GreaterThan_Price(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
  {
    if (r1->price > r2->price)
      return true;
    else
      return false;
  }

  bool FillReview(Review &rr)
  {
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
      return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
      return false;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
      return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
      continue;
    return true;
  }

  void ShowReview(const shared_ptr<Review> &rr)
  {
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
  }
}
