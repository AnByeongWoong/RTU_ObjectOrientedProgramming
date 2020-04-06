#include <iostream>
#include "Phone.h"
#include "inventory.h"

using namespace std;

// output abstraction object properties to the console window
void show(Phone item)
{
    if (item.get_name() == "" && item.get_type() == Phone::Type::ANY && item.get_price() == 0.0 && item.get_manufacturer() == "") {
        cout << "There is not that item" << endl;
        return;
    }
    cout << item.get_name() << " "
        << "'" << item.get_typeByString() << "' "
        << item.get_price() << "' "
        << item.get_capacityOfStorage() << "' "
        << item.get_manufacturer() << " "
        << endl;
}

Phone max_capacityOfStorage(const Inventory &inv)
{
    int temp=0;
    double max = 0.0;
    int i = 0;
    for(i=0; i<inv.get_count(); i++){
        if(inv.get_item(i).get_capacityOfStorage()>max){
            max = inv.get_item(i).get_capacityOfStorage();
            temp = i;
        }
    }
    return inv.get_item(temp);
}

double avg_price(const Inventory &inv)
{
    double avg;
    for(int i=0; i<inv.get_count(); i++)
    {
        avg+=inv.get_item(i).get_price();
    }
    return (avg/inv.get_count());
}

// solution entry function
int main()
{
    Inventory inv;

    inv.init();

    // specify and add a least two different abstraction objects
    // inv.add_item(1, "BMX", 499.99);
    // inv.add_item(2, "MTB", 549.99);
    inv.add_item("galaxy10", Phone::Type::SMARTPHONE, 150.00, 10000,"Samsung");
    inv.add_item("Iphone", Phone::Type::SMARTPHONE, 130.00, 10000,"Apple");
    inv.add_item("Ipad", Phone::Type::TABLETPC, 200.00, 20000,"Apple");
    inv.add_item("V50", Phone::Type::SMARTPHONE, 100.00, 8000,"LG");

    Phone qry;
    // provide some querying values (some can be default (e.g., "", 0) to denote unset criteria)
    qry.init("galaxy8", Phone::Type::SMARTPHONE, 150.00, 0.0,"");
    show(inv.find_item(qry));

    // test with another query values
    //qry.init(0, "BMX", 0.0);
    qry.init("galaxy10", Phone::Type::SMARTPHONE, 150.00, 0.0,"");
    show(inv.find_item(qry));

    //qry.init(0, "Beach", 0.0);
    qry.init("Iphone", Phone::Type::SMARTPHONE, 0.00, 0.0,"");
    show(inv.find_item(qry));

    qry.init("", Phone::Type::TABLETPC, 0.00, 0.0,"");
    show(inv.find_item(qry));

    cout<<"Max capacity of phone = ";
    show(max_capacityOfStorage(inv));

    cout<<"Avg price of whole Phoen = ";
    show(max_capacityOfStorage(inv));


#ifndef NDEBUG
    cin.get();  // wait until Enter key is pressed
#endif

    return 0;
}