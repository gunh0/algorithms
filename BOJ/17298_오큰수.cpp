#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int a[1000001];

int main()
{
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector<int> v(n);
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++) {
		if (s.empty()) {
			s.push(i);
		}
		while (!s.empty() && a[s.top()] < a[i]) {
			v[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		v[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	return 0;
}
