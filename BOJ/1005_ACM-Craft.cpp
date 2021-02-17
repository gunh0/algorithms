#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // Optimize I/O speed
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); // Added cout.tie for additional optimization

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        // Pre-allocate vectors with exact size needed
        vector<int> buildTime(N + 1);
        vector<vector<int>> adj(N + 1);
        vector<int> indegree(N + 1);
        vector<int> dp(N + 1);

        // Input building times
        for (int i = 1; i <= N; ++i) {
            cin >> buildTime[i];
            dp[i] = buildTime[i]; // Initialize DP array simultaneously
        }

        // Input dependencies and calculate indegree
        for (int i = 0; i < K; ++i) {
            int X, Y;
            cin >> X >> Y;
            adj[X].push_back(Y);
            ++indegree[Y];
        }

        int W;
        cin >> W;

        // Topological sort using queue
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process buildings in topological order
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // Reserve capacity for adjacency list to avoid reallocation
            for (const int &next: adj[current]) {
                dp[next] = max(dp[next], dp[current] + buildTime[next]);
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << dp[W] << '\n';
    }
    return 0;
}