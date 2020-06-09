#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int N;
int board[2001];
int cache[2001][2001];
vector<int> res;

int palin(int s, int e) {
	if (s >= e) {
		return 1;

	}
	int& ret = cache[s][e];
	if (ret != -1) return ret;

	if (board[s] == board[e]) {
		return ret = palin(s + 1, e - 1);
	}
	else { return 0; }
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {

		scanf("%d", &board[i]);
	}
	memset(cache, -1, sizeof(cache));
	int M;
	cin >> M;
	while (M--) {

		int S, E;
		scanf("%d %d", &S, &E);

		res.push_back(palin(S, E));
	}

	for (int i = 0; i < (int)res.size(); ++i) {
		printf("%d\n", res[i]);
	}

	return 0;
}