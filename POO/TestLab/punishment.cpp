#include <iostream>
using namespace std;

class Base
{
    string manufacturer;
    int price,
        nrMotors,
        category;
    Base *next;

public:
    Base(
        string manufacturer,
        int nrMotors,
        int price,
        int category)
    {
        manufacturer = manufacturer;
        nrMotors = nrMotors;
        price = price;
        category = category;
    }
    virtual void display()
    {
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nPrice: " << price;
        cout << "\nNr motors: " << nrMotors;
    }
    friend class List;
};

class Traditional : Base
{
    int energyClass,
        control;
    string color;

public:
    Traditional(
        int energyClass,
        int control,
        string color,
        string manufactuter,
        int nrMotors,
        int price,
        int category) : Base(manufactuter,
                             nrMotors,
                             price,
                             category)
    {
        this->energyClass = energyClass;
        this->control = control;
        this->color = color;
    }
    void display()
    {
        Base::display();
        cout << "\nEnergy class: " << energyClass;
        cout << "\nControl: " << control;
        cout << "\nColor: " << color;
    }
    friend class List;
};
class Embeddable : Base
{
    int type,
        energyConsumption,
        filter;

public:
    Embeddable(
        int type,
        int energyConsumption,
        int filter,
        string manufactuter,
        int nrMotors,
        int price,
        int category) : Base(manufactuter,
                             nrMotors,
                             price,
                             category)
    {
        type = type;
        energyConsumption = energyConsumption;
        filter = filter;
    }
    void display()
    {
        Base::display();
        cout << "\nType: " << type;
        cout << "\nEnergy consumption: " << energyConsumption;
        cout << "\nFilter: " << filter;
    }
    friend class List;
};

class List
{
public:
    Base *head;
    void addNode(Base *node);
    void insert(List &list);
    void deleteNode();
    void displayList();
    void displayByPrice();
    void searchNode();
};

void List::addNode(Base *node)
{
    Base *bptr;
    bptr = head;

    if (bptr)
    {
        if (node->manufacturer < bptr->manufacturer)
        {
            node->next = head;
            head = node;
        }
        else
        {
            while (bptr->next && bptr->next->manufacturer < node->manufacturer)
                bptr = bptr->next;

            node->next = bptr->next;
            bptr->next = node;
        }
    }
    else
        head = node;
}

class Overload
{
private:
    string manufacturer;
    int category,
        nrMotors,
        price;

public:
    inline string getManufacturer() { return manufacturer; }
    inline int getCategory() { return category; }
    inline int getNrMotors() { return nrMotors; }
    inline int getPrice() { return price; }
    friend ostream &operator<<(ostream &out, Overload &stream);
    friend istream &operator>>(istream &in, Overload &stream);
};

ostream &operator<<(ostream &out, Overload &stream)
{
    cout << "\nPay attention\n";
    return out;
}
istream &operator>>(istream &in, Overload &stream)
{
    cout << "Manufacturer: ";
    // cin >> stream.manufacturer;
    stream.manufacturer = "AA";
    cout << "Nr of motors: ";
    // cin >> stream.nrMotors;
    stream.nrMotors = 12;
    cout << "Price: ";
    // cin >> stream.price;
    stream.price = 13;
    cout << "Category (0 - embeddable / !0 - traditional): ";
    // cin >> stream.category;
    stream.category = 1;
    return in;
}

class Exception
{
public:
    string message;
    int data;
    Exception()
    {
        message = "";
        data = 0;
    };
    Exception(
        string message,
        int data)
    {
        message = message;
        data = data;
    };
};

void List::insert(List &list)
{
    Base *bptr;
    string manufacturer;
    int category,
        nrMotors,
        price;
    Overload stream;
    cout << stream;
    cin >> stream;

    if (stream.getCategory())
    { // traditional
        int energyClass,
            control;
        string color;

        cout << "Control: ";
        // cin >> control;
        control = 14;
        cout << "Color: ";
        // cin >> color;
        color = "aa";
        try
        {
            cout << "Energy class: ";
            // cin >> energyClass;
            energyClass = 4;
            if (energyClass <= 0)
                throw Exception("\nIt's supposed to be a positive integer", energyClass);
        }
        catch (Exception e)
        {
            do
            {
                cout << e.message;
                cout << "\nEnter a valid value: ";
                cin >> energyClass;
            } while (energyClass <= 0);
        }
        Traditional *tptr;
        tptr = new Traditional(energyClass,
                               control,
                               color,
                               stream.getManufacturer(),
                               stream.getNrMotors(),
                               stream.getPrice(),
                               stream.getCategory());
        bptr = tptr;
        list.addNode(bptr);
    }
    else
    { // embeddable
        int type,
            energyConsumption,
            filter;

        cout << "Type: ";
        cin >> type;
        cout << "Filter: ";
        cin >> filter;
        try
        {
            cout << "Energy consumption: ";
            cin >> energyConsumption;
            if (energyConsumption <= 0)
                throw Exception("\nIt's supposed to be a positive integer", energyConsumption);
        }
        catch (Exception e)
        {
            do
            {
                cout << e.message;
                cout << "\nEnter a valid value: ";
                cin >> energyConsumption;
            } while (energyConsumption <= 0);
        }

        Embeddable *eptr;
        eptr = new Embeddable(type,
                              energyConsumption,
                              filter,
                              stream.getManufacturer(),
                              stream.getNrMotors(),
                              stream.getPrice(),
                              stream.getCategory());
        list.addNode(eptr);
    }
}
void List::displayList()
{
    Base *bptr;
    bptr = head;
    if (bptr)
    {
        while (bptr)
        {
            bptr->display();
            bptr = bptr->next;
        }
    }
    else
        cout << "\nList is empty";
}
void List::displayByPrice()
{
}
void List::deleteNode()
{
}
void List::searchNode()
{
}
int main()
{
    int option = 0;
    List list;
    list.head = NULL;

    while (option != 1)
    {
        cout << "\n0. Exit";
        cout << "\n1. Add";
        cout << "\n2. Display alphabetically";
        cout << "\n3. Display by price";
        cout << "\n4. Delete by manufacturer and nr of motors";
        cout << "\n5. Search by manufacturer and price";
        cout << "\nOption: ";
        // cin >> option;
        option = 1;

        switch (option)
        {
        case 0:
            return 0;
            break;
        case 1:
            list.insert(list);
            list.displayList();
            return 0;
            break;
        case 2:
            list.displayList();
            break;
        case 3:
            list.displayByPrice();
            break;
        case 4:
            list.deleteNode();
            break;
        case 5:
            list.searchNode();
            break;
        default:
            break;
        }
    }
}