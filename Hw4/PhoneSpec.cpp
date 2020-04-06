#include "PhoneSpec.h"

PhoneSpec::PhoneSpec()
{
    
    _type = PhoneSpec::Type::ANY;
    _capacityOfStorage = 0.0;
    _manufacturer = "";
}

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