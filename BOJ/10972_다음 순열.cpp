#include<iostream>
#include<algorithm>

using namespace std;

int arr[10010];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int idx = -1;
	for (int i = n - 1; i > 0; i--) {
		if (arr[i - 1] < arr[i]) {
			idx = i;
			break;
		}
	}

	if (idx == -1) {
		puts("-1");
		return 0;
	}

	for (int i = n - 1; i >= idx; i--) {
		if (arr[idx - 1] < arr[i]) {
			swap(arr[idx - 1], arr[i]);
			break;
		}
	}

	sort(arr + idx, arr + n);

	for (int i = 0; i <= n - 1; i++)
		printf("%d ", arr[i]);

	return 0;
}