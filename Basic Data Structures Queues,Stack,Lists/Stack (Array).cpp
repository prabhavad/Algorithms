//Stack using array
#include<iostream>
using namespace std;
struct Stack
{
	int A[100];
	int size;
	int s;
	
	Stack()
	{
		size=0;
		s=0;
	}
	Stack(int as)
	{
		s=as;
		size=0;
	}
	int push(int a)
	{
		if(size==s)
		{
			cout<<"OVERFLOW\n";
			return 0;
		}
		A[size]=a;
		size++;
		return 1;
	}
	
	int pop()
	{
		if(size==0)
		{
			//cout<<"EMPTY\n";
			return 0;
		}
		size--;
		cout << A[size] <<'\n';
		return 1;
	}
	int peek()
	{
		if(size==0)
		{
			//cout<<"EMPTY\n";
			return -1;
		}
		else
			return A[size-1];
	}
	int show()
	{
		if(size==0)
			return 0;
		for(int i=size-1;i>=0;i--)
			cout<<A[i]<<' ';
		cout<<'\n';
		return 1;
	}
};


int main()
{
	int s;
	cin>>s;
	
	Stack S(s);
	
	int a,n;
	while(1)
	{
		cin >> a;
		//Options
		//1 -> Push
		//2 -> Pop
		//3 -> Peek
		//4 -> Display the Stack
		//0 -> Exit
		switch(a)
		{
			case 0:
				return 0;
			
			case 1:
				cin >> n;
				S.push(n);
				break;
			
			case 2:
				if(!S.pop())
					cout<<"EMPTY\n";
				break;
			
			case 3:
			{	int p = S.peek(); 
				if(p!=-1)
					cout << p << '\n';
				else
					cout << "EMPTY\n";
			}
			break;
			
			case 4:
				if(!S.show())
					cout << "EMPTY\n";
				break;
		
			default:
				cout<<"Wrong Choice\n";
		}
	}
}
