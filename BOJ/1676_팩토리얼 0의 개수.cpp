#include <iostream>

using namespace std;

int main() {
	int two, five, N, i;
	two = 0;
	five = 0;

	cin >> N;

	for (i = 2; i <= N; i *= 2) {
		two += N / i;
	}

	for (i = 5; i <= N; i *= 5) {
		five += N / i;
	}

	two < five ? printf("%d\n", two) : printf("%d\n", five);

	return 0;
}