//Selection Sort (Strings (Alphabets(a-z) only) )
//Input: Size of Array
//Output: Elements of Array (One per Line)
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define ll long long
#define MAX 1000000
using namespace std;

char A[MAX][100];

void checkString(char a[],char s,char e)
{
	int i=0;
	char C;
	C=getchar();
	for(i=0;C!='\n' && C!=EOF && C!='\r';)
	{
		//fflush(stdin);
		a[i]=C;
		if(C<s || C>e)
		{
			cout<<"Invalid String! '"<<a[i]<<"' Not Between "<<s<<" and "<<e<<" .\n";
			exit(0);
		}
		i++;
		C=getchar();
		
	}
	a[i]=0;
}

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
int isLess(char a[], char b[])
{
	int i=0;
	for(i=0;a[i]&&b[i];i++)
	{
		if(a[i]>b[i])
			return 0;
		if(a[i]<b[i])
			return 1;
	}
	if(a[i]!=0 && b[i]==0)
		return 0;

	return 1;

}
int getMin(char* a[100],int p, int q)
{
	int m=p;
	for(int i=p+1;i<=q;i++)
	{
		if(isLess(a[i],a[m]))
			m=i;
	}
	return m;
}
void sSort(char* a[100],int s)
{
	int m;
	for(int i=0;i<s;i++)
	{
		m=getMin(a,i,s-1);
		char *g;
		g=a[m];
		a[m]=a[i];
		a[i]=g;		
	}
}
int main()
{
	int size;
	size=getInt();
	char *p[MAX];
	for(int i=0;i<size;i++)
	{
		checkString(A[i],'a','z');
		p[i]=A[i];
		
	}
	clock_t s,e;
	s=clock();
	sSort(p,size);
	e=clock();
	for(int i=0;i<size;i++)
		cout<<p[i]<<'\n';
	cout<<fixed<<"Running Time: "<<(float)(e-s)/CLOCKS_PER_SEC<<" seconds\n";
}
