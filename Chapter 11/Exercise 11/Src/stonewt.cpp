// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout, std::endl;
#include "stonewt.h"

/* Subject 05 and Subject 06 Modification */
// // construct Stonewt object from double value
// Stonewt::Stonewt(double lbs)
// {
//     stone = int(lbs) / Lbs_per_stn; // integer division
//     pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
//     pounds = lbs;
// }

// // construct Stonewt object from stone, double values
// Stonewt::Stonewt(int stn, double lbs)
// {
//     stone = stn;
//     pds_left = lbs;
//     pounds = stn * Lbs_per_stn + lbs;
// }

// Stonewt::Stonewt() // default constructor, wt = 0
// {
//     stone = pounds = pds_left = 0;
// }

// Stonewt::~Stonewt() // destructor
// {
// }

// // show weight in stones
// void Stonewt::show_stn() const
// {
//     cout << stone << " stone, " << pds_left << " pounds\n";
// }

// // show weight in pounds
// void Stonewt::show_lbs() const
// {
//     cout << pounds << " pounds\n";
// }

// Subject 05

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, WeightUnit wtunit)
{
    stone = int(lbs) / Lbs_per_stn; // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    unit = wtunit;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, WeightUnit wtunit)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    unit = wtunit;
}

Stonewt::Stonewt() // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
    unit = cSTONE;
}

// Subject 05
Stonewt Stonewt::operator+(const Stonewt &st) const
{
    Stonewt temporary;
    temporary.pounds = pounds + st.pounds;
    temporary.stone = int(temporary.pounds) / Lbs_per_stn; // integer division
    temporary.pds_left = int(temporary.pounds) % Lbs_per_stn +
                         temporary.pounds - int(temporary.pounds);
    return temporary;
}

Stonewt Stonewt::operator-(const Stonewt &st) const
{
    Stonewt temporary;
    temporary.pounds = pounds - st.pounds;
    temporary.stone = int(temporary.pounds) / Lbs_per_stn; // integer division
    temporary.pds_left = int(temporary.pounds) % Lbs_per_stn +
                         temporary.pounds - int(temporary.pounds);
    return temporary;
}

Stonewt Stonewt::operator*(const double n) const
{
    Stonewt temporary;
    temporary.pounds = pounds * n;
    temporary.stone = int(temporary.pounds) / Lbs_per_stn; // integer division
    temporary.pds_left = int(temporary.pounds) % Lbs_per_stn +
                         temporary.pounds - int(temporary.pounds);
    return temporary;
}

ostream &operator<<(ostream &os, const Stonewt &wt)
{
    switch (wt.unit)
    {
    case cSTONE:
        os << wt.stone << " stone and " << wt.pds_left << " pounds";
        break;
    case cINTEGRATE_POUNDS:
        os << "nearly " << int(wt.pounds) << " pounds";
        break;
    case cFLOAT_POUNDS:
        os << wt.pounds << " pounds";
        break;
    }
    return os;
}