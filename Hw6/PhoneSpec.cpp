#include "PhoneSpec.h"

static const char* Type_cstr[] { "ANY", "SMARTPHONE", "TABLETPC", "FOLDERPHONE"};

PhoneSpec::PhoneSpec(PhoneSpec::Type type, double capacityOfStorage, string manufacturer)
{
    _type = type;
    _capacityOfStorage = capacityOfStorage;
    _manufacturer = manufacturer;

}

string PhoneSpec::get_typeByString() const
{
    if (_type == PhoneSpec::Type::SMARTPHONE) {
        return "SmartPhone";
    }
    else if (_type == PhoneSpec::Type::TABLETPC) {
        return "TabletPC";
    }
    else if (_type == PhoneSpec::Type::FOLDERPHONE) {
        return "FolderPhone";
    }
    else {
        return "Any";
    }
}

bool PhoneSpec::matches(const PhoneSpec& otherSpec) const
{
    if (this == &otherSpec) {
        return true;
    }

    if (PhoneSpec::Type::ANY != otherSpec.get_type() && _type != otherSpec.get_type()) {
        return false;
    }
    if (otherSpec.get_capacityOfStorage() != 0.0 && otherSpec.get_capacityOfStorage() != _capacityOfStorage) {
        return false;
    }
    if (otherSpec.get_manufacturer() != "" && otherSpec.get_manufacturer() != _manufacturer) {
        return false;
    }
    return true;

}

std::ostream & operator<<(std::ostream & os, PhoneSpec::Type type)
{
    os << Type_cstr[static_cast<size_t>(type)];
    return os;
}

void PhoneSpec::send_to(std::ostream & os) const
{
    os  << this->_type << ';'
        << this->_capacityOfStorage << ';'
        << this->_manufacturer;
}

std::istream & operator>>(std::istream & is, PhoneSpec::Type & type)
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
                if (0 == strcasecmp(tmp.c_str(), Type_cstr[i])) // for POSIX C++ include <strings.h>
                //if (0 == _stricmp(tmp.c_str(), Type_cstr[i]))     // Visual C++
                {
                    type = static_cast<PhoneSpec::Type>(i);
                    found = true;
                    break;
                }
            }
            if (!found)
                type = PhoneSpec::Type::ANY;
        }
    }
    return is;
}

std::istream & operator>>(std::istream & is, PhoneSpec & item)
{
    item.recv_from(is);
    return is;
}
void PhoneSpec::recv_from(std::istream & is)
{
   
    // Must be in the same order as in BicycleSpec::send_to(..)
    
    if (is)
        is >> this->_type; // operator>>() processed ';'

    if (is)
        (is >> this->_capacityOfStorage).ignore(); // call ignore() to skip ';'
    
    if (is)
        (is >> this->_manufacturer).ignore();

}