//Hashing with Chaining
//Options
	// 1 -> Insert an Integer (I/o: 1 <Integer>)
	// 2 -> Search for an Integer (I/o: 2 <Integer>)
	// 0 -> Exit
	
#include<iostream>
#include<cstdlib>
using namespace std;
int M;
struct node
{
    int num;
    node *prev;
    node *next;
    node()
    {
        prev = next = 0;
    }
};

struct dList
{
    node* front;
    node* end;
    int size;

    dList()
    {
        size = 0;
        front = end = 0;
    }

    void insert(int a)
    {
        node* t = new node;
        if(!t)
        {
            cout << "Overflow\n";
        }
        t -> num = a;
        if(size == 0)
        {
            front = end = t;
        }
        else
        {
            t -> prev = end;
            end -> next = t;
            end = t;
        }
        size++;
    }

    void remove(node *n)
    {
        if(n == front)
        {
            front = front -> next;
            delete n;
        }
        else if(n == end)
        {
            end = end -> prev;
            delete n;
        }
        else
        {
            n -> next -> prev = n -> prev;
            n -> prev -> next = n -> next;
            delete n;
        }
        size--;
    }

    node* search(int a)
    {
        node* t = front;
        if(size == 0)
            return 0;
        for(int i = 0 ; i < size ; i++, t = t -> next)
            if(t -> num == a)
                return t;
        return 0;

    }
    int show()
    {
        node* t = front;
        if(size == 0)
            return 0;
        for(int i = 0 ; i < size ; i++, t = t -> next)
            cout << t -> num << ' ';
        cout << '\n';
        return 1;
    }
};

struct Hash
{
    dList H[1253];

    int	hashF(int a)
    {
		if(a>=0)
			return a % M;
			
		return hashF(a+M);
    }

    void insert(int a)
    {
		cout<<hashF(a)<<'\n';
        H[hashF(a)].insert(a);
    }

    node* search(int a)
    {
		cout<<hashF(a)<<' ';
        return H[hashF(a)].search(a);
    }
    void remove(int a)
    {
        if(search(a))
        {
            H[hashF(a)].remove(search(a));
            cout << "Deleted\n";
        }
        else
            cout << "Not Found\n";
    }
};

int main()
{
    
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
    Hash H;
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
            H.insert(b);
            
            break;
        case 2:
            if(cin.peek() == ' ')
                cin >> b;
            else
                cout << "Option Not Complete\n";
            if(H.search(b))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;
        default:
            cout << "Wrong Choice\n";
        }
    }
}
