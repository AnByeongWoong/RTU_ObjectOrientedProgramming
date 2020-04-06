#ifndef INVENTORY_H
#define INVENTORY_H

#include "Phone.h"

class Inventory
{
public:
    // Initializes the inventory for storing abstraction objects
    /////Hw4
    //void init() { _count = 0; }
    Inventory() { _count = 0;  };

    // Returns the number of currently stored abstraction objects
    size_t get_count() const { return _count; }

    // Returns stored abstraction object by its index or default if index is invalid
    Phone get_item(size_t i) const { return (i < _count) ? _items[i] : Phone{}; }

    // From passed property values, creates and adds new abstraction object in an array _items
    void add_item(string name, double price, const PhoneSpec& spec);
    //void add_item(string name, PhoneSpec::Type type, double price, double capacityOfStorage, string manufacturer);

    // Looks for a matching abstraction object and returns the first found or default object
    Phone find_item(const PhoneSpec& query);
    Phone find_item(const Phone& query);
    int checkNumberOfSamePhoneSpec(const PhoneSpec& query);

private:
    // The maximum number of abstraction objects that can be stored
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    Phone _items[Inventory::MAX_SIZE];

    // The number of currently stored abstraction objects in the array _items
    size_t _count;
};

#endif