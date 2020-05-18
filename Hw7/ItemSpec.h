#ifndef ITEM_SPEC_H
#define ITEM_SPEC_H

#include<string>
#include<iostream>

class ItemSpec
{
    public:
        virtual void send_to(std::ostream & os) const = 0;
        virtual bool matches(const ItemSpec& otherSpec) const = 0;
        //virtual void recv_from(std::istream & is) = 0;
        virtual std::string getAllMemberByString() const = 0;
};
std::ostream & operator<<(std::ostream & os, const ItemSpec & spec);

#endif