#include <iostream>
using namespace std;
// crearea unei functii inline care va returna numarul minim
inline int minim(int x, int y)
{
    return x < y ? x : y;
}
int main()
{
    //citirea a doua valori intregi
    int x, y;
    cout << "Dati valoarea lui x: ";
    cin >> x;
    cout << "Dati valoarea lui y: ";
    cin >> y;
    //afisarea minimului
    cout << "Minimul este: " << minim(x, y);
    return 0;
}