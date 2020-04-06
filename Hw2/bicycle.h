#include<string>

using namespace std;

class Bicycle
{
    public:
        int get_id() {return _id;}
        string get_type() {return _type;}
        double get_price() {return _price;}
        void init(int id, string type, double price);
    private:
        int _id;
        string _type;
        double _price;
};
