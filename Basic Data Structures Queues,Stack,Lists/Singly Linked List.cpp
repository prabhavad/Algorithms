//Singly Linked List 
//No main()
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int num;
	node *prev;
	node *next;
	node()
	{
		prev=next=0;
	}
};

struct sList
{
	int size;
	node* top;
	
	sList()
	{
		top = 0;
		size = 0;
	}
	
	void insert(int a)
	{	
		node* t = new node;
		if(!t)
		{
			cout<<"Overflow\n";
			exit(0);
		}
		t->num = a;
		t->prev = top;
		top = t;
		size ++;
	}
	
	int rem_first()
	{
		if(size > 0)
		{
			cout << top->num << '\n';
			size--;
			node *p = top;
			top = top -> prev;
			delete p;
			return 1;
		}
		else
			return 0;
	}

	int show()
	{
		node* t = top;
		if(size ==0)
			return 0;
			
		for(int i=0 ; i < size ; i++)
		{
			cout << t->num << endl;
			t = t -> prev;
		}
		return 1;
	}

	int countAbove(int a)
	{
		int c=0;
		node* t = top;
		if(size ==0)
			return 0;
			
		for(int i=0 ; i < size ; i++)
		{
			if(t->num > a)
				c++;
			t = t -> prev;
		}
		return c;
	}

	int peek()
	{
		if(size > 0)
			return top->num;
		else
			return -1;
	}
};

