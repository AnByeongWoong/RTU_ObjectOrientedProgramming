#include "BicycleSpec.h"

#include <string> // for getline() function

#ifndef _MSC_VER
#include <strings.h> // for strcasecmp() function in POSIX C++
#endif

static const char* Type_cstr[]{ "Any", "MTB", "Street", "Beach", "BMX" };

std::ostream & operator<<(std::ostream & os, BicycleSpec::Type t)
{
    os << Type_cstr[static_cast<size_t>(t)];
    return os;
}


//std::ostream & operator<<(std::ostream & os, const BicycleSpec & spec)
//{
//    spec.send_to(os);
//    return os;
//}


void BicycleSpec::send_to(std::ostream & os) const {
    os << _type << ';'
       << _wheel_size << ';'
       << _gears;
}

std::istream & operator>>(std::istream & is, BicycleSpec::Type & type)
{
    if (is)
    {
        std::string tmp;
        getline(is, tmp, ';');

        if (is)
        {
            bool found{ false };

            for (size_t i{ 0 }; i < sizeof(Type_cstr)/sizeof(Type_cstr[0]); i++)
            {
                // Case insensitive comparison:
                #ifdef _MSC_VER
                if (0 == _stricmp(tmp.c_str(), Type_cstr[i]))   // for Visual Studio C++
                #else
                if (0 == strcasecmp(tmp.c_str(), Type_cstr[i])) // for POSIX/Linux C++
                #endif
                {
                    type = static_cast<BicycleSpec::Type>(i);
                    found = true;
                    break;
                }
            }
            if (!found)
                type = BicycleSpec::Type::ANY;
        }
    }
    return is;
}


std::istream & operator>>(std::istream & is, BicycleSpec & item)
{
    item.recv_from(is);
    return is;
}


void BicycleSpec::recv_from(std::istream & is)
{
    // Must be in the same order as in BicycleSpec::send_to(..)
    
    if (is)
        is >> _type; // operator>>() processed ';'

    if (is)
        (is >> _wheel_size).ignore(); // call ignore() to skip ';'
    
    if (is)
        (is >> _gears).ignore();
}


bool BicycleSpec::matches(const ItemSpec & itemSpec) const
{
    if (this == &itemSpec)
        return true;  // if comparing to self

    bool result{ true };

    // try to downcast to the required derived specification type
    auto temp{ dynamic_cast<const BicycleSpec*>(&itemSpec) };
    if (nullptr == temp)
        return false; // if itemSpec doesn't refer to BicycleSpec (or derived) class instance

    // cast to reference type for actual comparison of properties
    const BicycleSpec& otherSpec{ *temp };

    if (otherSpec.get_type() != BicycleSpec::Type::ANY
        && otherSpec.get_type() != this->_type)
        result = false;
        
    if (otherSpec.get_wheel_size() != 0
        && otherSpec.get_wheel_size() != this->_wheel_size)
        result = false;        

    if (otherSpec.get_gears() != 0
        && otherSpec.get_gears() != this->_gears)
        result = false;

    return result;
}
