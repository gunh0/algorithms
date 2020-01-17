#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <cstdlib>

using namespace std;

int grid[21][21];
int n;
bool check[21] = { false, };
int list[10];
int list2[10];
int ans = INT_MAX;

int get_min(int a, int b) { return a < b ? a : b; }

void dfs(int cur, int cnt) {
	int i;
	if (cnt == n / 2) {
		int j, k;
		int start = 0;
		int link = 0;

		k = 0;
		for (i = 1; i <= n; i++) {
			if (!check[i]) {
				list2[k] = i;
				k++;
			}
		}

		for (j = 0; j < n / 2; j++) {
			for (k = 1; k <= n; k++) {
				if (list[j] != k && check[k]) {
					start += grid[list[j]][k];
				}
				if (list2[j] != k && !check[k]) {
					link += grid[list2[j]][k];
				}
			}
		}

		ans = get_min(ans, abs(link - start));
		return;
	}

	for (i = cur + 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = true;
			list[cnt] = i;
			dfs(i, cnt + 1);
			check[i] = false;
		}
	}
}

int main() {

	int i, j;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &grid[i][j]);
		}
	}

	dfs(0, 0);
	printf("%d\n", ans);

	return 0;
}