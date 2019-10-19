#include <iostream>
using namespace std;
#define MAX 20

void showOff(int keys[], int parents[], int n);
void insert(int (*keys)[MAX], int (*parents)[MAX], int *n);
void searchParentOf(int keys[], int parents[], int n);
void searchRightSibling(int keys[], int parents[], int n);
void deleteNode(int (*keys)[MAX], int (*parents)[MAX], int *n);
int main()
{

    int keys[MAX],
        parents[MAX],
        n = 0;
    unsigned short int option;
    while (1)
    {
        cout << "\n0. Exit";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Get parent of";
        cout << "\n4. Get right sibling";
        cout << "\n5. Delete";
        cout << "\nOption: ";
        cin >> option;
        switch (option)
        {
        case 0:
            cout << "\nExecution terminated";
            return 0;
            break;
        case 1:
            insert(&keys, &parents, &n);
            break;
        case 2:
            showOff(keys, parents, n);
            break;
        case 3:
            searchParentOf(keys, parents, n);
            break;
        case 4:
            searchRightSibling(keys, parents, n);
            break;
        case 5:
            deleteNode(&keys, &parents, &n);
            break;
        default:
            cout << "\nInvalid option";
            break;
        }
    }
}
void showOff(int keys[], int parents[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("key: %d, parent: %d\n", keys[i], parents[i]);
    }
}
void insert(int (*keys)[MAX], int (*parents)[MAX], int *n)
{
    cout << "Node key: ";
    cin >> (*keys)[*n];
    (*parents)[*n] = (*n) > 0 ? (*keys)[((*n + 1) / 2) - 1] : -1;
    (*n)++;
}
void searchParentOf(int keys[], int parents[], int n)
{
    unsigned short int key;
    cout << "Insert a key: ";
    cin >> key;
    for (size_t i = 0; i < n; i++)
        if (keys[i] == key)
        {
            cout << "Parent key is: " << parents[i];
            break;
        }
}
void searchRightSibling(int keys[], int parents[], int n)
{
    unsigned short int key;
    cout << "Insert a key: ";
    cin >> key;
    for (size_t i = 0; i < n; i++)
        if (keys[i] == key)
        {
            if (parents[i] == parents[i + 1])
                cout << "Sibling key is: " << keys[i + 1];
            else
                cout << "This node does not have a right sibling";
            break;
        }
}

void deleteNode(int (*keys)[MAX], int (*parents)[MAX], int *n)
{
    int key, i, k, p = -1;
    cout << "Node to be deleted: ";
    cin >> key;
    if ((*keys)[0] == key)
    {
        for (i = 0; i < *n - 1; i++) //1 4 1 5 1 6 1 3 1 7 1 8
        {
            (*keys)[i] = (*keys)[i + 1];
            (*parents)[i] = (*parents)[i + 1];
        }
        (*parents)[0] = (*keys)[1];
        (*parents)[1] = -1;
    }
    else
    {
        for (i = 0; i <= *n && (*keys)[i] != key; i++)
            ;
        p = (*parents)[i];
        k = i;
        for (i = 0; i <= *n; i++)
            if ((*parents)[i] == key)
                (*parents)[i] = p;
        for (i = k; i < *n; i++)
        {
            (*keys)[i] = (*keys)[i + 1];
            (*parents)[i] = (*parents)[i + 1];
        }
    }
    (*n)--;
}