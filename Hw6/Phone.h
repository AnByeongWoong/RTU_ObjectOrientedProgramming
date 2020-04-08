#ifndef PHONE_H
#define PHONE_H

#include<string>
#include "PhoneSpec.h"
#include<memory>
using namespace std;

class Phone
{
public:

    
    Phone() = default;
    Phone(string name, double price, shared_ptr<const PhoneSpec> spec);

    string get_name() const { return _name; }
    double get_price() const { return _price; }
    shared_ptr<const PhoneSpec> get_spec() const { return _spec; }
    void send_to(std::ostream & os) const;
    
    void recv_from(std::istream & is);
    friend std::istream & operator>>(std::istream is, Phone & item);
    string getAllMemberByString() const;
private:

    string _name;
    double _price;
    shared_ptr<const PhoneSpec> _spec;
};

std::ostream & operator<<(std::ostream & os, const Phone & item);
#endif