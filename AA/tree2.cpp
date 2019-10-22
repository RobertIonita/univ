#include <iostream>
using namespace std;
#define MAX 20

void showOff(int keys[], int parents[], int n);
void preorder(int keys[], int parents[], int key, int n);
void inorder(int keys[], int parents[], int key, int n);
void postorder(int keys[], int parents[], int key, int n);
void insert(int (*keys)[MAX], int (*parents)[MAX], int *n);
int getLeftChild(int keys[], int parents[], int key, int n);
int getRightChild(int keys[], int parents[], int key, int n);
void searchParentOf(int keys[], int parents[], int n);
void searchRightSibling(int keys[], int parents[], int n);
void deleteNode(int (*keys)[MAX], int (*parents)[MAX], int *n);
int main()
{

    int keys[MAX],
        parents[MAX],
        n = 0, key;
    unsigned short int option;
    while (1)
    {
        cout << "\n0. Exit";
        cout << "\n1. Insert a node";
        cout << "\n2. Display as it is";
        cout << "\n3. Display preorder";
        cout << "\n4. Display inorder";
        cout << "\n5. Display postorder";
        cout << "\n6. Get parent of";
        cout << "\n7. Get right sibling";
        cout << "\n8. Delete a node";
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
            preorder(keys, parents, keys[0], n);
            break;
        case 4:
            inorder(keys, parents, keys[0], n);
            break;
        case 5:
            postorder(keys, parents, keys[0], n);
            break;
        case 6:
            searchParentOf(keys, parents, n);
            break;
        case 7:
            searchRightSibling(keys, parents, n);
            break;
        case 8:
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
        printf("key: %d, parent: %d\n", keys[i], parents[i]);
}

void preorder(int keys[], int parents[], int key, int n)
{
    if (key != -1) {
        cout << key << " ";
        preorder(keys, parents, getLeftChild(keys, parents, key, n), n);
        preorder(keys, parents, getRightChild(keys, parents, key, n), n);
    }
}
void inorder(int keys[], int parents[], int key, int n)
{
    if (key != -1) {
        inorder(keys, parents, getLeftChild(keys, parents, key, n), n);
        cout << key << " ";
        inorder(keys, parents, getRightChild(keys, parents, key, n), n);
    }
}
void postorder(int keys[], int parents[], int key, int n)
{
    if (key != -1) {
        postorder(keys, parents, getLeftChild(keys, parents, key, n), n);
        postorder(keys, parents, getRightChild(keys, parents, key, n), n);
        cout << key << " ";
    }
}

void insert(int (*keys)[MAX], int (*parents)[MAX], int *n)
{
    int key, node, unique = 1;
    cout << "Node key: ";
    cin >> key;
    int i = 0,
        kid = 0;
    if (*n <= 0)
    {
        (*parents)[*n] = -1;
        (*keys)[(*n)++] = key;
    }
    else
    {
        node = (*keys)[0];
        while (kid != -1)
        {
            if (node > key)
            {
                kid = getLeftChild((*keys), (*parents), node, *n);
                kid != -1 ? node = kid : 0;
            }
            else if (node < key)
            {
                kid = getRightChild((*keys), (*parents), node, *n);
                kid != -1 ? node = kid : 0;
            }
            else
            {
                cout << "This node already exists";
                unique = 0;
                break;
            }
        }
        if (unique)
        {
            (*parents)[*n] = node;
            (*keys)[(*n)++] = key;
        }
    }
}
int getLeftChild(int keys[], int parents[], int key, int n)
{
    int kid = -1;
    for (size_t i = 0; i < n; i++)
        if (parents[i] == key)
        {
            kid = keys[i];
            return kid;
        }
    return -1;
}
int getRightChild(int keys[], int parents[], int key, int n)
{
    int kid = -1;
    for (size_t i = n - 1; i > 0; i--)
        if (parents[i] == key && parents[i - 1] == key)
            kid = keys[i];
    return kid;
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
    
}
