#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

struct info {
	int node, cost;
	info(int n, int c) {
		node = n;
		cost = c;
	}

	bool operator<(const info& d)const {
		return cost > d.cost;
	}
};

vector<info> arr[801];

vector<int> dijk(int start, int N) {
	vector<int> dist(N + 1, 987654321);
	dist[start] = 0;
	priority_queue<info> q;
	q.push(info(start, 0));

	while (!q.empty()) {
		int node = q.top().node;
		int cost = q.top().cost;
		q.pop();
		if (dist[node] < cost) continue;
		for (int i = 0; i < arr[node].size(); i++) {
			int nextN = arr[node][i].node;
			int nextCost = arr[node][i].cost;
			if (dist[nextN] > dist[node] + nextCost) {
				dist[nextN] = dist[node] + nextCost;
				q.push(info(nextN, dist[nextN]));
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back(info(b, c));
		arr[b].push_back(info(a, c));
	}

	int node1, node2, ans1 = 0, ans2 = 0;
	cin >> node1 >> node2;

	vector<int> d;
	d = dijk(1, N);
	ans1 += d[node1];
	ans2 += d[node2];

	d = dijk(node1, N);
	ans1 += d[node2];
	ans2 += d[N];

	d = dijk(node2, N);
	ans1 += d[N];
	ans2 += d[node1];

	int res = min(ans1, ans2);
	if (res >= 987654321 || res < 0) cout << -1;
	else cout << res;

	return 0;
}