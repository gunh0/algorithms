#include <iostream>
#include <algorithm>

using namespace std;
pair<int, int> a[6];

int three(int i, int j, int k) {
	int l = a[i].first + a[j].first + a[k].first;
	int r = max(a[i].second, max(a[j].second, a[k].second));
	return l * r;
}

int twoonone(int i, int j, int k) {
	int l = max(a[i].first, a[j].first) + a[k].first;
	int r = max(a[i].second + a[j].second, a[k].second);
	return l * r;
}

int t;

int main() {
	cin >> t;
	while (t--) {
		for (int i = 0; i < 3; i++) {
			cin >> a[i].first >> a[i].second;
			a[i + 3].first = a[i].second;
			a[i + 3].second = a[i].first;
		}
		int r = 1e9;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 6; k++) {
					if (i % 3 == j % 3 || j % 3 == k % 3 || k % 3 == i % 3)continue;
					r = min(r, three(i, j, k));
					r = min(r, twoonone(i, j, k));
				}
			}
		}
		printf("%d\n", r);
	}
	return 0;
}