#include <iostream>
#include "Phone.h"
#include "Inventory.h"

using namespace std;

// output abstraction object properties to the console window
void show(Phone item)
{
    cout << item.get_name() << " "
         << "'" << item.get_type() << "' "
         << item.get_price() << " "
         << item.get_manufacturer()<<" "
         << endl;
}

// solution entry function
int main()
{
    Inventory inv;

    inv.init();

    // specify and add a least two different abstraction objects
    // inv.add_item(1, "BMX", 499.99);
    // inv.add_item(2, "MTB", 549.99);
    inv.add_item("galaxy10", "smartphone", 150.00, "Samsung" );
    inv.add_item("Iphone", "smartphone", 130.00, "Apple" );
    inv.add_item("Ipad", "TabletPC", 200.00, "Apple" );
    inv.add_item("V50", "smartPhone", 100.00, "LG" );

    Phone qry;
    // provide some querying values (some can be default (e.g., "", 0) to denote unset criteria)
    qry.init("galaxy8", "smartphone", 150.00, "");
    show(inv.find_item(qry));

    // test with another query values
    //qry.init(0, "BMX", 0.0);
    qry.init("galaxy8", "smartphone", 150.00, "");
    show(inv.find_item(qry));

    //qry.init(0, "Beach", 0.0);
    qry.init("Iphone", "smartphone", 0.00, "");
    show(inv.find_item(qry));

    qry.init("", "", 0.00, "Apple");
    show(inv.find_item(qry));

#ifndef NDEBUG
    cin.get();  // wait until Enter key is pressed
#endif

    return 0;
}