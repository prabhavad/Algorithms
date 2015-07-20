//Kruskal's Algorithm
//Output: Adjacency Matrix of MST

//Graph Input:
	//Number of Vertices
	//Number of Edges
	//<Node_1> <Node_2> <Edge_Cost>
	// ..
	// ..
#include<iostream>
#define Max 2147483647
using namespace std;
struct Edge
{
	int n1,n2,c;
	Edge(){}
	Edge(int a,int b,int d)
	{
		n1=a,n2=b,c=d;
	}
};


class dSet
{
	public:
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
	Node *N[100000];
	int size;
	dSet()
	{
		size=0;
	}
	void Makeset(int a)
	{		
		N[a] = new Node(a);
		N[a]->p = N[a];
		size++;
	}
	Node* getNode(int a)
	{
		return N[a];
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
	int Union(int a, int b)
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
			return 1;
		}
		else 
			return 0;
	}	
};
	
	

void merge(Edge a[], int s, int m,int e){
	
	Edge b[10000];
	Edge c[10000];
	for(int i=s;i<=m;i++)
		b[i-s]=a[i];
		
	b[m-s+1].c=Max;

	for(int i=m+1;i<=e;i++)
		c[i-m-1]=a[i];
	
	c[e-m].c=Max;
	
	int I=0,J=0;
	for(int i=s;i<=e;i++)
	{
		if(b[I].c<c[J].c)
		{
			a[i]=b[I++];
		}
		else
			a[i]=c[J++];
		
	}
}

void mSort(Edge a[],int p,int q){
	int m=(p+q)/2;
	if(q>p)
	{
		mSort(a,p,m);
		mSort(a,m+1,q);
		merge(a,p,m,q);
	}
}

int Tree[1000][1000];
int main()
{
	dSet S;
	int n,e,cost =0;
	cin>>n>>e;
	if(n<=0)
	{
		cout<<"Number of nodes should be Positive Integer\n";
		return 0;
	}
	if(e > (n*n-n)/2)
	{
		cout<<"Number of edges greater than upper bound\n";
		return 0;
	}
	if(e<0)
	{
		cout<<"Number of edges should be Positive Integer\n";
		return 0;
	}
	for(int i=0;i<n;i++)
		S.Makeset(i);
	Edge E[10000];
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a<0 || a>n || b<0 || b>n){
			cout<<"Invalid Edge\n";
			return 0;
		}
		E[i] = Edge(a,b,c);
	}
	mSort(E,0,e-1);
	int T[100000] = {0};
	int j=0;
	
	for(int i=0;j<n;i++)
	{
		if(S.Union(E[i].n1, E[i].n2)){
			Tree[E[i].n1][E[i].n2] = E[i].c;
			Tree[E[i].n2][E[i].n1] = E[i].c;
			cost += E[i].c;
		}
		if(!T[E[i].n1])
		{	
			j++;
			T[E[i].n1]++;
		}
		if(!T[E[i].n2])
		{	
			j++;
			T[E[i].n2]++;
		}
	}
	cout<<cost<<'\n';
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<Tree[i][j]<<' ';
		cout<<'\n';
	}
}
