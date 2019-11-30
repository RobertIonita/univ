#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <cstddef>
#include <valarray>

using namespace std;

class lista; //prototipul clasei lista
class sport  //clasa de baza sport
{
private:
	string nume,
		nume_a;
	int nr_pers,
		tip;
	sport *urm; //adresa urmatorului element din lista
public:
	sport(int tip_s, string n, string n_a, int nr) //constructor clasa de baza
	{
		nume = n;	 //alocare memorie pt variabila nume
		nume_a = n_a; //alocarea memorie pt variabila nume antrenor
		nr_pers = nr;
		tip = tip_s;
		urm = NULL; //adresa noului nod este initial NULL
	}
	int getTip()
	{
		return tip;
	}
	void seteazaNume(string numeNou)
	{
		nume_a = numeNou;
	}
	virtual void afisare() //functia de afisare elemente clasa de baza
	{
		cout << "-------------------------------\n";
		cout << "Nume: " << nume << endl;
		cout << "Nume antrenor: " << nume_a << endl;
		cout << "Numar persoane: " << nr_pers << endl;
		cout << "Tip: " << getTip() << endl;
	}
	virtual void scriere_sport() //functia de afisare elemente clasa de baza
	{
		ofstream fis;
		fis.open("POO/Project/assets/output.txt");
		if (fis.is_open())
		{
			fis << getTip() << " ";
			fis << nume << " ";
			fis << nume_a << " ";
			fis << nr_pers << " ";
			fis.close();
		}
		else
		{
			cout << "Auzi, bă, vezi că nu ți-a deschis fișierul";
		}
	}
	friend class lista; //declararea clasei lista friend la clasa de baza sport, pentru a avea acces la campurile acesteia
};

class volei : public sport //prima clasa derivata
{
private:
	string loc_intalnire;
	int categorie;

public:
	volei(int tip_s, string n, string n_a, int nr, string loc, int c) : sport(tip_s, n, n_a, nr) //constructor clasa derivata
	{
		loc_intalnire = loc;
		categorie = c;
	}
	void afisare() //afisare elemente din clasa derivata volei
	{
		sport::afisare(); //apelare afisare elemente din clasa de baza
		cout << "Loc de intalnire: " << loc_intalnire << endl;
		cout << "Categorie: " << categorie << endl;
	}
	friend class lista;
};

class baschet : public sport //a doua clasa derivata
{
private:
	string club,
		localitate;

public:
	baschet(int tip_s, string n, string n_a, int nr, string cl, string local) : sport(tip_s, n, n_a, nr) //constructor clasa derivata
	{
		club = cl;
		localitate = local;
	}
	void afisare() //functie de afisare
	{
		sport::afisare();
		cout << "Club: " << club << endl;
		cout << "Localitate: " << localitate << endl;
	}
	friend class lista;
};

class Supraincarcare // clasa utilizata pentru supraincarcarea operatorilor
{
	string nume_echipa,
		nume_antrenor;
	int nr_persoane,
		tip_sport;

public:
	friend ostream &operator<<(ostream &out, Supraincarcare &s);
	friend istream &operator>>(istream &in, Supraincarcare &s);
	string returnEchipa()
	{
		return nume_echipa;
	}
	string returnAntrenor()
	{
		return nume_antrenor;
	}
	int returnNr()
	{
		return nr_persoane;
	}
	int returnTip()
	{
		return tip_sport;
	}
};
ostream &operator<<(ostream &out, Supraincarcare &s) // functia de supraincarcare a operatorului de scriere
													 // acesta va fi utilizat pentru afisarea unui mesaj
{
	cout << "Vom citi datele pentru volei si basket:" << endl;
	cout << endl;
	return out;
}
istream &operator>>(istream &in, Supraincarcare &s) // functia de supraincarcare a operatorului de citire
													// acesta va fi utilizat pentru citirea datelor specifice clasei de baza
{
	cout << "Dati nume echipa: ";
	cin >> s.nume_echipa;
	cout << "Dati nume antrenor: ";
	cin >> s.nume_antrenor;
	cout << "Dati nr persoane: ";
	cin >> s.nr_persoane;
	cout << "Ce tip de sport? (0 - volei/ !0 - basket): ";
	cin >> s.tip_sport;
	return in;
}

class lista //class litsa
{
public:
	sport *head;	 //capul listei
	void adaugare(sport *s); //adaugare in lista
	void afisare_lista();	//afisarea listei
	void modificare(string nume, string nume_nou);
};

class MyException
{
public:
	string str_what;
	int what;
	MyException()
	{
		str_what = "";
		what = 0;
	}
	MyException(string s, int e)
	{
		str_what = s;
		what = e;
	}
};
class MyException2
{
public:
	string str_what;
	string what;
	MyException2()
	{
		str_what = "";
		what = " ";
	}
	MyException2(string s, string e)
	{
		str_what = s;
		what = e;
	}
};

