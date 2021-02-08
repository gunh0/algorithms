// N개의 수 A1, A2, ..., AN과 L이 주어졌을 때, i번째 수부터 i-L+1번째 수까지의 최솟값을 찾는 프로그램
// 입력: 첫째 줄에 N과 L이 주어진다. (1 ≤ L ≤ N ≤ 5,000,000) 둘째 줄에는 A1, A2, ..., AN이 주어진다. (-10^9 ≤ Ai ≤ 10^9)
// 출력: 첫째 줄에 Di를 공백으로 구분하여 순서대로 출력한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> getMinValues(const vector<int> &arr, int L) {
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (int i = 0; i < arr.size(); ++i) {
        // 현재 윈도우의 범위를 유지하기 위해 큐에서 벗어난 값 제거
        while (!minHeap.empty() && minHeap.top().second <= i - L) {
            minHeap.pop();
        }

        // 현재 값과 인덱스를 큐에 추가
        minHeap.push({arr[i], i});

        // 현재 윈도우의 최솟값을 결과에 추가
        result.push_back(minHeap.top().first);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> result = getMinValues(A, L);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}