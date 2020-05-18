#include "Laptop.h"

void Laptop::send_to(std::ostream & os) const
{
    Item::send_to(os);
    os  << this->_model << ';'
        << this->_price;
    if(this->get_spec())
    {
        os<<';';
        this->get_spec()->send_to(os);
    }
}

std::ostream & operator<<(std::ostream & os, const Laptop & item)
{
    item.send_to(os);
    return os;
}

std::istream & operator>>(std::istream & is, Laptop & item)
{
    item.recv_from(is);
    return is;
}
void Laptop::recv_from(std::istream & is)
{
    if(is)
    {
        getline(is >> std::ws, this->_model, ';');
    }
    if(is)
    {
        (is >> this->_price).ignore();
    }
    auto temp_spec { std::make_shared<LaptopSpec>()};
    is >> *temp_spec;
    set_spec(temp_spec); // replaces specification

}

string Laptop::getAllMemberByString() const
{
    string temp;
    temp.append(this->_model);
    temp.append(";");
    temp.append(std::to_string(this->_price));
    temp.append(";");
    if(this->get_spec())
    {
        temp.append(this->get_spec()->getAllMemberByString());
    }
    return temp;
}
