#ifndef PHONE_H
#define PHONE_H

#include<string>

using namespace std;

class Phone
{
public:
    enum class Type { ANY, SMARTPHONE, TABLETPC, FOLDERPHONE };
    ///////////check it is work or not
    Phone() = default;
    //Phone();
    Phone(string name, Phone::Type type, double price, double capacityOfStorage, string manufacturer);
    
    // void init(string name, string type, double price, string manufacturer);
    void init(string name, Phone::Type type, double price, double capacityOfStorage, string manufacturer);
    string get_name() const { return _name; }
    // string get_type() { return _type; }
    Phone::Type get_type() const { return _type; }
    string get_typeByString() const;
    double get_price() const { return _price; }
    string get_manufacturer() const { return _manufacturer; }
    double get_capacityOfStorage() const { return _capacityOfStorage; }

private:

    string _name;
    // string _type;
    Phone::Type _type;
    double _capacityOfStorage;
    double _price;
    string _manufacturer;
};


#endif