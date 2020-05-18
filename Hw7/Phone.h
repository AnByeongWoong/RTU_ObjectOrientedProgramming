#ifndef PHONE_H
#define PHONE_H

#include<string>
#include "PhoneSpec.h"
#include<memory>
#include "Item.h"
using namespace std;

class Phone : public Item
{
public:

    
    Phone() = default;
    Phone(string name, double price, shared_ptr<const PhoneSpec> spec);

    Phone(int id, const string & name,  const double price, shared_ptr<const PhoneSpec> spec)
    :Item(id, spec), _name{name}, _price{price}{}

    string get_name() const { return _name; }
    double get_price() const { return _price; }
    
    
    friend std::istream & operator>>(std::istream & is, Phone & item);
    
    string getAllMemberByString() const override;
    void recv_from(std::istream & is);
    void send_to(std::ostream & os) const override;

private:

    string _name;
    double _price;
};

std::ostream & operator<<(std::ostream & os, const Phone & item);
#endif