//Double Hashing
//Options
	// 1 -> Insert an Integer (I/o: 1 <Integer>)
	// 2 -> Search for an Integer (I/o: 2 <Integer>)
	// 0 -> Exit

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
#include<cstring>
#define MAX 100000
#define NIL INT_MIN
#define A 0.61803398875
using namespace std;

int H[MAX + 1];
int M;
void reset()
{
    for(int i = 0; i < MAX + 1; i++)
        H[i] = NIL;
}
int hf1(int k)
{
	if(k>=0)
		return (k % M);
	else
		return (hf1(k+M));
		
}
int hf2(double k)
{
    return (M * (fmod((k * A), 1)));
}
int hF(int k, int i)
{
	if(k>=0)
		return (hf1(k) + i * hf2(k)) % M;
	else
		return hf1((hf1(k) + i * hf2(k)));
}

void insert(int H[], int a)
{
    int i = 0, key;
    do
    {
        key = hF(a, i);

        cout << key << ' ';
        if(H[key] == NIL)
        {
            H[key] = a;
            return;
        }
        else
            i = i + 1;
    }
    while(i < M);
    cout << "Overflow!\n";
}

int search(int H[], int a)
{

    int key, i = 0;
    do
    {
        key = hF(a, i);
        cout << key << ' ';
        if(H[key] == a)
        {
            return 1;
        }
        else
            i = i + 1;
    }
    while(i < M && H[key] != NIL);
    return 0;
}

int main()
{
    reset();
    int a, b;
    if(!(cin >> M))
    {
        cout << "Invalid Input\n";
        return 0;
    }
    if(M < 0)
    {
        cout << "-Ve Size Not Allowed\n";
        return 0;
    }
    if(M == 0)
    {
        cout << "0 Size not Allowed\n";
    }
    while(1)
    {
        if(!(cin >> a))
        {
            cout << "Invalid Option\n";
            break;
        }
        switch(a)
        {
		case 0:
			return 0;
        case 1:
            if(cin.peek() == ' ')
                cin >> b;
            else
                cout << "Option Not Complete\n";
            insert(H, b);
            cout << '\n';
            break;
        case 2:
            if(cin.peek() == ' ')
                cin >> b;
            else
                cout << "Option Not Complete\n";
            if(search(H, b))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;
        default:
            cout << "Wrong Choice\n";
        }
    }
}
