#include "inventory.h"
#include <cmath>
#include<iostream>

Phone Inventory::find_item(const Phone& query) const
{

    for (size_t i = 0; i < this->_count; i++)
    {
        constexpr double epsil{ 0.005 };
        // for integer type property
        if (query.get_name() != "" && query.get_name() != _items[i].get_name())
            continue;
        if (query.get_price() != 0.0 && (epsil < abs(query.get_price() - _items[i].get_price())))
            continue;

        if (!_items[i].get_spec()->matches(*query.get_spec()))
            continue;
        return _items[i];
    }

    return Phone{};
}
Phone Inventory::find_item(const PhoneSpec& otherSpec) const
{
    for (size_t i = 0; i < _count; i++)
        if (_items[i].get_spec()->matches(otherSpec))
            return _items[i];

    return Phone{};
}

void Inventory::add_item(string name, double price, shared_ptr<const PhoneSpec> spec)
{
    //temp.init(name, type, price, capacityOfStorage, manufacturer);

    if (_count < Inventory::MAX_SIZE)
    {

        Phone newItem(name, price, spec);

        if (this->find_item(newItem).get_name() != "") {
            cout << "this item is already have" << endl;
            return;
        }


        _items[_count] = newItem;
        _count++;
    }
    cout << "the item " << name << "is added in inventory" << endl;

}


void Inventory::save(const std::string & csv_file_name) const
{
    
    try
    {
        ofstream writeFile;
        writeFile.open(csv_file_name);
        if(this->_count == 0)
        {
            throw 0;
        }
        if(writeFile.is_open())
        {
            for(int i=0; i<this->get_count(); i++)
            {
                string temp = this->get_item(i).getAllMemberByString();
                if(i!=this->get_count()-1)
                {
                    temp.append("\n");
                }
                
                writeFile.write(temp.c_str(), temp.size());
                //writeFile.write( <<this->get_item(i) );
            }
        }
        else
        {
            throw std::invalid_argument( "fail to open");
        }
        writeFile.close();
    }
    catch(int)
    {
        cerr<<"ERROR: empty inventory cannot save"<<endl;
    }
    catch(std::invalid_argument & a)
    {
        cerr<<a.what()<<csv_file_name<<endl;
    }
    catch(...)
    {
        cerr<<"ERROR: Unknown exception"<<endl;
        return;
    }

}

#include<sstream>
void Inventory::load(const std::string & csv_file_name)
{
    
    try
    {
        ifstream readFile;
        readFile.open(csv_file_name);
        if(!readFile)
        {
            throw std::invalid_argument("ERROR: file is not exist-- ");
        }
        if(readFile.is_open())
        {   
            int i = 0;
            while(!readFile.eof())
            {
                string line;
                getline(readFile, line);
                istringstream LineByItem(line);
                
                //LineByItem.str(line);
                this->_items[i].recv_from(LineByItem);
                i++;
            }
            this->set_count(i);
        }
        else
        {
            throw std::invalid_argument( "ERROR: file is not opened...");
        }
        
    }
    catch(std::invalid_argument & a)
    {
        cout<<a.what()<<csv_file_name<<endl;
    }
    catch(...)
    {
        cout<<"ERROR: Unknown exception"<<endl;
        return;
    }
}

