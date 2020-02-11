#include <iostream>

using namespace std;

int main() {
	int T, N;
	long long cache[21] = {};
	cin >> T;
	cache[1] = 1;
	for (int i = 2; i < 21; i++)
		cache[i] = i * (cache[i - 1] + cache[i - 2]);
	while (T--) {
		cin >> N;
		printf("%lld\n", cache[N - 1]);
	}

	return 0;
}