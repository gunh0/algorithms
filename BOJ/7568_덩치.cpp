#include <iostream>

using namespace std;

int n, a[3][51];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[0][i] >> a[1][i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) { continue; }
			if (a[0][i] < a[0][j] && a[1][i] < a[1][j]) { a[2][i]++; }
		}
	}

	for (int i = 0; i < n; i++)
		cout << a[2][i] + 1 << " ";
	return 0;
}
