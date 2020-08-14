#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 1e3;
int N, M;
vector<int> works[MAX];
int worker2work[MAX], work2worker[MAX];
bool visited[MAX];

bool func(int worker) {
	for (int i = 0; i < works[worker].size(); i++) { int workNum = works[worker][i]; if (visited[workNum]) { continue; } visited[workNum] = true; if (work2worker[workNum] == -1 || func(work2worker[workNum])) { worker2work[worker] = workNum; work2worker[workNum] = worker; return true; } } return false;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int cnt; cin >> cnt; for (int j = 0; j < cnt; j++) { int work; cin >> work; works[i].push_back(work - 1); }
	}
	memset(worker2work, -1, sizeof(worker2work));
	memset(work2worker, -1, sizeof(work2worker));

	int result = 0;
	for (int worker = 0; worker < N; worker++) {
		if (worker2work[worker] == -1) {
			memset(visited, false, sizeof(visited));
			if (func(worker)) result++;
		}
	} cout << result << "\n"; return 0;
	return 0;
}
