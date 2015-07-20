//Quick Sort (Floating Point Numbers)
//Input: Size of Array, And Elements of Array one per line

#include<iostream>
#include<cstdlib>
#include<cstdio>
#define ll double
#define MAX 100000000
#define Max 2147483647
using namespace std;
double A[MAX]={0};
double getInt()
{
	double a;
	if(!(cin>>a))
	{
		cout<<"Not Valid Real number\n";
		exit(0);
	}
	else
	{
		char c;
		c=getchar();
		if(c!='\n'&&c!='\r'&&c!=EOF)
		{
			cout<<"Not Valid Real number\n";
			exit(0);
		}
	}
	return a;
}

int getInt1()
{
	int a;
	if(!(cin>>a))
	{
		cout<<"Not Valid Integer\n";
		exit(0);
	}
	else
	{
		char c;
		c=getchar();
		if(c!='\n'&&c!='\r'&&c!=EOF)
		{
			cout<<"Not Valid Integer\n";
			exit(0);
		}
	}
	return a;
}


void swap(ll &a ,ll &b)
{
	ll t;
	t=a;
	a=b;
	b=t;
}

void qSort(ll a[],int s, int e)
{
	if(e>s)
	{
	
	int i=s-1,j=s;
	
	
	ll k=a[e];
	
	while(j<=e)
	{
		if(a[j]<=k)
		{
			ll t=a[i+1];
			a[i+1]=a[j];
			a[j]=t;
			i++;
		}
		j++;
	}
	
	
	qSort(a,s,i-1);
	qSort(a,i+1,e);
	}
}
int main()
{
	int n;
	ll *a=A;
	
	n=(int)getInt1();
	for(int i=0;i<n;i++)
		a[i]=getInt();
	
	qSort(a,0,n-1);
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<'\n';
	
}
