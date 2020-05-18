#include "Inventory.h"
#include "Bicycle.h"
#include "Guitar.h"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void show(const Item & item)
{
    cout << item << "\n";
}

int main()
{
    Inventory inv;
    
    // specification is constructed separately
    auto spec_bmx{ std::make_shared<BicycleSpec>(BicycleSpec::Type::BMX, 20, 1) };
    auto b1{ std::make_shared<Bicycle>(1, 149.0, "SCORE Stickerbomb", 2019, spec_bmx) };
    inv.add_item(b1);

    Bicycle b0(111, 440.0, "HARO ANNEX RACE MINI", 2017, spec_bmx);
    cout << b0 << "\n";

    auto filename{ "b0.csv" };
    ofstream ofs(filename);
    if (ofs)
        ofs << b0 << "\n";
    ofs.close(); 
    cout << "Saved...\n";

    Bicycle b00;
    ifstream ifs(filename);
    if (ifs)
        ifs >> b00;
    ifs.close();
    cout << "Read...\n"
         << b00 << "\n----\n";


    // specification is constructed during passing of an argument
    auto b2{ std::make_shared<Bicycle>(2, 129.0, "Bikko Classic cream", 2016, std::make_shared<BicycleSpec>(BicycleSpec::Type::STREET, 28, 1)) };
    inv.add_item(b2);

    // constructing and using shared specification
    auto spec_beach{ std::make_shared<BicycleSpec>(BicycleSpec::Type::BEACH, 27, 6) };
    inv.add_item(std::make_shared<Bicycle>(3, 185.0, "Romet Vintage M brown", 2019, spec_beach));
    inv.add_item(std::make_shared<Bicycle>(4, 197.0, "Romet Vintage M green", 2018, spec_beach));

    // provide some querying values (some can be default (e.g., "", 0) to denote unset criteria)
    show(inv.find_item(BicycleSpec{ BicycleSpec::Type::ANY, 20, 0 }));

    // test with another query values
    show(inv.find_item(*spec_beach));

    show(inv.find_item(BicycleSpec{}));
    
    // testing for non-matching criterion
    show(inv.find_item(BicycleSpec{ BicycleSpec::Type::MTB, 0, 0 }));
    //show(inv.find_item(Bicycle{ 5, 0.0, "", 0, std::make_shared<BicycleSpec>() }));

    // add another type of abstraction
    auto g1{ std::make_shared<Guitar>(6, 500.0, std::make_shared<GuitarSpec>("Fender Player Stratocaster MN", GuitarSpec::Type::ELECTRIC)) };
    inv.add_item(g1);

    show(inv.find_item(GuitarSpec{ "", GuitarSpec::Type::ELECTRIC }));

    auto inv_file_name{ "inventory.csv" };
    // save all items to file
    inv.save(inv_file_name);    
    
    /// Not implemented for Assignment 7:
    // load into different object
    //Inventory inv2;
    //inv2.load(inv_file_name);

#ifndef NDEBUG
    //cin.get();  // wait until Enter key is pressed
#endif

    return 0;
}