//Hashing with Quadratic Probing
//Options
	// 1 -> Insert an Integer (I/o: 1 <Integer>)
	// 2 -> Search for an Integer (I/o: 2 <Integer>)
	// 0 -> Exit

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<climits>
#define MAX 100000
#define NIL (INT_MAX-1)
using namespace std;
int H[MAX+1];
int M;
int hf(int k){
	if(k>=0)
		return (k%M);
	else
		return hf(k+M);
}
int hF(int k,int i){
	return hf(hf(k)+i*i);
}

void reset()
{
    for(int i = 0; i < MAX + 1; i++)
        H[i] = NIL;
}


void insert(int H[],int a)
{
	int i=0,key;
	do{
		key=hF(a,i);
		cout<<key<<' ';
		if(H[key]==NIL){
			H[key]=a;
			return;
		}
		else
			i=i+1;
	}while(i<M);
	cout<<"Overflow!\n";
}

int search(int H[],int a)
{
	
	int key,i=0;
	do{
		key=hF(a,i);
		cout<<key<<' ';
		if(H[key]==a){
			return 1;
		}
		else
			i=i+1;
	}while(i<M && H[key]!=NIL);
	return 0;
}

int main()
{
	int a,b;
	reset();
	if(!(cin>>M))
	{
		cout<<"Invalid Input\n";
		return 0;
	}
	if(M<0)
	{
		cout<<"-Ve Size Not Allowed\n";
		return 0;
	}
	if(M==0)
	{
		cout<<"0 Size not Allowed\n";
	}
	while(1)
	{
		if(!(cin>>a))
		{
			cout<<"Invalid Option\n";
			break;
		}
		switch(a)
		{
			case 0:
				return 0;
			case 1:
				if(cin.peek()==' ')
					cin>>b;
				else
					cout<<"Option Not Complete\n";
				insert(H,b);
				cout<<'\n';
				break;
			case 2:
				if(cin.peek()==' ')
					cin>>b;
				else
					cout<<"Option Not Complete\n";
				if(search(H,b))
					cout<<"FOUND\n";
				else
					cout<<"NOT FOUND\n";
				break;
			default:
				cout<<"Wrong Choice\n";
		}
	}
}
