#include <iostream>
using namespace std;

int Find(int n) {
	int a, b;
	if (n <= 1) return 0;
	a = Find(n / 3) + (n % 3) + 1;
	b = Find(n / 2) + (n % 2) + 1;
	return a < b ? a : b;
}

int main() {
	int n = 0;
	cin >> n;
	cout << Find(n);
}