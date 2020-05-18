#pragma once
#ifndef BICYCLE_SPEC
#define BICYCLE_SPEC

#include "ItemSpec.h"
#include <cstddef> // for std::size_t
#include <iostream>

class BicycleSpec : public ItemSpec {
public:
    enum class Type { ANY, MTB, STREET, BEACH, BMX };
    
    BicycleSpec() = default;
    BicycleSpec(Type type, unsigned short wheel_size, unsigned short gears)
        : _type{ type }
        , _wheel_size{ wheel_size }
        , _gears{ gears }
        { }

    bool matches(const ItemSpec & otherSpec) const override;

    Type get_type() const {  return _type;  }
    unsigned short get_wheel_size() const {  return _wheel_size;  }
    unsigned short get_gears() const {  return _gears;  }

    void send_to(std::ostream & os) const override;
    void recv_from(std::istream & is);
    friend std::istream & operator>>(std::istream & is, BicycleSpec & spec);
private:
    Type _type;
    unsigned short _wheel_size;
    unsigned short _gears;
};


std::ostream & operator<<(std::ostream & os, BicycleSpec::Type type);
std::istream & operator>>(std::istream & is, BicycleSpec::Type & type);

//std::ostream & operator<<(std::ostream & os, const BicycleSpec & spec);

#endif