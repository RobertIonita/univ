#include <iostream>
#include <stdlib.h>
using namespace std;

void menu();
int *insertNode(int **mat, int *arr, int *len, int nr);
int **insertEdge(int **mat, int *arr, int len);

int main()
{
    int option = !0,
        len = 0, nr,
        **matrix, *arr;
    while (option)
    {
        menu();
        cin >> option;
        switch (option)
        {
        case 0:
            cout << "\nTerminating task";
            return 0;
            break;
        case 1:
            cout << "\nHow many elements? ";
            cin >> nr;
            arr = insertNode(matrix, arr, &len, nr);
            break;
        case 2:
            matrix = insertEdge(matrix, arr, len);
            break;

        default:
            cout << "\nInvalid option";
            break;
        }
    }

    return 0;
}

int *insertNode(int **mat, int *arr, int *len, int nr)
{
    int j = 0, i = 0,
        key,
        count = *len + nr,
        *token, **matToken;
    token = (int *)malloc(sizeof(int *) * count);
    matToken = (int **)malloc(sizeof(int *) * count*count);
    for (i = 0; i < count; i++)
        matToken[i] = (int *)malloc(sizeof(int *) * count);
    for (i = 0; i < *len; i++)
        for (j = 0; j < *len; j++)
            if(mat[i][j])
                matToken[i][j]=mat[i][j];
            else
                matToken[i][j] = 0;
    mat = (int **) realloc(mat, sizeof(int*) * count*count);
    for (i = 0; i < count; i++)
        mat[i] = (int *) realloc(mat[i], sizeof(int*) * count);
    
    mat = matToken;
    free(matToken);
    for (i = 0; i < count; i++)
    {
        if (i < *len)
            token[i] = arr[i];
        else
        {
            cout << "\nkey: ";
            cin >> key;
            token[i] = key;
        }
    }
    *len = count;
    for (size_t i = 0; i < *len; i++)
        cout << token[i] << " ";
    arr = token;
    free(token);
    return arr;
}

int **insertEdge(int **mat, int *arr, int len)
{
    int token[len][len],
        a, b;
    for (size_t i = 0; i < len; i++)
        for (size_t j = 0; j < len; j++)
            token[i][j] = 0;
    cout << "\nInsert a and b nodes: ";
    cin >> a;
    cin >> b;
    token[a-1][b-1] = 1;
    token[b-1][a-1] = 1;

    return mat;
}

void menu()
{
    cout << "\n0.Exit";
    cout << "\n1.Insert node";
    cout << "\n2.Insert edge";
    cout << "\n3.Search node";
    cout << "\n4.Search edge";
    cout << "\n5.Delete node";
    cout << "\n6.Delete edge";
    cout << "\nOption: ";
}