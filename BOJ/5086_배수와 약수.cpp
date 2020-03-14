#include <iostream>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {

	while (true) {
		int n, k; cin >> n >> k;
		if (n + k == 0) {
			break;
		}

		if (k % n == 0 && n % k == n) {
			cout << "factor" << "\n";
		}
		else if (n % k == 0 && k % n == k) {
			cout << "multiple" << "\n";
		}
		else {
			cout << "neither" << "\n";
		}
	}

	return 0;
}