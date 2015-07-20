//Median In Linear Time
//Input: Size of array, and elements of array, one per line
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#define ll int
int A[100000000];
using namespace std;

int getInt()
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


void getM(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=1; j<n ; j++)
			if(a[j-1]>a[j])
			{
				int t=a[j-1];
				a[j-1]=a[j];
				a[j]=t;
			}	
}

void median(int a[], int n)
{	
	
	for(int i=0;i<n; i+=5)
	{
		if(i+5 < n)
		{
			getM(a+i,5);
			swap(a[i/5],a[i+2]);
		}
		else
		{
			getM(a+i,n-i);
			swap(a[i/5],(a+i)[(n-i)/2]);//[i+(n-i)/2 ]);
		}
	}
	if(n!=0)
		median(a,n/5);
}
int M;
int parti(int a[],int s, int e)
{
	if(e>=s)
	{
	
		int i=s-1,j=s;
		
		median(a+s,e-s+1);
		int k=a[s];
		
		swap(a[s],a[e]);
	
		while(j<=e)
		{
			if(a[j]<=k)
			{
				int t=a[i+1];
				a[i+1]=a[j];
				a[j]=t;
				i++;
			}
			j++;
		}
	
	
		if(i== (M))
			return a[i];
		else if (i>(M))
			parti(a,s,i-1);
		else
			parti(a,i+1,e);
	}
	return 0;
}


int main()
{
	
	int n;
	n=getInt();
	int *a=A;
	for(int i=0;i<n;i++)
	{
		
		cin>>a[i];
	}

	if(n%2==1)
	{
		M=(n)/2 ;
		int k=parti(a,0,n-1);
		cout<<k<<'\n';
	}
	else
	{
		M=n/2;
		int k=parti(a,0,n-1);
		M=n/2 - 1;
		int l=parti(a,0,n-1);
		cout<<(float)(k+l)/2.0<<'\n';
	}
	return 0;
}
