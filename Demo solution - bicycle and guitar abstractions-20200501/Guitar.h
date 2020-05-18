#pragma once
#include "Item.h"
#include "GuitarSpec.h"
#include <string>

class Guitar :
    public Item
{
public:
    Guitar() = default;
    Guitar(int id, double price, std::shared_ptr<const GuitarSpec> spec)
        : Item(id, spec), _price(price) { }

    double get_price() const { return _price; }

    void send_to(std::ostream& os) const override;

public:
    double _price;
};

