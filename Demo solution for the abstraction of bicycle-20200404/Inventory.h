#pragma once
#ifndef INVENTORY
#define INVENTORY

#include "Bicycle.h"
#include "BicycleSpec.h" // include explicitly even if would be included implicitly via Bicycle.h
#include <string>
#include <exception>

class Inventory
{
public:
    // Initializes the inventory for storing abstraction objects
    Inventory() : _count{ 0 } { }

    // Returns the number of currently stored abstraction objects
    size_t get_count() const { return _count; }

    const Bicycle & operator[](size_t i) const { return get_item(i); }
    // Returns stored abstraction object by its index or throws an exception if index is invalid
    const Bicycle & get_item(size_t i) const
    {
        if (i < _count)
            return _items[i];

        throw std::out_of_range("Invalid index value.");
    }

    // From passed property values, creates and adds new abstraction object in an array _items
    void add_item(unsigned id, double price, std::string model, unsigned short model_year, std::shared_ptr<const BicycleSpec> spec);

    // Looks for a matching abstraction object and returns the first found or default object
    Bicycle find_item(const Bicycle & query) const;
    Bicycle find_item(const BicycleSpec & spec_query) const;

    void save(const std::string & csv_file_name) const;
    void load(const std::string & csv_file_name);
private:
    // The maximum number of abstraction objects that can be stored
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    Bicycle _items[Inventory::MAX_SIZE];

    // The number of currently stored abstraction objects in the array _items
    size_t _count;
};
#endif