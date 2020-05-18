#include "Bicycle.h"

//std::ostream & operator<<(std::ostream & os, const Bicycle & item)
//{
//    item.send_to(os);
//    return os;
//}


void Bicycle::send_to(std::ostream & os) const
{
    Item::send_to(os);

    os << _price << ';'
       << _model << ';'
       << _model_year;
}


std::istream & operator>>(std::istream & is, Bicycle & item)
{
    item.recv_from(is);
    return is;
}


void Bicycle::recv_from(std::istream & is)
{
    // if (is)
    //    (is >> _id).ignore(); // call ignore() to skip ';'

    if (is)
       (is >> _price).ignore();

    if (is)
        getline(is >> std::ws, _model, ';'); // also skips ';'
   
    if (is)
       (is >> _model_year).ignore();

    auto temp_spec{ std::make_shared<BicycleSpec>() };
    is >> *temp_spec;  // alternative: temp_spec->recv_from(is);
    set_spec(temp_spec); // replaces specification
}

