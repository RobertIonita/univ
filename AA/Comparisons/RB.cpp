// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
    node *parent = NULL;
    bool color;
};

class RB_TREE
{

    node *root;

public:
    RB_TREE() : root(NULL) {}

    node *GetRoot() { return root; }

    void insert(int stuff)
    {
        if (root == NULL)
        {
            root = new node();
            root->data = stuff;
            root->parent = NULL;
            root->color = false;
        }
        else
        {
            auto linker = GetRoot();
            node *newnode = new node();
            newnode->data = stuff;

            while (linker != NULL)
            {
                if (linker->data > stuff)
                {
                    if (linker->left == NULL)
                    {
                        linker->left = newnode;
                        newnode->color = true;
                        newnode->parent = linker;
                        break;
                    }
                    else
                        linker = linker->left;
                }
                else
                {
                    if (linker->right == NULL)
                    {
                        linker->right = newnode;
                        newnode->color = true;
                        newnode->parent = linker;
                        break;
                    }
                    else
                        linker = linker->right;
                }
            }
            RB_Insert_Fixup(newnode);
        }
    }

    void RB_Insert_Fixup(node *z)
    {
        while (z->parent->color)
        {
            auto grandparent = z->parent->parent;
            auto uncle = GetRoot();
            if (z->parent == grandparent->left)
            {
                if (grandparent->right)
                    uncle = grandparent->right;
                if (uncle->color)
                {
                    z->parent->color = false;
                    uncle->color = false;
                    grandparent->color = true;
                    if (grandparent->data != root->data)
                        z = grandparent;
                    else
                        break;
                }
                else if (z == grandparent->left->right)
                    LeftRotate(z->parent);
                else
                {
                    z->parent->color = false;
                    grandparent->color = true;
                    RightRotate(grandparent);
                    if (grandparent->data != root->data)
                        z = grandparent;
                    else
                        break;
                }
            }
            else
            {
                if (grandparent->left)
                    uncle = grandparent->left;
                if (uncle->color)
                {
                    z->parent->color = false;
                    uncle->color = false;
                    grandparent->color = true;
                    if (grandparent->data != root->data)
                        z = grandparent;
                    else
                        break;
                }
                else if (z == grandparent->right->left)
                    RightRotate(z->parent);
                else
                {
                    z->parent->color = false;
                    grandparent->color = true;
                    LeftRotate(grandparent);
                    if (grandparent->data != root->data)
                        z = grandparent;
                    else
                        break;
                }
            }
        }
        root->color = false;
    }

    node *searchKey(int key, int *count)
    {
        auto temp = GetRoot();
        if (temp == NULL)
            return NULL;

        while (temp)
        {
            if (key == temp->data)
                return temp;
            else if (key < temp->data)
            {
                (*count)++;
                temp = temp->left;
            }
            else
            {
                (*count)++;
                temp = temp->right;
            }
        }
        return NULL;
    }

    void LeftRotate(node *x)
    {
        node *nw_node = new node();
        if (x->right->left)
            nw_node->right = x->right->left;
        nw_node->left = x->left;
        nw_node->data = x->data;
        nw_node->color = x->color;
        x->data = x->right->data;

        x->left = nw_node;
        if (nw_node->left)
            nw_node->left->parent = nw_node;
        if (nw_node->right)
            nw_node->right->parent = nw_node;
        nw_node->parent = x;

        if (x->right->right)
            x->right = x->right->right;
        else
            x->right = NULL;
        if (x->right)
            x->right->parent = x;
    }

    void RightRotate(node *x)
    {
        node *nw_node = new node();
        if (x->left->right)
            nw_node->left = x->left->right;
        nw_node->right = x->right;
        nw_node->data = x->data;
        nw_node->color = x->color;

        x->data = x->left->data;
        x->color = x->left->color;

        x->right = nw_node;
        if (nw_node->left)
            nw_node->left->parent = nw_node;
        if (nw_node->right)
            nw_node->right->parent = nw_node;
        nw_node->parent = x;
        if (x->left->left)
            x->left = x->left->left;
        else
            x->left = NULL;
        if (x->left)
            x->left->parent = x;
    }

    void inorder(node *temp)
    {
        if (!temp)
            return;
        inorder(temp->left);
        printf("\n%d:%d", temp->data, temp->color);
        inorder(temp->right);
    }
};

void writeStatistics(char *path, RB_TREE *head, int keys[], int n)
{
    int count;
    FILE *f = fopen(path, "wt");
    if (f != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            count = 0;
            (*head).searchKey(keys[i], &count);
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
void populate(RB_TREE *head, int arr[], int *n)
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
    RB_TREE root;
    int n = 0, arr[1000000];
    float avg;
    populate(&root, arr, &n);
    writeStatistics("AA/Comparisons/assets/RB.txt", &root, arr, n);
    printf("\nRB tree:");
    avg = analyseStatistics("AA/Comparisons/assets/RB.txt");

    printf("\nAVL raported to RBTree : %.2f%%", (11.363118 / avg - 1) * 100);
    return 0;
}
