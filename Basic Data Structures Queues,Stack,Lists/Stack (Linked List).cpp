//Stack using linked list
//Options
	//1 -> Push
	//2 -> Pop
	//3 -> Peek
	//4 -> Display the Stack
	//0 -> Exit
	
#include<iostream>
using namespace std;
struct node
{
	int num;
	node *prev;
};

struct stack
{
	int size;
	node* top;
	
	stack()
	{
		top = 0;
		size = 0;
	}
};	

void push(stack& S, int a)
{
	node* t = new node;
	//node* t= malloc(sizeof(node));
	t->num = a;
	t->prev = S.top;
	S.top = t;
	S.size++;
}

int pop(stack& S)
{
	if(S.size > 0)
	{
		cout << S.top->num << '\n';
		S.size--;
		node *p = S.top;
		S.top = S.top -> prev;
		delete p;
		//free(p)
		return 1;
	}
	else
		return 0;
}

int show(stack& S)
{
	node* t = S.top;
	if(S.size ==0)
		return 0;
		
	for(int i=0 ; i < S.size ; i++)
	{
		cout << t->num << endl;
		t = t->prev;
	}
	return 1;
}

int peek(stack& S)
{
	if(S.size > 0)
		return S.top->num;
	
	else
		return -1;
}

int main()
{
	stack S;
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
				push(S,n);
				break;
			
			case 2:
				if(!pop(S))
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
