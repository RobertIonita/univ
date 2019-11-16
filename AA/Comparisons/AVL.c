#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b);

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Helper function that allocates a new node with the given key and 
    NULL left and right pointers. */
struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)
        malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

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
struct Node *search(Node *node, int key, int *count)
{
    if (node == NULL || node->key == key)
        return node;
    else if (key > node->key)
    {
        (*count)++;
        return search(node->right, key, &(*count));
    }
    else
    {
        (*count)++;
        return search(node->left, key, &(*count));
    }
}

void writeStatistics(char *path, struct Node *head, int keys[], int n)
{
    int count;
    FILE *f = fopen(path, "wt");
    if (f != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            count = 0;
            search(head, keys[i], &count);
            fprintf(f, "%d %d\n", keys[i], count);
        }
    }
    fclose(f);
}

float analyseStatistics(char *path)
{
    FILE *f = fopen(path, "rt");
    int count, max = 0, min = 0, k = 0;
    float avg = 0;
    if (f != NULL)
    {
        while (!feof(f))
        {
            fscanf(f, "%d %d", &count, &count);
            count<min ? min = count : count> max ? max = count : 0;
            avg += count;
            k++;
        }
        avg /= k;
        fclose(f);
        printf("\nlongest path: %4d, shortest path: %4d, avg path: %4f", max, min, avg);
        return avg;
    }
    else
        printf("\nerror readin file");
    return -1;
}
void populate(struct Node *head, int arr[], int *n)
{
    FILE *f = fopen("AA/Comparisons/assets/input.txt", "rt");
    int key;
    if (f != NULL)
    {
        while (!feof(f))
        {
            fscanf(f, "%d", &key);
            head = insert(head, key);
            arr[(*n)++] = key;
        }
        fclose(f);
    }
    else
        printf("error reading file");


} 

void inorder (struct Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}
int main()
{
    struct Node *root = NULL;
    int n = 0, arr[1000000];
    float avg;
    populate(root, arr, &n);
    printf("\n nr: %d", n);

    printf("\ninorder:\n");
    inorder(root);
    writeStatistics("AA/Comparisons/assets/AVL.txt", root, arr, n);
    printf("\nAVL tree:");
    avg = analyseStatistics("AA/Comparisons/assets/AVL.txt");
    printf("\nAVL raported to RBTree : %.2f%%", (11.363118 / avg - 1) * 100);
    return 0;
}
