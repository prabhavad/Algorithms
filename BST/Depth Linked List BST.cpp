// Create Linked List of Nodes of same depth in a binary search tree
// BST is in Array form. -1 represents NULL. 2i,2i+1 is left,right child of i'th node 
// Input: Size of Array, and elements of array in a single line 
Input:
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
struct bst
{
    int num;
    bst *right;
    bst *left;
    bst()
    {
        right = left = 0;
        num = -1;
    }
};

struct node
{
    int data;
    node* next;
    node()
    {
        next = 0;
    }
};

class List
{
public:
    node *Head;
    node *Rear;
    List()
    {
        Head = Rear = 0;
    }

    void insert(int a)
    {
        node* p = new node;
        p->data = a;
        if(Head == 0)
        {
            Head = Rear = p;
        }
        else
        {
            Rear->next = p;
            Rear = p;
        }
    }

    void print()
    {
        node* t = Head;
        if(t == 0)
            cout << "Null";
        while(t)
        {
            cout << t->data;
            t = t->next;
            if(t)
                cout << "->";
        }
    }
    bool null()
    {
        if(Head == 0)
            return 1;
        return 0;
    }
};

void createBst(int B[], int i, int n, bst* &b)
{

    if(i <= n && B[i] != -1)
    {
        bst *p = new bst;
        p->num = B[i];
        b = p;
        createBst(B, 2 * i, n, b->left);
        createBst(B, 2 * i + 1, n, b->right);
    }
}

void createList(bst *b, List L[], int i, int &t)
{
    if(b)
    {
        if(L[i].null())
            t++;
        L[i].insert(b->num);
        createList(b->left, L, i + 1, t);
        createList(b->right, L, i + 1, t);
    }
}

int main()
{

    int n = 0, t, c = 0;
    int a [100000] = {0};
    cin >> n;
    if(n < 0)
    {
        cout << "-Ve Integer Not Allowed\n";
        return 0;
    }
    if(n == 0)
    {
        cout << "0 Size. No BST\n";
        return 0;
    }
    int j = 1;
    getchar();
    while(cin.peek() != '\n')
    {
        cin >> t;
        a[j++] = t;
        if(t != -1)
            c++;
    }
    if(c != n)
    {
        cout << "Number of Nodes: " << c << " is not equal to the Given Input: " << n << " \n";
        return 0;
    }

    j--;
    for(int i = 1; i <= j; i++)
    {
        if(a[i] < 0 && a[i] != -1)
        {
            cout << "Negative Number other than 0 Encountered\n ERROR !!\n";
            return 0;
        }
        if(a[i] == -1 && ((2 * i <= j && a[2 * i] != -1) || (2 * i + 1 <= j && a[2 * i + 1] != -1)))
        {
            cout << "Parent of A Child cannot be Null excpt for the Root\n";
            cout << i << "th Element has the problem: " << a[i] << " " << a[2 * i] << ' ' << a[2 * i + 1];
            return 0;
        }
    }

    bst *B;
    createBst(a, 1, j, B);
    t = 0;

    List L[10000];
    createList(B, L, 1, t);
    for(int i = 1; i <= t; i++)
    {
        L[i].print();
        cout << '\n';
    }
}
