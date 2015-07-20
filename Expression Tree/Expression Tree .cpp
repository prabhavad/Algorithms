//Expression Tree
// Input: A postfix expression
// Output: Prefix and Infix expression

#include<iostream>
#include<stdio.h>
using namespace std;
struct eTree
{
    char root;
    eTree* left;
    eTree* right;
    eTree *prev;
    eTree *parent;
    bool flag;
    eTree()
    {
        prev = 0;
        flag = 0;
        left = right = parent = 0;
    }
};
struct stack
{
    int size;
    eTree* top;

    stack()
    {
        top = 0;
        size = 0;
    }
    void push(char a)
    {
        eTree* t = new eTree;

        t->root = a;
        t->prev = top;
        top = t;
        size++;
    }
    void push(eTree *t)
    {
        t->prev = top;
        top = t;
        size++;
    }

    eTree* pop()
    {
        if(size > 0)
        {
            size--;
            eTree *p = top;
            top = top -> prev;
            return p;
        }
        else
            return 0;
    }

    int show()
    {
        eTree* t = top;
        if(size == 0)
            return 0;

        for(int i = 0 ; i < size ; i++)
        {
            cout << t->root << ' ';
            t = t->prev;
        }
        return 1;
    }

    char peek()
    {
        if(size > 0)
            return top->root;

        else
            return 0;
    }
};

int leaf(eTree* T)
{
    if(T->left == 0 && T->right == 0)
        return 1;
    else return 0;
}

void Infix(eTree* T)
{

    if(!T)
        return;
    if(!leaf(T))
        cout << "(";
    Infix(T->left);
    cout << T->root;
    Infix(T->right);
    if(!leaf(T))
        cout << ")";
}

void Prefix(eTree* T)
{
    if(!T)
        return;
    cout << T->root;
    Prefix(T->left);
    Prefix(T->right);
}

void Postfix(eTree* T)
{
    if(!T)
        return;
    Postfix(T->left);
    Postfix(T->right);
    cout << T->root;
}

void iPrefix(eTree* T)
{
    stack S;
    T->flag = 0;
    S.push(T);
    while(S.size != 0)
    {
        eTree *b = S.top;
        S.pop();
        if(!(b->flag) && b->left)
        {
            b->right->flag = 0;
            S.push(b->right);
            b->left->flag = 0;
            S.push(b->left);
            b->flag = 1;
        }
        cout << b->root;
		b->flag = 1;
    }
}

int isOp(char a)
{
    if(a == '+' || a == '-' || a == '*' || a == '^' || a == '/' || a == '\\')
        return 1;
    return 0;
}

void iInfix(eTree* T)
{
    for(; T;)
    {
        if(T->left && T->left->flag)
        {
            while(T->left)
            {
                T = T->left;
                cout << "(";
            }
            cout << T->root;
            T->flag = 0;
            T = T->parent;
        }
        else if(T->right && T->flag)
        {
            cout << T->root;
            T->flag = 0;
            T = T->right;
        }
        else if(!T->right)
        {
            cout << T->root;
            T->flag = 0;
            T = T->parent;
        }
        else
        {
            cout << ")";
            T = T->parent;
        }
    }
}


void iPostfix(eTree* T)
{
    stack S;
    T->flag = 0;
    S.push(T);
    while(S.size != 0)
    {
        eTree *b = S.top;

        if(!(b->left || b->right) || (b->flag))
        {
            S.pop();
            cout << b->root;
        }
        else if(!(b->flag))
        {
            b->right->flag = 0;
            b->left->flag = 0;
            S.push(b->right);
            S.push(b->left);
            b->flag = 1;
        }
    }
}

int main()
{
    char a[1000];
    if(!(cin.getline(a, 1000 - 1)))
	{
		cout<<"Empty File\n";
		return 0;
	}
	
    for(int i=0;a[i];i++)
    {
		if(!((a[i]>='a' && a[i]<='z')||(isOp(a[i]))))
		{
			cout<<"Invalid Character '"<<a[i]<<"'"<<"\n";
			return 0;
		}
	}
    stack S;
    if(!(a[0]>='a' && a[0]<='z'))
	{
		cout<<"Invalid Input, First Char needs to be a Variable\n";
	}	
    S.push(a[0]);
    for(int i = 1; a[i]; i++)
    {
        if(isOp(a[i]))
        {
            eTree* p = S.pop();
            eTree* q = S.pop();
            eTree* t = new eTree;
            t->root = a[i];
            t->right = p;
            p->parent = t;
            q->parent = t;
            t->left = q;
            S.push(t);
        }
        else
        {
            S.push(a[i]);
        }
    }
    eTree *T = S.pop();
    if(S.size!=0)
    {
		cout<<"Invalid Input\n";
		return 0;
	}
    
    cout << "Preorder: ";
    Prefix(T);
    cout << "\nInorder: ";
    Infix(T);
    cout << "\nPostorder: ";
    Postfix(T);
}
