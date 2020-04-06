#include "inventory.h"
#include <cmath>
#include<iostream>
//#include "Phone.h"

void Inventory::add_item(string name, Phone::Type type, double price, double capacityOfStorage,string manufacturer)
{
    Phone temp;
    temp.init(name, type, price, capacityOfStorage,manufacturer);
    if(this->find_item(temp).get_name()!=""){
        cout<<"this item is already have"<<endl;
        return;    
    }
    if (_count < Inventory::MAX_SIZE)
    {
        Phone new_item;
        new_item.init(name, type, price, capacityOfStorage,manufacturer);
        _items[_count] = new_item;
        _count++;
    }
    
}

Phone Inventory::find_item(Phone query)
{
    for (size_t i = 0; i < this->_count; i++)
    {
        // for integer type property
        if (query.get_name() != "" && query.get_name() != _items[i].get_name())
            continue;

        // for string type property
        if (query.get_type() != Phone::Type::ANY && query.get_type() != _items[i].get_type())
            continue;

        // for floating type property
        constexpr double epsil{ 0.005 };
        if (query.get_price() != 0.0 && (epsil < abs(query.get_price() - _items[i].get_price())))
            continue;
        if (query.get_capacityOfStorage() != 0.0 && (epsil < abs(query.get_capacityOfStorage() - _items[i].get_capacityOfStorage())))
            continue;

        /////////
        if (query.get_manufacturer() != "" && query.get_manufacturer() != _items[i].get_manufacturer())
            continue;
        return _items[i];
    }

    return Phone{}; // return the 'default' object
}
