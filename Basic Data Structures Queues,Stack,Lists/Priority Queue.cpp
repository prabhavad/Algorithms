//Priority Queue using Heaps
//Options
	//1 -> Push ( Data, Priority)
	//2 -> Pop
	//3 -> Peek
	//4 -> Increase Priotity (Data, New Priority)
	//0 -> Exit
//Data >= 0
//Priority >=1

#include<iostream>
#define left(a) (2*(a))
#define right(a) (2*(a) + 1)
#define parent(a) ((a)/2)

#define MAX 100000

using namespace std;

void minHeapify(int A[2][MAX], int p, int n)
{
	int l=p;
	if(left(p) <= n && (A[0][left(p)]) < A[0][p] )
		l=left(p);
	if(right(p) <= n && (A[0][right(p)] < A[0][l]))
		l=right(p);
	swap(A[0][p],A[0][l]);
	swap(A[1][p],A[1][l]);
	if(l!=p)
		minHeapify(A,l,n);
}

void bubbleU(int A[2][MAX],int i,int n)
{
	while(parent(i)>=1 && A[0][i] < A[0][parent(i)])
	{
		swap(A[0][i],A[0][parent(i)]);
		swap(A[1][i],A[1][parent(i)]);
		i=parent(i);
	}
}		
struct node
{
	int num;
	int pri;
};

struct pQueue
{
	int size;
	int P[2][MAX];
	
	pQueue()
	{
		size=0;
	}
	
	void show()
	{
		if(size==0)
			cout<<"Empty\n";
		else
			for(int i=1;i<=size;i++)
			{
				cout<< P[1][i] <<" (" << P[0][i] << ") "<<'\n';
			}
	}	
	
};

int insert(pQueue &A,node *a)
{	
	if(A.size==MAX-1)
	{
		cout<<"OVERFLOW\n";
		return 0;
	}
	A.P[0][A.size+1]=a->pri;
	A.P[1][A.size+1]=a->num;
	A.size++;
	
	if(A.size>1)		
	bubbleU(A.P ,A.size,A.size);
	return 1;
}

void increase(pQueue &A,int nu,int pr)
{
	int i,p;
	
	for(i=1;i<=A.size;i++)
		if(A.P[1][i]==nu)
		{
			p=i;
			break;
		}
		
	A.P[0][p]=pr;
	bubbleU(A.P, p, A.size);
}

node* remove(pQueue &A)
{
	node* t = new node;
	t->pri = A.P[0][1];
	t->num = A.P[1][1];
	A.P[1][1]=A.P[1][A.size];
	A.P[0][1]=A.P[0][A.size];
	A.size--;
	minHeapify(A.P ,1, A.size);	
	return t;
}

node* peek(pQueue &A)
{
	node* t = new node;
	t->pri = A.P[0][1];
	t->num = A.P[1][1];
	return t;
}

int main()
{
	int c;
	node n;
	pQueue Q;
	while(1)
	{
		if(!(cin>>c))
			return 0;
			
		switch(c)
		{
			case 0:
				return 0;
			case 1:
				cin>>n.num>>n.pri;
				insert(Q,&n);
				break;
				
			case 2:
			{
				if(Q.size==0)
					cout<<"Empty\n";
				else
				{
					node* p = remove(Q);
					cout<< p->num <<" ("<<p->pri<<") "<<'\n';
				}
				break;
			}
			case 3:
			{
				if(Q.size==0)
					cout<<"EMPTY\n";
				else
				{
					node* p = peek(Q);
					cout<< p->num <<" ("<<p->pri<<") "<<'\n';
				}
				break;
			}
			case 4:
			{
				int nu,pr;
				cin>>nu>>pr;
				increase(Q,nu,pr);
				break;
			}
			//case 5:
				//Q.show();
				//break;
			default:
				cout<<"Wrong Choice\n";
		}
	}
}
