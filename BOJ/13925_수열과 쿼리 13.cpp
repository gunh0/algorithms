#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

ll arr[101010];
ll tree[404040];
ll lazy[404040][2];
const ll mod = 1e9 + 7;

ll init(int node, int s, int e)
{ // init(1, 1, n)
    if (s == e)
        return tree[node] = arr[s];
    int m = s + e >> 1;
    return tree[node] = (init(node * 2, s, m) + init(node * 2 + 1, m + 1, e)) % mod;
}

void update_lazy(int node, int s, int e)
{
    ll &a1 = lazy[node][0];
    ll &b1 = lazy[node][1];
    if (a1 == 1 && b1 == 0)
        return;
    if (s != e)
    {
        for (int i = node * 2; i <= node * 2 + 1; i++)
        {
            ll a2 = lazy[i][0], b2 = lazy[i][1];
            lazy[i][0] = a1 * a2;
            lazy[i][0] %= mod;
            lazy[i][1] = a1 * b2 + b1;
            lazy[i][1] %= mod;
        }
    }
    tree[node] = a1 * tree[node] + (e - s + 1) * b1;
    tree[node] %= mod;
    a1 = 1, b1 = 0;
}

void update(int node, int s, int e, int l, int r, ll mul, ll sum)
{
    update_lazy(node, s, e);
    if (r < s || e < l)
        return;
    if (l <= s && e <= r)
    {
        lazy[node][0] *= mul;
        lazy[node][0] %= mod;
        lazy[node][1] *= mul;
        lazy[node][1] %= mod;
        lazy[node][1] += sum;
        lazy[node][1] %= mod;
        update_lazy(node, s, e);
        return;
    }

    int m = s + e >> 1;
    update(node * 2, s, m, l, r, mul, sum);
    update(node * 2 + 1, m + 1, e, l, r, mul, sum);
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % mod;
}

ll query(int node, int s, int e, int l, int r)
{
    update_lazy(node, s, e);
    if (r < s || e < l)
        return 0;
    if (l <= s && e <= r)
        return tree[node] % mod;
    int m = s + e >> 1;
    return (query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    init(1, 1, n);
    for (int i = 0; i < 404040; i++)
        lazy[i][0] = 1, lazy[i][1] = 0;
    int m;
    cin >> m;
    while (m--)
    {
        int op;
        cin >> op;
        ll x, y, v;
        cin >> x >> y;
        if (op != 4)
            cin >> v;
        if (op == 1)
        {
            update(1, 1, n, x, y, 1, v);
        }
        else if (op == 2)
        {
            update(1, 1, n, x, y, v, 0);
        }
        else if (op == 3)
        {
            update(1, 1, n, x, y, 0, v);
        }
        else
        {
            cout << query(1, 1, n, x, y) << "\n";
        }
    }
}