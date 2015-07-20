//Merge Sort (Integers)
//Input: Size of Array and elements of array one per line

#include<iostream>
#include<cstdlib>
#include<cstdio>
#define ll int
#define MAX 100000000
#define Max 2147483647
using namespace std;

ll A[MAX]={0};
int b[MAX];
int c[MAX];

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
			cout<<"Not Valid Integer\n";
			exit(0);
		}
	}
	return a;
}
void merge(ll a[], int s, int m,int e)
{
	
	
	for(int i=s;i<=m;i++)
		b[i-s]=a[i];
		
	b[m-s+1]=Max;

	for(int i=m+1;i<=e;i++)
		c[i-m-1]=a[i];
	
	c[e-m]=Max;
	
	int I=0,J=0;
	for(int i=s;i<=e;i++)
	{
		if(b[I]<c[J])
		{
			a[i]=b[I++];
		}
		else
			a[i]=c[J++];
		
	}
}
void mSort(ll a[],int p,int q)
{
	int m=(p+q)/2;
	if(q>p)
	{
		mSort(a,p,m);
		mSort(a,m+1,q);
		merge(a,p,m,q);
	}
}

int main()
{
	

	int n;
	ll *a=A;
	n=(int)getInt();
	
	for(int i=0;i<n;i++)
		a[i]=getInt();
		
		
	mSort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<'\n';
	
}
