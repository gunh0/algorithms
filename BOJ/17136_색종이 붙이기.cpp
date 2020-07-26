#include <iostream> 
#include <algorithm> 

using namespace std;

const int MAX = 10;
const int INF = 987654321;
int arr[MAX][MAX];
int cnt, result;
int paper[6] = { 0, 5, 5, 5, 5, 5 };
void func(int y, int x) {
	if (x == MAX) {
		func(y + 1, 0);
		return;
	}
	if (y == MAX) {
		result = min(result, cnt);
		return;
	}
	if (arr[y][x] == 0) {
		func(y, x + 1);
		return;
	}
	for (int len = 5; len >= 1; len--) {
		if (paper[len] == 0 || y + len > MAX || x + len > MAX) { continue; }
		bool flag = true;
		for (int j = 0; j < len; j++) {
			for (int k = 0; k < len; k++) {
				if (arr[y + j][x + k] == 0) {
					flag = false; break;
				}
			}
			if (flag == false) { break; }
		}
		if (flag == false) { continue; }
		for (int j = 0; j < len; j++) {
			for (int k = 0; k < len; k++) {
				arr[y + j][x + k] = 0;
			}
		} paper[len]--; cnt++;
		func(y, x + len);
		for (int j = 0; j < len; j++) {
			for (int k = 0; k < len; k++) {
				arr[y + j][x + k] = 1;
			}
		} paper[len]++; cnt--;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> arr[i][j];
		}
	} result = INF; func(0, 0);
	if (result == INF) cout << -1 << "\n";
	else cout << result << "\n";
	return 0;
}