#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

int arr[1000001];
int lis[1000001];
pii ans[1000001];
stack<int> s;

int _lower_bound(int start, int end, int target)
{
    int mid;

    while (start < end)
    {
        mid = (start + end) / 2;

        if (lis[mid] < target)
            start = mid + 1;

        else
            end = mid;
    }

    return end + 1;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int pLis = 0, pArr = 1;

    lis[pLis] = arr[0];
    ans[0].first = 0;
    ans[0].second = arr[0];

    while (pArr < n)
    {
        if (lis[pLis] < arr[pArr])
        {
            lis[++pLis] = arr[pArr];

            ans[pArr].first = pLis;
            ans[pArr].second = arr[pArr];
        }

        else
        {
            int pos = _lower_bound(0, pLis, arr[pArr]);
            lis[pos - 1] = arr[pArr];

            ans[pArr].first = pos - 1;
            ans[pArr].second = arr[pArr];
        }

        pArr++;
    }

    printf("%d\n", pLis + 1);

    int t = pLis;

    for (int i = n - 1; i >= 0; i--)
    {
        if (ans[i].first == t)
        {
            s.push(ans[i].second);
            t--;
        }
    }

    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }

    return 0;
}
