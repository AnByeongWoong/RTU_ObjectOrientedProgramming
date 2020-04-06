#include "Phone.h"


Phone::Phone(string name, double price, shared_ptr<const PhoneSpec> spec)
{
    _name = name;
    _price = price;
    _spec = spec;
}

std::ostream & operator<<(std::ostream & os, const Phone & item)
{
    item.send_to(os);
    return os;
}

void Phone::send_to(std::ostream & os) const
{
    os  << this->_name << ';'
        << this->_price;

    if (_spec)    
    {
        os << ';';
        _spec->send_to(os);
    }
}

std::istream & operator>>(std::istream & is, Phone & item)
{
    item.recv_from(is);
    return is;
}

void recv_from(std::istream & is)
{
    if (is)
        getline(is >> std::ws, this->_name, ';'); 
    if (is)
       (is >> this->_price).ignore();

    auto temp_spec{ std::make_shared<PhoneSpec>() };
    is >> *temp_spec;  // alternative: temp_spec->recv_from(is);
    _spec = temp_spec; // replaces specification

}