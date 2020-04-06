#ifndef PHONE
#define PHONE

#include<string>

using namespace std;

class Phone
{
public:
    void init(string name, string type, double price, string manufacturer);
    string get_name() { return _name; }
    string get_type() { return _type; }
    double get_price() { return _price; }
    string get_manufacturer() { return _manufacturer; }

private:
    string _name;
    string _type;
    double _price;
    string _manufacturer;
};


#endif