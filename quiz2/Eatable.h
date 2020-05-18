#ifndef Eastable_H
#define Eastable_H

#include <iostream>
#include <string>

using namespace std;

class Eatable
{
    public:
        Eatable() = default;
        Eatable(string query){ this->_name = query;}
        string get_name() const {return _name;}
        virtual void show() const
        {
            cout << _name << endl;
        }
    private:
        string _name;
};


#endif