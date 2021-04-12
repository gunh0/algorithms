#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
using namespace std;

static int lcs_bitset(const string &s1, const string &s2)
{
    const string &a = (s1.size() <= s2.size()) ? s1 : s2;
    const string &b = (s1.size() <= s2.size()) ? s2 : s1;

    const int n = (int)a.size();
    const int m = (int)b.size();
    if (n == 0 || m == 0)
        return 0;

    const int W = (n + 63) >> 6;
    const int lastBits = n & 63;
    const uint64_t lastMask = (lastBits == 0) ? ~0ULL : ((1ULL << lastBits) - 1ULL);

    vector<uint64_t> masks(26LL * W, 0ULL);
    for (int i = 0; i < n; ++i)
    {
        const int ch = a[i] - 'A';
        const int w = i >> 6;
        const int bit = i & 63;
        masks[(long long)ch * W + w] |= (1ULL << bit);
    }

    vector<uint64_t> S(W, 0ULL), X(W), Y(W), D(W);

    for (int i = 0; i < m; ++i)
    {
        const int ch = b[i] - 'A';
        const long long base = 1LL * ch * W;

        for (int w = 0; w < W; ++w)
        {
            X[w] = S[w] | masks[base + w];
        }

        uint64_t carry = 1ULL;
        for (int w = 0; w < W; ++w)
        {
            const uint64_t nextCarry = S[w] >> 63;
            Y[w] = (S[w] << 1) | carry;
            carry = nextCarry;
        }

        uint64_t borrow = 0ULL;
        for (int w = 0; w < W; ++w)
        {
            const uint64_t yw = Y[w] + borrow;
            const uint64_t borrow1 = (Y[w] + borrow < Y[w]) ? 1ULL : 0ULL;
            const uint64_t borrow2 = (X[w] < yw) ? 1ULL : 0ULL;
            D[w] = X[w] - yw;
            borrow = (borrow1 | borrow2);
        }

        for (int w = 0; w < W; ++w)
        {
            S[w] = X[w] & ~D[w];
        }
        S[W - 1] &= lastMask;
    }

    int answer = 0;
    for (int w = 0; w < W; ++w)
    {
        answer += __builtin_popcountll(S[w]);
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    if (!getline(cin, s1))
        return 0;
    if (!getline(cin, s2))
        return 0;

    cout << lcs_bitset(s1, s2) << '\n';
    return 0;
}
