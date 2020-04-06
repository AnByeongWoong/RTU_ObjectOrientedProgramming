#include "inventory.h"
#include <cmath>
#include<iostream>
//#include "Phone.h"


// Phone Inventory::find_item(const PhoneSpec& query)
// {
//     if (query.get_type() == PhoneSpec::Type::ANY && query.get_capacityOfStorage() == 0.0 && query.get_manufacturer() == "")
//         return Phone{};
//     for (size_t i = 0; i < this->_count; i++)
//     {
//         constexpr double epsil{ 0.005 };

//         // for string type property
//         if (query.get_type() != PhoneSpec::Type::ANY && query.get_type() != _items[i].get_spec().get_type())
//             continue;

//         // for floating type property


//         if (query.get_capacityOfStorage() != 0.0 && (epsil < abs(query.get_capacityOfStorage() - _items[i].get_spec().get_capacityOfStorage())))
//             continue;

//         /////////
//         if (query.get_manufacturer() != "" && query.get_manufacturer() != _items[i].get_spec().get_manufacturer())
//             continue;
//         return _items[i];
//     }

//     return Phone{}; // return the 'default' object
// }
// Phone Inventory::find_item(const Phone& query)
// {
       
//     for (size_t i = 0; i < this->_count; i++)
//     {
//         constexpr double epsil{ 0.005 };
//         // for integer type property
//         if (query.get_name() != "" && query.get_name() != _items[i].get_name())
//             continue;
//         if (query.get_price() != 0.0 && (epsil < abs(query.get_price() - _items[i].get_price())))
//             continue;
//         // for string type property
//         if (query.get_spec().get_type() != PhoneSpec::Type::ANY && query.get_spec().get_type() != _items[i].get_spec().get_type())
//             continue;

//         // for floating type property


//         if (query.get_spec().get_capacityOfStorage() != 0.0 && (epsil < abs(query.get_spec().get_capacityOfStorage() - _items[i].get_spec().get_capacityOfStorage())))
//             continue;

//         /////////
//         if (query.get_spec().get_manufacturer() != "" && query.get_spec().get_manufacturer() != _items[i].get_spec().get_manufacturer())
//             continue;
//         return _items[i];
//     }

//     return Phone{}; // return the 'default' object
// }
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
Phone Inventory::find_item(const PhoneSpec & otherSpec)
{
    for (size_t i=0; i < _count; i++)
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