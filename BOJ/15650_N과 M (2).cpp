#include <iostream>

using namespace std;

#define MAX 8 + 1

void dfs(int _n, int _m, int _lists[], bool _check[], int cnt) {
	if (cnt == _m) {
		// 오름차순인지 확인(아니라면 출력안하고 재귀함수 종료)
		for (int i = 0; i < _m - 1; i++) {
			if (_lists[i] > _lists[i + 1]) return;
		}

		for (int i = 0; i < _m; i++) {
			cout << _lists[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= _n; i++) {
		if (!_check[i]) {
			_check[i] = true;
			_lists[cnt] = i;
			dfs(_n, _m, _lists, _check, cnt + 1);
			_check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int lists[MAX] = { 0, };
	bool check[MAX] = { 0, };

	cin >> n >> m;

	dfs(n, m, lists, check, 0);

	return 0;
}