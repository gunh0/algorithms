#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool COMP(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int N;
vector<pair<int, int>> v;

int main()
{
	scanf("%d", &N);
	for (int i = 0, a, b; i < N; ++i)
	{
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}
	
	sort(v.begin(), v.end(), COMP);
	
	for (auto &i : v)
	{
		printf("%d %d\n", i.first, i.second);
	}
	
	return 0;
}