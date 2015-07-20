// Print BST in Brackets (LISP Format)
// Input: Elements of bst in a single line
#include<iostream>
using namespace std;

struct bst
{
    int num;
    bst *right;
    bst *left;
    bst* parent;
    bst()
    {
        right = left = parent = 0;
        num = -1;
    }
};

int Insert(bst* &r, int n)
{
    if(r == 0)
    {
        bst *p = new bst;
        p->num = n;
        r = p;
    }
    else if(n <= r->num)
    {
        if(r->left == 0)
        {
            bst *p = new bst;
            p->num = n;
            p->parent = r;
            r->left = p;
        }
        else
            Insert(r->left, n);
    }

    else if(n > r->num)
    {
        if(r->right == 0)
        {
            bst *p = new bst;
            p->num = n;
            p->parent = r;
            r->right = p;
        }
        else
            Insert(r->right, n);
    }
    return 1;
}

void print(bst* &b)
{

    if(b == 0)
    {
        cout << "()";
        return;
    }
    else
    {
        cout << "(";
        cout << b->num << ' ' ;

        print(b->left);
        cout << ' ';
        print(b->right);
        cout << ")";
    }

}

int main()
{
    bst *B;
    int a;
    if(!(cin.peek() == '\n'))
        while(cin >> a && Insert(B, a) && cin.peek() != '\n');

    print(B);
}
