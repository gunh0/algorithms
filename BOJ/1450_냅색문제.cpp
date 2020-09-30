#include <iostream>
#include <algorithm>

using namespace std;

#define mxl 1 << 15
#define mxn 15
int s1[mxl], s2[mxl], l1, l2, a[mxn];

void dfs(int s, int e, int sum, int w, int m)
{
    if (sum > m)
        return;
    if (s == e)
    {
        if (w == 1)
            s1[l1++] = sum;
        else
            s2[l2++] = sum;
        return;
    }
    dfs(s + 1, e, sum, w, m);
    dfs(s + 1, e, sum + a[s], w, m);
}

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;

    for (int i = 0; i < n / 2; i++)
        cin >> a[i];
    dfs(0, n / 2, 0, 1, m);
    sort(s1, s1 + l1);

    for (int i = n / 2; i < n; i++)
        cin >> a[i - n / 2];
    dfs(0, n - n / 2, 0, 2, m);
    sort(s2, s2 + l2);

    for (int i = 0, j = l2 - 1; i < l1 && j >= 0; i++)
    {
        while (s1[i] + s2[j] > m)
            j--;
        ans += j + 1;
    }
    printf("%d", ans);

    return 0;
}