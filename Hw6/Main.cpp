#include <iostream>
#include "Phone.h"
#include "inventory.h"

using namespace std;


// void show(Phone item)
// {
//     if (item.get_name() == "" && item.get_price() == 0.0) {
//         cout << "There is not that item" << endl;
//         return;
//     }

//     cout << item.get_name() << " "
//         << "'" << item.get_price() << "' ";
//     if (item.get_spec())
//     {
//         cout << item.get_spec()->get_typeByString() << "' "
//             << item.get_spec()->get_capacityOfStorage() << "' "
//             << item.get_spec()->get_manufacturer() << " "
//             << endl;
//     }


// }

void show(const Phone & item)
{
    cout<<item<<"\n";
}

Phone max_capacityOfStorage(const Inventory& inv)
{
    int temp = 0;
    double max = 0.0;
    int i = 0;
    for (i = 0; i < inv.get_count(); i++) {
        if (inv.get_item(i).get_spec()->get_capacityOfStorage() > max) {
            max = inv.get_item(i).get_spec()->get_capacityOfStorage();
            temp = i;
        }
    }

    return inv.get_item(temp);
}
double avg_price(const Inventory& inv)
{
    double avg = 0.0;
    for (int i = 0; i < inv.get_count(); i++)
    {
        avg += inv.get_item(i).get_price();
    }
    return (avg / inv.get_count());
}
//////// 질문 여기서 반드시 abstraction 부분에서만 하는 것인가?
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
    inv.add_item("galaxy10", 150.00, Samsung);
    inv.add_item("galaxy10", 150.00, Samsung);
    inv.add_item("Iphone", 130.00, ApplePhone);
    inv.add_item("Ipad", 200.00, AppleTablet);
    inv.add_item("V50", 100.00, LG);

    cout << endl;
    shared_ptr<PhoneSpec> sameSamsung = make_shared<PhoneSpec>(PhoneSpec::Type::SMARTPHONE, 15000, "Samsung");
    inv.add_item("galaxy20", 190.00, sameSamsung);
    inv.add_item("galaxy10S", 180.00, sameSamsung);
    inv.add_item("galaxyNote10", 180.00, sameSamsung);
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


#ifndef NDEBUG
    cin.get();  // wait until Enter key is pressed
#endif

    return 0;
}