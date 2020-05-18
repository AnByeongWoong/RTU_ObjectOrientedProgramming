#include "Guitar.h"

void Guitar::send_to(std::ostream& os) const
{
    Item::send_to(os);

    os << ';' << _price;
}
