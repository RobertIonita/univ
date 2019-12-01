#include <iostream> // Header that defines the standard input/output stream objects
#include <fstream>  // Header providing file stream classes
using namespace std;

class Base // Base class
{
private:
    string manufacturer, // Google/Apple/..
        color;           // White/Black/..
    unsigned short int
        price,  // in USD
        weight; // in grams

public:
    Base( // Base class object constructor
        string manufacturer,
        string color,
        unsigned short int price,
        unsigned short int weight)
    {
        this->manufacturer = manufacturer;
        this->color = color;
        this->price = price;
        this->weight = weight;
    }
    virtual void display() // Display Base class object fileds
    {
        cout << "\n------------------------------------\n";
        cout << "\nManufacturer: " << this->manufacturer;
        cout << "\nColor: " << this->color;
        cout << "\nPrice: " << this->price;
        cout << "\nWeight: " << this->weight;
    }
    virtual Base *getData() // Get Base class object
    {
        return this;
    }
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
        unsigned short int weight) : Base(manufacturer,
                                          color,
                                          price,
                                          weight)
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
};
class Size // Utility class to store size
{
public:
    unsigned short int
        width,     // in mm
        height,    // in mm
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
        ringtoneVolume; // in db
    Size *size;         // Size of landline

public:
    Landline( // Derived class object constructor
        Size *size,
        unsigned short int type,
        unsigned short int ringtoneVolume,
        string manufacturer,
        string color,
        unsigned short int price,
        unsigned short int weight) : Base(manufacturer,
                                          color,
                                          price,
                                          weight)
    {
        this->size = size->getData();
        this->type = type;
        this->ringtoneVolume = ringtoneVolume;
    }
    void display() // Display Landline class object and Base class object fileds
    {
        Base::display(); // Display Base class object fileds
        cout << "\nType: " << type ? "Digital" : "Analog";
        cout << "\nRingtone volume: " << ringtoneVolume;
        cout << "\nWidth: " << size->width << "mm";
        cout << "\nHeight: " << size->height << "mm";
        cout << "\nThickness: " << size->thickness << "mm";
    }
};

int menu();
void tempUtility();

int main(void) // Driver function
{
    menu();
    return 0;
}

int menu()
{
    unsigned short int option;

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
            break;
        case 2:
            break;
        case 3:
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
        type = 1;

    Size size;
    size.width = 200;
    size.height = 240;
    size.thickness = 80;

    base = new Base(manuf, color, price, weight);
    mobile = new Mobile(screen, os, warranty, manuf, color, price, weight);
    landline = new Landline(&size, type, volume, manuf, color, price, weight);
    base->display();
    mobile->display();
    landline->display();
}