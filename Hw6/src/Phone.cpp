#include "Phone.h"


Phone::Phone(string name, double price, shared_ptr<const PhoneSpec> spec)
{
    _name = name;
    _price = price;
    _spec = spec;
}
