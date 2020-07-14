#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

#define MAX 100500

using namespace std;
bool visit[MAX + 1] = { 0 };
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (n == k) printf("0\n");
	else {
		queue<int> q; int depth = 0;
		q.push(n); visit[n] = true; while (!q.empty()) {
			int size = q.size(); for (int i = 0; i < size; i++) {
				int v = q.front(); q.pop();
				if (v == k) {
					printf("%d\n", depth);
					queue<int> empty;
					q = empty; break;
				}
				if (v - 1 >= 0 && !visit[v - 1]) {
					q.push(v - 1); visit[v - 1] = true;
				}
				if (v + 1 <= MAX && !visit[v + 1]) {
					q.push(v + 1);
					visit[v + 1] = true;
				}
				if (v * 2 <= MAX && !visit[v * 2]) {
					q.push(v * 2);
					visit[v * 2] = true;
				}
			} depth++;
		}
	} return 0;
}
