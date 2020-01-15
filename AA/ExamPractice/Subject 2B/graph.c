// Se consideră un graf orientat și neponderat având următoarele noduri de tip literă de alfabet:
// A, e, q, Z, h, w, u, p, X, x, o, r, K, l, v
// Se vor genera automat arce de legătură orientate dinspre coloane spre vocale.
// Să se implementeze {adăugare nod, adăugare arc, ștergere nod, ștergere arc}

#include <stdio.h>
#include <stdlib.h>

#define MAX 30
typedef struct Subnode
{
    int cost;
    char key;
    struct Subnode *next;
} Subnode;

typedef struct Node
{
    unsigned short int visited : 1;
    char key;
    struct Node *next;
    struct Subnode *sublist;
} Node;

void menu(int *option)
{
    printf("\n0. Exit");
    printf("\n1. Add node");
    printf("\n2. Display list");
    printf("\n3. Add edge");
    printf("\n4. Delete an edge");
    printf("\n5. Delete a node");
    printf("\nOption: ");
    scanf("%d", option);
}
Node *searchNode(Node *head, char key);
void displayList(Node *head);
Node *readNode(Node *head);
Node *addNode(Node *head, char key);
Node *deleteNode(Node *head);
Subnode *deleteSubnode(Subnode *head, char key);
Subnode *addSubnode(Subnode *head, char key);
Node *addEdge(Node *head);
void deleteEdge(Node *head);
char toUppercase(char ch);
int isVowel(char ch);
Node *knot(Node *head);

int main()
{
    Node *list = NULL;
    list = addNode(list, 'A');
    list = addNode(list, 'e');
    list = addNode(list, 'q');
    list = addNode(list, 'Z');
    list = addNode(list, 'h');
    list = addNode(list, 'w');
    list = addNode(list, 'u');
    list = addNode(list, 'p');
    list = addNode(list, 'X');
    list = addNode(list, 'x');
    list = addNode(list, 'o');
    list = addNode(list, 'r');
    list = addNode(list, 'K');
    list = addNode(list, 'l');
    list = addNode(list, 'v');
    list = knot(list);
    displayList(list);

    int option;
    while (1)
    {
        // menu(&option);
        option = 0;
        switch (option)
        {
        case 0:
            return 0;
        case 1:
            list = readNode(list);
            list = knot(list);
            break;
        case 2:
            displayList(list);
            break;
        case 3:
            addEdge(list);
            break;
        case 4:
            deleteEdge(list);
            break;
        case 5:
            list = deleteNode(list);
            break;
        default:
            break;
        }
    }
}
Node *searchNode(Node *head, char key)
{
    Node *node = head;
    for (node = head; node && node->key != key; node = node->next)
        ;
    return node;
}
Subnode *searchSubnode(Subnode *head, char key)
{
    Subnode *subnode = head;
    for (subnode = head; subnode && subnode->key != key; subnode = subnode->next)
        ;
    return subnode;
}

Node *inject(Node *head, Node *node)
{
    Node *q1, *q2;
    for (q1 = q2 = head; q1 != NULL && q1->key < node->key; q2 = q1, q1 = q1->next)
        ;
    if (q1 != q2)
    {
        q2->next = node;
        node->next = q1;
    }
    else
    {
        node->next = head;
        head = node;
    }
    return head;
}

Node *addNode(Node *head, char key)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->sublist = NULL;
    node->visited = 0;
    node->key = key;
    head = inject(head, node);
    return head;
}

Node *knot(Node *head)
{
    Node *q1, *q2;
    for (q1 = head; q1; q1 = q1->next)
        if (!isVowel(q1->key))
            for (q2 = head; q2; q2 = q2->next)
                if (isVowel(q2->key) && searchSubnode(q1->sublist, q2->key) == NULL)
                    q1->sublist = addSubnode(q1->sublist, q2->key);
    return head;
}

Node *readNode(Node *head)
{
    char key;
    printf("\nInsert key: ");
    scanf(" %c", &key);
    if (searchNode(head, key) == NULL)
        head = addNode(head, key);
    return head;
}

