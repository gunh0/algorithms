#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int n, i, j = 0;
	stack<int> s;
	vector<char> v;

	cin >> n;
	vector<int> arr;

	for (i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	for (i = 1; i <= n; i++) {
		s.push(i);
		v.push_back('+');

		while (!s.empty() && s.top() == arr[j]) {
			s.pop();
			v.push_back('-');
			j++;
		}
	}

	if (!s.empty()) printf("NO\n");
	else {
		for (i = 0; i < v.size(); i++) printf("%c\n", v[i]);
	}

	return 0;
}