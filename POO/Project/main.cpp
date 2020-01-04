#include <iostream> // Header that defines the standard input/output stream objects
#include <fstream>  // Header providing file stream classes
using namespace std;

class List;
class Base;
class Mobile;
class Landline;
int menu();
void tempUtility();

int main(void) // Driver function
{
    tempUtility();
    // menu();
    return 0;
}

class Exception
{
public:
    string message;
    int data;
    Exception()
    {
        this->message = "";
        this->data = 0;
    }
    Exception(string mesage, int data)
    {
        this->message = mesage;
        this->data = data;
    }
};

class Base // Base class
{
private:
    string manufacturer, // Google/Apple/..
        color;           // White/Black/..
    unsigned short int
        price,    // in USD
        weight,   // in grams
        category; // 0 - mobile / !0 - landline
    Base *next;

public:
    Base( // Base class object constructor
        string manufacturer,
        string color,
        unsigned short int price,
        unsigned short int weight,
        unsigned short int category)
    {
        this->manufacturer = manufacturer;
        this->color = color;
        this->price = price;
        this->weight = weight;
        this->category = category;
    }
    virtual void display() // Display Base class object fileds
    {
        cout << "\n------------------------------------\n";
        cout << "\nManufacturer: " << this->manufacturer;
        cout << "\nColor: " << this->color;
        cout << "\nPrice: $" << this->price;
        cout << "\nWeight: " << this->weight << "g";
    }
    virtual Base *getData() // Get Base class object
    {
        return this;
    }
    friend class List;
};

class Mobile : public Base // Derived class Mobile extends class Base
{
private:
    string screen,       // Amoled/OLED/IPS/..
        operatingSystem; // Android/iOS/Symbian/..
    unsigned short int
        warranty; // in months
public:
    Mobile( // Derived class object constructor
        string screen,
        string operatingSystem,
        unsigned short int warranty,
        string manufacturer,
        string color,
        unsigned short int price,
        unsigned short int weight,
        unsigned short int category) : Base(manufacturer,
                                            color,
                                            price,
                                            weight,
                                            category)
    {
        this->screen = screen;
        this->operatingSystem = operatingSystem;
        this->warranty = warranty;
    }
    void display() // Display Mobile class object and Base class object fileds
    {
        Base::display(); // Display Base class object fileds
        cout << "\nDisplay: " << screen;
        cout << "\nOperating system: " << operatingSystem;
        cout << "\nWarranty: " << warranty << " months";
    }
    friend class List;
};
class Size // Utility class to store size
{
public:
    unsigned short int
        width,     // in mm
        length,    // in mm
        thickness; // in mm
    Size *getData()
    {
        return this;
    }
};

class Landline : public Base // Derived class Landline extends class Base
{
private:
    unsigned short int
        type : 1,       // 0 - Analog/ 1 - Digital
        ringtoneVolume; // in dB
    Size *size;         // Size of landline

public:
    Landline( // Derived class object constructor
        Size *size,
        unsigned short int type,
        unsigned short int ringtoneVolume,
        string manufacturer,
        string color,
        unsigned short int price,
        unsigned short int weight,
        unsigned short int category) : Base(manufacturer,
                                            color,
                                            price,
                                            weight,
                                            category)
    {
        this->size = size;
        this->type = type;
        this->ringtoneVolume = ringtoneVolume;
    }
    void display() // Display Landline class object and Base class object fileds
    {
        string techType;
        type ? techType = "Digital" : techType = "Analog";

        Base::display(); // Display Base class object fileds
        cout << "\nType: " << techType;
        cout << "\nRingtone volume: " << ringtoneVolume << "dB";
        cout << "\nWidth: " << size->width << "mm";
        cout << "\nLength: " << size->length << "mm";
        cout << "\nThickness: " << size->thickness << "mm";
    }
    friend class List;
};

class List
{
public:
    Base *head;
    void addNode(Base *node);
    void displayList();
    void insert();
};

void List::addNode(Base *node)
{
    Base *bptr;
    bptr = head;
    if (bptr)
    {
        if (node->color < bptr->color)
        {
            node->next = head;
            head = node;
        }
        else
        {
            while (bptr->next && (bptr->next)->color < node->color)
                bptr = bptr->next;
            node->next = bptr->next;
            bptr->next = node;
        }
    }
    else
        head = node;
}

void List::displayList()
{
    Base *bptr;
    bptr = head;

    if (!bptr)
        cout << "List is empty";
    else
        while (bptr)
        {
            bptr->display();
            bptr = bptr->next;
        }
}

