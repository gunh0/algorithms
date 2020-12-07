#include <algorithm>
#include <iostream>
#include <vector>

#define x first
#define y second
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

ll arr[101010];
ll sum[101010];
ll dp[2][101010];
int track[222][101010];
vector<int> ans;

struct CHT
{
	ll a[101010], b[101010], c[101010];
	int pv, top;

	void init()
	{
		pv = top = 0;
	}

	ll f(ll idx, ll x)
	{
		return a[idx] * x + b[idx];
	}

	void insert(ll aa, ll bb, ll cc)
	{
		if (top >= 1 && aa == a[top - 1])
		{
			c[top - 1] = cc;
			return;
		}
		while (top >= 2 && (b[top - 1] - b[top - 2]) * (a[top - 2] - aa) >= (bb - b[top - 2]) * (a[top - 2] - a[top - 1]))
			top--;
		a[top] = aa;
		b[top] = bb;
		c[top] = cc;
		top++;
		if (pv >= top)
			pv = top - 1;
	}

	p get(ll x)
	{
		while (pv + 1 < top && a[pv + 1] * x + b[pv + 1] > a[pv] * x + b[pv])
			pv++;
		return { f(pv, x), c[pv] };
	}
} cht;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i], sum[i] = sum[i - 1] + arr[i];

	for (int i = 1; i <= k; i++)
	{
		cht.init();
		cht.insert(0, 0, 0);
		for (int j = 1; j <= n; j++)
		{
			auto now = cht.get(sum[j]);
			dp[i & 1][j] = now.x;
			track[i][j] = now.y;
			cht.insert(sum[j], dp[i - 1 & 1][j] - sum[j] * sum[j], j);
		}
	}
	cout << dp[k & 1][n] << "\n";

	int now = n;
	ans.push_back(-1);
	for (int i = k; i >= 1; i--)
	{
		ans.push_back(track[i][now]);
		now = track[i][now];
	}
	sort(all(ans));
	for (int i = 1; i <= k; i++)
	{
		if (!ans[i])
			ans[i] = 1;
		if (ans[i] <= ans[i - 1])
			ans[i] = ans[i - 1] + 1;
	}
	for (int i = 1; i <= k; i++)
		cout << ans[i] << " ";
}