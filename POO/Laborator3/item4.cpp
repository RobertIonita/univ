#include <iostream>
using namespace std;
// clasa de baza
class Forma
{
protected:
    int latime;
    int lungime;

public:
    // constructorul clasei de baza
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
    // funcția pentru calcularea ariei
    int getAria()
    {
        return (lungime * latime);
    }
};
class Atreiadimensiune
{
protected:
    int inaltimea;

public:
    Atreiadimensiune(int h) { inaltimea = h; };
};
// clasa derivata
// mosternire multipla
class Paralelipiped : public Dreptunghi, public Atreiadimensiune
{
public:
    Paralelipiped(int w, int l, int k) : Dreptunghi(w, l), Atreiadimensiune(k){};
    int getVolum()
    {
        return (lungime * latime * inaltimea);
    }
};
int main(void)
{
    Dreptunghi Rect(8, 7);
    // Afisarea ariei obiectului.
    cout << "Aria totala dreptunghi: " << Rect.getAria() << endl;
    Paralelipiped par(9, 8, 4);
    cout << "Aria totala dreptunghi: " << par.getAria() << endl;
    cout << "Volumul totala paralelipiped: " << par.getVolum() << endl;
    return 0;
}