#include "Inventory.h"

//void Inventory::add_item(unsigned id, double price, std::string model, unsigned short model_year, std::shared_ptr<const BicycleSpec> spec)
void Inventory::add_item(std::shared_ptr<Item> new_item)
{
    if (_count < Inventory::MAX_SIZE)
    {
        //Bicycle new_item(id, price, model, model_year, spec);

        if (new_item->get_id() != find_item(*new_item->get_spec()).get_id())
        {
            _items[_count] = new_item;
            _count++;
        }
    }
}

/// This overload is not possible unless also the class Item implements some kind of function matched()
//const Item & Inventory::find_item(const Item & query) const
//{    
//    for (size_t i = 0; i < _count; i++)
//    {
//        // for integer type property
//        if (query.get_id() != 0
//            && query.get_id() != _items[i]->get_id())
//            continue;
//
//        // for floating type property
//        constexpr double epsil{ 0.005 };
//        if (query.get_price() != 0.0
//            && (epsil < abs(query.get_price() - _items[i].get_price())))
//            continue;
//		
//        // for string type property
//        if (query.get_model() != ""
//            && query.get_model() != _items[i].get_model())
//            continue;
//        
//        if (query.get_model_year() != 0
//            && query.get_model_year() != _items[i].get_model_year())
//            continue;
//
//        // check specification properties
//        if (false == _items[i]->get_spec()->matches(*query.get_spec())) // note the asterisk for dereferencing
//            continue;
//            
//        return *_items[i];
//    }
//
//    static const Item def{};
//    return def; // return the 'default' value object (or null in Java)
//}


const Item & Inventory::find_item(const ItemSpec & query_spec) const
{
    for (size_t i{ 0U }; i < _count; i++)
        if (_items[i]->get_spec()->matches(query_spec))
            return *_items[i]; // return the first object with a matching specification

    static const Item def{};
    return def; // return the 'default' value object (or null in Java)
}


void Inventory::save(const std::string & csv_file_name) const
{
    // TODO :::
}


void Inventory::load(const std::string & csv_file_name)
{
    // TODO :::
}