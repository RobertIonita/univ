#include <iostream>

using namespace std;
int main()
{
    int nr;
    cout << "Valoare numarului intreg este: ";
    cin >> nr;
    // declararea și inițializarea variabilelor pentru sumă și produs
    int s = 0, p = 1;
    // folosirea instrucțiunii while pentru citirea numerelor până la întâlnirea numărului 0
    while (nr != 0)
    {
        //verificarea numărului dacă este număr par
        if (nr % 2 == 0)
            s = s + nr;
        else
            p = p * nr;
        cout << "Valoare numarului intreg este: ";
        cin >> nr;
    }
    cout << "Suma numerelor pare este: " << s << endl;
    cout << "Produsul numerelor impare este: " << p;
    return 0;
}