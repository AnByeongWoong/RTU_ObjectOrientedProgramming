#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include <ostream>
#include "ItemSpec.h"

using namespace std;


class Item
{
    public: 
        Item()  = default;
        Item(int id, std::shared_ptr<const ItemSpec> spec): _id{id}
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
        virtual void send_to(std::ostream & os) const
        {
            os << _id << std::endl;

            if(_spec)
                _spec->send_to(os);
        }

        virtual string getAllMemberByString() const{ 
            string temp;
            temp.append(std::to_string(this->_id));
            temp.append(";");
            return temp;
            }

        virtual void recv_from(std::istream & is) const{}

    protected:
        void set_spec(std::shared_ptr<const ItemSpec> spec)
        {
            _spec = spec;
        }
    private:
        int _id;
        std::shared_ptr<const ItemSpec> _spec;
};

std::ostream & operator<<(std::ostream & os, const Item & item);

#endif