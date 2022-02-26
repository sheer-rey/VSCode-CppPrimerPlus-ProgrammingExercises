// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

/* Subject 05 and Subject 06 Modification */
enum WeightUnit
{
    cSTONE,
    cINTEGRATE_POUNDS,
    cFLOAT_POUNDS
};

class Stonewt
{
private:
    enum // pounds per stone
    {
        Lbs_per_stn = 14
    };

    int stone;       // whole stones
    double pds_left; // fractional pounds
    double pounds;   // entire weight in pounds

    /* Subject 05 and Subject 06 Modification */
    // forward declaration
    WeightUnit unit = cSTONE;

public:
    /* Subject 05 and Subject 06 Modification */
    // Stonewt(double lbs);          // constructor for double pounds
    // Stonewt(int stn, double lbs); // constructor for stone, lbs
    // Stonewt();                    // default constructor
    // ~Stonewt();
    // void show_lbs() const; // show weight in pounds format
    // void show_stn() const; // show weight in stone format
    Stonewt(double lbs, WeightUnit wtunit = cSTONE);          // constructor for double pounds
    Stonewt(int stn, double lbs, WeightUnit wtunit = cSTONE); // constructor for stone, lbs
    Stonewt();                                                // default constructor
    ~Stonewt() = default;

    /* Subject 05 and Subject 06 Modification */
    // Subject 05
    Stonewt &SwitchUnit(WeightUnit wtunit) { unit = wtunit; return *this; }
    Stonewt operator+(const Stonewt &st) const;
    Stonewt operator-(const Stonewt &st) const;
    Stonewt operator*(const double n) const;
    friend Stonewt operator*(const double n, const Stonewt &st) { return st * n; }
    friend ostream &operator<<(ostream &os, const Stonewt &wt);

    // Subject 06
    bool operator>(const Stonewt &st) const { return pounds > st.pounds; }
    bool operator<(const Stonewt &st) const { return pounds < st.pounds; }
    bool operator==(const Stonewt &st) const { return pounds == st.pounds; }
    bool operator>=(const Stonewt &st) const { return pounds >= st.pounds; }
    bool operator<=(const Stonewt &st) const { return pounds <= st.pounds; }
    bool operator!=(const Stonewt &st) const { return pounds != st.pounds; }
};
#endif
