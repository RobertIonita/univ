
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get the height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Helper function that allocates a new node with the given key and 
    NULL left and right pointers. */
struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)
        malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
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

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
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

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node *insert(struct Node *node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right)); /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
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
    } /* return the (unchanged) node pointer */
    return node;
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void populate(struct Node **head, int arr[], int *n)
{
    FILE *f = fopen("AA/Comparisons/assets/input.txt", "rt");
    int key;
    if (f != NULL)
    {
        while (!feof(f))
        {
            fscanf(f, "%d", &key);
            *head = insert(*head, key);
            arr[(*n)++] = key;
        }
        fclose(f);
    }
    else
        printf("error reading file");
}
struct Node *search(struct Node *head, int key, int *count)
{
    if (head == NULL || head->key == key)
        return head;
    else if (key > head->key)
    {
        (*count)++;
        return search(head->right, key, &(*count));
    }
    else
    {
        (*count)++;
        return search(head->left, key, &(*count));
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
int main()
{
    struct Node *root = NULL;
    int n = 0, arr[1000000];
    float avg;
    populate(&root, arr, &n);

    // inOrder(root);

    writeStatistics("AA/Comparisons/assets/AVL.txt", root, arr, n);
    printf("\nAVL tree:");
    avg = analyseStatistics("AA/Comparisons/assets/AVL.txt");
    return 0;
}
