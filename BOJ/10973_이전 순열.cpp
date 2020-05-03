#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int n, i, k, arr[10000];

int main() {
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	if (n == 1) {
		printf("-1");
		return 0;
	}

	int p = n - 1;

	while (arr[p - 1] < arr[p]) {
		p--;
		if (p == 0)
			break;
	}

	if (p == 0) {
		printf("-1");
		return 0;
	}

	for (k = n - 1; arr[p - 1] < arr[k]; --k);

	int tmp = arr[p - 1];
	arr[p - 1] = arr[k];
	arr[k] = tmp;

	sort(arr + p, arr + n, greater<int>());

	for (i = 0; i < n; ++i)
		printf("%d ", arr[i]);

	return 0;
}
