#include "inventory.h"
#include <cmath>

void Inventory::add_item(string name, string type, double price, string manufacturer)
{
    if (_count < Inventory::MAX_SIZE)
    {
        Phone new_item;
        new_item.init(name, type, price, manufacturer);
        _items[_count] = new_item;
        _count++;
    }
}

Phone Inventory::find_item(Phone query)
{
    for (size_t i = 0; i < _count; i++)
    {
        // for integer type property
        if (query.get_name() != ""&& query.get_name() != _items[i].get_name())
            continue;

        // for string type property
        if (query.get_type() != ""&& query.get_type() != _items[i].get_type())
            continue;

        // for floating type property
        constexpr double epsil{ 0.005 };
        if (query.get_price() != 0.0&& (epsil < abs(query.get_price() - _items[i].get_price())))
            continue;
        
        /////////
        if(query.get_manufacturer() != "" && query.get_manufacturer() != _items[i].get_manufacturer() )
            continue;
        return _items[i];
    }

    return Phone{}; // return the 'default' object
}
