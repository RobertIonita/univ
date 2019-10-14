#include <iostream>
using namespace std;
// clasa de baza
class Forma
{
protected:
    int latime;
    int lungime;

public:
    // constructorul clasei de bază
    Forma(int w, int l)
    {
        latime = w;
        lungime = l;
    }
};
// clasa derivata
class Dreptunghi : public Forma
{
public:
    // constructorul clasei derivate
    Dreptunghi(int w, int l) : Forma(w, l){};
    // funcția de claculare a ariei
    int getAria()
    {
        return (lungime * latime);
    }
};
// clasa derivata
class Paralelipiped : public Dreptunghi
{
    int inaltimea;

public:
public:
    // constructorul clasei derivate
    Paralelipiped(int w, int l, int h) : Dreptunghi(w, l)
    {
        inaltimea = h;
    };
    // funcția de calculare a volumului
    int getVolum()
    {
        return (lungime * latime * inaltimea);
    }
};
int main(void)
{
    // crearea unui obiect
    Dreptunghi Rect(5, 7);
    // Afisarea ariei obiectului.
    cout << "Aria totala dreptunghi: " << Rect.getAria() << endl;
    Paralelipiped par(2, 3, 4);
    cout << "Aria totala dreptunghi: " << par.getAria() << endl;
    cout << "Volumul totala paralelipiped: " << par.getVolum() << endl;
    return 0;
}