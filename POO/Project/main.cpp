#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Base
{
private:
    string manufacturer,
        color;
    int price;

public:
    virtual void setData(string manufacturer, string color, int price)
    {
        this->manufacturer = manufacturer;
        this->color = color;
        this->price = price;
    }
    virtual void display()
    {
        cout << this->manufacturer << endl;
        cout << this->color << endl;
        cout << this->price << endl;
    }
    virtual Base *getData()
    {
        return this;
    }
};

int main()
{
    Base b,
        *n;
    string
        m = "Google",
        c = "white";
    int p = 2;
    b.setData(m, c, p);
    n = b.getData();
    n->display();

    return 0;
}