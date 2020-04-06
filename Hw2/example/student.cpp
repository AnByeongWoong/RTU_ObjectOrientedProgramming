#include <string>
using namespace std;

class Student{
    public:
    void init(int id, string name){ _id= id; _name = name; }
    int get_id() {return _id;}
    string get_name() {return _name;}

    private:
        int _id;
        string _name;
};

void main(){
    Student tom;
    tom.init(1001, "Tom Apple");

    Student group1[10];
    group1[0].init(1002, "Anna Lorenz");

    group1[1] = tom;

}