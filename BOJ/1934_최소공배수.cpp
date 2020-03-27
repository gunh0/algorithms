#include <iostream>

using namespace std;

int gcd(int x, int y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main() {
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		printf("%d\n", (a * b) / gcd(a, b));
	}
	return 0;
}