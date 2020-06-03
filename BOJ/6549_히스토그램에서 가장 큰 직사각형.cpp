#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	while (true) {
		cin >> n;
		if (!n)break;
		stack<pair<int, int> > st;
		long long int ans = 0;
		for (int i_index = 0; i_index <= n; i_index++) {
			int i_height;
			if (i_index < n)
				cin >> i_height;
			else
				i_height = -1;
			int left = i_index;
			// top_index: st.top().first | top_height: st.top().second
			while (!st.empty() && st.top().second > i_height) {
				ans = ans > ((long long int)i_index - st.top().first)* st.top().second ? ans : ((long long int)i_index - st.top().first) * st.top().second;
				left = st.top().first;
				st.pop();
			}
			st.push(make_pair(left, i_height));
		}
		printf("%lld\n", ans);
	}
	return 0;
}