#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void showOff(int keys[], int n);
void insert(int (*keys)[MAX], int *n);
void sort(int(arr)[], int n);
void normailize(int (*arr)[MAX], int token[], int left, int right, int *k);
void searchParentOf(int keys[], int n);
void searchRightSibling(int keys[], int n);
void deleteNode(int (*keys)[MAX], int *n);
int main()
{

    int keys[MAX] = {1, 2, 3, 4, 5, 6},
        n = 6;
    unsigned short int option = 1;
    while (1)
    {
        printf("\n0. Exit");
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Get parent of");
        printf("\n4. Get right sibling");
        printf("\n5. Delete");
        printf("\nOption: ");
        scanf("%hd", &option);
        switch (option)
        {
        case 0:
            printf("\nExecution terminated");
            return 0;
            break;
        case 1:
            insert(&keys, &n);
            break;
        case 2:
            showOff(keys, n);
            break;
        case 3:
            searchParentOf(keys, n);
            break;
        case 4:
            searchRightSibling(keys, n);
            break;
        case 5:
            deleteNode(&keys, &n);
        default:
            printf("\nInvalid option");
            break;
        }
    }
}
void showOff(int keys[], int n)
{
    for (int i = 0; i < n; i++)
        printf("key: %d, parent: x\n", keys[i]);
}
void insert(int (*keys)[MAX], int *n)
{
    int k = 0,
        clone[MAX];
    printf("Node key: ");
    scanf("%d", &(*keys)[*n]);
    sort((*keys), *n);

    for (size_t i = 0; i < *n; i++)
        clone[i] = (*keys)[i];
    normailize(&(*keys), clone, 0, *n, &k);
    (*n)++;
}

void sort(int(arr)[], int n)
{
    for (size_t gap = n / 2; gap > 0; gap /= 2)
    {
        for (size_t i = gap; i < n; i++)
        {
            int temp = arr[i],
                j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void normailize(int (*arr)[MAX], int token[], int left, int right, int *k)
{
    (*arr)[(*k)] = token[(right + left) / 2];
    (*k)++;

    if (*k <= right) {
        normailize(&(*arr), token, 0, ((right - left) / 2) - 1, k);
        normailize(&(*arr), token, ((right + left) / 2), right, k);
    }
}

void searchParentOf(int keys[], int n)
{
    unsigned short int
        key,
        i;
    printf("Insert a key: ");
    scanf("%hd", &key);
    for (i = 0; i < n && keys[i] != key; i++)
        ;
    if (i == n)
    {
        printf("\nkey: \'%hu\' doesn't exists", key);
    }
    else
    {
        printf("\nindex: %hu", i);
    }
}
void searchRightSibling(int keys[], int n)
{
    unsigned short int key;
    printf("Insert a key: ");
    scanf("%hd", &key);
}

void deleteNode(int (*keys)[MAX], int *n)
{
    int key, i, k, p = -1;
    printf("Node to be deleted: ");
    scanf("%d", &key);
    for (size_t i = 0; i < *n; i++)
        if ((*keys)[i] == key)
            for (size_t j = i; j < *n - 1; j++)
                (*keys)[j] = (*keys)[j + 1];
    (*n)--;
}