#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

int get_max(int a, int b) { return a > b ? a : b; }

int main() {

	int n, i, j, len = 0;

	cin >> n;
	vector<vector<int>> v(n);
	vector<int> lis;
	for (i = 0; i < n; i++) {
		v[i] = vector<int>(2);
		cin >> v[i][0] >> v[i][1];
	}

	sort(v.begin(), v.end(), comp);

	for (i = 0; i < n; i++) {
		lis.push_back(1);
		for (j = 0; j < i; j++) {
			if (lis[j] + 1 > lis[i] && v[i][1] > v[j][1]) lis[i] = lis[j] + 1;
		}
		len = get_max(len, lis[i]);
	}

	printf("%d\n", n - len);
	return 0;
}