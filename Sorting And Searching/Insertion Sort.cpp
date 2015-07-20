//Insertion Search
//Input: Size of Array and Elements of Array
#include<iostream>
#include<cstdlib>
#include<cstdio>
#define ll long long
#define MAX 100000000
#define Max 2147483647
using namespace std;
ll A[MAX]={0};
ll inv=0;
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
void swap(ll &a ,ll &b)
{
	inv++;
	ll t;
	t=a;
	a=b;
	b=t;
}

void iSort(ll a[],int n)
{
	int j;
	for(int i=0;i<n-1;i++)
	{
		j=i+1;
		while(j>=1 && a[j]<a[j-1])
		{
			ll t;
			
			inv++;
			t=a[j];
			a[j]=a[j-1];
			a[j-1]=t;
			
			j--;
		}
	}
}
int main()
{
	
	
	int n;
	ll *a=A;
	n=(int)getInt();
	for(int i=0;i<n;i++)
		a[i]=getInt();
	
	iSort(a,n);
	
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<'\n';
	//cout<<inv<<'\n'; counts number of invertions
	
	
}
