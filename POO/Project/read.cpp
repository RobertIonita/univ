#include <iostream>
#include <fstream> //biblioteca pentru lucru cu fisiere
#include <string>
using namespace std;
int main()
{
    //crearea unui obiect pentru citirea din fisier
    ifstream fis("POO/Project/assets/input.txt");
    //variabila care va retine textul
    string linie_fisier;
    //se verifica daca este deschis fisierul
    if (fis.is_open())
    {
        //se afiseaza informatia din fisier linie cu linie
        while (getline(fis, linie_fisier))
        {
            cout << linie_fisier << endl;
        }
        //se inchide fisierul
        fis.close();
    }
    else
        //daca nu se deschide fisierul se afiseaza urmatorul mesaj
        cout << "Nu s-a putut deschide fisierul";
    return 0;
}