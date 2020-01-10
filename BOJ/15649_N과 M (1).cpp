#include <iostream>

using namespace std;

#define MAX 8+1

int n, m;
int lists[MAX];
bool check[MAX] = { 0, };


void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << lists[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = true;
			lists[cnt] = i;
			dfs(cnt + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	dfs(0);

	return 0;
}
