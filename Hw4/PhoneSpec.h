#ifndef PHONE_SPEC_H
#define PHONE_SPEC_H

#include<string>

using namespace std;

class PhoneSpec
{
public:
    enum class Type { ANY, SMARTPHONE, TABLETPC, FOLDERPHONE };
    PhoneSpec() = default;
    PhoneSpec(PhoneSpec::Type type, double capacityOfStorage, string manufacturer);
    PhoneSpec::Type get_type() const { return _type; }
    string get_typeByString() const;
    
    string get_manufacturer() const { return _manufacturer; }
    double get_capacityOfStorage() const { return _capacityOfStorage; }

private:
    PhoneSpec::Type _type;
    double _capacityOfStorage;
    string _manufacturer;
};


#endif