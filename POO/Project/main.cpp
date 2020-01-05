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
    // tempUtility();
    menu();
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
    inline virtual string getScreenType() { return 0; }
    inline virtual string getOS() { return 0; }
    inline virtual unsigned short int getWarranty() { return 0; }
    inline virtual float getSize() { return 0; }
    inline virtual unsigned short int getTechType() { return 0; }
    inline virtual unsigned short int getRingVolume() { return 0; }
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
    inline string getScreenType() { return this->screen; }
    inline string getOS() { return this->operatingSystem; }
    inline unsigned short int getWarranty() { return this->warranty; }

    friend class List;
};

class Landline : public Base // Derived class Landline extends class Base
{
private:
    unsigned short int
        type : 1,       // 0 - Analog/ 1 - Digital
        ringtoneVolume; // in dB
    float size;         // Size of landline

public:
    Landline( // Derived class object constructor
        float size,
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
        cout << "\nSize: " << size << "inch";
    }
    inline float getSize() { return this->size; }
    inline unsigned short int getTechType() { return this->type; }
    inline unsigned short int getRingVolume() { return this->ringtoneVolume; }
    friend class List;
};

class List
{
public:
    Base *head;
    void addNode(Base *node);
    void displayList();
    void insert();
    void writeDown();
    void deleteNode();
    void populate();
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
        cout << "\nList is empty";
    else
    {
        cout << "\n\t\tMobile:";
        while (bptr)
        {
            if (bptr->category == 0)
                bptr->display();
            bptr = bptr->next;
        }
        bptr = head;

        cout << "\n\n\t\tLandline:";
        while (bptr)
        {
            if (bptr->category == 1)
            {
                bptr->display();
            }
            bptr = bptr->next;
        }
    }
    cout << "\n------------------------------------\n";
}

void List::writeDown()
{
    Base *bptr;
    bptr = head;
    ofstream file;

    file.open("POO/Project/assets/output.txt");
    if (file.is_open())
    {
        while (bptr)
        {
            file << bptr->category << " ";
            file << bptr->manufacturer << " ";
            file << bptr->color << " ";
            file << bptr->price << " ";
            file << bptr->weight << " ";
            if (bptr->category == 0)
            { // mobile
                file << bptr->getScreenType() << " ";
                file << bptr->getOS() << " ";
                file << bptr->getWarranty() << "\n";
            }
            else
            { // landline
                file << bptr->getTechType() << " ";
                file << bptr->getRingVolume() << " ";
                file << bptr->getSize() << "\n";
            }
            bptr = bptr->next;
        }
        file.close();
    }
    else
    {
        cout << "\nFile was not open";
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
    cin >> stream.manufacturer;
    cout << "Color: ";
    cin >> stream.color;
    cout << "Price: ";
    cin >> stream.price;
    cout << "Weight: ";
    cin >> stream.weight;
    cout << "Category (0 - mobile / !0 - landline): ";
    cin >> stream.category;
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
        float size;
        unsigned short int
            type,
            ringtoneVolume;

        cout << "Size (inch): ";
        cin >> size;
        cout << "Type (0 - analog / 1 - digital): ";
        cin >> type;
        try
        {
            cout << "Ringtone volume (dB): ";
            cin >> ringtoneVolume;
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
        lptr = new Landline(size,
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

void List::deleteNode()
{
    Base *bptr, *aux;
    bptr = aux = head;
    string manufacturer,
        color;
    cout << "Manufacturer: ";
    cin >> manufacturer;
    cout << "Color: ";
    cin >> color;

    if (bptr)
    {
        while (bptr && (bptr->manufacturer != manufacturer || bptr->color != color))
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
            cout << "\nRecord not found";
    }
    else
        cout << "\nList is empty";
}

void List::populate()
{
    Base *bptr;
    Mobile *mptr;
    Landline *lptr;
    bptr = head;
    ifstream file;
    string screen, manufacturer, color, OS;
    unsigned short int warranty, price, weight, category, type, volume;
    float size;
    string str;
    file.open("POO/Project/assets/input.txt");
    if (file.is_open())
    {
        while (file >> category >> manufacturer >> color >> price >> weight)
        {
            if (category == 0)
            {
                file >> screen >> OS >> warranty;
                mptr = new Mobile(screen, OS, warranty, manufacturer, color, price, weight, category);
                this->addNode(mptr);
            }
            else
            {
                file >> size >> type >> volume;
                lptr = new Landline(size, type, volume, manufacturer, color, price, weight, category);
                this->addNode(lptr);
            }
        }
        file.close();
    }
    else
        cout << "\nFile was not open";
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
        cin >> option;
        switch (option)
        {
        case 1:
            list.populate();
            break;
        case 2:
            list.insert();
            break;
        case 3:
            list.displayList();
            list.writeDown();
            break;
        case 4:
            list.deleteNode();
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
    float size = 5.4;
    base = new Base(manuf, color, price, weight, category);
    mobile = new Mobile(screen, os, warranty, manuf, color, price, weight, category);
    category = 1;
    landline = new Landline(size, type, volume, manuf, color, price, weight, category);
    base->display();
    list.addNode(mobile);
    list.addNode(landline);
    list.displayList();
}