//Linear Search
//Input: Size of Array,Elements of Array, And Element to be searched
//Output: If found Position of Element(0 based Indexing), Else, -1

#include<iostream>
#include<cstdlib>
#include<cstdio>
#define ll long long
#define MAX 100000000
using namespace std;

ll A[MAX]={0};
ll getInt()
{
	ll a;
	if(!(cin>>a))
	{
		cout<<"Not Valid Integer\n";
		exit(0);
	}
	else
	{
		char c;
		c=getchar();
		if(c!='\n'&&c!='\r'&&c!=' '&&c!=EOF)
		{
			cout<<"Not Valid Integer\n";
			exit(0);
		}
	}
	return a;
}

ll linSearch(ll a[],int n,ll k)
{
	if(n==0)
		return 0;
	if(n==1 && a[0]!=k)
		return 0;
	else if(a[n-1]==k)
		return n;
	else
		return (linSearch(a,n-1,k));
}	

int main()
{
	
	int n;
	ll *a=A;
	n=(int)getInt();
	for(int i=0;i<n;i++)
		a[i]=getInt();
	ll k;
	k=getInt();
	
	cout<<linSearch(a,n,k)-1<<'\n';
	
	return 0;
}
