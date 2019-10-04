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
    void initialize(char *d_name, char *d_surname, char *d_address, int d_id, int d_age)
    {
        strcpy(name, d_name);
        strcpy(surname, d_surname);
        strcpy(address, d_address);
        id = d_id;
        age = d_age;
    }
    //functie de showOff
    void showOff()
    {
        cout << "Nume: " << name << endl;
        cout << "Prenume: " << surname << endl;
        cout << "Vârsta: " << age << endl;
        cout << "Adresa: " << id << endl;
        cout << "CNP: " << id << endl;
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
    void initialize(char *c_make, char *c_model, char *c_driver,  int c_year)
    {
        strcpy(make, c_make);
        strcpy(model, c_model);
        strcpy(driver, c_driver);
        year = c_year;
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
    cin.getline(name, 20);
    cout << "Dați prenumele șoferului: ";
    cin.getline(surname, 20);
    cout << "Dați adresa șoferului: ";
    cin.getline(address, 50);
    cout << "Dați vârsta șoferului: ";
    cin >> age;
    cout << "Dați cnp-ul șoferului: ";
    cin >> id;
    cout << "Dați marca mașinii: ";
    while (getchar() != '\n')
    ;
    cin.getline(make, 20);
    cout << "Dați modelul mașinii: ";
    cin.getline(model, 20);
    cout << "Dați numele șoferului mașinii: ";
    cin.getline(driver, 20);
    cout << "Dați anul de fabricare mașinii: ";
    cin >> year;

    student.initialize(name, surname, address, age, id);
    car.initialize(make, model, driver, year);
    student.showOff();
    car.showOff();



    return 0;
}