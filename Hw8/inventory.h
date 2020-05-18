#ifndef INVENTORY_H
#define INVENTORY_H

#include "Phone.h"
#include <exception>
////// we have to include this 
#include<fstream>
#include<vector>
class Inventory
{
public:
    Inventory() = default;


    size_t get_count() const { return _items.size(); }
    // Phone get_item(size_t i) const { return (i < _count) ? _items[i] : Phone{}; }

    Phone find_item(const Phone& query) const;
    // void add_item(string name, double price, shared_ptr<const PhoneSpec> spec);
    void add_item(const Phone & new_item);
    Phone find_item(const PhoneSpec& otherSpec);
    const Phone & operator[](size_t i) const {return get_item(i);}
    const Phone & get_item(size_t i) const{
        if (i < this->_items.size()){
            return _items[i];
        }
        throw std::out_of_range("Invalid index value. ");
    }
    void save(const std::string & csv_file_name) const;
    void load(const std::string & csv_file_name);
    //void set_count(size_t num){ this->_items.size() = num ;}
    std::vector<Phone> find_all_items(const PhoneSpec & otherSpec) ;
    /// 여기다가 const 가능할 것 같은데 나중에 생각해보기
    std::vector<Phone> get_items() const { return this->_items;}
    friend Phone max_capacityOfStorage(const Inventory& inv);
    friend double avg_price(const Inventory& inv);
private:
    // static const size_t MAX_SIZE{ 10 };

    std::vector<Phone> _items;

    //size_t _count;
};

#endif
 