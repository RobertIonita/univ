#include <iostream>
using namespace std;
int main()
{
    int nr;
    cout << "Valoare numarului intreg este: ";
    cin >> nr;
    int s = 0, p = 1;
    //verificam daca numarul introdus este 0
    while (nr != 0)
    {
        //verificam daca numarul este par
        if (nr % 2 == 0)
            //daca numarul este par atunci se va aduna la suma anterioara
            s = s + nr;
        else
            //daca numarul este impar atunci se va înmulti cu produsul anterior
            p = p * nr;
        cout << "Valoare numarului intreg este: ";
        //se citeste urmatorul numar
        cin >> nr;
    }
    //se afiseaza suma si produsul
    cout << "Suma numerelor pare este: " << s << endl;
    cout << "Produsul numerelor impare este: " << p;
    getchar();
    return 0;
}