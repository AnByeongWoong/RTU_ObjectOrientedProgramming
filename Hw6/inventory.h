#ifndef INVENTORY_H
#define INVENTORY_H

#include "Phone.h"
#include <exception>
////// we have to include this 
#include<fstream>
class Inventory
{
public:
    Inventory() { _count = 0; };


    size_t get_count() const { return _count; }
    // Phone get_item(size_t i) const { return (i < _count) ? _items[i] : Phone{}; }

    Phone find_item(const Phone& query) const;
    void add_item(string name, double price, shared_ptr<const PhoneSpec> spec);
    Phone find_item(const PhoneSpec& otherSpec) const;
    const Phone & operator[](size_t i) const {return get_item(i);}
    const Phone & get_item(size_t i) const{
        if (i < _count){
            return _items[i];
        }
        throw std::out_of_range("Invalid index value. ");
    }
    void save(const std::string & csv_file_name) const;
    void load(const std::string & csv_file_name);
    void set_count(size_t num){ _count = num ;}
private:
    static const size_t MAX_SIZE{ 10 };

    Phone _items[Inventory::MAX_SIZE];

    size_t _count;
};

#endif
 