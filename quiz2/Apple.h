#ifndef APPLE_H
#define APPLE_H

#include "Eatable.h"

class Apple : Eatable
{
    public:
        Apple() = default;
        Apple(string name, string sort)
        :Eatable(name), _sort{sort}{}
        string get_sort(){return _sort;}
        void show() const override
        {
            Eatable::show();
            cout<<_sort<<endl;
        }
    private:
        string _sort;
};

#endif