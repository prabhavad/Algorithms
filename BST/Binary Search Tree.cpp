//Binary Search Tree
//Options:
	// 1 -> Insert (I/o: 1 <Integer>)
	// 2 -> Search (I/o: 2 <Integer>)
	// 3 -> Print Minimum Number 
	// 4 -> Print Maximum Number 
	// 5 -> Print Inorder Predecessor (I/o: 5 <Integer>)
	// 6 -> Print Inorder Successor (I/o: 6 <Integer>)
	// 7 -> Delete (I/o: 7 <Integer>)
	// 8 -> Output Inorder traversal
	// 9 -> Output Preorder traversal
	// 10 -> Output Postorder traversal
	// 0 -> Exit
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

void Insert(bst* &r, int n)
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
}

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

bst* search(bst* &b, int n)
{
    if(b == 0)
        return 0;
    else if(b->num == n)
        return b;

    else if(b->num >= n)
        return search(b->left, n);
    else
        return search(b->right, n);
}

bst* smallest(bst* &b)
{
    if(b == 0)
        return 0;
    if(b->left == 0)
        return b;
    else
        return smallest(b->left);
}

bst* maximum(bst* &b)
{
    if(b == 0)
        return 0;
    if(b->right == 0)
        return b;
    else
        return maximum(b->right);
}

void deleteNode(bst* &r)
{
    if(r->right)
    {
        bst *p = smallest(r->right);
        r->num = p->num;
        deleteNode(p);
    }
    
    else if(r->left)
    {
        bst *p = maximum(r->left);
        r->num = p->num;
        deleteNode(p);
    }
    
    else
    {
        if(r->parent && r->parent->left == r)
            r->parent->left = 0;
        else if(r->parent && r->parent->right == r)
            r->parent->right = 0;
        r = 0;
    }
}

void Delete(bst* &r, int n)
{
    if(r->num == n)
        deleteNode(r);
    else if(n <= r->num)
        Delete(r->left, n);
    else
        Delete(r->right, n);
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

void pre_order(bst* &b)
{

    if(b == 0)
        return;
    else
    {
        cout << b->num << ' ';
        pre_order(b->left);
        pre_order(b->right);
    }
}

void post_order(bst* &b)
{

    if(b == 0)
        return;
    else
    {
        post_order(b->left);
        post_order(b->right);
        cout << b->num << ' ';
    }
}

int leaf(bst* &a)
{
    if(a->left == 0 && a->right == 0)
        return 1;
    else
        return 0;
}

bst* sucessor(bst* b)
{
    if(b->right)
        return smallest(b->right);
    bst* y = b->parent;
    while(y && b == y->right)
    {
        b = y;
        y = y->parent;
    }
    return y;
}

bst* predecessor(bst* b)
{
    if(b->left)
        return maximum(b->left);
    bst* y = b->parent;
    while(y && b == y->left)
    {
        b = y;
        y = y->parent;
    }
    return y;
}

int main()
{
    int c;
    bst *B;
    if(!(cin >> c))
    {
		cout << "Empty File\n";
		return 0;
	}
    while(1)
    {
        switch(c)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            int a;
            if(cin.peek() == ' ')
                cin >> a;
            else
                cout << "Option Not Complete\n";
            if(a < 0)
            {
                cout << "Negative Integer Not Allowed\n";
            }
            else 
                Insert(B, a);
            break;
        }
        case 2:
        {
            int a;
            if(cin.peek() == ' ')
                cin >> a;
            else
                cout << "Option Not Complete\n";
            if(a < 0)
            {
                cout << "Negative Integer Not Allowed\n";
                break;
            }
            if(search(B, a))
                cout << "FOUND\n";
            else
                cout << "NOT FOUND\n";
            break;
        }
        case 3:
        {
            bst* a = smallest(B);
            if(!a)
                cout << "NIL\n";
            else
                cout << a->num << '\n';
            break;
        }
        case 4:
        {
			
            bst* a = maximum(B);
            if(a == 0)
                cout << "NIL\n";
            else
                cout << a->num << '\n';
            break;
        }
        case 5:
        {
            int a;
            if(cin.peek() == ' ')
                cin >> a;
            else
                cout << "Option Not Complete\n";
            if(a < 0)
            {
                cout << "Negative Integer Not Allowed\n";
                break;
            }
            bst *b = search(B, a);
            if(b)
            {
                if(predecessor(b))
                    cout << predecessor(b)->num << '\n';
                else
                    cout << "NIL\n";
            }
            else
                cout << "NOT FOUND\n";
            break;
        }
        case 6:
        {
            int a;
            if(cin.peek() == ' ')
                cin >> a;
            else
                cout << "Option Not Complete\n";
            if(a < 0)
            {
                cout << "Negative Integer Not Allowed\n";
                break;
            }
            bst *b = search(B, a);
            if(b)
            {
                if(sucessor(b))
                    cout << sucessor(b)->num << '\n';
                else
                    cout << "NIL\n";
            }
            else
                cout << "NOT FOUND\n";
            break;
        }
        case 7:
        {
            int a;
            if(cin.peek() == ' ')
                cin >> a;
            else
                cout << "Option Not Complete\n";
            if(a < 0)
            {
                cout << "Negative Integer Not Allowed\n";
                break;
            }
            if(search(B,a))
				Delete(B, a);
            else
				cout<<"NOT FOUND\n";
            break;
        }
        case 8:
            in_order(B);
            cout << '\n';
            break;
        case 9:
            pre_order(B);
            cout << '\n';
            break;
        case 10:
            post_order(B);
            cout << '\n';
            break;
        default:
            cout << "Wrong Choice\n";
            break;
        }
        if(!(cin>>c))
        {
			cout<<"Exiting, File not complete\n";
			return 0;
		}	
    }
}
