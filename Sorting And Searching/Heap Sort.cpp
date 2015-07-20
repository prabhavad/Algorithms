//Heap Sort (Strings (Alphabets(A-Z) only) )
//Input: Size of Array
//Output: Elements of Array (One per Line)

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define ll long long
#define MAX 1000000
using namespace std;
char A[MAX][50];

void checkString(char a[],char s,char e)
{
	int i=0;
	char C;
	C=getchar();
	for(i=0;C!='\n'&&C!=EOF && C!='\r';)
	{
		a[i]=C;
		if(C<s || C>e)
		{
			cout<<"Invalid String! "<<a[i]<<" Not Between "<<s<<" and "<<e<<" .\n";
			exit(0);
		}
		i++;
		C=getchar();
		
	}
	a[i]=0;
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
		if(c!='\n'&&c!=' '&&c!=EOF&&c!='\r')
		{
			cout<<"Not Valid Integer\n";
			exit(0);
		}
	}
	return a;
}

void heapify(char* a[MAX],int n,int i)
{
    int l=2*i;
    int r=2*i+1;
    int max;
    if(l<=n-1 && isLess(a[i],a[l]))
        max=l;
    else
        max=i;
    if(r<=n-1 && isLess(a[max],a[r]))
        max=r;
    if(max!=i)
    {
        char *t;
        t=a[i];
		a[i]=a[max];
		a[max]=t;
		heapify(a,n,max);
    }
}
void makeHeap(char* a[MAX],int n)
{
    for(int i=(n-1)/2;i>=0;i--)
        heapify(a,n,i);
}

void hSort(char* a[100], int n)
{
    makeHeap(a,n);
    for(int i=(n-1);i>=(1);i--)
    {
        char* t;
        t=a[0];
		a[0]=a[i];
		a[i]=t;
		n--;
        heapify(a,n,0);
    }
}

int main()
{
	int size;
	size=getInt();
	char *p[MAX];
	for(int i=0;i<size;i++)
	{
		checkString(A[i],'A','Z');
		p[i]=A[i];
	}
	
	
	hSort(p,size);
	
	for(int i=0;i<size;i++)
		cout<<p[i]<<'\n';
	
}
