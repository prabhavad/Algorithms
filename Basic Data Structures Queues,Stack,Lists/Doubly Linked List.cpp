//Doubly Linked List
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

struct dList
{
	node* front;
	node* end;
	int size;
	
	dList()
	{
		size = 0;
		front = end = 0;
	}
	
	void insert(int a)
	{
		node* t = new node;
		if(!t)
		{
			cout << "Overflow\n";
		}
		t -> num = a;
		if(size == 0)
		{
			front = end = t;
		}
		else
		{
			t -> prev = end;
			end -> next = t;
			end = t;
		}
		size++;
	}
	
	int removeAlt(int k=-3)
	{
		if(k==-3)
			k=front->num;
		node* t = front;
		int i;
		for(i=0;i<size;i++)
		{
			if(t->num == k)
				break;
			t=t->next;
		}
		
		if(i>size)
			return 0;
		int f=1;
		int kk=size;
		for(int j=i;j<kk;j++,f++)
		{
			if(f&1)
				remove(t);
		 	t=t->next;
		}
		return 1;
	}
	void remove(node *n)
	{
		if(n == front)
		{
			front = front -> next;
			delete n;
		}
		else if(n == end)
		{
			end = end -> prev;
			delete n;
		}
		else
		{
			n -> next -> prev = n -> prev;
			n -> prev -> next = n -> next;
			delete n;
		}
		size--;
	}
	
	int show()
	{
		node* t = front;
		if(size == 0)
			return 0;
		for(int i = 0 ; i < size ; i++, t = t -> next)
			cout << t -> num << ' ';
		cout<<'\n';
		return 1;
	}
};

int main() //double linked list
{
	dList S;
	int n;
	
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		S.insert(a);
	}
	S.removeAlt();
	cout<<"";
	if(!S.show())
		cout<<"EMPTY\n";
	return 0;
}

