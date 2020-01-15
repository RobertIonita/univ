// Un arbore binar echilibrat în sens AVL are introduse următoarele elemente:
// V, L, k, R, O, X, x, P, U, W, H, z, Q, E, a
// Să se implementeze un un program cu următoarele funcții:
// {inserție literă, cautare literă, afișare inordine}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char key;
    int height;
    Node *left;
    Node *right;
} Node;

Node *search(Node *head, char key);
void searchNode(Node *root);
void inorder(Node *root);
Node *insert(Node *node, char key);
Node *readNode(Node *root);
int getBalance(Node *N);
Node *leftRotate(Node *x);
Node *rightRotate(Node *y);
Node *newNode(int key);
int max(int a, int b);
int height(Node *N);

void menu(int *option)
{
    printf("\n0. Exit");
    printf("\n1. Add node");
    printf("\n2. Display inorder");
    printf("\n3. Search node");
    printf("\nOption: ");
    scanf("%d", option);
}
int main()
{
    Node *root = NULL;
    root = insert(root, 'V');
    root = insert(root, 'L');
    root = insert(root, 'k');
    root = insert(root, 'R');
    root = insert(root, 'O');
    root = insert(root, 'X');
    root = insert(root, 'x');
    root = insert(root, 'P');
    root = insert(root, 'U');
    root = insert(root, 'W');
    root = insert(root, 'H');
    root = insert(root, 'z');
    root = insert(root, 'Q');
    root = insert(root, 'E');
    root = insert(root, 'a');
    printf("\ninorder: \n");
    inorder(root);

    int option;
    while (1)
    {
        // menu(&option);
        option = 0;
        switch (option)
        {
        case 0:
            printf("\nGoodbye");
            return 0;
        case 1:
            root = readNode(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            searchNode(root);
            break;
        default:
            break;
        }
    }
}

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *newNode(int key)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *readNode(Node *root)
{
    char key;
    printf("\nInsert key: ");
    scanf(" %c", &key);
    root = insert(root, 'M');
    return root;
}

Node *insert(Node *node, char key)
{
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->key);
        inorder(root->right);
    }
}

void searchNode(Node *root)
{
    Node *node;
    char key;
    printf("\nInsert key: ");
    scanf(" %c", &key);
    node = search(root, key);
    if (node)
        printf("\nkey: %c, height: %d", node->key, node->height);
}

Node *search(Node *head, char key)
{
    if (head == NULL || head->key == key)
        return head;
    else if (key > head->key)
        return search(head->right, key);
    else
        return search(head->left, key);
}