Subnode *addSubnode(Subnode *head, char key)
{
    Subnode *subnode,
        *q1, *q2;
    subnode = (Subnode *)malloc(sizeof(Subnode));
    subnode->next = NULL;
    subnode->key = key;
    for (q1 = q2 = head; q1 != NULL && q1->key < key; q2 = q1, q1 = q1->next)
        ;
    if (q1 == q2)
    {
        subnode->next = head;
        head = subnode;
    }
    else
    {
        q2->next = subnode;
        subnode->next = q1;
    }
    return head;
}

void displayList(Node *head)
{
    Node *node = head;
    Subnode *subnode;
    if (!node)
        printf("\nList is empty");
    for (node = head; node; node = node->next)
    {
        printf("\nnode: %c", node->key);
        if (node->sublist != NULL)
            for (subnode = node->sublist; subnode; subnode = subnode->next)
                printf("\n\tVertex: %c", subnode->key);
    }
}
Node *cleanUp(Node *head)
{
    Node *node = head;
    for (node = head; node; node = node->next)
        node->visited = 0;
    return head;
}

Node *deleteNode(Node *head)
{
    char key;
    printf("\nkey: ");
    scanf(" %c", &key);
    Node *q1, *q2;
    for (q1 = q2 = head; q1 != NULL && q1->key != key; q2 = q1, q1 = q1->next)
        ;
    if (q1 != q2)
    {
        q2->next = q1->next;
        for (q2 = head; q2 != NULL; q2 = q2->next)
            if (q2->sublist)
                q2->sublist = deleteSubnode(q2->sublist, q1->key);
        free(q1);
    }
    else
        head = head->next;
    return head;
}

Subnode *deleteSubnode(Subnode *head, char key)
{
    Subnode *q1, *q2;
    for (q1 = q2 = head; q1 != NULL && q1->key != key; q2 = q1, q1 = q1->next)
        ;

    if (q1 != NULL && q1->key == key)
    {
        if (q1 == q2)
            head = head->next;
        else
        {
            q2->next = q1->next;
            free(q1);
        }
    }
    return head;
}

char toUppercase(char ch)
{
    if (ch > 96)
        ch -= 32;
    return ch;
}

int isVowel(char ch)
{
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    for (size_t i = 0; i < 5; i++)
        if (vowels[i] == toUppercase(ch))
            return 1;
    return 0;
}

Node *addEdge(Node *head)
{
    Subnode *subnode;
    Node *nodeA, *nodeB;
    char keyA, keyB;
    unsigned short int distance = 0;
    printf("\nInsert first vertex: ");
    scanf(" %c", &keyA);
    while ((nodeA = searchNode(head, keyA)) == NULL)
    {
        printf("\nInsert an existing vertex: ");
        scanf(" %c", &keyA);
    }

    printf("\nInsert second vertex: ");
    scanf(" %c", &keyB);
    while ((nodeB = searchNode(head, keyB)) == NULL || keyA == keyB)
    {
        printf("\nInsert an existing vertex different from first one: ");
        scanf(" %c", &keyB);
    }
    if (searchSubnode(nodeA->sublist, nodeB->key) == NULL)
        nodeA->sublist = addSubnode(nodeA->sublist, nodeB->key);
    return head;
}

void deleteEdge(Node *head)
{
    Subnode *subnode;
    Node *nodeA, *nodeB;
    char keyA, keyB;
    printf("\nInsert first vertex: ");
    scanf(" %c", &keyA);
    while ((nodeA = searchNode(head, keyA)) == NULL)
    {
        printf("\nInsert an existing vertex: ");
        scanf(" %c", &keyA);
    }
    printf("\nInsert second vertex: ");
    scanf(" %c", &keyB);
    while ((nodeB = searchNode(head, keyB)) == NULL || keyA == keyB)
    {
        printf("\nInsert an existing vertex different from first one: ");
        scanf(" %c", &keyB);
    }

    nodeA->sublist = deleteSubnode(nodeA->sublist, nodeB->key);
    nodeB->sublist = deleteSubnode(nodeB->sublist, nodeA->key);
}