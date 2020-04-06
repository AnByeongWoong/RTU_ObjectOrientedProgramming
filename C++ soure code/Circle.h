/// Don't modify anything in this file!

#ifndef CIRCLE
#define CIRCLE

#include <cmath>

class Circle {
public:
    Circle(double radius) : r(radius) { }
    double get_radius() const { return r;  }
    double get_area() const { return M_PI * r * r; } 
private:
    double r;
};

#endif