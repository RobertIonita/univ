#include <iostream>
using namespace std;
#define MAX 20

void showOff(int keys[],int parents[], int n);
void insert(int (*keys)[], int (*parents)[], int *n);

int main()
{

    int keys[] = {2, 4},
        parents[] = {2, 4},
        n = sizeof(keys)/sizeof(int);
    unsigned short int option;
    while(1)
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
            cout << "\nexecution terminated";
            return 0;
            break;
        case 1:
            // insert(keys, &parents, &n);
            break;
        case 2:
            showOff(keys, parents, n);
            break;
        default:
            cout << "\nInvalid option";
            break;
        }
    }
}
void showOff(int keys[],int parents[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("key: %d, parent: %d\n", keys[i], parents[i]);
    }
}
void insert(int (*keys)[],int (*parents)[], int *n){
    cout << "Node key: ";
    cin >> (*keys)[*n];
    cout << (*keys)[*n];
}