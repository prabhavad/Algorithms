//Check if given graph is bipartite or not
//Input: Graph (Number of (Nodes,Edges) and Edges )

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
struct Edge
{
	int n1,n2,c;
	Edge(){}
	Edge(int a,int b,int d)
	{
		n1=a,n2=b,c=d;
	}
};

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
template<class T>
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

template<class T>
class queue{
	
	
	qNode<T>* rear;
	int size;
	public:
	qNode<T>* top;
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
		qNode<T> *p=new qNode<T>(a);
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
		qNode<T> *a=top;
		top = top->next;
		delete a;
		size--;
	}
	T Top()
	{
		return top->v;
	}
	void remove(int a)
	{
		qNode<T> *A = top;
		qNode<T> *B;
		if(A->v.n==a)
		{
			B = top;
			
			top=top->next;
			size--;
			delete B;
			return;
		}
		while(A){
			if(A->next && A->next->v.n == a)
			{	
				B=A->next;
				A->next = A->next->next;
			
				delete B;
				break;
			}
			A=A->next;
		}
		size--;
	}
	void print()
	{
		qNode<T> *a = top;
		while(a){
			cout<<a->v.n<<' ';
			a=a->next;
		}
		cout<<'\n';
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
int getCO(int a)
{ 
	return ((a==1)?2:1);
}
struct node{
	int f;
	int v;
	int d;
	int p,pe,c;
	queue<Pair> Nber;
	node()
	{
		f=0;
		c=v=0;
		d=INF;
		p=-1;
	}
	node(int a)
	{
		c=f=0;
		v=a;
		p=-1;
		d =INF;
	}  
	void visit()
	{
		f=1;
		//cout<<v<<' ';
	};
	void set()
	{
		f=1;
	}
};

class Graph{
	int n;
	int e;
	public: 
	
	node G[1000];
	
	Graph(int a,int b)
	{
		n=a;
		e=b;
		for(int i=1;i<=n;i++)
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
	
	int is_bi(int a)
	{
		queue<int> Q;
		Q.push(a);
		for(int i=1;i<=n;i++)
			G[i].f=0;
		while(Q.empty()!=1)
		{
			int q = Q.Top();
			qNode<Pair> *t = G[q].Nber.top;
			
			G[q].visit();

			
			Q.pop();
			while(t)
			{
				if(G[t->v.n].f==0){
					if(G[t->v.n].c == 0)
					{
			
						G[t->v.n].c = getCO(G[q].c);
					}
					G[t->v.n].set();
					Q.push(t->v.n);
				
				}
				else 
					if(G[t->v.n].c && t->v.n!=q &&G[t->v.n].c == G[q].c)
					{	
						return 0;
					}
				t=t->next;
			}
		}
		return 1;
	}
	
};

int main()
{
	int n,e;
	cin>>n;
	cin>>e;	
	Graph G(n,e);
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b;
		c=0;
		G.addEdge(a,b,c);
	}
	
	G.G[1].c=1;
	int flag = 0;
	for(int i=1;i<=n;i++){
		if(!G.is_bi(i)){
			cout<<"NO"<<'\n';
			flag = 1;
			break;
		}
	}
	if(!flag)
		cout<<"YES";
}
