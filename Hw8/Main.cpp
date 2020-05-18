#include <iostream>
#include "Phone.h"
#include "inventory.h"

using namespace std;

template <typename T>
void show(const T & item)
{
    cout<<item<<"\n";
}
template<typename T>
void show_all(const std::vector<T> & items)
{
    std::for_each(items.begin(), items.end(), show<T>);
}
// void showAll(const Inventory & inv)
// {
//     for(int i=0; i<inv.get_count(); i++)
//     {
//         show(inv.get_item(i));
//     }
// }

bool is_less(const Phone & item1, const Phone & item2)
{
    return item1.get_spec()->get_capacityOfStorage() < item2.get_spec()->get_capacityOfStorage() ;
}

Phone max_capacityOfStorage(const Inventory& inv)
{
    if(0 == inv.get_count())
        throw std::range_error("There are no items");
    return *std::max_element(inv._items.begin(), inv._items.end(), is_less);
}
class Average
{
public:
    Average(): _sum{0.0}, _count{0} {}
    void operator()(const Phone & item)
    {
        _sum += item.get_price();
        _count ++;
    }
    double result() const {return _count ? _sum/_count : 0.0;}
private:
    double _sum;
    size_t _count;
};
double avg_price(const Inventory& inv)
{
    return std::for_each(inv._items.begin(), inv._items.end(), Average()).result();   
}
Phone max_price(const Inventory& inv)
{
    int temp = 0;
    double max = 0.0;
    int i = 0;
    for (i = 0; i < inv.get_count(); i++) {
        if (inv.get_item(i).get_price() > max) {
            max = inv.get_item(i).get_price();
            //cout << "it is max "<<max<<"&"<< i << endl;
            temp = i;
        }
    }

    return inv.get_item(temp);
}


int main()
{

    Inventory inv;
    shared_ptr<PhoneSpec> Samsung = make_shared<PhoneSpec>(PhoneSpec::Type::SMARTPHONE, 10000, "Samsung");
    shared_ptr<PhoneSpec> ApplePhone = make_shared<PhoneSpec>(PhoneSpec::Type::SMARTPHONE, 10000, "Apple");
    shared_ptr<PhoneSpec> AppleTablet = make_shared<PhoneSpec>(PhoneSpec::Type::TABLETPC, 20000, "Apple");
    shared_ptr<PhoneSpec> LG = make_shared<PhoneSpec>(PhoneSpec::Type::SMARTPHONE, 8000, "LG");
    inv.add_item(Phone("galaxy10", 150.00, Samsung));
    inv.add_item(Phone("galaxy10", 150.00, Samsung));
    inv.add_item(Phone("Iphone", 130.00, ApplePhone));
    inv.add_item(Phone("Ipad", 200.00, AppleTablet));
    inv.add_item(Phone("V50", 100.00, LG));

    cout << endl;
    shared_ptr<PhoneSpec> sameSamsung = make_shared<PhoneSpec>(PhoneSpec::Type::SMARTPHONE, 15000, "Samsung");
    inv.add_item(Phone("galaxy20", 190.00, sameSamsung));
    inv.add_item(Phone("galaxy10S", 180.00, sameSamsung));
    inv.add_item(Phone("galaxyNote10", 180.00, sameSamsung));
    show(inv.find_item(*sameSamsung));

    ///// check how to delete object that we make.
    Phone* qry;
    qry = new Phone("galaxy8", 150.00, Samsung);
    show(inv.find_item(*qry));
    qry = new Phone("galaxy10", 150.00, Samsung);
    show(inv.find_item(*qry));
    qry = new Phone("Iphone", 0.00, ApplePhone);
    show(inv.find_item(*qry));
    qry = new Phone("", 0.00, AppleTablet);
    show(inv.find_item(*qry));

    cout << endl;
    cout << "------- find by spec of Phone ------" << endl;
    show(inv.find_item(PhoneSpec(PhoneSpec::Type::SMARTPHONE, 10000, "Samsung")));
    show(inv.find_item(PhoneSpec(PhoneSpec::Type::SMARTPHONE, 10000, "Apple")));
    show(inv.find_item(PhoneSpec(PhoneSpec::Type::SMARTPHONE, 8000, "LG")));
    cout << endl;
    cout << "Max capacity of phone = ";
    show(max_capacityOfStorage(inv));
    cout << "Max price of Phone = ";
    show(max_price(inv));
    cout << "Avg price of whole Phone = " << avg_price(inv) << endl;

    cout<< "---------------checking HW6-----------------"<<endl;
    // show_all(inv.get_items());
    inv.save("data1.csv");
    Inventory inv2;
    inv2.load("data100.csv");
    inv2.save("data100.csv");
    inv2.load("data1.csv");
    show_all(inv2.get_items());


#ifndef NDEBUG
    cin.get();  // wait until Enter key is pressed
#endif

    return 0;
}