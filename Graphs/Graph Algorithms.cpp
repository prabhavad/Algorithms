//Graphs
//Contains Following Functions:
	// 1. BFS
	// 2. DFS
	// 3. Prims (Output: Adjacency Matrix of MST)
	// 4. Dijkstra's Shortest Path Algorithm 
	
//Graph Input:
	//Number of Vertices
	//Number of Edges
	//<Node_1> <Node_2> <Edge_Cost>
	// ..
	// ..

#include<iostream>
#include<stdio.h>
#include<limits.h>
#define INF INT_MAX
#define left(a) (2*(a))
#define right(a) (2*(a) + 1)
#define parent(a) ((a)/2)
using namespace std;

int Tree[1000][1000]={0};
int T[1000]={0};
template<class T,class P> struct pQueue{
	
	struct pNode{
		int in;
		T data;
		P pri;
		pNode(T a,P b)
		{
			data=a;
			pri=b;
		}
		pNode()
		{
			in=0;
		}
	};
	
	pNode N[1000];
	int H[1000];
	int size;
	
	pQueue(){
		size=0;
		for(int i=0;i<1000;i++)
			H[i]=0;
	}
	
	void minHeapify(int a){
		int l=a;
		if(left(a)<=size && N[a].pri > N[left(a)].pri)
			l=left(a);
		if(right(a)<=size && N[l].pri > N[right(a)].pri)
			l=right(a);
		if(l!=a)
		{
			pNode temp;
			temp = N[a];
			N[a] = N[l];
			N[l] = temp;
			minHeapify(l);
		}
	}
	
	void bubbleUp(int a){
		if(parent(a)>0 && N[parent(a)].pri > N[a].pri)
		{
			pNode temp;
			temp = N[a];
			N[a] = N[parent(a)];
			N[parent(a)] = temp;
			bubbleUp(parent(a));
		}
	}
	
	void push(T a,P b){
		size++;
		N[size]=pNode(a,b);
		H[a]=1;
		bubbleUp(size);
	}
	
	T top(){
		return N[1].data;
	}
	
	P topPri(){
		return N[1].pri;
	}
	
	void pop(){
		H[top()]=0;
		N[1] = N[size];
		size--;
		minHeapify(1);
	}
	
	int increase_insert(T a,P b){
		int l=1;
		if(H[a])
		{
			for(int i=1;i<=size;i++)
				if(N[i].data == a){
					l=i;
					break;
				}
			int flag=0;
			if(N[l].pri >= b){
				N[l].pri=b;
				bubbleUp(l);
				flag = 1;
			}
			return flag;
		}
		else{
			push(a,b);
			return 1;
		}
	}
	void print(){
		for(int i=1;i<=size;i++)
			cout<<N[i].data<<','<<N[i].pri<<'\n';
		cout<<'\n';
	}
	bool empty(){
		return (size==0);
	}
};

class Pair{
	public:
	int n;
	int c;
	Pair(int a,int b)
	{
		n=a;
		c=b;
	}
	Pair()
	{
		n=c=0;
	}
};

template<class T> class queue{
	struct qNode
	{
		T v;
		qNode* next;
		qNode(T q)
		{
			v=q;
			next=0;
		}
	};
	
	qNode* rear;
	int size;
	public:
	qNode* top;
	queue()
	{
		size=0;
		top=rear=0;
	}
	bool empty()
	{
		return (size==0);
	}
	void push(T a)
	{
		qNode *p=new qNode(a);
		if(size ==0)
			top = rear = p;
		else
		{
			rear->next = p;
			rear = p;
		}
		size++;
	}
	void pop()
	{
		qNode *a=top;
		top = top->next;
		delete a;
		size--;
	}
	T Top()
	{
		return top->v;
	}
};

template<class T> class stack{
	struct sNode
	{
		T v;
		sNode* next;
		sNode(T q)
		{
			v=q;
			next=0;
		}
	};
	
	int size;
	public:
	sNode* top;
	stack()
	{
		size=0;
		top=0;
	}
	bool empty()
	{
		return (size==0);
	}
	void push(T a)
	{
		sNode *p=new sNode(a);
		if(size ==0)
			top = p;
		else
		{
			p->next = top;
			top = p;
		}
		size++;
	}
	void pop()
	{
		sNode *a=top;
		top = top->next;
		delete a;
		size--;
	}
	T Top()
	{
		return top->v;
	}
};

