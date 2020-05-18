#include "LaptopSpec.h"
static const char* Type_cstr2[]{ "ANY", "WINDOWS", "MACOS" };
LaptopSpec::LaptopSpec(LaptopSpec::OS os, int ram, string manufacturer, int weightOfLaptop)
{
    _os = os;
    _ram = ram;
    _manufacturer = manufacturer;
    _weightOfLaptop = weightOfLaptop;
}
string LaptopSpec::get_OSByString() const
{

    return Type_cstr2[(int)_os];

}
bool LaptopSpec::matches(const ItemSpec& itemSpec) const
{
    if (this == &itemSpec) {
        return true;
    }
    auto temp{ dynamic_cast<const LaptopSpec*>(&itemSpec) };
    if (nullptr == temp)
        return false;
    const LaptopSpec& otherSpec{ *temp };
    if (LaptopSpec::OS::ANY != otherSpec.get_os() && _os != otherSpec.get_os()) {
        return false;
    }
    if (otherSpec.get_ram() != 0 && otherSpec.get_ram() != _ram)
    {
        return false;
    }
    if (otherSpec.get_manufacturer() != "" && otherSpec.get_manufacturer() != _manufacturer) {
        return false;
    }
    if (otherSpec.get_weightOfLaptop() != 0 && otherSpec.get_weightOfLaptop() != _weightOfLaptop)
    {
        return false;
    }
    return true;
}
std::ostream& operator<<(std::ostream& os, LaptopSpec::OS type)
{
    os << Type_cstr2[static_cast<size_t>(type)];
    return os;
}
void LaptopSpec::send_to(std::ostream& os) const
{
    os << this->_os << ';'
        << this->_manufacturer << ';'
        << this->_ram << ';'
        << this->_weightOfLaptop;
}
void LaptopSpec::recv_from(std::istream& is)
{
    if (is)
        is >> this->_os;

    if (is)
        (is >> this->_manufacturer).ignore(); // call ignore() to skip ';'

    if (is)
        (is >> this->_ram).ignore();
    if (is)
        (is >> this->_weightOfLaptop).ignore();
}

string LaptopSpec::getAllMemberByString() const
{
    string temp;
    temp.append(Type_cstr2[static_cast<size_t>(this->_os)]);
    temp.append(";");
    temp.append(this->_manufacturer);
    temp.append(";");
    temp.append(to_string(this->_ram));
    temp.append(";");
    temp.append(to_string(this->_weightOfLaptop));
    return temp;
}

std::istream& operator>>(std::istream& is, LaptopSpec::OS& type)
{
    if (is)
    {
        std::string tmp;
        getline(is, tmp, ';');
        if (is)
        {
            bool found{ false };

            for (size_t i{ 0 }; i < sizeof(Type_cstr2) / sizeof(Type_cstr2[0]); i++)
            {
                if (0 == strcasecmp(tmp.c_str(), Type_cstr2[i])) // for POSIX C++ include <strings.h>
                //if (0 == _stricmp(tmp.c_str(), Type_cstr2[i]))     // Visual C++
                {
                    type = static_cast<LaptopSpec::OS>(i);
                    found = true;
                    break;
                }
            }
            if (!found)
                type = LaptopSpec::OS::ANY;
        }
    }
    return is;
}
