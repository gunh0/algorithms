#include <iostream>
#include <algorithm>

using namespace std;

pair<long long, long long> zeros(long long n) {
	long long two = 0, five = 0, i = 0;
	for (i = 2; i <= n; i *= 2) two += n / i;
	for (i = 5; i <= n; i *= 5) five += n / i;
	return (pair <long long, long long>(two, five));
}

int main() {
	int n, r;
	pair<long long, long long> ansn, ansr, ansnr;
	long long t, f;

	cin >> n >> r;

	ansn = zeros(n);
	ansr = zeros(r);
	ansnr = zeros(n - r);

	t = ansn.first - ansr.first - ansnr.first;
	f = ansn.second - ansr.second - ansnr.second;

	printf("%lld\n", min(t, f));

	return 0;
}