#include <iostream>
#include "Phone.h"
#include "inventory.h"

using namespace std;

// output abstraction object properties to the console window
void show(Phone item)
{
    if (item.get_name() == "" && item.get_spec().get_type() == PhoneSpec::Type::ANY && item.get_price() == 0.0 && item.get_spec().get_manufacturer() == "") {
        cout << "There is not that item" << endl;
        return;
    }
    cout << item.get_name() << " "
        << "'" << item.get_spec().get_typeByString() << "' "
        << item.get_price() << "' "
        << item.get_spec().get_capacityOfStorage() << "' "
        << item.get_spec().get_manufacturer() << " "
        << endl;
}

Phone max_capacityOfStorage(const Inventory& inv)
{
    int temp = 0;
    double max = 0.0;
    int i = 0;
    for (i = 0; i < inv.get_count(); i++) {
        if (inv.get_item(i).get_spec().get_capacityOfStorage() > max) {
            max = inv.get_item(i).get_spec().get_capacityOfStorage();
            //cout << "it is max "<<max<<"&"<< i << endl;
            temp = i;
        }
    }
  
    return inv.get_item(temp);
}
double avg_price(const Inventory& inv)
{
    double avg=0.0;
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



// solution entry function
int main()
{
    
    // Inventory inv;
    // inv.init();

    ////// 여기 체크하기
    Inventory inv;
    
    inv.add_item("galaxy10", 150.00, PhoneSpec(PhoneSpec::Type::SMARTPHONE,  10000, "Samsung"));
    inv.add_item("galaxy10", 150.00, PhoneSpec(PhoneSpec::Type::SMARTPHONE, 10000, "Samsung"));
    inv.add_item("Iphone", 130.00, PhoneSpec(PhoneSpec::Type::SMARTPHONE, 10000, "Apple"));
    inv.add_item("Ipad", 200.00, PhoneSpec(PhoneSpec::Type::TABLETPC, 20000, "Apple"));
    inv.add_item("V50", 100.00, PhoneSpec(PhoneSpec::Type::SMARTPHONE, 8000, "LG"));

    PhoneSpec sameSpec(PhoneSpec::Type::SMARTPHONE, 15000, "Samsung");
    inv.add_item("galaxy20", 190.00, sameSpec);
    inv.add_item("galaxy10S", 180.00, sameSpec);
    inv.add_item("galaxyNote10", 180.00, sameSpec);
    show(inv.find_item(sameSpec));
    ///// check how to delete object that we make.
    Phone* qry;
    qry = new Phone("galaxy8", 150.00, PhoneSpec::Type::SMARTPHONE, 0.0, "");
    show(inv.find_item(*qry));
    qry = new Phone("galaxy10", 150.00,PhoneSpec::Type::SMARTPHONE, 0.0, "");
    show(inv.find_item(*qry));
    qry = new Phone("Iphone", 0.00, PhoneSpec::Type::SMARTPHONE, 0.0, "");
    show(inv.find_item(*qry));
    qry = new Phone("", 0.00, PhoneSpec::Type::TABLETPC, 0.0, "");
    show(inv.find_item(*qry));

    cout << "Max capacity of phone = ";
    show(max_capacityOfStorage(inv));

    cout << "Avg price of whole Phone = " << avg_price(inv) << endl;


#ifndef NDEBUG
    cin.get();  // wait until Enter key is pressed
#endif

    return 0;
}

   // inv.add_item("galaxy10", PhoneSpec::Type::SMARTPHONE, 150.00, 10000, "Samsung");
    // inv.add_item("galaxy10", PhoneSpec::Type::SMARTPHONE, 150.00, 10000, "Samsung");
    // inv.add_item("Iphone", PhoneSpec::Type::SMARTPHONE, 130.00, 10000, "Apple");
    // inv.add_item("Ipad", PhoneSpec::Type::TABLETPC, 200.00, 20000, "Apple");
    // inv.add_item("V50", PhoneSpec::Type::SMARTPHONE, 100.00, 8000, "LG");


    // Phone qry;    
    //qry.init("galaxy8", Phone::Type::SMARTPHONE, 150.00, 0.0, "");
    // show(inv.find_item(qry));
    // qry.init("galaxy10", Phone::Type::SMARTPHONE, 150.00, 0.0, "");
    // show(inv.find_item(qry));
    // qry.init("Iphone", Phone::Type::SMARTPHONE, 0.00, 0.0, "");
    // show(inv.find_item(qry));
    // qry.init("", Phone::Type::TABLETPC, 0.00, 0.0, "");
    // show(inv.find_item(qry));
