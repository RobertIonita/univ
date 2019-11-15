#include <iostream>
using namespace std;
class Nod
{
    int info;
    Nod *next, *prim, *ultim;

public:
    Nod()
    {
        Nod::prim = NULL;
        Nod::ultim = NULL;
    };
    void adaugare_in_spate();
    void afisare_lista();
    void inserare_element_dupa_o_valoare(int);
    void inserare_element_inainte_de_o_valoare(int);
    void stergere_element_lista(int);
    void ordonare_lista();
};
//functia de creare si adaugare a unui nou element in spatele listei
void Nod::adaugare_in_spate()
{
    Nod *c;
    //daca lista este vida (prim==0) se aloca primul Nod
    if (!prim)
    {
        prim = new Nod;
        cout << "Dati informatia din nod: ";
        cin >> prim->info;
        //la creare primul si ultimul Nod vor fi identici
        ultim = prim;
    }
    //altfel se adauga un nou element la sfarsit
    else
    {
        //se aloca un nou Nod
        c = new Nod;
        cout << "Dati informatia din nod: ";
        //se completeaza campul informatie utila
        cin >> c->info;
        //se adauga dupa ultimul Nod
        ultim->next = c;
        //noul nod devine ultimul
        ultim = c;
    }
    //adresa ultimului nod devine NULL
    ultim->next = NULL;
}
//functia de afisare_lista parcurge elementele listei si le afiseaza
void Nod::afisare_lista()
{
    Nod *nod;
    //se porneste de la primul nod din lista
    nod = prim;
    //cat timp nu am ajuns la sfarsitul listei
    while (nod)
    {
        //se afiseaza informatia
        cout << nod->info << " ";
        //se avanseaza la urmatorul nod din lista
        nod = nod->next;
    }
    cout << endl;
}
void Nod::inserare_element_dupa_o_valoare(int val)
{
    //nodul *a retine adresa nodului de inserat, cu nodul *c se avanseaza in lista
    Nod *c, *a;
    c = prim;
    //verificam existenta informatiei in lista
    while (c)
    {
        if (c->info != val)
            c = c->next;
        else
            break;
    }
    if (c)
    {
        //se porneste de la primul nod
        c = prim;
        //cat timp nu am gasit informatia si nu e sfarsitul listei
        while (c->info != val && c->next != NULL)
            //inaintam in lista
            c = c->next;
        //alocam memorie pentru nod
        a = new Nod;
        //citim informatia
        cout << "Introduceti informatia nodului pe care il inserati: ";
        cin >> a->info;
        //legam nodul in locul potrivit
        a->next = c->next;
        c->next = a;
        //daca adaugam nodul la sfarsit
        if (c == ultim)
            ultim = a;
    }
    else
        cout << "Info nu este!";
}
void Nod::inserare_element_inainte_de_o_valoare(int val)
{
    //nodul *a retine adresa nodului de inserat, cu nodul *c se avanseaza in lista
    Nod *c, *a;
    //verificam existenta informatiei in lista
    c = prim;
    while (c)
    {
        if (c->info != val)
            c = c->next;
        else
            break;
    }
    if (c)
    {
        c = prim;
        //daca inseram inaintea primului nod
        if (prim->info == val)
        {
            c = new Nod;
            cout << "Introduceti informatia nodului pe care il inserati: ";
            cin >> c->info;
            //legam nodul de primul nod
            c->next = prim;
            //primul nod devine cel inserat
            prim = c;
        }
        //daca nu inseram inainte de primul nod
        else
        {
            //c se pozitioneaza inainte de elementul cautat
            while (c->next->info != val && c)
                c = c->next;
            //alocam memorie noului nod
            a = new Nod;
            cout << "Introduceti informatia nodului pe care il inserati: ";
            cin >> a->info;
            //legam nodul de lista
            a->next = c->next;
            c->next = a;
        }
    }
    else

        cout << "Elementul dat nu se gaseste in lista!";
}
void Nod::stergere_element_lista(int val)
{
    //nodul a se sterge, c este nodul precedent
    Nod *c, *a;
    c = prim;
    //daca se sterge primul nod
    if (prim->info == val)
    {
        //se retine primul nod in a
        a = prim;
        //primul va deveni urmatorul element
        prim = prim->next;
        //se elibereaza memoria
        delete a;
    }
    //daca nu e primul nod
    else
    {
        //se cauta elementul de sters
        while (c->next->info != val && c)
            c = c->next;
        //se tine nodul de sters
        a = c->next;
        c->next = a->next;
        //daca se sterge ultimul nod
        if (a == ultim)
            ultim = c;
        // se elibereaza memoria
        delete a;
    }
}
void Nod::ordonare_lista()
{
    Nod *c;
    int ord, aux;
    //bubble sort
    do
    {
        c = prim;
        ord = 1;
        //cat nu am ajuns la sfarsitul listei
        while (c->next)
        {
            //daca nodurile nu sunt ordonate
            if (c->info > c->next->info)
            {
                //se interschimba informatia
                aux = c->info;
                c->info = c->next->info;
                c->next->info = aux;
                ord = 0;
            }
            //se inainteaza in lista
            c = c->next;
        }
    } while (ord == 0);
}
int main()
{
    Nod nd;
    int n, val_info;
    cout << "Dati numarul de noduri=";
    cin >> n;
    //adaugare
    for (int i = 1; i <= n; i++)
        nd.adaugare_in_spate();
    cout << endl;
    //afisare lista
    nd.afisare_lista();
    //inserare dupa o valoare
    cout << "Dupa ce valoare din lista se realizeaza inserarea: ";
    cin >> val_info;
    nd.inserare_element_dupa_o_valoare(val_info);
    nd.afisare_lista();
    //inserare dupa o valoare
    cout << "Valoarea inainte de care se face inserarea ";
    cin >> val_info;
    nd.inserare_element_inainte_de_o_valoare(val_info);
    nd.afisare_lista();
    //stergere
    cout << endl
         << "Ce element vreti sa stergeti: ";
    cin >> val_info;
    nd.stergere_element_lista(val_info);
    nd.afisare_lista();
    //ordonare
    nd.ordonare_lista();
    nd.afisare_lista();
}