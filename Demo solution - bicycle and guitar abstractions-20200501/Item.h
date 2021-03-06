#pragma once
#ifndef ITEM

#include <memory>
#include <ostream>
#include "ItemSpec.h"

class Item
{
public:
    Item() = default; // not mandatory, but will be required for the next assignment

    Item(int id, std::shared_ptr<const ItemSpec> spec)
        : _id{ id }
    {
        set_spec(spec);
    }

    int get_id() const
    {
        return _id;
    }

    std::shared_ptr<const ItemSpec> get_spec() const
    {
        return _spec;
    }

    virtual void send_to(std::ostream& os) const
    {
        os << _id << std::endl;

        if (_spec)
            _spec->send_to(os);
    }

protected:
    // for changing the specification only in this and in derived classes:
    void set_spec(std::shared_ptr<const ItemSpec> spec)
    {
        _spec = spec;
    }

private:
    int _id;
    std::shared_ptr<const ItemSpec> _spec;
};

std::ostream& operator<<(std::ostream& os, const Item& item);

#endif // !ITEM
