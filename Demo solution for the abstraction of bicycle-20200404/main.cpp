#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void show(const Bicycle & item)
{
    cout << item << "\n";
}

int main()
{
    Inventory inv;
    
    // specification is constructed separately
    auto spec_bmx{ std::make_shared<BicycleSpec>(BicycleSpec::Type::BMX, 20, 1) };
    inv.add_item(1, 149.0, "SCORE Stickerbomb", 2019, spec_bmx);

    Bicycle b1(111, 440.0, "HARO ANNEX RACE MINI", 2017, spec_bmx);
    cout << b1 << "\n";

    auto filename{ "b1.csv" };
    ofstream ofs(filename);
    if (ofs)
        ofs << b1 << "\n";
    ofs.close(); 
    cout << "Saved...\n";

    Bicycle b2;
    ifstream ifs(filename);
    if (ifs)
        ifs >> b2;
    ifs.close();
    cout << "Read...\n"
         << b2 << "\n----\n";


    // specification is constructed during passing of an argument
    inv.add_item(2, 129.0, "Bikko Classic cream", 2016, std::make_shared<BicycleSpec>(BicycleSpec::Type::STREET, 28, 1 ));

    // constructing and using shared specification
    auto spec_beach{ std::make_shared<BicycleSpec>(BicycleSpec::Type::BEACH, 27, 6) };
    inv.add_item(3, 185.0, "Romet Vintage M brown", 2019, spec_beach);
    inv.add_item(4, 197.0, "Romet Vintage M green", 2018, spec_beach);

    // provide some querying values (some can be default (e.g., "", 0) to denote unset criteria)
    show(inv.find_item(BicycleSpec{ BicycleSpec::Type::ANY, 20, 0 }));

    // test with another query values
    show(inv.find_item(*spec_beach));

    show(inv.find_item(Bicycle{ 0, 0.0, "", 2016, std::make_shared<BicycleSpec>() }));
    
    // testing for non-matching criterion
    show(inv.find_item(BicycleSpec{ BicycleSpec::Type::MTB, 0, 0 }));
    show(inv.find_item(Bicycle{ 5, 0.0, "", 0, std::make_shared<BicycleSpec>() }));

    auto inv_file_name{ "inventory.csv" };
    // save all items to file
    inv.save(inv_file_name);    
    // load into different object
    Inventory inv2;
    inv2.load(inv_file_name);
    // test, that loading into inv2 succeeded
    // :::

#ifndef NDEBUG
    //cin.get();  // wait until Enter key is pressed
#endif

    return 0;
}