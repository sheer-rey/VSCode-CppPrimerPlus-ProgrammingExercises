// vect.h -- Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode
        {
            RECT,
            POL
        };
        // RECT for rectangular, POL for Polar modes
    private:
        double x; // horizontal value
        double y; // vertical value

        /* Suject 02: comment the polar coordinates */
        // double mag; // length of vector
        // double ang; // direction of vector in degrees

        Mode mode; // RECT or POL
                   // private methods for setting values

        /* Suject 02: comment the polar coordinates and modify realization*/
        // void set_mag();
        // void set_ang();
        // void set_x();
        // void set_y();
        double set_mag() const;
        double set_ang() const;
        void set_x_y(double mag, double ang);

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; }           // report x value
        double yval() const { return y; }           // report y value
        double magval() const { return set_mag(); } // report magnitude
        double angval() const { return set_ang(); } // report angle
        void polar_mode();                          // set mode to POL
        void rect_mode();                           // set mode to RECT
                                                    // operator overloading
        Vector operator+(const Vector &b) const;
        Vector operator-(const Vector &b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        // friends
        friend Vector operator*(double n, const Vector &a);
        friend std::ostream &operator<<(std::ostream &os, const Vector &v);
    };

} // end namespace VECTOR
#endif
