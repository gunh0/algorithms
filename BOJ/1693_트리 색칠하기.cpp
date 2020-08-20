#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

typedef pair<int, int> PAIR;
vector<int> adj[100004];
vector<int> child[100004];
const int MAX_COLOR = 20;
bool isVisited[100004];
int n;
int D[100004][MAX_COLOR + 1];

void fill_table(int root) {
	for (auto c : adj[root]) {
		if (isVisited[c])
			continue;
		isVisited[c] = true;
		child[root].push_back(c);
		fill_table(c);
	}

	PAIR min1 = { 0x7ffff000, 100 };
	PAIR min2 = { 0x7fffffff, 100 };

	for (int i = 1; i <= MAX_COLOR; i++) {
		int cost = i;
		for (auto c : child[root])
			cost += D[c][i];
		if (make_pair(cost, i) < min1) {
			min2 = min1;
			min1 = { cost, i };
		}
		else if (make_pair(cost, i) < min2)
			min2 = { cost, i };
	}
	for (int i = 0; i <= MAX_COLOR; i++)
		D[root][i] = min1.X;
	D[root][min1.Y] = min2.X;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	isVisited[1] = true;
	fill_table(1);
	printf("%d", D[1][0]);
	return 0;
}