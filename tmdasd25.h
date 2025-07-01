/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tugas Masa Depan dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h> // include library stdio.h
#include <string.h> // include library string.h
#include <malloc.h> // include library malloc.h

// define macro
#define slv solve();

// declare typdef struct for list
typedef struct{
    // contents of the container
    char consequence[201];
}boxList;

typedef struct elmL* elmListAddress;
typedef struct elmL{
    boxList container;
    elmListAddress next;
}element;

typedef struct{
    element* first;
}list;

// declare typedef struct for n-ary tree
typedef struct{
    // contens of the container
    int level;
    char name[201];
    list L;
}box;

typedef struct nde* nodeAddress;
typedef struct nde{
    box container;
    nodeAddress sibling;
    nodeAddress child;
    nodeAddress parent;
}node;

typedef struct{
    node *root;
}tree;

// declare typedef struct for queue
typedef struct{
    // contents of the container 
    node *elementQ;
}boxQue;

typedef struct elmQ *elmQueueAddress;
typedef struct elmQ{
    boxQue container;
    elmQueueAddress next;
}elementQ;

typedef struct{
    elementQ *first;
    elementQ *last;
}queue;

// declare typedef struct for stack
typedef struct{
    // contents of the container 
    int num;
}boxStck;

typedef struct elmS *elmStackAddress;
typedef struct elmS{
    boxStck container;
    elmStackAddress next;
}elementS;

typedef struct {
    elementS* top;
}stack;

// declare global variable
extern stack space; // stack to save number of spation per level
extern stack maxLen; // stak to save max lenght string per level
extern int maxLevel; // to save maximum level in this tree
extern int justConseq; // to set mode print (print just consequence or not)

// declare procedure and function for list
void createList(list *L);
int countElementList(list L);
void addFirst(boxList temp, list *L);
void addAfter(element* prev, boxList temp, list *L);
void addLast(boxList temp, list *L);

// declare procedure and function for stack
void createStack(stack *S);
int countElementStack(stack S);
void push(boxStck tmp, stack *S);
void pop(stack *S);
int getElement(stack S, int n);
void updateStack(stack *S, int idx, int newVal);

// declare procedure and function for queue
void createQueue(queue *Q);
int isEmpty(queue Q);
int countElementQueue(queue Q);
void add(boxQue tmp, queue *Q);
void del(queue *Q);

// declare procedure and function for n-ary tree
void createTree(box tmp, tree* T);
void addChild(box tmp, node* root);
void delAll(node* root);
void delChild(box tmp, node* root);
node* findNodeBFS(box find, node* root);
void printNode(node *root);
void printPreOrder(node* root);
void delPreOrder(box tmp, node* root);

// declare procedure to make spation
void createSpace();
void resetSpace();
void countSpace(node *root);

// procedure to solve the problem
void solve();