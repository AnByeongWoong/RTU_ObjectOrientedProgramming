/// Below are commented asserts.
/// Remove comment from these lines as you finish the appropriate function to test its correctness.
/// If uncommented asserts work correctly, then there will not be any output.
/// Don't modify assert expressions!

#include "Cone.h"
#include <cmath>
#include <cassert>
    
int main()
{
    constexpr double epsil{ 0.005 };
    
    /// Item 3: Cone instance creation
    Cone c0{ M_PI, 5.0 };

    /// Item 4: Retrieve radius
//    assert(abs(M_PI - c0.radius()) < epsil);
    
    /// Item 4: Retrieve height
//    assert(abs(5.0 - c0.height()) < epsil);

    /// Item 5: Retrieve volume
//    assert(abs(51.68 - c0.volume()) < epsil);
    
    /// Item 5: Retrieve base area
//    assert(abs(31.0 - c0.base_area()) < epsil);

    /// Item 5: Retrieve lateral area
//    assert(abs(58.28 - c0.lateral_area()) < epsil);

    /// Item 5: Retrieve total surface area
//    assert(abs(89.28 - c0.total_area()) < epsil);
    
    return 0;
}