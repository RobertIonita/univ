#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Lista;

class Instrumente
{
private:
    string material;
    string culoare;
    string producator;
    int tip;
    Instrumente *urm;

public:
    Instrumente(int t, string materia, string culoar, string producat)
    {
        material = materia;
        culoare = culoar;
        producator = producat;
        tip = t;
    }
    virtual void afisare()
    {
        cout << "Material: " << material << "\n";
        cout << "Culoare: " << culoare << "\n";
        cout << "Producator: " << producator << "\n";
    }

    inline virtual string getNume() { return 0; }
    inline virtual int getVechime() { return 0; }
    inline virtual string getBbrand() { return 0; }
    inline virtual int getOctave() { return 0; }

    friend class Lista;
};

class Pian : public Instrumente
{
private:
    string nume;
    int vechime;

public:
    Pian(int t, string materia, string culoar, string producat, string num, int vech) : Instrumente(t, materia, culoar, producat)
    {
        nume = num;
        vechime = vech;
    }
    void afisare()
    {
        Instrumente::afisare();
        cout << "Nume: " << nume << "\n";
        cout << "Vechime: " << vechime << "\n\n";
    }

    inline string getNume() { return nume; }
    inline int getVechime() { return vechime; }

    friend class Lista;
};

class Flaut : public Instrumente
{
private:
    string brand;
    int octave;

public:
    Flaut(int t, string materia, string culoar, string producat, string bran, int oc) : Instrumente(t, materia, culoar, producat)
    {
        brand = bran;
        octave = oc;
    }
    void afisare()
    {
        Instrumente::afisare();
        cout << "Brand:" << brand << "\n";
        cout << "Octave atinse: " << octave << "\n\n";
    }

    inline string getBbrand() { return brand; }
    inline int getOctave() { return octave; }

    friend class Lista;
};

class Lista
{
public:
    Instrumente *head;
    void adaugare(Instrumente *a);
    void afisare_lista();
    void stergere(string cul);
    void cautare_lista(string materiaaal);
    void salvare();
    void citire(Lista &list);
};

void Lista::cautare_lista(string materiaaal)
{
    Instrumente *a;
    for (a = head; a && a->material != materiaaal; a = a->urm)
        ;
    if (a)
        a->afisare();
    else
        cout << "Error 404: Not Found.";
}

void Lista::adaugare(Instrumente *a)
{
    Instrumente *p;
    p = head;

    if (!p)
        head = a;
    else
    {
        if (p)
        {
            if (a->material == p->material)
            {
                a->urm = head;
                head = a;
            }
            else
            {
                while (p->urm && ((p->urm)->material < a->material))
                    p = p->urm;
                a->urm = p->urm;
                p->urm = a;
            }
        }
    }
}

void Lista::stergere(string cul)
{
    Instrumente *p, *q;
    p = q = head;

    if (p)
    {
        while (p && p->culoare != cul)
        {
            q = p;
            p = p->urm;
        }
        if (p)
        {
            if (p != q)
            {
                q->urm = p->urm;
                delete p;
            }
            else
            {
                head = p->urm;
                delete p;
            }
        }
        else
            cout << "\nCuloarea nu exista in lista";
    }
    else
        cout << "\nLista este vida!";
}

void Lista::afisare_lista()
{
    Instrumente *a;
    a = head;
    if (!a)
        cout << "Lista e vida. \n";
    else
        while (a)
        {
            a->afisare();
            a = a->urm;
        }
}

class Supraincarcare
{
public:
    string plastic, color, produc;

public:
    friend ostream &operator<<(ostream &out, Supraincarcare &a);
    friend istream &operator>>(istream &in, Supraincarcare &a);
};

ostream &operator<<(ostream &out, Supraincarcare &a)
{
    cout << "Reading data..\n";
    return out;
}

istream &operator>>(istream &in, Supraincarcare &a)
{
    cout << "Material: ";
    cin >> a.plastic;
    cout << "Culoare: ";
    cin >> a.color;
    cout << "Producator: ";
    cin >> a.produc;
    return in;
}

