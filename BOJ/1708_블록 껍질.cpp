#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

#define MAX 100002

using namespace std;

typedef long long ll;

struct Point {
	int x, y;
	int p, q;
	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}
};

bool comp1(const Point& A, const Point& B) {
	if (A.y != B.y)
		return A.y < B.y;

	return A.x < B.x;
}
bool comp(const Point& A, const Point& B) {
	if (1LL * A.q * B.p != 1LL * A.p * B.q)
		return 1LL * A.q * B.p < 1LL * A.p * B.q;

	if (A.y != B.y)
		return A.y < B.y;

	return A.x < B.x;
}

ll ccw(const Point& A, const Point& B, const Point& C) {
	return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}

Point p[MAX];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		p[i] = Point(x, y);
	}

	sort(p, p + n, comp1);

	for (int i = 1; i < n; i++) {
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}

	sort(p + 1, p + n, comp);

	stack<int> s;

	s.push(0);
	s.push(1);

	int next = 2;

	while (next < n) {
		while (s.size() >= 2) {
			int first, second;
			second = s.top();
			s.pop();
			first = s.top();

			if (ccw(p[first], p[second], p[next]) > 0) {
				s.push(second);
				break;
			}
		}
		s.push(next++);
	}

	printf("%d", s.size());

	return 0;
}