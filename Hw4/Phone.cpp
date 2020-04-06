#include "Phone.h"

Phone::Phone()
{
    _name = "";
    _price = 0.0;
    // default for spec
}

Phone::Phone(string name, PhoneSpec::Type type , double capacityOfStorage , string manufacturer )
{
    _name = name;
    _price = 0.0;
    ///////// 이거 어떻게 해결해야하는건지 물어보기
    PhoneSpec temp(type, capacityOfStorage, manufacturer);
    _spec = temp;
}
Phone::Phone(double price, PhoneSpec::Type type , double capacityOfStorage , string manufacturer )
{
    _name = "";
    _price = 0.0;
    ///////// 이거 어떻게 해결해야하는건지 물어보기
    PhoneSpec temp(type, capacityOfStorage, manufacturer);
    _spec = temp;
}


Phone::Phone(string name, double price, PhoneSpec::Type type , double capacityOfStorage, string manufacturer)
{
    _name = name;
    _price = price;
    ///////// 이거 어떻게 해결해야하는건지 물어보기
    PhoneSpec temp(type, capacityOfStorage, manufacturer);
    _spec = temp;

}
///// 이거 돌아가는지 보기
Phone::Phone(string name, double price, PhoneSpec spec)
{
    _name = name;
    _price = price;
    _spec = spec;
}
