#include <iostream>
// #include <stdafx.h>
#include <string.h>

using namespace std;

class Driver
{
    char name[20],
        surname[20],
        address[50];
    int id,
        age;

public:
    //funcție inline într-un mod automat
    void initialize()
    {
        cin.get(name, 20);
        cin.get(surname, 20);
        cin.get(address, 50);
        cin >> id;
        cin >> age;
    }
    //functie de showOff
    void showOff()
    {
        cout << "Nume: " << name << endl;
        cout << "Prenume: " << surname << endl;
        cout << "Vârsta: " << age << endl;
        cout << "CNP: " << id << endl;
        cout << "Adresa: " << id << endl;
    }
};

class Vehicle
{
    int year;
    char make[20],
        model[20],
        driver[20];

public:
    //funcție inline într-un mod automat
    void initialize()
    {
        cin >> year;
        cin.get(make, 20);
        cin.get(model, 20);
        cin.get(driver, 20);
    }
    //functie de showOff
    void showOff()
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Driver: " << driver << endl;
    }
};

int main()
{
    Driver student;
    Vehicle car;

    int age, id, year;
    char name[20],
        surname[20],
        address[50],
        make[20],
        model[20],
        driver[20];
        
    cout << "Dați numele șoferului: ";
    cin >> name;
    cout << "Dați prenumele șoferului: ";
    cin >> surname;
    cout << "Dați adresa șoferului: ";
    cin >> address;
    cout << "Dați vârsta șoferului: ";
    cin >> age;
    cout << "Dați cnp-ul șoferului: ";
    cin >> id;
    cout << "Dați marca mașinii: ";
    cin >> make;
    cout << "Dați modelul mașinii: ";
    cin >> model;
    cout << "Dați anul de fabricare mașinii: ";
    cin >> year;
    cout << "Dați numele șoferului mașinii: ";
    cin >> driver;

    student.initialize();
    car.initialize();
    student.showOff();
    car.showOff();



    return 0;
}