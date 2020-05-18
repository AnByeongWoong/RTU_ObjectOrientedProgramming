#pragma once
#ifndef ITEM_SPEC

#include <ostream>

class ItemSpec
{
public:
    virtual void send_to(std::ostream& os) const = 0;
    virtual bool matches(const ItemSpec& itemSpec) const = 0;
};

std::ostream& operator<<(std::ostream& os, const ItemSpec& spec);

#endif // !ITEM_SPEC
