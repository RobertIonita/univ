#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char cheie;
    struct Node *dreapta;
    struct Node *stanga;
    int inaltime;
};

int maxim(int a, int b)
{
    return a > b ? a : b;
}

int inaltime(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->inaltime;
}

struct Node *newNode(char cheie)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->cheie = cheie;
    n->dreapta = NULL;
    n->stanga = NULL;
    n->inaltime;

    return n;
}

struct Node *rotireDreapta(struct Node *y)
{
    struct Node *x = y->stanga;
    struct Node *t2 = x->dreapta;

    x->dreapta = y;
    y->stanga = t2;

    x->inaltime = 1 + maxim(inaltime(x->dreapta), inaltime(x->stanga));
    y->inaltime = 1 + maxim(inaltime(y->dreapta), inaltime(y->stanga));

    return x;
}

struct Node *rotireStanga(struct Node *x)
{
    struct Node *y = x->dreapta;
    struct Node *t2 = y->stanga;

    y->stanga = x;
    x->dreapta = t2;

    x->inaltime = 1 + maxim(inaltime(x->dreapta), inaltime(x->stanga));
    y->inaltime = 1 + maxim(inaltime(y->dreapta), inaltime(y->stanga));

    return y;
}

int getbalanta(struct Node *n)
{
    if (n == NULL)
        return 0;
    return inaltime(n->stanga) - inaltime(n->dreapta);
}

struct Node *inserare(struct Node *n, char cheie)
{
    if (n == NULL)
        return newNode(cheie);
    if (cheie < n->cheie)
        n->stanga = inserare(n->stanga, cheie);
    else if (cheie > n->cheie)
        n->dreapta = inserare(n->dreapta, cheie);
    else
        return n;

    n->inaltime = 1 + maxim(inaltime(n->dreapta), inaltime(n->stanga));
    int balanta = getbalanta(n);

    if (balanta > 1 && cheie < n->stanga->cheie)
        return rotireDreapta(n);
    if (balanta < -1 && cheie > n->dreapta->cheie)
        return rotireStanga(n);

    if (balanta > 1 && cheie > n->stanga->cheie)
    {
        n->stanga = rotireStanga(n->stanga);
        return rotireDreapta(n);
    }
    if (balanta < -1 && cheie < n->dreapta->cheie)
    {
        n->dreapta = rotireDreapta(n->dreapta);
        return rotireStanga(n);
    }

    return n;
}

void preordine(struct Node *n)
{
    if (n != NULL)
    {
        printf("%c ", n->cheie);
        preordine(n->stanga);
        preordine(n->dreapta);
    }
}

int cautare(struct Node *n, char cheie)
{
    int ok = 0;
    if (n != NULL)
    {
        if (cheie == n->cheie)
        {
            ok = 1;
            return 1;
        }
        if (ok == 1)
        {
            printf("Element gasit. 🙂 \n");
        }
        else
            printf("Element inexistent. \n");
        preordine(n->stanga);
        preordine(n->dreapta);
    }
}

void inordine(struct Node *n)
{
    if (n != NULL)
    {
        inordine(n->stanga);
        printf("%c ", n->cheie);
        inordine(n->dreapta);
    }
}

struct Node *predecesor(struct Node *crt)
{
    if (crt == NULL)
        return 0;
    if (crt->stanga == NULL)
        return crt->stanga;
    crt = crt->stanga;
    while (crt != NULL)
    {
        if (crt->dreapta == NULL)
            return crt->dreapta;
        crt = crt->dreapta;
    }
}

struct Node *sterge(struct Node *n, char cheie)
{
    if (n == NULL)
    {
        printf("Arbore vid.\n");
        return n;
    }
    if (cheie < n->cheie)
        n->stanga = sterge(n->stanga, cheie);
    else if (cheie > n->cheie)
        n->dreapta = sterge(n->dreapta, cheie);
    else
    {
        if ((n->stanga == NULL) || (n->dreapta == NULL))
        {
            struct Node *aux = n->stanga ? n->stanga : n->dreapta;
            if (aux == NULL)
            {
                aux = n;
                n = NULL;
            }
            else
                *n = *aux;
            free(aux);
        }
        else
        {
            struct Node *aux = predecesor(n->dreapta);
            n->cheie = aux->cheie;
            n->dreapta = sterge(n->dreapta, aux->cheie);
        }
    }

    n->inaltime = 1 + maxim(inaltime(n->dreapta), inaltime(n->stanga));
    int balanta = getbalanta(n);

    if (balanta < -1 && getbalanta(n->dreapta) > 0)
    {
        n->dreapta = rotireDreapta(n->dreapta);
        return rotireStanga(n);
    }
    if (n == NULL)
    {
        printf("Arborele este vid.\n");
        return n;
    }
    return n;
}

int main()
{
    int opt;
    char cheie;
    struct Node *root = NULL;
    struct Node *crt = NULL;
    struct Node *parinte = NULL;
    do
    {
        printf("\n\n1. adauga\n");
        printf("2. sterge\n");
        printf("3. afiseaza\n");
        printf("optiiune: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 0:
            printf("\nGoodbye");
            return 0;
            break;
        case 1:
            printf("Cheie: ");
            scanf(" %c", &cheie);
            root = inserare(root, cheie);
            break;
        case 2:
            printf("Cheie: ");
            scanf(" %c", &cheie);
            root = sterge(root, cheie);
            break;
        case 3:
            printf("\ninordine:\n");
            inordine(root);
            printf("\npreordine:\n");
            preordine(root);
            break;
        default:
            printf("ls\n");
            break;
        }
    } while (opt != 0);
    return 0;
}