class MyException
{
public:
    string str_what;
    int what;
    MyException()
    {
        str_what = " ";
        what = 0;
    }
    MyException(string s, int e)
    {
        str_what = s;
        what = e;
    }
};

void introducere(Lista &list, int x)
{
    string nu, bra;
    int vec, oct;
    Instrumente *instr;
    Supraincarcare supr;
    cout << supr;
    cin >> supr;

    if (x == 2)
    {
        Pian *pi;
        cout << "Nume pian: ";
        cin >> nu;
        try
        {
            cout << "Vechimea pianului: ";
            cin >> vec;
            if (vec <= 0)
                throw MyException("Va rugam sa dati o valoare valida. ", vec);
        }
        catch (MyException e)
        {
            do
            {
                cout << "Dati vechimea pianului: ";
                cin >> vec;
            } while (vec <= 0);
        }
        pi = new Pian(x, supr.plastic, supr.color, supr.produc, nu, vec);
        instr = pi;
        list.adaugare(pi);
    }

    else if (x == 3)
    {
        Flaut *fla;
        cout << "Brand: ";
        cin >> bra;
        cout << "Octave atinse: ";
        cin >> oct;
        fla = new Flaut(x, supr.plastic, supr.color, supr.produc, bra, oct);
        instr = fla;
        list.adaugare(fla);
    }
}

void Lista::citire(Lista &list)
{
    Instrumente *a;
    Pian *pian;
    Flaut *flaut;
    ifstream f;
    char aux;
    string materiall, culoaree, getNume, producatorr, brandd;
    int tipp, octavee, getVechime;
    f.open("Text.txt");
    if (f.is_open())
    {
        while (f >> tipp >> materiall >> culoaree >> producatorr)
        {
            if (tipp == 2)
            {
                f >> getNume;
                f >> getVechime;
                pian = new Pian(tipp, materiall, culoaree, producatorr, getNume, getVechime);
                list.adaugare(pian);
            }
            if (tipp == 3)
            {
                f >> brandd;
                f >> octavee;
                flaut = new Flaut(tipp, materiall, culoaree, producatorr, brandd, octavee);
                list.adaugare(flaut);
            }
        }
    }
    f.close();
}

void Lista::salvare()
{
    Instrumente *a;
    a = head;
    ofstream f;
    f.open("TextIesire.txt");
    if (f.is_open())
    {
        while (a)
        {
            f << a->tip << " ";
            f << a->material << " ";
            f << a->culoare << " ";
            f << a->producator << " ";
            if (a->tip == 2)
            {
                f << a->getNume() << " ";
                f << a->getVechime() << "\n";
            }
            else if (a->tip == 3)
            {
                f << a->getBbrand() << " ";
                f << a->getOctave() << "\n";
            }
            a = a->urm;
        }
        f.close();
    }
    else
        cout << "Fisierul nu poate fi deschis.\n\n";
}

int main()
{
    Lista list;
    list.head = NULL;
    int opt;
    string m, cul;
    do
    {
        cout << "\n0. Iesire.";
        cout << "\n1. Incarcare date din fisier.";
        cout << "\n2. Adaugare piane.";
        cout << "\n3. Adaugare flaute.";
        cout << "\n4. Afisare lista instrumente.";
        cout << "\n5. Cautare instrument dupa material.";
        cout << "\n6. Stergere dupa culoare";
        cout << "\n7. Salvare date in fisier.";
        cout << "\nOptiunea dvs: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            list.citire(list);
            break;
        case 2:
            introducere(list, 2);
            break;
        case 3:
            introducere(list, 3);
            break;
        case 4:
            list.afisare_lista();
            break;
        case 5:
            cout << "Dati materialul: ";
            cin >> m;
            list.cautare_lista(m);
            break;
        case 6:
            cout << "\nDati culoarea: ";
            cin >> cul;
            list.stergere(cul);
            break;
        case 7:
            list.salvare();
            break;
        default:
            cout << "\nNu ati introdus o varianta valida. \n";
        }
    } while (opt != 0);
    return 0;
}