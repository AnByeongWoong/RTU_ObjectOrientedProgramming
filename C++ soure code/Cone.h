/// Add required C++ statements to declare and define the class Cone
// #ifndef CONE_H
// #define CONE_H
#include "Circle.h"

class Cone
{
    public:
        Cone() = default;
        Cone(float height, float radius);

        float get_h() const {return h; }
        float get_r() const {return b.get_radius();}
        float volume();
        float base_area();
        float lateral_area();
        float total_area();
    private:
        //float _r;
        float h;
        Circle b;
};
// #endif
//:::