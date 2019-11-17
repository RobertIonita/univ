#include <iostream>
using namespace std;

class BTreeNode
{
    int *keys;
    int t;
    BTreeNode **C;
    int n;
    bool leaf;

public:
    BTreeNode(int _t, bool _leaf);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(int k, int *count);
    friend class BTree;
};

class BTree
{
    BTreeNode *root;
    int t;

public:
    BTree(int _t)
    {
        root = NULL;
        t = _t;
    }
    void traverse()
    {
        if (root != NULL)
            root->traverse();
    }

    BTreeNode *search(int k, int *count)
    {
        return (root == NULL) ? NULL : root->search(k, &(*count));
    }
    void insert(int k);
};
BTreeNode::BTreeNode(int t1, bool leaf1)
{
    t = t1;
    leaf = leaf1;
    keys = new int[2 * t - 1];
    C = new BTreeNode *[2 * t];
    n = 0;
}

void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (leaf == false)
            C[i]->traverse();
        cout << " " << keys[i];
    }
    if (leaf == false)
        C[i]->traverse();
}

BTreeNode *BTreeNode::search(int k, int *count)
{
    int i = 0;
    while (i < n && k > keys[i]) {
        i++;
        (*count)++;
    }
    if (keys[i] == k)
        return this;
    if (leaf == true)
        return NULL;
    return C[i]->search(k, &(*count));
}

void BTree::insert(int k)
{
    if (root == NULL)
    {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else
    {
        if (root->n == 2 * t - 1)
        {
            BTreeNode *s = new BTreeNode(t, false);
            s->C[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);
            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

void BTreeNode::insertNonFull(int k)
{
    int i = n - 1;
    if (leaf == true)
    {
        while (i >= 0 && keys[i] > k)
        {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n = n + 1;
    }
    else
    {
        while (i >= 0 && keys[i] > k)
            i--;
        if (C[i + 1]->n == 2 * t - 1)
        {
            splitChild(i + 1, C[i + 1]);
            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y)
{
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];
    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }
    y->n = t - 1;
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];
    C[i + 1] = z;
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];
    keys[i] = y->keys[t - 1];
    n = n + 1;
}

void writeStatistics(char *path, BTree *head, int keys[], int n)
{
    int count;
    FILE *f = fopen(path, "wt");
    if (f != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            count = 0;
            (*head).search(keys[i], &count);
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
}
void populate(BTree *head, int arr[], int *n)
{
    FILE *f = fopen("AA/Comparisons/assets/input.txt", "rt");
    int key;
    if (f != NULL)
    {
        while (!feof(f))
        {
            fscanf(f, "%d", &key);
            (*head).insert(key);
            arr[(*n)++] = key;
        }
        fclose(f);
    }
    else
        printf("error reading file");
}

int main()
{
    BTree root(3);
    int n = 0, arr[1000000];
    float avg;
    populate(&root, arr, &n);
    writeStatistics("AA/Comparisons/assets/BTree.txt", &root, arr, n);
    printf("\nBTree tree:");
    avg = analyseStatistics("AA/Comparisons/assets/BTree.txt");
    return 0;
}
