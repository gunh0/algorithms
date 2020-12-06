#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

#define MAX_N 1000000

typedef long long ll;
using namespace std;

ll n, m, k, seg[4 * MAX_N], lazy[4 * MAX_N], a, b, c, d;

void update_lazy(ll node, ll x, ll y)
{
	if (!lazy[node])
		return;
	seg[node] += (y - x + 1) * lazy[node];
	if (x != y)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

ll update(ll lo, ll hi, ll val, ll node, ll x, ll y)
{
	update_lazy(node, x, y);
	if (y < lo || hi < x)
		return seg[node];
	if (lo <= x && y <= hi)
	{
		lazy[node] += val;
		update_lazy(node, x, y);
		return seg[node];
	}
	ll mid = (x + y) >> 1;
	return seg[node] = update(lo, hi, val, node * 2, x, mid) + update(lo, hi, val, node * 2 + 1, mid + 1, y);
}

ll query(ll lo, ll hi, ll node, ll x, ll y)
{
	update_lazy(node, x, y);
	if (y < lo || hi < x)
		return 0;
	if (lo <= x && y <= hi)
		return seg[node];
	ll mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main()
{
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a);
		update(i, i, a, 1, 1, n);
	}
	for (int i = 0; i < m + k; i++)
	{
		scanf("%lld", &a);
		if (a == 1)
		{
			scanf("%lld%lld%lld", &b, &c, &d);
			update(b, c, d, 1, 1, n);
		}
		else
		{
			scanf("%lld%lld", &b, &c);
			printf("%lld\n", query(b, c, 1, 1, n));
		}
	}
	return 0;
}
