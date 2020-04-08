#ifndef PHONE_SPEC_H
#define PHONE_SPEC_H

#include<string>
#include<iostream>
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

    bool matches(const PhoneSpec& otherSpec) const;
    void send_to(std::ostream & os) const;
    void recv_from(std::istream & is);
    friend std::istream & operator>>(std::istream & is, PhoneSpec & spec );

    string getAllMemberByString() const;

private:
    PhoneSpec::Type _type;
    double _capacityOfStorage;
    string _manufacturer;
};
std::ostream & operator<<(std::ostream & os, PhoneSpec::Type type);
std::istream & operator>>(std::istream & is, PhoneSpec::Type &type);

std::ostream & operator<<(std::ostream & os, const PhoneSpec & spec);
#endif