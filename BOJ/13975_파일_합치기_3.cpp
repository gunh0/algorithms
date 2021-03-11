#include <iostream>
#include <queue>

using namespace std;

// This program computes the minimal total cost to merge K files into one.
// It uses a min-heap (priority queue) to always merge the two smallest files first.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int K;
        cin >> K;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < K; ++i)
        {
            long long size;
            cin >> size;
            pq.push(size);
        }
        long long total_cost = 0;
        while (pq.size() > 1)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            total_cost += a + b;
            pq.push(a + b);
        }
        cout << total_cost << '\n';
    }
    return 0;
}