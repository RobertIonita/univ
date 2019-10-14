#include <iostream>
using namespace std;
// clasa de baza
class Forma
{
public:
    // funcție setare latime
    void setLatime(int w)
    {
        latime = w;
    }
    // functie setare inaltime
    void setInaltime(int h)
    {
        inaltime = h;
    }

protected:
    int latime;
    int inaltime;
};
// clasa derivata
class Dreptunghi : public Forma
{
public:
    // funcție de calculare a ariei
    int getAria()
    {
        return (latime * inaltime);
    }
};
int main(void)
{
    // crearea unui obiect
    Dreptunghi Rect;
    Rect.setLatime(5);
    Rect.setInaltime(7);
    // Afisarea ariei obiectului.
    cout << "Aria totala: " << Rect.getAria() << endl;
    return 0;
}