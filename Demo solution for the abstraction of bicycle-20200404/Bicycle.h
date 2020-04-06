#pragma once
#ifndef BICYCLE
#define BICYCLE

#include "BicycleSpec.h"
#include <string>
#include <memory>
#include <iostream>

class Bicycle
{
public:
    Bicycle() = default;
    Bicycle(unsigned id, double price, std::string model, unsigned short model_year, std::shared_ptr<const BicycleSpec> spec)
        : _id{ id }
        , _price{ price }
        , _model{ model }
        , _model_year{ model_year }
        , _spec{ spec }
        { }
        
    unsigned get_id() const {  return _id;  }
    double get_price() const {  return _price;  }
    std::string get_model() const {  return _model;  }
    unsigned short get_model_year() const {  return _model_year;  }
    std::shared_ptr<const BicycleSpec> get_spec() const {  return _spec;  }
    
    void send_to(std::ostream & os) const;        
    void recv_from(std::istream & is);
    friend std::istream & operator>>(std::istream & is, Bicycle & item);
private:
    unsigned _id;
    double _price;
    std::string _model;
    unsigned short _model_year;
    std::shared_ptr<const BicycleSpec> _spec;
};

std::ostream& operator<<(std::ostream & os, const Bicycle & item);

#endif