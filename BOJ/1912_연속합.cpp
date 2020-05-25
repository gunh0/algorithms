#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template< class T, class Compare >
T max(std::initializer_list<T> ilist, Compare comp)
{
    return *std::max_element(ilist.begin(), ilist.end(), comp);
}

int main() {
    int n, i;
    int ans = 0;

    cin >> n;
    vector<int> arr;
    vector<int> dp;

    int tmp = 0;
    for (i = 0; i < n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    dp.push_back(arr[0]);
    ans = dp[0];

    for (i = 1; i < n; i++) {
        dp.push_back(max(dp[i - 1] + arr[i], arr[i]));
        ans = max(ans, dp[i]);
    }

    printf("%d", ans);

    return 0;
}