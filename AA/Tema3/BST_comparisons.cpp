
#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000
struct node
{
    int key;
    node *left, *right;
};

node *addNode(int key)
{
    node *clone = new node;
    clone->key = key;
    clone->left = NULL;
    clone->right = NULL;
    return clone;
}

void populateVector(node *root, vector<node *> &nodes)
{
    if (root == NULL)
        return;
    populateVector(root->left, nodes);
    nodes.push_back(root);
    populateVector(root->right, nodes);
}

node *normalize(vector<node *> &nodes, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    node *root = nodes[mid];
    root->left = normalize(nodes, start, mid - 1);
    root->right = normalize(nodes, mid + 1, end);
    return root;
}

node *balanceTree(node *root)
{
    vector<node *> nodes;
    populateVector(root, nodes);
    int n = nodes.size();
    return normalize(nodes, 0, n - 1);
}

node *insert(node *head, int key)
{
    if (head == NULL)
        return addNode(key);
    if (key < head->key)
        head->left = insert(head->left, key);
    else if (key > head->key)
        head->right = insert(head->right, key);
    else
        cout << "This node already exists";
    return head;
}

void inorder(node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}
void preorder(node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->key);
    preorder(node->left);
    preorder(node->right);
}
void postorder(node *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->key);
}

void showOff(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

node *populate(node *head, int arr[], int *n)
{
    FILE *f = fopen("AA/Tema3/input.txt", "rt");
    int key;
    if (f != NULL)
    {
        while (!feof(f))
        {
            fscanf(f, "%d", &key);
            arr[(*n)++] = key;
            head = insert(head, key);
        }
        fclose(f);
    }
    else
        printf("error reading file");
    return head;
}

struct node *search(node *head, int key, int *count)
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

void writeStatistics(char *path, node *head, int keys[], int n)
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
            count < min ? min = count : count > max ? max = count : 0;
            avg += count;
            k++;
        }
        avg /= k;
        fclose(f);
        printf ("\nlongest path: %4d, shortest path: %4d, avg path: %4f", max, min, avg);
        return avg;
    }
    else
        printf("\nerror readin file");
}

int main()
{
    int keys[MAX],
        n = 0;
    node *root = NULL;
    root = populate(root, keys, &n);
    float balanced,
        unbalanced;
    // showOff(keys, n);

    // printf("\ninorder:\n");
    // inorder(root);
    // printf("\npreorder:\n");
    // preorder(root);
    // printf("\npostorder:\n");
    // postorder(root);

    writeStatistics("AA/Tema3/unbalanced.txt", root, keys, n);
    printf("\nUnbalanced tree:");
    unbalanced = analyseStatistics("AA/Tema3/unbalanced.txt");

    root = balanceTree(root);
    writeStatistics("AA/Tema3/balanced.txt", root, keys, n);
    printf("\n\nBalanced tree:");
    balanced = analyseStatistics("AA/Tema3/balanced.txt");

    printf("\nUnbalanced raported to Balanced : %.2f%%", (unbalanced/balanced - 1)*100);
    return 0;
}
