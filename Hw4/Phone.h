#ifndef PHONE_H
#define PHONE_H

#include<string>
#include "PhoneSpec.h"

using namespace std;

class Phone
{
public:
    
    ///////////check it is work or not
    Phone() = default;
    //Phone();
    Phone(string name, PhoneSpec::Type type = PhoneSpec::Type::ANY , double capacityOfStorage = 0.0, string manufacturer = "");
    Phone(double price, PhoneSpec::Type type = PhoneSpec::Type::ANY , double capacityOfStorage = 0.0, string manufacturer = "");
    Phone(string name, double price, PhoneSpec::Type type = PhoneSpec::Type::ANY , double capacityOfStorage = 0.0, string manufacturer = "");
    Phone(string name, double price, PhoneSpec spec);
    string get_name() const { return _name; }
    double get_price() const { return _price; }
    PhoneSpec get_spec() const {return _spec; }

private:

    string _name;
    double _price;
    PhoneSpec _spec;
};


#endif