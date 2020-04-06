#include "inventory.h"
#include <cmath>
#include<iostream>

Phone Inventory::find_item(const Phone& query)
{

    for (size_t i = 0; i < this->_count; i++)
    {
        constexpr double epsil{ 0.005 };
        // for integer type property
        if (query.get_name() != "" && query.get_name() != _items[i].get_name())
            continue;
        if (query.get_price() != 0.0 && (epsil < abs(query.get_price() - _items[i].get_price())))
            continue;

        if (!_items[i].get_spec()->matches(*query.get_spec()))
            continue;
        return _items[i];
    }

    return Phone{};
}
Phone Inventory::find_item(const PhoneSpec& otherSpec)
{
    for (size_t i = 0; i < _count; i++)
        if (_items[i].get_spec()->matches(otherSpec))
            return _items[i];

    return Phone{};
}

void Inventory::add_item(string name, double price, shared_ptr<const PhoneSpec> spec)
{
    //temp.init(name, type, price, capacityOfStorage, manufacturer);

    if (_count < Inventory::MAX_SIZE)
    {

        Phone newItem(name, price, spec);

        if (this->find_item(newItem).get_name() != "") {
            cout << "this item is already have" << endl;
            return;
        }


        _items[_count] = newItem;
        _count++;
    }
    cout << "the item " << name << "is added in inventory" << endl;

}