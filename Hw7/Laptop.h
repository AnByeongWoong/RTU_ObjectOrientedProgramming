#ifndef LAPTOP_H
#define LAPTOP_H

#include<string>
#include "LaptopSpec.h"
#include<memory>
#include "Item.h"

using namespace std;

class Laptop : public Item
{
    public:
        Laptop() = default;
        Laptop(int id, const string model, double price, shared_ptr<const LaptopSpec> spec)
        :Item(id, spec), _model{model}, _price{price}{}
        string get_model() const {return _model;}
        double get_price() const {return _price;}
        
        
        void recv_from(std::istream & is);
        friend std::istream & operator>>(std::istream & is, Laptop & item);
        
        string getAllMemberByString() const;
        void send_to(std::ostream& os) const override;
    private:
        string _model;
        double _price;
        
        
};
std::ostream & operator<<(std::ostream & os, const Laptop & item);
#endif