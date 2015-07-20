//Queue using Linked List
//Options
	//1 -> Push
	//2 -> Pop
	//3 -> Peek
	//4 -> Display the Queue
	//0 -> Exit
#include<iostream>
using namespace std;
struct node
{
	int num;
	node *next;
};

struct queue
{
	int size;
	node* rear;
	node* front;
	queue()
	{
		rear = front = 0;
		size = 0;
	}
};	

void enqueue(queue& Q, int a)
{ 
	node* t = new node;
	t -> num = a;
	if(Q.size==0)
	{
		Q.rear = Q.front = t;
		Q.size++;
	}
	else
	{
		Q.rear -> next = t;
		Q.rear = t;
		Q.size++;
	}
}

int dequeue(queue& Q)
{
	if(Q.size > 0)
	{
		cout << Q.front -> num << '\n';
		Q.size--;
		node *p = Q.front;
		Q.front = Q.front -> next;
		delete p;
		return 1;
	}
	else
		return 0;
}

int show(queue& Q)
{
	node* t = Q.front;
	if(Q.size ==0)
		return 0;
		
	for(int i=0 ; i < Q.size ; i++)
	{
		cout << t->num << endl;
		t = t->next;
	}
	return 1;
}

int peek(queue& Q)
{
	if(Q.size > 0)
		return Q.front->num;
	
	else
		return -1;
}

int main()
{
	queue S;
	int a,n;
	while(1)
	{
		cin >> a;
		switch(a)
		{
			case 0:
				return 0;
			
			case 1:
				cin >> n;
				enqueue(S,n);
				break;
			
			case 2:
				if(!dequeue(S))
					cout<<"EMPTY\n";
				break;
			
			case 3:
			{	int p = peek(S); 
				if(p!=-1)
					cout << p << '\n';
				else
					cout << "EMPTY\n";
			}
			break;
			
			case 4:
				if(!show(S))
					cout << "EMPTY\n";
				break;
		
			default:
				cout<<"Wrong Choice\n";
		}
	}
}
