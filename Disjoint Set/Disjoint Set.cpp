//Disjoint Sets (With ranked union and path compression)
//Options:
	// 1 -> Makeset (Input: 1 <Integer>)
	// 2 -> Find (Input: 2 <Integer> Output: Representative)
	// 3-> Union (Input: 3 <Integer_1> <Integer_2>)
#include<iostream>
using namespace std;
struct Node
{
	int v;
	Node* p;
	Node* next;
	int rank;
	Node(int a)
	{
		v=a;
		rank=0;
		next = 0;
	}
};

struct List
{
	Node *top;
	void insert(int a)
	{
		Node *pq = new Node(a);
		pq->v = a;
		pq->p = pq;
		pq->next = top;
		top = pq;
	}
};

int h(int a)
{
	return (a+100000)%100000;
}

class dSet
{
	public:
	List N[100000];
	int size;
	dSet()
	{
		size=0;
	}
	void Makeset(int a)
	{	
		int f = h(a);	
		
		N[f].insert(a);
		size++;
	}
	Node* getNode(int a)
	{
		Node *p = N[h(a)].top;
		while(p)
		{
			if(p->v ==a)
				return p;
			p=p->next;
		}
		return 0;
	}
	Node* Findset(Node *a)
	{
		if(a->p==a)
			return a;
		else
		{
			a->p = Findset(a->p);
			return a->p;
		}
	}
	int Findset(int a)
	{
		int b = Findset(getNode(a))->v;
		return b;
	}
	void Union(int a, int b)
	{
		Node* x=Findset(getNode(a));
		Node* y=Findset(getNode(b));
		if(x && y && x!=y)
		{
			if(x->rank >= y->rank)
			{
				y->p = x;
				if(x->rank==y->rank)
					x->rank++;
		
			}
			else
				x->p=y;
		}
	}	
};
	
	
int main()
{
	dSet S;
	//cin.tie(0);
	while(1)
	{
		int a, b, c;
		cin>>a;
		if(a==0)
			return 0;
		else if(a==1)
		{
			cin>>b;
			S.Makeset(b);
		}
		else if(a==2)
		{
			cin>>b;
			cout<<S.Findset(b)<<'\n';
		}
		else if(a==3)
		{
			cin>>b>>c;
			S.Union(b,c);
		}
		else
			cout<<"Wrong Choice\n";
	}
}
