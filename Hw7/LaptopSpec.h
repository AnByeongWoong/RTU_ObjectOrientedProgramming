#ifndef LAPTOP_SPEC_H
#define LAPTOP_SPEC_H
#include "ItemSpec.h"

#include<string>
#include<iostream>
#include "ItemSpec.h"

using namespace std;


class LaptopSpec : public ItemSpec
{

    public:
        enum class OS{ANY, WINDOWS, MACOS};
        LaptopSpec() = default;
        LaptopSpec(LaptopSpec::OS os, int ram, string manufacturer, int weightOfLaptop);
        LaptopSpec::OS get_os() const {return _os;}
        int get_ram() const {return _ram;}
        string get_OSByString() const;
        string get_manufacturer() const {return _manufacturer;}
        int get_weightOfLaptop() const {return _weightOfLaptop; }

        bool matches(const ItemSpec& itemSpec) const override;
        void send_to(std::ostream& os) const override;
        void recv_from(std::istream & is) override;

        friend std::istream& operator>>(std::istream& is, LaptopSpec& spec);

        string getAllMemberByString() const override;

    private:
        LaptopSpec::OS _os;
        int _ram;
        string _manufacturer;
        int _weightOfLaptop;

};

std::ostream& operator<<(std::ostream& os, LaptopSpec::OS LapOs);
std::istream& operator>>(std::istream& is, LaptopSpec::OS& LapOs);


#endif