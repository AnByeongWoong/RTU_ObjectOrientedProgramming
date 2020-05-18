#include "inventory.h"
#include <cmath>




//////////////////////
const Item & Inventory::find_item(const Item & otherItem) const
{
    // virtual이용해서 구현하기
    // for (size_t i = 0; i < this->_count; i++)
    // {
    //     constexpr double epsil{ 0.005 };
    //     // for integer type property
    //     if (query.get_name() != "" && query.get_name() != _items[i].get_name())
    //         continue;
    //     if (query.get_price() != 0.0 && (epsil < abs(query.get_price() - _items[i].get_price())))
    //         continue;

    //     if (!_items[i].get_spec()->matches(*query.get_spec()))
    //         continue;
    //     return _items[i];
    // }
    static const Item def{};
    return def;
}
const Item & Inventory::find_item(const ItemSpec & otherSpec) const
{
    for (size_t i = 0; i < _count; i++)
        if (_items[i]->get_spec()->matches(otherSpec))
            return *_items[i];
    static const Item def{}; 
    return def;
}

void Inventory::add_item(std::shared_ptr<Item> newItem)
{
    //temp.init(name, type, price, capacityOfStorage, manufacturer);

    if (_count < Inventory::MAX_SIZE)
    {
        // ID 는 오류가 있어서 Name 으로 바꿈
        if (this->find_item(*newItem->get_spec()).get_id() != newItem ->get_id()) {
            _items[_count] = newItem;
            _count++;
            // cout << "the item " << name << "is added in inventory" << endl;
        }
    }
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
                //// 왜 문제인진 나중에 실행해보고 확인하기
                //// 마찬가지로 id도 넣어줘야하는지 보기 아마 넣어줘야 할 듯
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
                ////// 여기서는 왜 대체 화살표일까? 물어보기
                ///// 여기서 recv_from이 잘 작동하도록 제대로 보기
                this->_items[i]->recv_from(LineByItem);
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

