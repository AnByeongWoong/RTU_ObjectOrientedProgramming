#include "Phone.h"

void Phone::init(string name, Phone::Type type, double price, double capacityOfStorage, string manufacturer)
{
    _name = name;
    _type = type;
    _price = price;
    _capacityOfStorage = capacityOfStorage;
    _manufacturer = manufacturer;
}

string Phone::get_typeByString() const 
{   
    if(_type == Phone::Type::SMARTPHONE){
        return "SmartPhone";
    }
    else if(_type == Phone::Type::TABLETPC){
        return "TabletPC";
    }
    else if(_type == Phone::Type::FOLDERPHONE){
        return "FolderPhone";
    }
    else{
        return "Any";
    }
}