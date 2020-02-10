#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>
#include <string>
using namespace std;

class Exception
{
public:
    int value;
    string msg;
    Exception()
    {
        value = 0;
        msg = "";
    }
    Exception(int value, string msg)
    {
        this->value = value;
        this->msg = msg;
    }
};

class Base
{
    int value;
    unsigned short int type;
    string data;
    Base *next;

public:
    Base(int value, string data, unsigned short int type)
    {
        this->value = value;
        this->data = data;
        this->type = type;
    }
    virtual void display()
    {
        cout << "\n-------------------";
        cout << "\nValue: " << value;
        cout << "\nData: " << data;
    }
    friend class List;
};

class Derived1 : Base
{
    int first;

public:
    Derived1(
        int first,
        int value,
        string data,
        unsigned short int type) : Base(value,
                                        data,
                                        type)
    {
        this->first = first;
    }
    void display()
    {
        Base::display();
        cout << "\nFirst: " << first;
    }
    friend class List;
};

class Derived2 : Base
{
    int second;

public:
    Derived2(
        int second,
        int value,
        string data,
        unsigned short int type) : Base(value,
                                        data,
                                        type)
    {
        this->second = second;
    }
    void display()
    {
        Base::display();
        cout << "\nSecond: " << second;
    }
    friend class List;
};

class Overload
{
    int value,
        type;
    string data;

public:
    Base *bptr;
    Base *constructBase()
    {
        bptr = new Base(value, data, type);
        return bptr;
    }
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
    cout << "Value: ";
    cin >> stream.value;
    cout << "Data: ";
    cin >> stream.data;
    cout << "Type (0 - Derived1 / !0 - Derived2): ";
    cin >> stream.type;
    return in;
}

class List
{
public:
    Base *head;
    void addNode(Base *node);
    void deleteNode(string data);
    void insert();
    void remove();
    void displayList();
};

void List::addNode(Base *node)
{
    Base *bptr;
    bptr = head;

    if (bptr)
    {
        if (node->data < bptr->data)
        {
            node->next = head;
            head = node;
        }
        else
        {
            while (bptr->next && bptr->next->data < node->data)
                bptr = bptr->next;

            node->next = bptr->next;
            bptr->next = node;
        }
    }
    else
        head = node;
}

void List::insert()
{
    Base *bptr;
    int value;
    string data;
    Overload stream;

    cout << stream;
    cin >> stream;
    bptr = stream.constructBase();

    if (bptr->type)
    { // Derived2
        int second;
        try
        {
            cout << "Second: ";
            cin >> second;
            if (second < 0)
                throw Exception(second, "\nNegative values are not allowed");
        }
        catch (Exception e)
        {
            cout << e.msg;
            do
            {
                cout << "\nInsert a positive integer: ";
                cin >> second;
            } while (second < 0);
        }
        Derived1 *dptr;
        dptr = new Derived1(second,
                            bptr->value,
                            bptr->data,
                            bptr->type);
        this->addNode(dptr);
    }
    else
    { // Derived1
        int first;
        try
        {
            cout << "First: ";
            cin >> first;
            if (first == 0)
                throw Exception(first, "\nNil values are not allowed");
        }
        catch (Exception e)
        {
            cout << e.msg;
            do
            {
                cout << "\nInsert a non-nil integer: ";
                cin >> first;
            } while (first == 0);
        }

        Derived2 *dptr;
        dptr = new Derived2(first,
                            bptr->value,
                            bptr->data,
                            bptr->type);
        this->addNode(dptr);
    }
}

void List::displayList()
{
    Base *bptr;
    if (head)
        for (bptr = head; bptr != NULL; bptr = bptr->next)
            bptr->display();
    else
        cout << "\nList is empty";
}

void List::deleteNode(string data)
{
    Base *bptr = head;
    if (bptr)
    {
        if (bptr->data == data)
            head = bptr->next;
        else
        {
            while (bptr->next != NULL && bptr->next->data != data)
                bptr = bptr->next;
            if(bptr->next)
            {
                if (bptr->next->next)
                    bptr->next = bptr->next->next;
                else
                    bptr->next = NULL;
            }
            else
                cout << "\nRecord not found";
            
        }
    }
    else
        cout << "\nList is emty";
}

void List::remove()
{
    string data;
    cout << "\nData: ";
    cin >> data;
    this->deleteNode(data);
}

int main()
{
    List list;
    list.head = NULL;
    int option;

    while (1)
    {
        cout << "\n0. Exit";
        cout << "\n1. Add item";
        cout << "\n2. Display list";
        cout << "\n3. Delete item";
        cout << "\nChoice: ";
        cin >> option;
        switch (option)
        {
        case 0:
            return 0;
            break;
        case 1:
            list.insert();
            break;
        case 2:
            list.displayList();
            break;
        case 3:
            list.remove();
            break;
        default:
            cout << "\nInvalid option";
            break;
        }
    }
}