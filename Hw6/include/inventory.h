#ifndef INVENTORY_H
#define INVENTORY_H

#include "Phone.h"

class Inventory
{
public:
    Inventory() { _count = 0; };


    size_t get_count() const { return _count; }
    Phone get_item(size_t i) const { return (i < _count) ? _items[i] : Phone{}; }
    Phone find_item(const Phone& query);
    void add_item(string name, double price, shared_ptr<const PhoneSpec> spec);
    Phone find_item(const PhoneSpec& otherSpec);

private:
    static const size_t MAX_SIZE{ 10 };

    Phone _items[Inventory::MAX_SIZE];

    size_t _count;
};

#endif
