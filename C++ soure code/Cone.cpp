/// Add required C++ statements to define the class Cone

#include "Cone.h"

Cone::Cone(float height, float radius)
{
    h = height;
    b = Circle(radius);
}

float Cone::volume(){
    return b.get_area()*h/3;
}
float Cone::base_area(){
    return b.get_area();
}

float Cone::lateral_area(){
    return M_PI*b.get_radius()*sqrt(pow(b.get_radius(),2)+pow(h,2));
}
float Cone::total_area(){
    return this.lateral_area()+this.base_area();
}