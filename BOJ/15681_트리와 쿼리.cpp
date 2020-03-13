#include<iostream>
#include<vector>
using namespace std;

int N, R, Q;
vector<int> dp;
vector<bool> visited;

int solve(vector<vector<int>>& tree, int search) {
	int& result = dp[search];
	if (result != 0) return result;

	result = 1;
	for (const int& child : tree[search]) {
		if (visited[child] == false) {
			visited[child] = true;
			result += solve(tree, child);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> R >> Q;
	vector<vector<int>> tree(N);

	int U, V;
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		tree[U - 1].push_back(V - 1);
		tree[V - 1].push_back(U - 1);
	}

	dp.resize(N);
	visited.resize(N);

	visited[R - 1] = true;
	solve(tree, R - 1);

	int solveNode;
	for (int i = 0; i < Q; i++) {
		cin >> solveNode;
		cout << solve(tree, solveNode - 1) << '\n';
	}

	return 0;
}