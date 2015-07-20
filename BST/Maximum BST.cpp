// Print Size of Maximum Valid BST
// BST is in Array form. -1 represents NULL. 2i,2i+1 is left,right child of i'th node 
// Input: Size of Array, and elements of array in a single line
#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 2147483647
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

void print(bst* &b)
{
    if(b == 0)
        return;
    else
    {
        cout << b->num << ' ';
        cout << "(";
        print(b->left);
        cout << ")";
        cout << " (";
        print(b->right);
        cout << ")";
    }
}


int isBst(bst* b, int &c)
{
    int l = 1, r = 1;

    if(b)
        c++;
    else
        return 1;

    if(b->left && (b->num <= b->left->num))
        l = 0;

    else if(b->right && (b->num >= b->right->num))
        r = 0;

    int c1 = 0, c2 = 0;

    if(l && r)
    {
        bool q = (isBst(b->left, c1) && isBst(b->right, c2));
        c += c1 + c2;
        return q;
    }
    else
    {
        c = 0;
        return 0;
    }
}

void in_order(bst* &b)
{
    if(b == 0)
        return;
    else
    {
        in_order(b->left);
        cout << b->num << ' ';
        in_order(b->right);
    }
}
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

int getMaxBst(bst *b)
{

    int c = 0;
    if(!b)
        return 0;

    if(isBst(b, c))
    {
        //cout<<b->num<<' '<<c<<'\n';
        return c;
    }
    else
    {
        cout << b->num << ' ';
        int c1 = 0, c2 = 0;
        c1 = getMaxBst(b->left);
        c2 = getMaxBst(b->right);
        //cout<<c1<<','<<c2<<':'<<max(c1,c2)<<'\n';
        return max(c1, c2);
    }
}


int getM(bst *b, int &f1, int &len, int &Mi, int &Ma)
{
    if(b == 0)
    {
        f1 = 1;
        len = 0;
        Mi = INF;
        Ma = -INF;
        return 0;
    }
    if(!(b->left))
        Mi = b->num;
    if(!(b->right))
        Ma = b->num;

    int l = 1, r = 1;
    int fl = 0, fr = 0, ll = 0, lr = 0, mal = 0, mar = 0, mil = 0, mir = 0, ml, mr;

    ml = getM(b->left, fl, ll, mil, mal);
    mr = getM(b->right, fr, lr, mir, mar);

    if(b->left && b->num < mal)
        l = 0;
    if(b->right && b->num > mir)
        r = 0;
    Mi = min(b->num, mil);
    Mi = min(Mi, mir);
    Ma = max(b->num, mal);
    Ma = max(Ma, mar);
    //cout<<b->num<<' '<<"Sizes: "<<ml<<','<<mr<<" MaL,MiR: "<<mal<<','<<mir<<':';
    if(fl && fr && l && r)
    {
        f1 = 1;
        len = lr + ll + 1;

        //cout<<ml+mr+1<<'\n';
        //cout<<f1<<'\n';
        return ml + mr + 1;
    }

    f1 = 0;
    len = ll + lr + 1;
    //cout<<max(ml,mr)<<'\n';
    //cout<<f1<<'\n';
    return max(ml, mr);
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
            cout << i << "th Element has the problem: " << a[2 * i] << ' ' << a[2 * i + 1];
            return 0;
        }
    }

    bst *B;
    createBst(a, 1, j, B);
    cout << "Inorder Traversal: ";
    in_order(B);
    cout << '\n';

    int f, l, mi, ma;
    cout << "Maximum size of BST: " << getM(B, f, l, mi, ma) << '\n';

}
