#pragma once
#ifndef BICYCLE
#define BICYCLE

#include "Item.h"
#include "BicycleSpec.h"
#include <string>
#include <memory>
#include <iostream>

class Bicycle : public Item
{
public:
    Bicycle() = default;
    Bicycle(unsigned id, double price, std::string model, unsigned short model_year, std::shared_ptr<const BicycleSpec> spec)
        : Item(id, spec)
        , _price{ price }
        , _model{ model }
        , _model_year{ model_year }
        { }
        
    double get_price() const {  return _price;  }
    std::string get_model() const {  return _model;  }
    unsigned short get_model_year() const {  return _model_year;  }
    
    void send_to(std::ostream & os) const override;     
    void recv_from(std::istream & is);
    friend std::istream & operator>>(std::istream & is, Bicycle & item);
private:
    double _price;
    std::string _model;
    unsigned short _model_year;
};

//std::ostream& operator<<(std::ostream & os, const Bicycle & item);

#endif