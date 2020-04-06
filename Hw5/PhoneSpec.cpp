#include "PhoneSpec.h"

/*PhoneSpec::PhoneSpec()
{

    _type = PhoneSpec::Type::ANY;
    _capacityOfStorage = 0.0;
    _manufacturer = "";
}*/

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

bool PhoneSpec::matches(const PhoneSpec & otherSpec) const
{
    if(this == &otherSpec){
        return true;
    }

    if(PhoneSpec::Type::ANY != otherSpec.get_type() && _type != otherSpec.get_type()){
        return false;
    }
    if(otherSpec.get_capacityOfStorage() != 0.0 && otherSpec.get_capacityOfStorage() != _capacityOfStorage){
        return false;
    }
    if(otherSpec.get_manufacturer() != "" && otherSpec.get_manufacturer() != _manufacturer){
        return false;
    }
    return true;

}