class Overload // class used to overload operators
{
private:
    string manufacturer, // Google/Apple/..
        color;           // White/Black/..
    unsigned short int
        price,    // in USD
        weight,   // in grams
        category; // 0 - mobile / !0 - landline
public:
    Base *bptr;
    int getCategory()
    {
        return this->category;
    }
    Base *construnctBase()
    {
        bptr = new Base(manufacturer, color, price, weight, category);
        return bptr;
    }
    friend ostream &operator<<(ostream &out, Overload &stream);
    friend istream &operator>>(istream &in, Overload &stream);
};
ostream &operator<<(ostream &out, Overload &stream) // function to overload displaying
{
    cout << "\nData will be recorded:\n";
    return out;
}
istream &operator>>(istream &in, Overload &stream) // function to overload reading
{
    cout << "Manufacturer: ";
    // cin >> stream.manufacturer;
    stream.manufacturer = "LG";
    cout << "Color: ";
    // cin >> stream.color;
    stream.color = "White";
    cout << "Price: ";
    // cin >> stream.price;
    stream.price = 230;
    cout << "Weight: ";
    // cin >> stream.weight;
    stream.weight = 139;
    cout << "Category (0 - mobile / !0 - landline): ";
    // cin >> stream.category;
    stream.category = 1;
    return in;
}

void List::insert()
{
    Base *bptr;      // instance of Base object pointer
    Overload stream; // instance of Overload object
    cout << stream;  // overload displaying
    cin >> stream;   // overload reading
    bptr = stream.construnctBase();

    if (stream.getCategory() == 0)
    { // mobile
        Mobile *mptr;
        string screen,
            operatingSystem;
        unsigned short int warranty;

        try
        {
            cout << "Screen technology: ";
            cin >> screen;
            cout << "Operating system: ";
            cin >> operatingSystem;
            cout << "Warranty: ";
            cin >> warranty;
            if (warranty < 6)
                throw(Exception("\nWarranty should be at least 6 months", warranty));
        }
        catch (Exception e)
        {
            do
            {
                cout << e.message;
                cout << "\nInseart a valid warranty period: ";
                cin >> warranty;
            } while (warranty < 6);
        }
        mptr = new Mobile(screen,
                          operatingSystem,
                          warranty,
                          bptr->manufacturer,
                          bptr->color,
                          bptr->price,
                          bptr->weight,
                          bptr->category);
        this->addNode(mptr);
    }
    else
    { // landline
        Landline *lptr;
        Size size;
        unsigned short int
            type,
            ringtoneVolume;

        cout << "Width (mm): ";
        // cin >> size.width;
        size.width = 203;
        cout << "Length (mm): ";
        // cin >> size.length;
        size.length = 308;
        cout << "Thickness (mm): ";
        // cin >> size.thickness;
        size.thickness = 49;
        cout << "Type (0 - analog / 1 - digital): ";
        // cin >> type;
        type = 1;
        try
        {
            cout << "Ringtone volume (dB): ";
            // cin >> ringtoneVolume;
            ringtoneVolume = 56;
            if (ringtoneVolume >= 160)
                throw(Exception("\nYour eardrums will burst at this point", ringtoneVolume));
        }
        catch (Exception e)
        {
            do
            {
                cout << e.message;
                cout << "\nInseart a safe ringtone volume: ";
                cin >> ringtoneVolume;
            } while (ringtoneVolume >= 160);
        }
        lptr = new Landline(&size,
                            type,
                            ringtoneVolume,
                            bptr->manufacturer,
                            bptr->color,
                            bptr->price,
                            bptr->weight,
                            bptr->category);
        this->addNode(lptr);
    }
}

int menu()
{
    unsigned short int option;
    List list;
    list.head = NULL;
    while (1)
    {
        cout << "\n1. Încarcare informații dintr-un fișier.";
        cout << "\n2. Adăugarea unui articol nou";
        cout << "\n3. Afișarea articolelor pe categorie și salvarea în fișier";
        cout << "\n4. Stergerea unei articol după producător și culoare.";
        cout << "\n5. Modificarea prețului";
        cout << "\n6. Sortarea listei după culoare";
        cout << "\n7. Salvarea într-un fișier a articolelor după un preț citit de la tastatură.";
        cout << "\n8. Ieșire";
        cout << "\nOptiunea aleasă: ";
        // cin >> option;
        option = 2;
        switch (option)
        {
        case 1:
            break;
        case 2:
            list.insert();
            list.displayList();
            break;
        case 3:
            list.displayList();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            return 0;
            break;
        default:
            cout << "\nOptiunea invalida: ";
            break;
        }
    }
}

void tempUtility()
{
    Base *base;
    List list;
    Mobile *mobile;
    Landline *landline;

    string
        manuf = "Google",
        color = "White",
        screen = "OLED",
        os = "Android";

    unsigned short int
        price = 2,
        weight = 162,
        warranty = 24,
        volume = 45,
        type = 1,
        category = 0;

    Size size;
    size.width = 200;
    size.length = 240;
    size.thickness = 80;

    base = new Base(manuf, color, price, weight, category);
    mobile = new Mobile(screen, os, warranty, manuf, color, price, weight, category);
    category = 1;
    landline = new Landline(&size, type, volume, manuf, color, price, weight, category);
    base->display();
    list.addNode(mobile);
    list.addNode(landline);
    list.displayList();
}