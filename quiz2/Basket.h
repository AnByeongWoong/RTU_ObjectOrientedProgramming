#ifndef BASKET_H
#define BASKET_H

#include "Eatable.h"

class Basket
{
    public:
        static const int MAX_SIZE = 10;
        Basket() {_count = 0; }
        void put(Eatable newItem)
        {
            try
            {
                if(newItem.get_name().empty())
                {
                    throw newItem;
                }
                if(_count<MAX_SIZE)
                {
                    _Item[_count++] = newItem;
                }
                else if(_count >=10)
                {
                    throw std::invalid_argument("The basket is full");
                }
            }
            catch(Eatable e)
            {
                std::cerr << "ERROR: The new item can't be null."<<endl;
            }
            catch(const std::invalid_argument e)
            {
                std::cerr << e.what() << '\n';
            }
            catch(...)
            {
                cerr<<"ERROR: Unknown exception"<<endl;
            }
            
        }
        void showContents() const
        {
            for(int i=0; i<=_count; i++)
            {
                if(i==10) break;

                _Item[i]->show();
            }
        }

    private:
        int _count;
        std::shared_ptr<Eatable> _Item[MAX_SIZE];
        
};

#endif