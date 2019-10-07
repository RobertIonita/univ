#include <iostream>
using namespace std;
//definirea structurii masina
typedef struct
{
    char marca[20];
    char model[30];
    float consum, pret;
} masina;
int main()
{
    //crearea unui pointer de tip masina
    masina *ma;
    //alocarea dinamica a memoriei pentru pointer
    ma = new masina;
    //citirea informatiilor
    cout << "Dati marca masinii: ";
    cin >> ma->marca;
    cout << "Dati modelul masinii: ";
    cin >> ma->model;
    cout << "Dati consumul de combustibil: ";
    cin >> ma->consum;
    cout << "Dati pretul masinii: ";
    cin >> ma->pret;
    //afisarea informatiilor

    cout << "Marca: " << ma->marca << " Model: " << ma->model << " Consum: " << ma->consum << " Pret: " << ma->pret;
    delete ma;
    return 0;
}