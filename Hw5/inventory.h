#ifndef INVENTORY_H
#define INVENTORY_H

#include "Phone.h"

class Inventory
{
public:
    // Initializes the inventory for storing abstraction objects
    /////Hw4
    //void init() { _count = 0; }
    Inventory() { _count = 0; };


    size_t get_count() const { return _count; }
    Phone get_item(size_t i) const { return (i < _count) ? _items[i] : Phone{}; }
    // void add_item(string name, double price, const PhoneSpec& spec);
    //Phone find_item(const PhoneSpec& query);
    Phone find_item(const Phone& query);
    void add_item(string name, double price, shared_ptr<const PhoneSpec> spec);
    Phone find_item(const PhoneSpec& otherSpec);

private:
    // The maximum number of abstraction objects that can be stored
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    Phone _items[Inventory::MAX_SIZE];

    // The number of currently stored abstraction objects in the array _items
    size_t _count;
};

#endif
