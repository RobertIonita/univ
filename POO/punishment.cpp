#include <iostream>
#include <ostream>
#include <istream>
using namespace std;

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
        this->manufacturer = manufacturer;
        this->nrMotors = nrMotors;
        this->price = price;
        this->category = category;
    }
    virtual void display()
    {
        std::cout << "\nManufacturer: " << manufacturer;
        std::cout << "\nPrice: " << price;
        std::cout << "\nNr motors: " << nrMotors;
    }
    friend class List;
};

class Traditional : Base
{
    int energyClass;
    string color,
        control;

public:
    Traditional(
        string color,
        string control,
        int energyClass,
        string manufactuter,
        int nrMotors,
        int price,
        int category) : Base(manufactuter,
                             nrMotors,
                             price,
                             category)
    {
        this->control = control;
        this->color = color;
        this->energyClass = energyClass;
    }
    void display()
    {
        Base::display();
        std::cout << "\nControl: " << control;
        std::cout << "\nColor: " << color;
        std::cout << "\nEnergy class: " << energyClass;
        std::cout << "\n--------------------";
    }
    friend class List;
};
class Embeddable : Base
{
    int type,
        energyConsumption;
    string filter;

public:
    Embeddable(
        int type,
        int energyConsumption,
        string filter,
        string manufactuter,
        int nrMotors,
        int price,
        int category) : Base(manufactuter,
                             nrMotors,
                             price,
                             category)
    {
        this->type = type;
        this->energyConsumption = energyConsumption;
        this->filter = filter;
    }
    void display()
    {
        Base::display();
        std::cout << "\nType: " << type;
        std::cout << "\nFilter: " << filter;
        std::cout << "\nEnergy consumption: " << energyConsumption;
        std::cout << "\n--------------------";
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
    Base *bptr;
    Base *construnctBase()
    {
        bptr = new Base(manufacturer, nrMotors, price, category);
        return bptr;
    }
    friend ostream &operator<<(ostream &out, Overload &stream);
    friend istream &operator>>(istream &in, Overload &stream);
};

ostream &operator<<(ostream &out, Overload &stream)
{
    std::cout << "\nPay attention\n";
    return out;
}
istream &operator>>(istream &in, Overload &stream)
{
    std::cout << "Manufacturer: ";
    std::cin >> stream.manufacturer;
    std::cout << "Nr of motors: ";
    std::cin >> stream.nrMotors;
    std::cout << "Price: ";
    std::cin >> stream.price;
    std::cout << "Category (0 - embeddable / !0 - traditional): ";
    std::cin >> stream.category;
    return in;
}

void List::insert(List &list)
{
    Base *bptr;
    string manufacturer;
    int category,
        nrMotors,
        price;
    Overload stream;
    std::cout << stream;
    std::cin >> stream;
    bptr = stream.construnctBase();

    if (bptr->category)
    { // traditional
        int energyClass;
        string color,
            control;

        std::cout << "Control: ";
        std::cin >> control;
        std::cout << "Color: ";
        std::cin >> color;
        try
        {
            std::cout << "Energy class: ";
            std::cin >> energyClass;
            if (energyClass <= 0)
                throw Exception("\nIt's supposed to be a positive integer", energyClass);
        }
        catch (Exception e)
        {
            do
            {
                std::cout << e.message;
                std::cout << "\nEnter a valid value: ";
                std::cin >> energyClass;
            } while (energyClass <= 0);
        }
        Traditional *tptr;
        tptr = new Traditional(control,
                               color,
                               energyClass,
                               bptr->manufacturer,
                               bptr->nrMotors,
                               bptr->price,
                               bptr->category);
        bptr = tptr;
        list.addNode(bptr);
    }
    else
    { // embeddable
        int type,
            energyConsumption;
        string filter;

        std::cout << "Type: ";
        std::cin >> type;
        std::cout << "Filter: ";
        std::cin >> filter;
        try
        {
            std::cout << "Energy consumption: ";
            std::cin >> energyConsumption;
            if (energyConsumption <= 0)
                throw Exception("\nIt's supposed to be a positive integer", energyConsumption);
        }
        catch (Exception e)
        {
            do
            {
                std::cout << e.message;
                std::cout << "\nEnter a valid value: ";
                std::cin >> energyConsumption;
            } while (energyConsumption <= 0);
        }

        Embeddable *eptr;
        eptr = new Embeddable(type,
                              energyConsumption,
                              filter,
                              bptr->manufacturer,
                              bptr->nrMotors,
                              bptr->price,
                              bptr->category);
        bptr = eptr;
        list.addNode(bptr);
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
        std::cout << "\nList is empty";
}
void List::displayByPrice()
{
    int price;
    std::cout << "\nPrice: ";
    std::cin >> price;

    Base *bptr;
    bptr = head;
    if (bptr)
    {
        while (bptr)
        {
            if (bptr->price == price)
                bptr->display();
            bptr = bptr->next;
        }
    }
    else
        std::cout << "\nList is empty";
}
void List::deleteNode()
{
    Base *aux,
        *bptr;
    bptr = aux = head;
    string manufacturer;
    int nrMotors;
    std::cout << "Manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Nr of motors: ";
    std::cin >> nrMotors;

    if (bptr)
    {
        while (bptr && (bptr->manufacturer != manufacturer || bptr->nrMotors != nrMotors))
        {
            aux = bptr;
            bptr = bptr->next;
        }
        if (bptr)
        {
            if (bptr != aux)
            {
                aux->next = bptr->next;
                delete bptr;
            }
            else
            {
                head = bptr->next;
                delete bptr;
            }
        }
        else
            std::cout << "\nRecord not found";
    }
    else
        std::cout << "\nList is empty";
}
void List::searchNode()
{
    Base *bptr;
    bptr = head;
    string manufacturer;
    int price;
    std::cout << "Manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Price: ";
    std::cin >> price;
    while (bptr->next && (bptr->manufacturer != manufacturer || bptr->price != price))
        bptr = bptr->next;
    if (bptr)
        bptr->display();
    else
        std::cout << "\nRecord not found";
}
int main()
{
    int option;
    List list;
    list.head = NULL;

    while (1)
    {
        std::cout << "\n0. Exit";
        std::cout << "\n1. Add";
        std::cout << "\n2. Display alphabetically";
        std::cout << "\n3. Display by price";
        std::cout << "\n4. Delete by manufacturer and nr of motors";
        std::cout << "\n5. Search by manufacturer and price";
        std::cout << "\nOption: ";
        std::cin >> option;

        switch (option)
        {
        case 0:
            return 0;
            break;
        case 1:
            list.insert(list);
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