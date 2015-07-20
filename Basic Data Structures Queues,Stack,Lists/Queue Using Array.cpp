//Queue using Array(Size = 100)
//Options
	//1 -> Push
	//2 -> Pop
	//3 -> Peek
	//4 -> Display the Queue
	//0 -> Exit
	
#include<iostream>
#define QSI 10000
using namespace std;
struct Queue
{
	int A[QSI];
	int size;
	
	int front;
	int end;
	int s;
	Queue(int as)
	{
		front=0;
		end=-1;
		size=0;
		s=as;
	}
	void enqueue(int a)
	{
		if(size==s)
		{
			cout<<"OVERFLOW\n";
			return;
		}
		size++;
		if(end+1 < QSI)
		{
			A[end+1]=a;
			end++;
		}
		else
		{
			A[0] = a;
			end = 0;
		}
	}
	int dequeue()
	{
		if(size==0)
		{
		//	cout<<"EMPTY\n";
			return 0;
		}
		cout<<A[front]<<endl;
		
		if(front+1 < QSI)
			front++;
		else
			front=0;
		size--;
		return 1;
	}
	int peek()
	{
		if(size==0)
		{
		//	cout<<"EMPTY\n";
			return -1;
		}
		
		return A[front];
	}
	int show()
	{
		if(size==0)
			return 0;
		if(front <= end)
		{
			for(int i=front; i<=end; i++)
			{
				cout<<A[i]<<' ';
			}
		}
		else
		{
			for(int i=front; i< QSI; i++)
				cout<<A[i]<<' ';
			for(int i=0; i<=end;i++)
				cout<<A[i]<<' ';
		}
		return 1;
	}
};

int main()
{
	int s;
	cin>>s;
	if(s<0)
	{
		cout<<"Negative Size ERROR !!\n";
		return 0;
	}
	if(s==0)
	{
		cout<<"Zero Size ERROR !!\n";
		return 0;
	}
	if(s>100)
	{
		cout<<"Maximum Size ERROR !!\n";
		return 0;
	}	
	Queue S(s);
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
				S.enqueue(n);
				break;
			
			case 2:
				if(!S.dequeue())
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
				cout<<'\n';
				break;
		
			default:
				cout<<"Wrong Choice\n";
		}
	}
}

		
		
