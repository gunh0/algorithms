#include <iostream>

using namespace std;

typedef long long ll;	// 거리의 제곱수로 비교

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		ll dx = x1 - x2;
		ll dy = y1 - y2;

		if (r1 > r2) swap(r1, r2);
		ll add = r1 + r2;
		add = add * add;
		ll sub = r2 - r1;
		sub = sub * sub;
		ll d = dx*dx + dy*dy;

		if (d < add && d > sub) {	// 원이 두 점에서 만나는 경우
			cout << 2;
		}
		else if (d == add || (d == sub && d != 0)) {	// 두 원이 외접하는 경우 || 두 원이 내접하는 경우
			cout << 1;
		}
		else if (d < sub || d > add) {	// 하나의 원이 다른 원을 포함하는 경우 || 두원이 멀리 떨어져 만나지 않는 경우
			cout << 0;
		}
		else if (d == 0) {
			if (r1 == r2)	// 무수히 많은 점에서 만나는 경우
				cout << -1;
			else
				cout << 0;
		}
		cout << '\n';
	}

	return 0;

}