struct node{
	int f;
	int v;
	int d;
	int p,pe;
	queue<Pair> Nber;
	node()
	{
		f=0;
		v=0;
		d=INF;
		p=-1;
	}
	node(int a)
	{
		f=0;
		v=a;
		p=-1;
		d =INF;
	}  
	void visit()
	{
		f=1;
		cout<<v<<' ';
	};
	void set()
	{
		f=1;
	}
};

class Graph{
	int n;
	int e;
	public: node G[1000];
	public:
	Graph(int a,int b)
	{
		n=a;
		e=b;
		for(int i=1;i<n;i++)
		{
			G[i] = node(i);
		}
	}
	void addEdge(int a, int b, int c)
	{
		Pair A = Pair(a,c);
		Pair B = Pair(b,c);
		G[a].Nber.push(B);
		G[b].Nber.push(A);
	}
	
	//For bfs and dfs, G[i].f is used as flag 
	void bfs(int a)
	{
		queue<node*> Q;
		Q.push(&G[a]);
		while(Q.empty()!=1)
		{
			//cout<<"visit"<<'\n';

			node t = *Q.Top();
			G[t.v].visit();
			Q.pop();
			
			while(!t.Nber.empty())
			{
				if(G[t.Nber.Top().n].f==0){
					G[t.Nber.Top().n].set();
					Q.push(&G[t.Nber.Top().n]);
				}
				t.Nber.pop();
			}
		}
	}
	void dfs()
	{
		for(int i=0;i<n;i++)
			G[i].f = 0;
			
		for(int i=0;i<n;i++)
			if(G[i].f == 0)
				dfs(i);
	}
	
	void dfs(int a)
	{
		stack<node*> Q;
		Q.push(&G[a]);
		while(Q.empty()!=1)
		{
			node t = *Q.Top();
			t.visit();
			G[t.v].set();
			Q.pop();
			
			while(!t.Nber.empty())
			{
				if(G[t.Nber.Top().n].f==0){
					
					G[t.Nber.Top().n].set();
					Q.push(&G[t.Nber.Top().n]);
				}
				t.Nber.pop();
			}
		}
	}	
	//Dijkstra's Shortest Path
	// G[i].d has the distance from Source
	// 
	void sPath(int a){
		pQueue<int,int> Q;
		Q.push(a,0);
		while(!Q.empty())
		{
			node a = G[Q.top()];
			G[a.v].d = Q.topPri();
			Q.pop();
			while(!a.Nber.empty())
			{
				if(G[a.Nber.Top().n].d > G[a.v].d)
				{	
					Q.increase_insert(a.Nber.Top().n,a.Nber.Top().c + G[a.v].d);
				}
				a.Nber.pop();
			}			
		}
		return;
	}
	// Tree[][] is the adjancency matrix of the MST
	int prim()
	{
		int cost = 0;
		pQueue<int,int> Q;
		Q.push(0,0);
		while(!Q.empty())
		{
			node a = G[Q.top()];
			G[a.v].d = Q.topPri();
			T[a.v]=1;
			
			if(a.v != 0){
				Tree[G[a.p].v][a.v] = Tree[a.v][G[a.p].v] = G[a.v].pe;
				cost += Tree[a.v][G[a.p].v];
			} 
			Q.pop();
			while(!a.Nber.empty())
			{
				if(T[a.Nber.Top().n] == 0)
				{	
					int f = Q.increase_insert(a.Nber.Top().n,a.Nber.Top().c);
					if(f){
						G[a.Nber.Top().n].p = a.v;
						G[a.Nber.Top().n].pe = a.Nber.Top().c;
					}
				}
				a.Nber.pop();
			}			
		}
		
		return cost;
	}
};

int main()
{
	int n,e;
	cin>>n;
	cin>>e;
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
	Graph G(n,e);
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a<0 || a>n || b<0 || b>n){
			cout<<"Invalid Edge\n";
			return 0;
		}
		G.addEdge(a,b,c);
	}
	int a;
	cin>>a;
	G.bfs(a);
}
