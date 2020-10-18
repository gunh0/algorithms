#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXNUM 100000

struct Node {
	int location;
	int time;
	int from;
};

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> answer;
	int dp[MAXNUM + 1];
	memset(dp, -1, sizeof(dp));

	queue<Node> q;

	Node start = { n, 0, n };
	dp[n] = n;
	q.push(start);

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.location == k) {
			printf("%d\n", cur.time);

			int trace = cur.location;
			while (trace != n) {
				answer.push_back(trace);
				trace = dp[trace];
			}
			answer.push_back(trace);

			reverse(answer.begin(), answer.end());
			int len = answer.size();
			for (int i = 0; i < len; i++) {
				printf("%d ", answer[i]);
			}
			printf("\n");
			return 0;
		}

		int left = cur.location - 1;
		int right = cur.location + 1;
		int jump = cur.location * 2;

		if (left >= 0 && dp[left] == -1) {
			Node temp = { left, cur.time + 1, cur.location };
			dp[left] = temp.from;

			q.push(temp);
		}
		if (right <= MAXNUM && dp[right] == -1) {
			Node temp = { right, cur.time + 1, cur.location };
			dp[right] = temp.from;

			q.push(temp);
		}
		if (jump <= MAXNUM && dp[jump] == -1) {
			Node temp = { jump, cur.time + 1, cur.location };
			dp[jump] = temp.from;

			q.push(temp);
		}
	}

	return 0;
}