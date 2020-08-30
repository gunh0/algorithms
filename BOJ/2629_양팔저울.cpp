#include <iostream>
#include <cmath>

using namespace std;

#define MAX 30*500

int n, sinker[30], m, marble[7];
bool visited[31][15001];

void backtracking(int result, int depth) {
	if (depth > n)return;
	if (visited[depth][result])return;

	visited[depth][result] = true;

	backtracking(result + sinker[depth], depth + 1);
	backtracking(abs(result - sinker[depth]), depth + 1);
	backtracking(result, depth + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> sinker[i];
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> marble[i];
	}
	backtracking(0, 0);
	for (int i = 0; i < m; ++i) {
		if (marble[i] > MAX) {
			cout << "N ";
		}
		else if (visited[n][marble[i]]) {
			cout << "Y ";
		}
		else
			cout << "N ";
	}
	cout << endl;
	return 0;
}