#include <iostream>
using namespace std;
class Student
{
    char nume[20], pren[20];

    int grupa, cod_postal;

public:
    Student(); //Constructor

    ~Student(); //Destructor
    void citire_date();
    void afisare_date();
};
//constructor
Student::Student()
{
    cout << "Constructor: Informatiile despre student:" << endl;
}
// funcție pentru citirea informațiilor
void Student::citire_date()
{
    cout << "Nume:";
    cin >> nume;
    cout << "Prenume:";
    cin >> pren;
    cout << "Grupa:";
    cin >> grupa;
    cout << "Cod postal: ";
    cin >> cod_postal;
}
//funcție pentru afișarea datelor
void Student::afisare_date()
{
    cout << "Nume :" << nume << endl;
    cout << "Prenume:" << pren << endl;
    cout << "Grupa:" << grupa << endl;
    cout << "Cod postal :" << cod_postal;
}
//destructor
Student ::~Student()
{
    cout << "Destructor: Eliberare memorie! ";
}
int main()
{
    //crearea unui obiect de tip Student
    Student s;
    //citirea informațiilor
    s.citire_date();
    //afișarea informațiilor
    s.afisare_date();
    //s.~Student( ) //apelare explicită

    return 0;
}