void citire(lista &list) //citire din fisier
{
	ifstream fis("POO/Project/assets/input.txt");
	string linie_fisier,
		loc = "loc",
		club = "club",
		echipa = "echipa",
		antrenor = "antrenor";

	int nr_persoane = 2,
		categorie = 1,
		tip;

	volei *v;
	baschet *b;

	if (fis.is_open())
	{
		while (getline(fis, linie_fisier))
		{
			tip = std::stoi(linie_fisier, nullptr, 10);
			cout << "\n"
				 << tip;
			if (tip == 0)
			{
				v = new volei(tip, echipa, antrenor, nr_persoane, loc, categorie); //apelare constructcu info citite
				list.adaugare(v);
			}
			else
			{
				b = new baschet(tip, echipa, antrenor, nr_persoane, club, loc); //apelare constructor cu info citite
				list.adaugare(b);
			}
		}
		fis.close();
	}
	else
		cout << "Nu s-a putut deschide fisierul";
}
void introducere(lista &list) //introducere info in noduri
{
	int categorie;
	string loc,
		club; //Ex. A3, A3/A4/A5, A4, etc.
	sport *s;

	Supraincarcare supr;

	cout << supr; // supraincarcarea scrierii
	cin >> supr;  // supraincarcarea citirii

	if (supr.returnTip() == 0) // daca s-a ales adaugarea volei
	{
		volei *v;

		try
		{
			cout << "Introduceti categoria: ";
			cin >> categorie;
			cout << "Locul de intalnire: ";
			cin >> loc;
			if (categorie < 0)
				throw MyException("Categoria nu are o valoare pozitiva \n", categorie);
		}
		catch (MyException e)
		{
			do
			{
				cout << "Introduceti valoare pozitiva: ";
				cin >> categorie;
			} while (categorie < 0);
		}

		v = new volei(supr.returnTip(), supr.returnEchipa(), supr.returnAntrenor(), supr.returnNr(), loc, categorie); //apelare constructcu info citite
		s = v;
		list.adaugare(v); //se adauga nodul
	}
	else if (supr.returnTip() == 1) //daca s-a ales adaugarea basket
	{
		baschet *b;

		try
		{
			cout << "Introduceti localitatea: ";
			cin >> loc;
			cout << "Introduceti numele clubului: ";
			cin >> club;
			if (club.length() < 2)
				throw MyException2("Numele clubului nu e valid\n", club);
		}
		catch (MyException2 e)
		{
			do
			{
				cout << "Introduceti un nume cu mai mult de 2 caractere: ";
				cin >> club;
			} while (club.length() < 3);
		}

		b = new baschet(supr.returnTip(), supr.returnEchipa(), supr.returnAntrenor(), supr.returnNr(), club, loc); //apelare constructor cu info citite
		s = b;																									   //cast pentru clasa de baza
		list.adaugare(b);																						   //se adauga nodul
	}
}

void lista::afisare_lista() //afisarea listei
{
	sport *s;
	s = head; //se initializeaza cu capul listei
	if (!s)   //daca lista este vida
		cout << "Lista este vida!";
	else
	{
		cout << "\nVolei: \n";
		while (s) //cat timp sunt noduri in lista
		{
			if (s->getTip() == 0)
			{
				s->afisare(); //se apeleaza afisarea corespunzatoare nodului curent
				s->scriere_sport();
			}
			s = s->urm; //se trece la urm nod in lista
		}
		s = head;
		cout << "\nBaschet: \n";
		while (s) //cat timp sunt noduri in lista
		{
			if (s->getTip() == 1)
			{
				s->afisare(); //se apeleaza afisarea corespunzatoare nodului curent
				s->scriere_sport();
			}
			s = s->urm; //se trece la urm nod in lista
		}
	}
}

void lista::modificare(string nume, string nume_nou)
{
	sport *p; //variabila p este declarata de tip sport
	p = head; //se initializeaza cu capul listei
	while (p) //daca lista nu e vida
	{
		if (nume == p->nume_a)		 //daca nodul care se adauga este mai mic decat primul nod din lista
			p->seteazaNume(nume_nou); //capul listei devine noul nod
		p = p->urm;
	}
}

//adaugarea in lista ordonata
void lista::adaugare(sport *s)
{
	sport *p; //variabila p este declarata de tip sport
	p = head; //se initializeaza cu capul listei
	if (p)	//daca lista nu e vida
	{
		if (s->nr_pers < p->nr_pers) //daca nodul care se adauga este mai mic decat primul nod din lista
		{
			s->urm = head; //noul nod se leaga de primul nod
			head = s;	  //capul listei devine noul nod
		}
		else
		{
			while (p->urm && (p->urm)->nr_pers < s->nr_pers) //se parcurge lista pana cand exista elemente si noul nod nu este mai mare decat nodul curent
				p = p->urm;
			s->urm = p->urm; //se fac legaturi intre noul nod si cele din lista
			p->urm = s;
		}
	}
	else
		head = s; //daca lista este vida, capul este nodul adaugat
}

int main() //programul principal
{
	int opt;
	lista list;
	string str1 = "nume1",
		   str2 = "nume nou";
	list.head = NULL;
	do
	{
		cout << "\n1.Incarcare informații dintr-un fișier..";
		cout << "\n2.Adăugarea unui echipe noi.";
		cout << "\n3.Afișarea echipelor pe categorie și salvarea în fișier.";
		cout << "\n4.Stergerea unei echipe după nume ";
		cout << "\n5.Modificarea numelui antrenorului ";
		cout << "\n6.Sortarea listei după nr persoane ";
		cout << "\n7.Salvarea într-un fișier a echipelor după numele atrenorului citit de la tastatură.";
		cout << "\n0.Iesire.";
		cout << "\nDati optiunea dvs: ";
		cin >> opt;
		//apelare functii in functie de optiunea aleasa
		switch (opt)
		{
		case 1:
			citire(list);
			break;
		case 2:
			introducere(list);
			break;
		case 3:
			list.afisare_lista();
			break;
		case 4:
			list.modificare(str1, str2);
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "Comanda gresita!";
		}
	} while (opt != 0);
}