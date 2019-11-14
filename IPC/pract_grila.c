#include <stdio.h>

#include <stdlib.h>

#include <time.h>

int main()
{
	int op, i, start = 1, cate, corect = 0, gresit = 0,
			   var, total = 149;

	printf("\n Insert start question number: ");
	scanf("%d", &start);
	for (cate = start; cate <= total; cate++)
	{
		op = cate;
		printf("\nIntrebarea %d", cate);
		switch (op)
		{
		case 1:
			printf("\nExecutia unui program se face din:\n1)memoria externa\n2)procesor\n3)memoria interna.\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 2:
			printf("\nCe valoare are variabila x din int x = 7^2?\n1)49\n2)3\n3)5.\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 3:
			printf("\nModulul grafic este utilizat\n1)pt afisarea desenelor si eventual a unui text\n2)pt afisarea caracterelor\n3)pt afisarea desenelor si caracterelor.\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 4:
			printf("\nPt declaratia int tab[10] care este rezultatul atribuirii tab[55] = 100\n1)eroare de compilare\n2)se scrie 100 peste caracterul de la tab[55]\n3)niciunul.\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 5:
			printf("\nCare este efectul secventei\nint n, i;\nprintf('Valoarea lui n:')\nscanf('%%d', &n);\nfor(i = 0 ; i < n ; i++)\n\tprintf('%%d', i);\n1)se afiseaza valori de la 1 la n\n2)se afiseaza valori de le 0 la n-1\n3)se afiseaza pe linie noua val n-1.\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 6:
			printf("\nCe este gresit in urmatoarea secventa?\nchar *sir\nstrcpy(sir,”Sesiune”)\n1)secventa este corecta\n2)Pointerul sir nu este initializat\n3)Nu se poate copia un sir de caractere intr-un pointer.\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 7:
			printf("\nValoarea zecimalei a constatei hexazecimale 0x88 este\n1)64\n2)16\n3)136.\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 8:
			printf("\nApelul care implica functia standard qsort:\nqsort(t, i, sizeof(int), (cmPtr)cmp)?\n1)este corect\n2)este gresit pentru ca apare incorect sizeof(int)\n3)este gresit pt ca lipseste ceva intre (cmPtr) si cmp.\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 9:
			printf("\nWorld Wide Web este:\n1)o infrastructura fizica\n2)o retea de informatii conectate\n3)un mediu suport pt comunicare.\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 10:
			printf("\nCare din urmatoarele clase de memorare se specifica implicit?\n1)auto\n2)register\n3)extern\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 11:
			printf("\nPentru\nint n = 12, m = 5;\nfloat x;\nvaloarea expresiei x = 1,5 + n/m este:\n1)3.9\n2)3.5\n3)de tip doble\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 12:
			printf("\nSecventa char = 'c';\nconst char *ptr = &ch;\n*ptr = 'a';\neste\n1)corecta\n2)eronata pt ca se modifica un pointer constant\n3)eronata pt ca se modifica o valoare constanta\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 13:
			printf("\nO functie modifica o variabile in functia care a apelat-o daca:\n1)in apelul fct se va preciza adresa variabilei a carei valoare va fi modificat si...\n2)in definitia functiei *same*...\n3)in declaratia functiei *same again*...\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 14:
			printf("\nUn calculator de proces\n1)este folosit pt a controla un proces\n2)calculeaza un proces\n3)descrie procese technologice\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;

		case 15:
			printf("\nPt situatia urmatoare:\ntypedef enum{calciu, magneziu, sodiu, potasiu, zinc}minerale;\nnminerale min;\ncare este intregul asociat elementului ”sodiu”?");
			printf("\n1)3");
			printf("\n2)2");
			printf("\n3)1\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 16:
			printf("\nCe va afisa secventa:\nint tab[] = {1, 12, 0x61};\nint *p;\np = tab + 2\nprintf(”o/oc”, *p);");
			printf("\n1)61");
			printf("\n2)0x63");
			printf("\n3)Simbolul corespunzator codului ASCII cu val 97\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 17:
			printf("\nInstructiunea DO...WHILE este:");
			printf("\n1)cu test initial");
			printf("\n2)cu test final");
			printf("\n3)fara test\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 18:
			printf("\nIn C, declararea unui tablou de fct");
			printf("\n1)este permisa");
			printf("\n2)este permisa cu anumite restrictii");
			printf("\n3)nu este permisa\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 20:
			printf("\nCare este rezultatul programului urmator:\n#include <stdio.h>\nint func(int, int)\nint main()\n{int result1, result2;\nint(*ptrFunc)(int, int);\nptrFunc = func;\nresult1 = (*ptrFunc)(10, 20);\nresult2 = ptrFunc(10, 20);\nprintf(”Rezultat1 = %%d Rezultat 2 = %%d”, result1, result2)\nreturn 0;\n}\nint func(int x, int y){return x + y;}");
			printf("\n1)Rezultat1 = 30 Rezultat2 = 30");
			printf("\n2)Rezultat1 = 30 Rezultat2 = 60");
			printf("\n3)Eroare de compilare\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 21:
			printf("\nCe facilitati ofera un mediu de programare?");
			printf("\n1)facilitati de scriere, compilare si depanare a programelor");
			printf("\n2)viteza de calcul sporita");
			printf("\n3)gestioneaza memoria calculatorului\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 22:
			printf("\nCare este rezultatul corect pt secventa de program:\nint main()\n{int a = 425\nint b = ++a %%10;\nprintf(”%%d”, b);");
			printf("\n1)3");
			printf("\n2)2");
			printf("\n3)6\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 23:
			printf("\nCe afiseaza urmatoarea secventa de program?\nint const x = 16;\nprintf(”%%d”,++x);");
			printf("\n1)eroare de compilare");
			printf("\n2)16");
			printf("\n3)17\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 24:
			printf("\nTipurile statice sunt(structurate):");
			printf("\n1)structura, pointere, sir de caractere, tablou");
			printf("\n2)structura, tablou, sir de caractere");
			printf("\n3)structura, pointer, caracter\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 25:
			printf("\nAlocarea dinamica a unui bloc de memorie cu instructiuni malloc() are loc in zona de memorie:");
			printf("\n1)stock/stiva");
			printf("\n2)BIOS");
			printf("\n3)heap\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 26:
			printf("\nCe afiseaza secventa urmatoare:\nfor( i = 0 ; i < n ; i++)\n\tfor( j = 0 ; j <= i ; j++)\n\t\tprintf(”o/of”, mat[i][j]);");
			printf("\n1)elemente de pe si de sub DP");
			printf("\n2)el de pe si de sub DS");
			printf("\n3)el de pe DS\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 27:
			printf("\nCe rezultat are executia urmatorului program:\n#include<stdio.h>\nint main()\n{int a = 5;\nswitch(a)\n{\tcase 1: printf(”UNU”);\n\tcase 2:printf(”DOI”);\n\tcase 3+2:printf(”TREI”);\n\tcase 5: printf(”STOP”);\n}\nreturn 0;\n}");
			printf("\n1)eroare pt ca nu exista ”break” peste tot");
			printf("\n2)eroare pt ca e duplicata eticheta 5");
			printf("\n3)eroare pt ca nu e permisa eticheta 3+2\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 28:
			printf("\nPt secventa int Tab[10]\nint *point_ex;\nint i;\npoint_ex = 8;\nAfirmatia incorecta e:");
			printf("\n1)Tab[5] = 16");
			printf("\n2)Point_ex[5] = 16;");
			printf("\n3)Point_ex[0] = 1;\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 29:
			printf("\nMetoda de proiectare ascendenta are ca dezavantaj:");
			printf("\n1)detectarea erorilor in faza de integrare");
			printf("\n2)detectarea erorilor in faza de proiectoare");
			printf("\n3)imposibilitatea detectarii eroriloe\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 30:
			printf("\nDeclararea unei variabile in C inseamna");
			printf("\n1)asocierea unui nume cu un domeniu de valori");
			printf("\n2)asocierea unui nume cu o zona de memorie");
			printf("\n3)asocierea unui tip cu o zona de memorie\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 31:
			printf("\nDeclaratia typedef struct\n{int re = 0;\nint im = 0;};\neste");
			printf("\n1)corecta");
			printf("\n2)corecta in anumite conditii");
			printf("\n3)nu este corecta\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 32:
			printf("\nCare este rezultatul instructiunii printf din secventa urmatoare:\nint x = 524;\nint y = x-- %%20;\nprintf(”%%d %%d”, x, y);");
			printf("\n1)5233");
			printf("\n2)5234");
			printf("\n3)5244\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 33:
			printf("\nPt afisarea in baza 10 a unui nr real in notatia zecimala, vom folosi secventa de formatare:");
			printf("\n1)%%e");
			printf("\n2)%%d");
			printf("\n3)%%f\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);

			break;
		case 34:
			printf("\nO variabila locala este recunoscuta din locul declaratiei pana la");
			printf("\n1)sfarsitul programului");
			printf("\n2)sfarsitul textului sursa");
			printf("\n3)sfarsitul blocului in care a fost declarata\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 35:
			printf("\nCare este varianta corecta de alocare dinamica pt tabloul bidimensional din secventa de mai jos:\nint *mat[i][j]\nfor(i = 0; i <3; i++)\n{\n\tfor(j=0;j<4;j++);\n\t{\n\t\tmat[i*4+j]=1;\n\t\tprintf(”%%d”, mat[i*4+j]);");
			printf("\n1)mat = (int*)malloc(3,4)");
			printf("\n2)mat = (int*)malloc(3*4*sizeof(int))");
			printf("\n3)mat = malloc(3*4*sizeof(int))\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 36:
			printf("\nCe se va afisa pe ecran in urma executarii urmatoarei secventa de instructiuni,\nstiind ca in variabila m au fost citite valorile 425,24,755\nint i, r;\nfor(i=1;i<4;i++)\n{\nscanf(”%%d”, &m);\nif(i %%2 == 0)\n\tprintf(”%%d, m %%10);\nelse prinf(” %%d”, (m/10)%%10);\n}");
			printf("\n1)3,4,5");
			printf("\n2)4,4,5");
			printf("\n3)2,4,5\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 37:
			printf("\nCe rezultat are programul?\nstruct Ptr\n{int x,y}\nint main()\n{\nstruct Ptrp1 = {1,2};\nstruct Ptr *p2 = &Ptr1;\nprintf(”%%d %%d”, p2->x, p2->y);\nreturn 0;");
			printf("\n1)eroare de compilare");
			printf("\n2)eroare de executie");
			printf("\n3)1 2\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 38:
			printf("\nFie secventa de cod:\nint main()\nchar s1[20] = ”aaa”;\nchar s2[10] = ”bbb”;\nint k = strlen(strcpy(strcat(s1,s2),s2));\nprintf(”%%d”, k);\nreturn 0;\n}\nValoarea variabilei k la iesire va fi:");
			printf("\n1)3");
			printf("\n2)6");
			printf("\n3)9\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 39:
			printf("\nCare este rezultat afisarii din secventa urmatoare de program\nint i=1;\nwhile(i++<5)\nprintf(”%%d”, i++);");
			printf("\n1)2 4 6");
			printf("\n2)6");
			printf("\n3)7\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 40:
			printf("\nCe afiseaza programul?\n...int main()\n{\nint x;\nfloat y;\ny=x=5.5;\nprintf(printf(”x=%%d y= %%f”, x,y);\nreturn 0;\n}");
			printf("\n1)5 5.000000");
			printf("\n2)5.000000 5.500000");
			printf("\n3)5 5\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 41:
			printf("\nCare este codul corespondent adaugarii unui nod in fata listei?");
			printf("\n1)q = prim\nwhile(q -> urm != NULL)\n\tq = q->urm;\nq->urm = prim;");
			printf("\n2)p->urm = prim;\nprim = p;");
			printf("\n3)p->urm = prim;\np = prim;\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 42:
			printf("\nCe va afisa urmatoarea secventa de cod:\n...int *v=20;\nprintf(”%%d”, *v);");
			printf("\n1)20");
			printf("\n2)Eroare");
			printf("\n3)Adresa variabilei v\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 43:
			printf("\nCare este rezultatul transformarii nr 243 din baza 10 in baza 16");
			printf("\n1)153");
			printf("\n2)3F");
			printf("\n3)F3\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 44:
			printf("\nCum se declara o variabila de tip vector de sir de caractere in limbajul C?");
			printf("\n1)char sir[20];");
			printf("\n2)string sir[20];");
			printf("\n3)char sir[20][20];\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 45:
			printf("\nCare va fi rezultatul executiei urmatorului program pt x=10 si y=20?\nint expmat(int a, int b)\n{float c;\nc=(a+b)/2;\nreturn 0;\n}\nint main()\nint x,y;\nc=0;\nexpmat(x,y);\nprintf(”Rezultatul este %%f”,c);\nreturn0;\n}");
			printf("\n1)Se va afisa 15.000000");
			printf("\n2)Se va afisa o eroare deoarece compilatorul nu vede valoarea schimbata dupa executia fct");
			printf("\n3)Vor fi erori de compilare\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 46:
			printf("\nCe semnifica modul ”wt” din urmatoarea secventa de program?\n...FILE *fisier;\nfisier=fopent(”exemplu.txt”;”wt”)");
			printf("\n1)doar scriere; daca fisierul nu exista acesta va fi creat, iar dc exista va fi suprascris");
			printf("\n2)citire si scriere; daca fisierul nu exista acesta va fi creat, iar dc exista va fi suprascris");
			printf("\n3)doar citire, daca fisierul nu exista se semnaleaza o eroare\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 47:
			printf("\nCe va afisa program?\n#include<stdio.h>\nint swap(char *sir1, char *sir2)\n{\nchar *temp=sir1;\nsir1=sir2;\nsir1=sir2;\nsir2=temp;\nreturn 0;\n}\nint main()\n{\nchar *s1=”Vacanta”;\nchar s2=”sesiune”\nswap(s1,s2);\nprintf(”sirul 1 este %%s, sirul 2 este %%s”, s1, s2);\nreturn 0;\n}");
			printf("\n1)sirul 1 este vacanta, sirul 2 este sesiune");
			printf("\n2)sirul 1 este sesiune, sirul 2 este vacanta");
			printf("\n3)nu se afiseaza nimic\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 48:
			printf("\nCare va fi noua valoare a variabilei z(in baza 10) dupa aplicarea operatorului\nde deplasare la stanga in urmatoarea secventa de cod:\nint z=255, z=z<<3;");
			printf("\n1)252");
			printf("\n2)2040");
			printf("\n3)2254\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 49:
			printf("\nCare dintre urmatorii operatori are cea mai mica prioritate?");
			printf("\n1)-");
			printf("\n2)/");
			printf("\n3)=\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 50:
			printf("\nCe tipareste secventa de cod:\nint a[s]={1,2,3};\nint *ptr=a;\nint **adr=&ptr;\nprintf(”%%p %%p”, *adrs, a);");
			printf("\n1)1 2");
			printf("\n2)doua adrese diferite");
			printf("\n3)aceeasi adresa de 2 ori\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 51:
			printf("\nCe valoare returneaza functia strcmp() cand cele doua stringuri care le opereaza sunt egale?");
			printf("\n1)2");
			printf("\n2)1");
			printf("\n3)0\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 52:
			printf("\nIn conformitate cu specificatiile ANSI cum se declara corect\nfct main cand primeste argumente in linie comanda");
			printf("\n1)int main(){ int arcg; char *argv;}");
			printf("\n2)int main()(int arcg, char *arcv[])");
			printf("\n3)int main(arcgc, argv)\nint arcgc;\nchar *argv;\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 53:
			printf("\nCe returneaza fct fopen() daca operatia de deschidere esueaza?");
			printf("\n1)va genera o eroare");
			printf("\n2)returneaza NULL");
			printf("\n3)returneaza un pointer catre tipul FILE\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 54:
			printf("\nCe valoare va avea y in secventa de program\n...int y;\nint z[3]={2,1};\ny=z[z[1]];");
			printf("\n1)1");
			printf("\n2)2");
			printf("\n3)”*backslash*0”\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 55:
			printf("\nSpatiu ocupat in memorie de o variabila de tip int");
			printf("\n1)este de 2 octeti");
			printf("\n2)este de 4 octeti");
			printf("\n3)depinde de tipul compilatorului\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 56:
			printf("\nCare dintre urmatoarele variante este un apel corect de functii");
			printf("\n1)func x,y;");
			printf("\n2)int funct()");
			printf("\n3)func()\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 57:
			printf("\nCe va afisa urmatoare secventa de cod?\nint x,y;\nint x=7;\ny=x>>2;\nprintf(”%%d”, y);");
			printf("\n1)0");
			printf("\n2)1");
			printf("\n3)2\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 58:
			printf("\nCe va afisa urmatorul program?\n#include <stdio.h>\nint main()\n{\nint c=1;\nwhile(c++<=10)\n\tprintf(”%%d”, c++);\nreturn 0;\n}");
			printf("\n1)3 6 9 12");
			printf("\n2)12");
			printf("\n3)2 4 6 8 10\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 59:
			printf("\nSingura operatie permisa in c, asociata unei variabile de tip tablou, ca intreg:");
			printf("\n1)este incrementarea");
			printf("\n2)este atribuirea");
			printf("\n3)nu exista\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 60:
			printf("\nCare este valoarea variabilei intregi i din instructiunea\nfor(i=0;i<15;i++){...}");
			printf("\n1)15");
			printf("\n2)14");
			printf("\n3)0\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 61:
			printf("\nIn secventa de cod\nFILE *fisier;\nfisier=fopen(”exemplu.txt”, ”at”);");
			printf("\n1)doar scriere, dc fisierul nu exista va fi creat, iar daca exista se va adauga la sfarsitul lui");
			printf("\n2)doar scriere, de fisierul nu exista va fi creat, iar daca exista va fi suprascris");
			printf("\n3)citire si scriere, dc fisierul nu exista va fi creat, iar daca exista va fi suprascris\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 62:
			printf("\nCe va afisa urmatoarea secventa de cod?\nint main()\n{\nint i;\nfor(i=1;i<=6;i++)\n{if(i %%3==0)break;\nprintf(”%%d”,i);\n}\nreturn0;\n}");
			printf("\n1)1 2");
			printf("\n2)1 2 4 5");
			printf("\n3)1 2 3\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 63:
			printf("\nCe este gresit in urmatoarea secventa?\nchar *sir;\nstrcpy(sir, ”vacanta”);");
			printf("\n1)Pointerul sir nu este initializat");
			printf("\n2)Secventa este corecta");
			printf("\n3)Nu se poate copia un sir de caractere intr-un pointer\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 64:
			printf("\nValoarea zecimala a constantei 0xA5 este:");
			printf("\n1)50");
			printf("\n2)165");
			printf("\n3)15\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 65:
			printf("\nCe rol are campul de inlantuire intr-un nod al liste simplu inlatuite?");
			printf("\n1)de a lega(inlantui) ultimul nod de primul");
			printf("\n2)indica adresa primului element din lista");
			printf("\n3)indica adresa urmatorului el din lista daca acesta exista\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 66:
			printf("\nCe va afisa la rulare urmatorul program, pt n=5?\n#include<stdio.h>\nint main()\n{float i,n;\nscanf(”%%f”, n);\nfor(i=1;i<=n;i++)\nztprintf(”%%f”, i);\nreturn 0;\n}");
			printf("\n1)1 2 3 4 5");
			printf("\n2)1.00000 2.00000 3.00000 4.00000 5.00000");
			printf("\n3)Eroare\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 67:
			printf("\nCe va afisa programul urmator:\ntypedef stuct\n{int numar;\nchar num[50];}curs;\nint main()\n{\ncurs[]={{1,”Limbajul c#”}, {2, ”Limbajul c++”}, {3,”Limbajul c}};\nprintf(”%%d”, c[1].numar);\nprintf(”%%s”, ((*(c+1).nume);\nreturn 0;\n}");
			printf("\n1)Limbajul c++");
			printf("\n2)limbajul c#");
			printf("\n3)limbajul c\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 68:
			printf("\nSecventa de program\nint func(int x){x=10;}\nint main()\n{int y=20;\nfunc(y);\nprintf(”%%d”, y);\nreturn0;\n}\n va afisa:");
			printf("\n1)eroare la executie");
			printf("\n2)10");
			printf("\n3)20\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 69:
			printf("\nPt situatia urmatoare\ntypedef enum{masa, casa, curte,caine,pom,pisica}domestic;\ndomestic d;\ncare este intregul asociat elementului ”caine”?");
			printf("\n1)5");
			printf("\n2)4");
			printf("\n3)3\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 70:
			printf("\nCare dintre urmatoarele variante exprima corect definitia unei functii:");
			printf("\n1)int funct();");
			printf("\n2)void funct(int){printf(”Hello”);");
			printf("\n3)int funct(int x){return x=x+1;}\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 71:
			printf("\nSecventa:\nchar s[]=”Bubu”;\n*s=<c>;\nprintf(”%%s, s);\nva afisa:");
			printf("\n1)Bubu");
			printf("\n2)Eroare de compilare");
			printf("\n3)Cubu\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 72:
			printf("\nPrecizati ce va afisa secventa\nint multime[]={1,12,0x01};\nint *ptr;\nptr=multime+2;\nprintf(”%%c”, *ptr);");
			printf("\n1)61");
			printf("\n2)0x61");
			printf("\n3)Simbolul corespunzator codului ASCII cu valoara 97(”a”)\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 73:
			printf("\nCare va fi noua valoare a variabilei x(in baza 10) dupa aplicarea operatorului de deplasare la stanga in urmatoarea secventa de cod?\nint x=255;\nx=x<<2;");
			printf("\n1)1020");
			printf("\n2)253");
			printf("\n3)1024\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 74:
			printf("\nSpatiul de memorie alocat dinamic se afla");
			printf("\n1)in stiva/stack");
			printf("\n2)in heap");
			printf("\n3)in memoria auxiliara\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 75:
			printf("\nPentru\nint n=10,m=4;\nfloat x;\nvaloarea expresiei x=1.5 + n/m este:");
			printf("\n1)4.0");
			printf("\n2)3.5");
			printf("\n3)eroare\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 76:
			printf("\nSecventa\nstruct film{\nchar titlu[50];\nint an;}");
			printf("\n1)defineste o variabila de tip structura");
			printf("\n2)este gresita");
			printf("\n3)defineste un tip de structura\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 77:
			printf("\nCe va afisa urmatorul prograam\n#include <stdio.h>\nint main()\n{int rezultat, a=3;\nfloat b=6;\nrezultat=b %%a;\nprintf(”%%d”, rezultat);\nreturn 0;\n}");
			printf("\n1)1");
			printf("\n2)0");
			printf("\n3)eroare de compilare \n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 78:
			printf("\nCare din urmatorii operatori este operatorul logic NOT?");
			printf("\n1)&");
			printf("\n2)!");
			printf("\n3)|\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 79:
			printf("\nCe tip de variabile nu accepta instuctiunea switch?");
			printf("\n1)char");
			printf("\n2)int");
			printf("\n3)float\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 80:
			printf("\nCe va afisa urmatorul cod sursa?\n#include <stdio.h>\nint main()\n{int x=1;\ndo\n\tprintf(”%%d”, x);\nwhile(x+1<=1);\nreturn 0;\n}");
			printf("\n1)1");
			printf("\n2)1 2");
			printf("\n3)Eroare de executie\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 81:
			printf("\nCare va fi valoarea variabilei a dupa atribuirile din urmatoarea secventa de cod:\nint a=3,b=5,*p;\np=&b;\na=*p;");
			printf("\n1)5");
			printf("\n2)4");
			printf("\n3)3\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 82:
			printf("\nSecventa de program\n...int i=0;\nswitch(i)\n{case '0':printf(”PC”);\n\tbreak;\ncase '1':printf(”LSD”);\n\tbreak;\ndefault:printf(”vacanta”);\n};\nare rezultatul");
			printf("\n1)vacanta");
			printf("\n2)PC");
			printf("\n3)PCLSD\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 83:
			printf("\nAlegeti secventa corecta de program in C care are ca rezultat suma\n elementelor unui tablou de numere intregi <tab> care contine 15 elemente\nsuma = 0;");
			printf("\n1)for(i=0;i<=15;i++)suma = suma + tab[i];");
			printf("\n2)for(i==0;i<15;i++)suma = suma + tab[i];");
			printf("\n3)for(i=0;i<15;i++)suma = suma + tab[i];\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 84:
			printf("\nCare este rezultatul secventei:\n...int a[]={18,28,38};\nprintf(” %%d”, *a+1);");
			printf("\n1)18");
			printf("\n2)19");
			printf("\n3)28\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 85:
			printf("\nSecventa\nconst int a=5;\na++;\nprintf(”%%d”, a);\nafiseaza:");
			printf("\n1)5");
			printf("\n2)6");
			printf("\n3)eroare de compilare\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 86:
			printf("\nCe este gresit in urmatoarea secventa:\nchar *sirp;\nstrcpy(sirp, ”Ianuarie”);");
			printf("\n1)Secventa este corecta");
			printf("\n2)Pointerul sirp nu este initializat");
			printf("\n3)Nu se poate copia un sir de caractere intr-un pointer\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 87:
			printf("\nCare este rezultatul secventei de mai jos:\nint main();\n{int i;\nfor(i=0;i<=255;i++)printf(” %%c %%d”, i, i);\nreturn 0;\n}");
			printf("\n1)2 randuri de valori intregi de la 0 la 255");
			printf("\n2)codurile ASCII si val intreaga coresp de la 0 la 255");
			printf("\n3)codurile ASCII si val intreaga coresp pt litere mari, mici si cifre)\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 88:
			printf("\nEste posibil ca o functie in c sa modifice o variabila in fct pe care a apelat-o?");
			printf("\n1)Dc in apelul functiei se foloseste asociat cu parametrul resp operatorul ””");
			printf("\n2)nu");
			printf("\n3)dc in apelul fct se foloseste asociat cu parametrul resp operatorul &\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 89:
			printf("\nLimbajul masina");
			printf("\n1)este un limbaj de nivel inalt");
			printf("\n2)depinde de tipul microprocesorului");
			printf("\n3)este utilizat si epntru a scrie programe sursa\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 90:
			printf("\nConsiderand declaratia:\nchar sir[10];\natribuirea\nsir = ”exemplu” este");
			printf("\n1)executata doar in standardul ANSII");
			printf("\n2)incorecta");
			printf("\n3)corecta\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 91:
			printf("\nInstructiunea WHILE este:");
			printf("\n1)cu test final");
			printf("\n2)cu test initial");
			printf("\n3)fara test\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 92:
			printf("\nPt secventa\nint i, j;\nfloat(i/j);");
			printf("\n1)va utiliza impartie in intreg");
			printf("\n2)va forta impartirea in real");
			printf("\n3)va utiliza impartirea in intreg si apoi va face conversia in float\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 93:
			printf("\nUn calculator de proces");
			printf("\n1)este folosit pt a defini un proces electronic");
			printf("\n2)furnizeaza o marime de control spre un proces electronic, economic...");
			printf("\n3)descrie un proces tehnologic\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 94:
			printf("\nParametri efectivi sunt:");
			printf("\n1)valori curente ale variabilelor utilizate la fct");
			printf("\n2)valori care apar in declaratia unei fct");
			printf("\n3)variabile locale ale fct\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 95:
			printf("\nCorespondentul hexazecimalului al lui 109 zecimal este");
			printf("\n1)0x6D");
			printf("\n2)0x613");
			printf("\n3)0xA9\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 96:
			printf("\nTipul <unsigned char> se reprezinta pe:");
			printf("\n1)1 octet, cu semn");
			printf("\n2)1 octet, fara semn");
			printf("\n3)2 octet, fara semn\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 97:
			printf("\nPt a inmulti un nr cu 4 se poate folosi operatia de deplasare");
			printf("\n1)cu 2 poz la stanga");
			printf("\n2)cu o poz la stanga");
			printf("\n3)cu 2 poz la dreapta\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 98:
			printf("\nFgetpos are ca efect");
			printf("\n1)setarea pointerului fisier asociat cu fluxul curent la o noua pozitie");
			printf("\n2)setarea poz pointerului fisier asociata cu fluxul curent");
			printf("\n3)memorarea locatiei pointerului fisier asociata cu fluxul curent\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 99:
			printf("\nInternetul este");
			printf("\n1)o colectie de informatii");
			printf("\n2)un serviciu");
			printf("\n3)o infrastructura fizica\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 100:
			printf("\nCompilatorul este");
			printf("\n1)un program care traduce programele surs in pr obiect");
			printf("\n2)un echipament de calcul");
			printf("\n3)un program care traduce programele obiect in prog sursa\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 101:
			printf("\nTipuri de memorie interna");
			printf("\n1)ROM, RAM");
			printf("\n2)CD-ROM, ROM");
			printf("\n3)Hard-Disk si ROM\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 102:
			printf("\nCare dintre urmatorii operatori are cea mai mare prioritate");
			printf("\n1)=");
			printf("\n2)+");
			printf("\n3)/\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 103:
			printf("\nCare dintre urmatorii operatori are cea mai mica prioritate");
			printf("\n1)=");
			printf("\n2)+");
			printf("\n3)/\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 104:
			printf("\nPrecizati ce reprezinta int(*)(int a, float b)");
			printf("\n1)reprezinta o fct care retine un pointer catre un intreg");
			printf("\n2)reprezinta un pointer catre o fct ce retine un intreg");
			printf("\n3)incorect\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 105:
			printf("\nPt a face interschimbarea a 2 var de acelasi tip fara a folosi o a treiea variabila, afisarea corecta este:");
			printf("\n1)a=a*b;b=a*b;a=b/a");
			printf("\n2)a=a*b;b=a/b;a=a/b;");
			printf("\n3)b=a*b;a=a/b;b=a*b;\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 106:
			printf("\nBIOS este");
			printf("\n1)un echipament");
			printf("\n2)un program aflat in memoria RAM");
			printf("\n3)un program aflat in memoria ROM\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 107:
			printf("\nPt secventa de program\ntypdef struct\n{int r, im;}ax;\nax c;\ncare este variabila corecta pentru citire?");
			printf("\n1)scanf(”%%d”, &c);");
			printf("\n2)nu se poate efectua citirea");
			printf("\n3)scanf(” %%d %%d, &c.re, &c.in);\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 108:
			printf("\nTipurile caracterizate prin intervalul <int> se reprez in memorie prin");
			printf("\n1)2 octeti, cu semn");
			printf("\n2)1 octet, fara semn");
			printf("\n3)2 octet, fara semn\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 109:
			printf("\nProgramul:\nint main()\n{char string[10];\nchar *str1=”abcdefghi”;\ncrlscr();\nstrncpy(string, str1, 3);\nstring[3]=<*backslah*0>;\nprintf(” %%s”, string);\nreturn 0;}\nafiseaza pe ecran");
			printf("\n1)def");
			printf("\n2)abcdefghi");
			printf("\n3)abc\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 110:
			printf("\nCare din urmatoarele structuri are sinteza corecta?");
			printf("\n1)examen, *examene, examen");
			printf("\n2)examen,m examen[examen]");
			printf("\n3)examen, examen, exAmen\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 111:
			printf("\n-0.00000021 se reprezinta ca");
			printf("\n1)-2.1E7");
			printf("\n2)-2.1E10-7");
			printf("\n3)-2.1E-7\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 112:
			printf("\nPt secventa de program ce efect se obtine?\nchar c[20]=””;\nFILE *f;\nf = fopen(”test.bin”, ”rb”);\nfseek(f, -2, SEEK_END);\nfread(c, 2, 1, f);\nfclose();");
			printf("\n1)citeste primii 2 octeti din fisier");
			printf("\n2)citeste ultimii 2 octeti din fisier");
			printf("\n3)citeste ultimii 20 octeti din fisier\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 113:
			printf("\nDezalocarea memoriei ocupate de variabilele alocate dinamic trebuie facuta, in limbajul C:");
			printf("\n1)explicit, de catre programator");
			printf("\n2)explicit sau implicit(de catre mediul de programare)1");
			printf("\n3)explicit, de catre utilizator\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 114:
			printf("\nUn broswer este:");
			printf("\n1)un motor de cautare");
			printf("\n2)un program care permite gasirea si vizualizareaa informatiei");
			printf("\n3)un document multimedia\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 115:
			printf("\nTipuri de memorie externa");
			printf("\n1)discuri flexibile, cadre");
			printf("\n2)memoria RAM, Hard-disk-ul");
			printf("\n3)CD-ROM, Hard-Disk\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 116:
			printf("\nLa retelele de tip stea comunicarea intre 2 noduri se fac");
			printf("\n1)prin intermediul nodului central");
			printf("\n2)nodul din partea dreapta comunica cu cel din partea stanga");
			printf("\n3)nodul din partea stanga comunica cu celelalte\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 117:
			printf("\n Ce valoare zecimala are 0x3D");
			printf("\n1)16");
			printf("\n2)39");
			printf("\n3)61\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 118:
			printf("\nTipul int este definit pe urmatorul domeniu de valori");
			printf("\n1)-255 255");
			printf("\n2)-256 256");
			printf("\n3)-32768 32767\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 119:
			printf("\nTipului real i se pot aplica operatiile care au rezultat real");
			printf("\n1)<, <=, >, =>");
			printf("\n2)abs(x), pow(x), sqrt(x)");
			printf("\n3)eof, eol\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 120:
			printf("\nIn urma executiei programului urmator:\nint main()\n{char *str1=”inginerie”, *str2 = ”ner”, *ptr;\nptr = strstr(str1, str2);\nprintf(”rezultatul este %%s>, ptr);\n}\nse va afisa");
			printf("\n1)5");
			printf("\n2)nerie");
			printf("\n3)ner\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 121:
			printf("\nCe afiseaza urmatoarea secventa de program:\nint x=16;\nprintf(”%%x”, x);");
			printf("\n1)16");
			printf("\n2)10");
			printf("\n3)x\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 122:
			printf("\nRezultatul operatiei a/(float)b cu a si b de tip intreg este:");
			printf("\n1)float");
			printf("\n2)int");
			printf("\n3)double\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 123:
			printf("\nPt a imparti un nr cu 2 se poate folosi operatia de deplasare");
			printf("\n1)cu o poz spre stanga");
			printf("\n2)cu o poz spre dreapta");
			printf("\n3)cu 2 poz spre stanga\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 124:
			printf("\nAlegeti varianta corecta relativ la secventa urmatoare\nchar c;\nchar *const cp = sc;");
			printf("\n1)cp nu trebuie modificat, desi entiatea pe care o indica poate fi modificata");
			printf("\n2)cp poate fi modificat, la fel si entitatea pe care o indica");
			printf("\n3)cp poate fi modificat, dar entitatea pe care o indica nu poate fi modificata\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 125:
			printf("\nPrecizati ce va afisa secventa de mai jos:\nint (*fct)(int a, int b);\nint suma(int a, int b){return a+b;}\nint diferenta(int a, int b){return a-b;}\nint main()\n{int a=12, b=9;\nif(a&b)fct =suma;\nelse fct=diferenta;\nprintf(”%%d”, (*fct)(a, b));\n return 0;\n}");
			printf("\n1)9");
			printf("\n2)15");
			printf("\n3)secventa e gresita\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 126:
			printf("\nModul test considera ecranul");
			printf("\n1)la fct ca si modul grafic");
			printf("\n2)format din pozitii caracter");
			printf("\n3)ca un patrat\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 127:
			printf("\nUn tip in programare reprezinta");
			printf("\n1)o multime de valori careia i se poate atasa un nume");
			printf("\n2)o multime de variabile");
			printf("\n3)un subdomeniu\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 128:
			printf("\nCorespondentul hexazecimal al lui 73 zecimal este");
			printf("\n1)0x10");
			printf("\n2)0x49");
			printf("\n3)0x2A\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 129:
			printf("\nIndicati ce reprezinta expresia\nint *funct(int a, float b);");
			printf("\n1)reprezinta o functie care relationeaza un pointer catre un intreg");
			printf("\n2)reprezinta un pointer catre o fct care rel cu un intreg");
			printf("\n3)reprezinta o declaratie incorecta\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 130:
			printf("\nCare dintre urmatoarele instructiuni sunt iterative");
			printf("\n1)<while> si <do-while>");
			printf("\n2)<case> si <do-while>");
			printf("\n3)<;f> si <while>\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 131:
			printf("\nIn urma executiei secventei de mai jos se vor afisa\nint main()\n{int tab[3][3]={1,2,3,4,5,6,7,8,9};\nint i, j;\nfor(i=0;i<3-1;i++)\n\tfor(j=0;j<3-1-i;j++)\n\t\tprintf(”%%d”, tab[i][j]);\nreturn 0;\n}");
			printf("\n1)el de pe DS");
			printf("\n2)el de deasupra DS");
			printf("\n3)el de deasupra DP\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 132:
			printf("\nIn urma executiei secventei de mai jos se vor afisa\nint main()\n{int tab[3][3]={1,2,3,4,5,6,7,8,9};\nint i, j;\nfor(i=0;i<3;i++)\n\tfor(j=0;j<=i;j++)\n\t\tprintf(”%%d”, tab[i][j]);\nreturn 0;\n}");
			printf("\n1)el de pe DS");
			printf("\n2)el de pe DP");
			printf("\n3)el de pe si de sub DP\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 133:
			printf("\nCe afiseaza uurmatoarea secventa pt variabila\n#include <stdio.h>\nint main()\n{int var=77;\nprintf(”Variabila var este %%c”, var);\n}");
			printf("\n1)un intreg zecimal");
			printf("\n2)un caracter ASCII");
			printf("\n3)un sir de caractere\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 134:
			printf("\nCe va returna urmatorul program dupa executie?\nint main()\n{int i;\nfor(i=0;i<20,i++)\n{if(i %%2==0)\n\tcontinue;\n\tprintf(”%%d”, i);\n}\nreturn 0;\n}");
			printf("\n1)2 4 6 8 10 12 14 16 18 20");
			printf("\n2)1 3 5 7 9 11 13 15 17 19");
			printf("\n3)2 4 6 8 10 12 14 16 18\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 135:
			printf("\nCe valoare are variabila n?\nint m=524;int n = m++ %%20;");
			printf("\n1)10");
			printf("\n2)4");
			printf("\n3)2\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 136:
			printf("\nCe valoare are variabila c?\nchar c = (3<<5)/32-2+<a>;");
			printf("\n1)b");
			printf("\n2)a");
			printf("\n3)z\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 137:
			printf("\nIn secventa int *const cpi=&i\ncpi este:");
			printf("\n1)un pointer catre un intreg");
			printf("\n2)un pointer constant catre un intreg");
			printf("\n3)un pointer catre o constanta intreaga\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 138:
			printf("\nProgramul\n#include <stdio.h>\nint main()\n{\nchar **ptr=NULL;\nchar *p=NULL;\nchar c=<d>;\np=&c;\nptr=&p;\nprintf(”c=[%%c]”, c);\nprintf(”*p=[%%c]”, *p);\nprintf(”**ptr[%%c]”, **ptr);\nreturn 0;}\nare ca efect");
			printf("\n1)c=[d] *p=0x002bfe0b **p=0x002bfe14");
			printf("\n2)c=[d] *p=[d] **p=0x002bfe17");
			printf("\n3)c=[d] *p=[d] **p=[d]\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 139:
			printf("\nCe valoare va avea variabila p in urmatorul rand de cod\np = strstr(s1, s2);\ndaca s1 si s2 sunt 2 siruri citite de la tastatura");
			printf("\n1)un pointer de tip char care dc este nenul, s1 contine s2");
			printf("\n2)un pointer de tip intreg care dc este nenul, s1 contine s2");
			printf("\n3)un pointer de tip char care dc este nenul, s2 contine s1\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 140:
			printf("\nProgramul\nint main()\n{char string[10];\nchar *str1=”marsupial”;\nstrcpy(string, str1, 4);\nstring[4]=< backslash 0>;\nprintf(” %%s”, string);\nreturn 0;\n}\nafiseaza pe ecran");
			printf("\n1)marsupial");
			printf("\n2)mar");
			printf("\n3)mars\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 141:
			printf("\nParametrii formali sunt:");
			printf("\n1)care apar in declaratia unei fct");
			printf("\n2)care apar in apelul unei fct");
			printf("\n3)care se transmit in afara fct\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 142:
			printf("\nCare este rezultatul urmatorului program?\ntest(char *x, char y)\n{*x=y; y=<1>; printf(” %%c %%c”, x, y);}\nint main()\n{char m = <2>;\nchar n = <3>;\ntest(&m, n);\nprintf(”%%c %%c”, m, n);}");
			printf("\n1)3313");
			printf("\n2)3131");
			printf("\n3)3133\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 143:
			printf("\nCare este rezultatul programului urmator\nint main()\n{int rez1, rez2;\nint(*pFunc)(int, int);\npFunc = func;\nrez1=(*pFunc)(10, 20);\nrez2=pFunc(10, 20);\nprintf(”Rezultat 1=%%d Rezultat 2=%%d”, rez1, rez2);\nreturn 0;\n}\nint func(int x, int y){return x-y;}");
			printf("\n1)Rezultat 1=-10 Rezultat 2=-10");
			printf("\n2)Rezultat 1=-10 Rezultat 2=-20");
			printf("\n3)Eroare de compilare\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 144:
			printf("\nCe valoare zecimala are 0xAF");
			printf("\n1)175");
			printf("\n2)150");
			printf("\n3)25\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 145:
			printf("\nSecventa:\nchar ch=<c>;\nconst char *ptr=&ch;*ptr=<a>;\neste:");
			printf("\n1)corecta");
			printf("\n2)eronata pt ca se modifica un pointer constant");
			printf("\n3)eronata pt ca se modifica o val constanta\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 146:
			printf("\nIn urma executiei programului urmator:\nint main()\n{char *str1=”calambur”;\n*str2 = ”amb”, *ptr;\nptr = strstr(str1, str2);\nprintf(”Rezulatul este: %%s”, ptr);\nreturn 0;\n}\nse va afisa");
			printf("\n1)5");
			printf("\n2)amb");
			printf("\n3)ambur\n");
			scanf("%d", &var);
			if (var == 3)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 147:
			printf("\nCe afiseaza urmatoarea secventa de program?\nint m = 322;\nint n = m++ %%10;");
			printf("\n1)3");
			printf("\n2)2");
			printf("\n3)22\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 148:
			printf("\nAlegeti varianta corecta relativ la declaratia urmatoare\nfloat(*q)[];");
			printf("\n1)un tablou de pointeri catre variabile reale");
			printf("\n2)un pointer catre un tablou de variabile reale");
			printf("\n3)este eronata\n");
			scanf("%d", &var);
			if (var == 2)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		case 149:
			printf("\nstruct individ\n{char *nume;\nint varsta;\nfloat inaltime;\n}\ndefineste:");
			printf("\n1)un tip de structura");
			printf("\n2)o variabila de tip structura");
			printf("\n3)nimic\n");
			scanf("%d", &var);
			if (var == 1)
			{
				printf("Corect");
				corect++;
			}
			else
			{
				printf("Incorect");
				gresit++;
			}
			printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
			break;
		}
	}
	printf(" %d : %d (%d) \n", corect, gresit, total + 1 - start);
}