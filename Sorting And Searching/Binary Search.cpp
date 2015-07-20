//Linear Search
//Input: Size of Array,Elements of Array in sorted order (Array may be rotated), And Element to be searched
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
		if(c!='\n' && c!='\r' && c!=' ' && c!=EOF)
		{
			cout<<c<<" Not Valid Integer\n";
			exit(0);
		}
	}
	return a;
}

int getChange(ll a[],int p, int q)
{
	int m=(p+q)/2;
	int n=q-p+1;
	//cout<<"Binary: "<<p<<" , "<<q<<endl;
	
	
	if(n==2&&a[p]<a[q])
		return -1;
	
	else if(n==1)
		return -1;
	else if(n<1)
		return -1;
	
	if(a[m]>a[m+1])
		return m;
	else if(a[m]<a[m-1])
		return m-1;
		
	else if(a[m]<a[p])
		return getChange(a,p,m-1);
	else
		return getChange(a,m,q);
}
int binSearch(ll a[],int p,int q, ll k)
{
	//cout<<"BinSearch: "<<p<<" , "<<q<<endl;
	int m=(p+q)/2;
	int n=q-p+1;
	if(n==1 && a[p]!=k)
		return -1;
	else if(n<1)
		return -1;
	if(a[m]==k)
		return m;
	else if(a[m]>k)
		return binSearch(a,p,m-1,k);
	else
		return binSearch(a,m+1,q,k);
}

int main()
{
	int n;
	ll *a=A;
	n=(int)getInt();
	
	for(int i=0;i<n;i++)
		a[i]=getInt();
	int c;
	
	
	
	c=getChange(a,0,n-1);
	//cout<<"Change: "<<c<<endl;
	ll k;
	k=getInt();
	if(c!=-1)
	{
		if(k>=(a[0]) && k<=(a[c]))	
			cout<<binSearch(a,0,c,k);
		else
			cout<<binSearch(a,c+1,n-1,k);
	}
	else
		cout<<binSearch(a,0,n-1,k);
	
	
	return 0;
}
