#include "Phone.h"


// Phone::Phone(string name, double price, shared_ptr<const PhoneSpec> spec)
// {
//     _name = name;
//     _price = price;
//     _spec = spec;
// }

std::ostream & operator<<(std::ostream & os, const Phone & item)
{
    item.send_to(os);
    return os;
}

////// send_to 가 많이 찜찜하지만 그냥 넘어가보자
void Phone::send_to(std::ostream & os) const 
{
    Item::send_to(os);
    
    os  << this->_name << ';'
        << this->_price;

    }

std::istream & operator>>(std::istream & is, Phone & item)
{
    item.recv_from(is);
    return is;
}

void Phone::recv_from(std::istream & is)
{
    // if (is)
    //    (is >> _id).ignore();

    if (is){
        getline(is >> std::ws, this->_name, ';'); 
    }
        
    if (is){
        (is >> this->_price).ignore();
    }
       
    auto temp_spec{ std::make_shared<PhoneSpec>() };
    is >> *temp_spec;  // alternative: temp_spec->recv_from(is);
    set_spec(temp_spec); // replaces specification
}

string Phone::getAllMemberByString() const
{
    string temp = Item::getAllMemberByString();
    temp.append(this->_name);
    temp.append(";");
    temp.append(std::to_string(this->_price));
    temp.append(";");
    if(this->get_spec())
    {
        temp.append(this->get_spec()->getAllMemberByString());
    }
    return temp;
}