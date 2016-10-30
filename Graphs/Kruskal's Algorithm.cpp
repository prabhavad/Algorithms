//Kruskal's Algorithm
//Output: Adjacency Matrix of MST

//Graph Input:
//Number of Vertices
//Number of Edges
//<Node_1> <Node_2> <Edge_Cost>
// ..
// ..
#include <iostream>
#include <vector>
#include <algorithm>

#define Max 2147483647
using namespace std;
struct Edge {
	int n1, n2, c;
	Edge() {}
	Edge(int a, int b, int d) {
		n1 = a, n2 = b, c = d;
	}
};

class dSet {
	std::vector<int> id;
	std::vector<int> rank;

  public:
	dSet(int N) {
		id.resize(N);
		rank.resize(N);
		for (int i = 0; i < N; i++) {
			id[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x) {
		if (id[x] != x)
			id[x] = find(id[x]);
		return id[x];
	}
	bool Union(int x, int y) {
		int first = find(x);
		int second = find(y);
		if (first == second)
			return false;
		if (rank[first] > rank[second]) {
			id[second] = first;
		}
		else if (rank[first] < rank[second]) {
			id[first] = second;
		}
		else if (second != first) {
			id[second] = first;
			rank[first]++;
		}
		return true;
	}
};

int Tree[1000][1000];
int main() {
	int n, e, cost = 0;
	cin >> n >> e;
	dSet S(n);
	if (n <= 0) {
		cout << "Number of nodes should be Positive Integer\n";
		return 0;
	}
	if (e > (n * n - n) / 2) {
		cout << "Number of edges greater than upper bound\n";
		return 0;
	}
	if (e < 0) {
		cout << "Number of edges should be Positive Integer\n";
		return 0;
	}
	Edge E[10000];
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a < 0 || a > n || b < 0 || b > n) {
			cout << "Invalid Edge\n";
			return 0;
		}
		E[i] = Edge(a, b, c);
	}
	std::sort(E, E + e, [](const Edge &a, const Edge &b) -> bool { return a.c < b.c; });
	int T[100000] = {0};
	int j = 0;

	for (int i = 0; j < n; i++) {
		if (S.Union(E[i].n1, E[i].n2)) {
			Tree[E[i].n1][E[i].n2] = E[i].c;
			Tree[E[i].n2][E[i].n1] = E[i].c;
			cost += E[i].c;
		}
		if (!T[E[i].n1]) {
			j++;
			T[E[i].n1]++;
		}
		if (!T[E[i].n2]) {
			j++;
			T[E[i].n2]++;
		}
	}
	cout << cost << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << Tree[i][j] << ' ';
		cout << '\n';
	}
}
